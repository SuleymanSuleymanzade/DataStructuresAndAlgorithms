#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;

struct Node{
	int x, y, dist;
	Node(){};
	Node(int x, int y, int dist = 0):x(x), y(y), dist(dist){}
	
	vector<pair<int,int>> path;

	bool operator < (const Node& O)const{
		return x < O.x || (x == O.x && y < O.y);
	}
};

bool is_ok(int x, int y){
	return (x >= 0 && x < 8 && y < 8 && y >= 0);	
}


pair<int, vector<pair<int,int> > > bfs(Node src, Node dest){
	
	//vector<bool> visited;
	queue<Node> q;
	q.push(src);
	
	map<Node, bool> visited;

	int row[] = {1, 1, -1, -1, 2,  2, -2, -2};
	int col[] = {2, -2, 2, -2, 1, -1, -1, 1};
	
	while(!q.empty()){
		
		Node node = q.front();
		q.pop();

		int x = node.x;
		int y = node.y;
		int dist = node.dist;
		
		vector< pair<int,int> > path = node.path;

		if(x == dest.x && y == dest.y)
			return make_pair(dist, node.path);

		if(!visited.count(node)){
			visited[node] = true;

			for(int i = 0; i < 8; i++){

				int new_x = x + row[i];
				int new_y = y + col[i];
				
				vector< pair< int, int> > new_path = path;
				new_path.push_back(make_pair(new_x, new_y));

				if(is_ok(new_x, new_y)){
					Node nn;
					nn.x = new_x;
					nn.y = new_y;
					nn.dist = dist + 1;
					nn.path = new_path;
					
					q.push(nn);
				}

			}
		}
	}
	return make_pair(-1e9, vector< pair<int,int>> ());
}


int main(){

	Node start = {3, 1};
	Node end = {7, 7};

	pair<int, vector<pair<int,int> > > res = bfs(start, end);

	cout<<"the distance is: "<<res.first<<endl;
	for(auto path: res.second){
		cout<<path.first<<" "<<path.second<<endl;
	}


	return 0;
}
