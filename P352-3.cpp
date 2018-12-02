#include<iostream>
#include<list>
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
		for (int i = n; i > 0; i--) {
			HeadNode[i].data = i;
			HeadNode[i].link = NULL;
		}
	};
	void Add(int u, int v) {
		Node *temp = &HeadNode[u];
		while (temp!=NULL) {
			if (temp->link == NULL) {
				temp->link = &HeadNode[v];
				break;
			}
			temp = temp->link;
		}
		Node *temp2 = &HeadNode[v];
		while (temp2!=NULL) {
			if (temp2->link == NULL) {
				temp2->link = &HeadNode[u];
				break;
			}
			temp2 = temp2->link;
		}
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
}