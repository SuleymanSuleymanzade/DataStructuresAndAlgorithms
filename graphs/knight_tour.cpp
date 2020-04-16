#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

struct Node{
	int x, y, dist;
	
	Node(int x, int y, int dist = 0):x(x), y(y), dist(dist){}
	
	bool operator < (const Node& O)const{
		return x < O.x || (x == O.x && y < O.y);
	}
};

bool is_ok(int x, int y){
	return (x >= 0 && x < 8 && y < 8 && y >= 0);	
}


int bfs(Node src, Node dest){
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

		if(x == dest.x && y == dest.y)
			return dist;

		if(!visited.count(node)){
			visited[node] = true;

			for(int i = 0; i < 8; i++){

				int new_x = x + row[i];
				int new_y = y + col[i];

				if(is_ok(new_x, new_y)){
					Node nn(new_x, new_y, dist + 1);
					q.push(nn);
				}

			}
		}
	}
	return -1e9;
}


int main(){

	Node start = {3, 1};
	Node end = {7, 7};

	int res = bfs(start, end);
	cout<<"the distance is: "<<res<<endl;


	return 0;
}
