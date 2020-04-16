#include<iostream>
#include<vector>
#include<string>
using namespace std;

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



int main(){

    node *n1 = create(5);
    node *n2 = create(7);
    node *n3 = create(10);
    node *n4 = create(444);
    node *n5 = create(111);

    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n4->right = n5;
    
    traverse(n1, "inorder");
    cout<<"-----------------------"<<endl;
    traverse(n1, "postorder");
    cout<<"-----------------------"<<endl;
    traverse(n1, "preorder");

return 0;
}
