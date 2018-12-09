#include<iostream>
using namespace std;

#define MAX 10

bool s[MAX];
int dist[MAX][MAX];
int length[MAX][MAX];

void  MartixWDgraph(const int n, const int v) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			dist[i][j] = length[i][j];
		}
	}
	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
}

int main() {
	fill(s, s + MAX, false);
	//fill(dist, dist + MAX, 0);
	cout << "Input the edges.(Multi-source path) (Like: u,v,w)" << endl;
	cout << "Please end with -1000" << endl;
	int u, v, w;
	while (true) {
		cin >> u >> v >> w;
		if (u == -1 || v == -1 || w == -1) {
			break;
		}
		length[u][v] = w;
	}
	cout << "Searching shortest pass from 0->every point." << endl;
	MartixWDgraph(MAX, 0);

	for (int i = 0; i < MAX; ++i) {
		cout << dist[i] << " ";
	}
}
