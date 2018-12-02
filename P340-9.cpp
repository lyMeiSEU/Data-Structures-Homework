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
	int n;
public:
	Graph(const int vertices = 0) :n(vertices)
	{
		HeadNode = new Node[n];
	};
	void Add(int u, int v) {
		HeadNode[u].link = &HeadNode[v];
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
}