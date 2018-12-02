#include<iostream>
#include<list>
#include<queue>
using namespace std;

struct Node
{
	int data;
	Node*link;
};

class Graph {
private:
	Node *HeadNode;
	bool *visited;
	int n;
public:
	Graph(const int vertices = 0) :n(vertices)
	{
		HeadNode = new Node[n];
		for (int i = n-1; i >= 0; i--) {
			HeadNode[i].data = i;
			HeadNode[i].link = NULL;
		}
	};
	void Add(int u, int v) {
		Node *temp = &HeadNode[u];
		while (temp!=NULL) {
			temp = temp->link;
		}
		temp = &HeadNode[v];
		Node *temp2 = &HeadNode[v];
		while (temp2!=NULL) {
			temp2 = temp2->link;
		}
		temp2 = &HeadNode[u];
	}
	virtual void DFS() {
		visited = new bool[n];
		fill(visited, visited + n, false);
		DFS(0);
		delete []visited;
	}

	virtual void DFS(const int v) {
		visited[v] = true;
		Node *temp = &HeadNode[v];
		int w = 0;
		while (temp != NULL) {
			if (!visited[w]) {
				DFS(w);
			}
			w++;
			temp = temp->link;
		}
	}

	virtual void BFS(int v) {
		visited = new bool[n];
		fill(visited, visited + n, false);
		visited[v] = true;
		queue<int>q;
		q.push(v);
		while (!q.empty()) {
			v = q.front();
			q.pop();
			Node *temp = &HeadNode[v];
			int w = 0;
			while (temp != NULL) {
				if (!visited[w]) {
					DFS(w);
				}
				w++;
				temp = temp->link;
			}
		}
		delete[] visited;
	}
};

int main() {
	int N, V;
	cout << "Input the number of Nodes and Vertexs int the Graph" << endl;
	cin >> N >> V;
	Graph G(N);
	cout << "Input Nodes inorder." << endl;
	while (V--) {
		int u, v;
		cin >> u>>v;
		G.Add(u, v);
	}
	cout << "Traveling the tree DFS()" << endl;
	G.DFS();
	cout << "Traveling the tree BFS()" << endl;
	G.BFS(5);
}