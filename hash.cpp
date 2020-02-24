#include<iostream>
#include<vector>
#include<cmath>
#include<string>
#include<cstring>
#include<cctype>
using namespace std;

class Person{
    private:
        string name, sname, phone_num;
    public:
        Person(string name,string  sname,string phone_num){
            this->name = name;
            this->sname = sname;
            this->phone_num = phone_num;
        }
        string get_name(){
            return this->name;
        }
        string get_sname(){
            return this->sname;
        }
        void get_all_data(){
            cout<<this->name<<" "<<this->sname<<endl;
            cout<<this->phone_num<<endl;
        }
};


vector< vector < pair<string, Person*> > > hash_table;

int h_func(string name, int n){
    int sum = 0;
    for(int i = 0; i < name.size(); i++){
        sum += toupper(name[i]) * (i + 1);
    }
    return sum % n;
}

void add_data(Person *p,int n){

    int h_i = h_func(p->get_name(), n);
    hash_table[h_i].push_back(make_pair(p->get_name(), p));
}


pair<int, int> find_data(string name,int n){
        int h_i = h_func(name, n);

        for(int i = 0; i < hash_table[h_i].size(); i++){
            if (hash_table[h_i][i].first == name)
                return make_pair(h_i, i);

        }
        return make_pair(1e9, 1e9);
}

void show_ht(){
    for(int i = 0; i < hash_table.size(); i++){
        cout<<i<<": ";
        for(int j = 0; j < hash_table[i].size(); j++){
            cout<<hash_table[i][j].first<<" ";
        }
        cout<<endl;
    }
}

void remove_person(string name, string sname, int n){
    pair<int,int> loc = find_data(name, n);
    for(int i = 0; i < hash_table[loc.first].size(); i++){
        if(name == hash_table[loc.first][i].second->get_name() && 
                sname == hash_table[loc.first][i].second->get_sname())
            delete hash_table[loc.first][i].second;

    }

}


int main(){

    int n = 10;
    
    hash_table.resize(n);

    Person *haciahmad = new Person("Haciahmad", "Ahmadzade", "555-123-123");
    Person *tarlan = new Person("Tarlan", "Omarbayli", "111-222-444");
    Person *aydan = new Person("Aydan", "Sheydayeva","555-555-555");

    add_data(haciahmad, n);
    add_data(tarlan, n);
    add_data(aydan, n);
    
    show_ht();
    cout<<endl<<endl;
    pair<int, int> loc = find_data(haciahmad->get_name(), n);
    hash_table[loc.first][loc.second].second->get_all_data();
return 0;
}
