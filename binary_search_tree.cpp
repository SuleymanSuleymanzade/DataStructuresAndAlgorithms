#include<iostream>
#include<vector>
#include<string>
using namespace std;

int max(int a, int b){
    return a > b ? a : b;
}

struct node{
    int data;
    node* left;
    node* right;
};

node* create(int data){
    node* nn = new node();
    nn->left = NULL;
    nn->right = NULL;
    nn->data = data;
    return nn;
}

void process(node* root){
    cout<<root->data<<endl;
}

void traverse(node* root, string mode="inorder"){
   if(root == NULL)
       return;
   if(mode == "inorder"){
        traverse(root->left, "inorder");
        process(root);
        traverse(root->right, "inorder");
   }else if(mode == "postorder"){
        traverse(root->right);
        traverse(root->left);
        process(root);
   }else if(mode == "preorder"){
        process(root);
        traverse(root->left);
        traverse(root->right);
   }
   else
       return;
}

node* insert(node* root, int key){
    if(root == NULL)
        return create(key);
    if(key > root->data)
        root->right = insert(root->right, key);
    else if(key < root-> data)
        root->left = insert(root->left, key);
    return root;
}

node* search_node(node* root, int key){
    if (root == NULL)
        return root;
    if(key > root->data)
        return search_node(root->right, key);
    else if(key < root->data)
        return search_node(root->left, key);
    else
        return root;
}

bool is_data(node* root, int key){
    node* ans = search_node(root, key);
    return ans != NULL ? true : false; 
}

node* extremum(node* root, string mode){
        node* ans = root;
        if(mode == "max"){
            while(ans->right != NULL){
                ans = ans->right;
            }
        }
        else if(mode == "min"){
            while(ans->left != NULL){
                ans = ans->left;
        }
    }else
        return NULL;
    return ans;
}

node* delete_node(node* root, int key){
    if(root == NULL)
        return root;
    if(key > root->data){
        root->right = delete_node(root->right, key);
    }
    else if(key < root->data){
        root->left = delete_node(root->left, key);
    }
    else{/*
        if(root->left == NULL && root->right == NULL){
            node* temp = root;
            delete root;
            return temp;
        }*/
        if(root->left == NULL){
            node* temp = root->right;
            delete root;
            return temp;
        }else if(root->right == NULL){
            node* temp = root->left;
            delete root;
            return temp;
        }
        node* temp = extremum(root->right, "min");
        root->data = temp->data;
        root->right = delete_node(root->right, key);
    }
    return root;
}

node* LCA(node* root, int n1, int n2){
    if(root == NULL)
        return root;
    if(root->data == n1 || root->data == n2)
        return root;
    node* l_lca = LCA(root->left, n1, n2);
    node* r_lca = LCA(root->right, n1, n2);
    
    if(l_lca && r_lca)
        return root;
    
    return l_lca != NULL? l_lca : r_lca;
}

int height(node* root){
    if(root == NULL)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}


int diameter(node* root){
    if(root == NULL)
        return 0;
    
    int h_left = height(root->left);
    int h_right = height(root->right);
    
    int d_left = diameter(root->left);
    int d_right = diameter(root->right);

    return max(h_left + h_right + 1, max(d_left, d_right));

}

int main(){
/* -------- bst ------------------
   node* root = NULL;
   root = insert(root, 5);
   root = insert(root, 7);
   root = insert(root, 3);
   root = insert(root, 123);
   root = insert(root, 4);
   root = insert(root, 777);

   cout<<is_data(root, 4)<<endl;
   root = delete_node(root, 4);
   cout<<is_data(root, 4)<<endl;

---------------------------------------------*/
/*------------LCA-and diameter-----------------    
*/
    node* root = create(5);
    root->left = create(1);
    root->right = create(4);
    root->left->left = create(2);
    root->left->right = create(6);
    root->left->left->left = create(7);
    root->left->left->right = create(8);
    root->left->left->right->left = create(9);
    root->left->left->right->right = create(10);
    root->right->right = create(12);
    root->right->left = create(3);
    root->right->left->left = create(11);
    root->right->left->right = create(13);
   
    cout<<LCA(root, 7, 10)->data<<endl;
    cout<<LCA(root, 6, 7)->data<<endl;
    cout<<"height: "<<height(root)<<endl;
    cout<<"diameter: "<<diameter(root)<<endl;
    //traverse(root, "inorder");
/*-----------------------------------------*/

return 0;
}
