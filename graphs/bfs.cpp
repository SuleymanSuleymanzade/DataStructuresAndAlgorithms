#include<iostream>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

vector< vector< int> > graph;
vector<bool> visited;

/*
    0| -> 1 -> 2
    1| -> 0
    2|
    3| -> 5
    4| -> 5 -> 3 -> 0
    5| -> 2

*/
void add_edge(int from, int to,bool directed = true){
    graph[from].push_back(to);
    if(directed == false)
        graph[to].push_back(from); // undirected
}

void print_graph(vector< vector< int> > g){
    for(int i = 0; i < g.size(); i++){
        cout<<i<<": ";
        for(int j = 0; j < g[i].size(); j++){
            cout<<g[i][j]<<" ";
        }
        cout<<endl;
    }
}

void process(int node){
    cout<<node<<endl;
}


void bfs(int u){
    visited[u] = true;
    queue<int> q;
    q.push(u);
    
    while(!q.empty()){

        int v = q.front();
        q.pop();
        process(v);
        for(int i = 0; i < graph[v].size(); i++){
            if(!visited[graph[v][i]]){
                q.push(graph[v][i]);
                visited[graph[v][i]] = true;
            }            
        }    
    }
}


int main(){
    graph.resize(6);
    visited.assign(6, false);

    add_edge(0,1);
    add_edge(0,2);
    add_edge(1, 0);
    add_edge(3, 5);
    add_edge(4, 5);
    add_edge(4, 3);
    add_edge(4, 0);
    add_edge(5, 2);
    
    //print_graph(graph);
    bfs(4);
    return 0;
}



