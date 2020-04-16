#include<iostream>
#include<vector>
using namespace std;

vector< vector< int> > graph;
vector<bool> visited;

void add_edge(int u, int v){
	graph[u].push_back(v);
	graph[v].push_back(u);
}
vector< vector< int> > cc_global;
int global_counter = 0;

void process(int u, bool notify = false){
	if(notify)
		cout<<u<<" ";
	cc_global[global_counter].push_back(u);
}	

void dfs(int u){
	visited[u] = true;
	process(u);
	for(int i = 0; i < graph[u].size();i++){
		if(!visited[graph[u][i]])
			dfs(graph[u][i]);
	}
}

void cc(vector< vector<int> > g, vector<bool> vis, bool notify = false){
	fill(vis.begin(), vis.end(), false);
	int con_comp = 1;
	cc_global.resize(g.size());
	for(int  i = 0; i < g.size(); i++){
		if(!visited[i]){
				if(notify)
					cout<<con_comp<<": ";
				dfs(i, notify);
				global_counter++;
				if(notify)
					cout<<endl;
		}
	}
}

void directed_to_undirected(vector<vector< int> > g){
	for(int i = 0; i < g.size(); i++){
		for(int j = 0; j < g[i].size(); j++){
			int node = graph[i][j];
			bool flag = false;
			for(int k = 0; k < graph[j].size(); k++){
				if(graph[j][k] == node)
					flag = true;
			}
			if(!flag)
				graph[j].push_back(node);
		}
	}
}

int main(){
	graph.resize(9);
	visited.assign(9, false);

	add_edge(0, 1);
	add_edge(1, 3);
	add_edge(0, 3);
	add_edge(3, 2);
	add_edge(6, 7);
	add_edge(6, 8);
	add_edge(4, 5);

	//dfs(0);
	cc(graph, visited);
	return 0;
}