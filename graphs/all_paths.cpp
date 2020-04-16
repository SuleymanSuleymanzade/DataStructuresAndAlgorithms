#include<iostream>
#include<vector>
using namespace std;

vector<vector<int> >  graph;
vector<bool> visited;
vector<int> path;

vector< vector< int> > paths;
int path_count = 0;

void dfs(int curr, int dest){
	path.push_back(curr);

	if(curr == dest){
		for(auto i: path)
			cout<<i<< " ";
		cout<<endl;
		return;
	}
	visited[curr] = true;
	for(int i = 0; i < graph[curr].size(); i++){
		if(!visited[graph[curr][i]])
			dfs(graph[curr][i], dest);
	}
	path.pop_back();
	visited[curr] = false;
}

void add(int u, int v){
	graph[u].push_back(v);
}


int main(){
	graph.resize(7);
	visited.assign(7, false);
	add(1, 2);
	add(2, 3);
	add(3, 5);
	add(2, 4);
	add(4, 6);
	add(6, 5);
	add(2, 5);
	add(5, 3);


	dfs(1, 3);

	return 0;
}


