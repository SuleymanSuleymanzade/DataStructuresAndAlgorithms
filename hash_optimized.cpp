#include<iostream>
#include<vector>
#include<cmath>
#include<string>
#include<cstring>
#include<cctype>
using namespace std;


vector< vector < string > > hash_table;

int h_func(string name, int n){
    int sum = 0;
    for(int i = 0; i < name.size(); i++){
        sum += toupper(name[i]) * (i + 1);
    }
    return sum % n;
}

void add_data(string name,int n){
    int h_i = h_func(name, n);
    hash_table[h_i].push_back(name);
}


pair<int, int> find_data(string name,int n){
        int h_i = h_func(name, n);

        for(int i = 0; i < hash_table[h_i].size(); i++){
            if (hash_table[h_i][i] == name)
                return make_pair(h_i, i);

        }
        return make_pair(1e9, 1e9);
}

void show_ht(){
    for(int i = 0; i < hash_table.size(); i++){
        cout<<i<<": ";
        for(int j = 0; j < hash_table[i].size(); j++){
            cout<<hash_table[i][j]<<" ";
        }
        cout<<endl;
    }
}


int main(){

    int n = 10;
    
    hash_table.resize(n);

    string name =  "haciahmad";
    
    add_data(name, n);
    add_data("Ali", n);
    add_data("Tarlan", n);
    add_data("Elgun", n);
    add_data("Ila", n);
    
    show_ht();
    pair<int, int> loc = find_data("Ali", n);
    cout<<"Ali: "<<loc.first<<" "<<loc.second<<endl;
return 0;
}
