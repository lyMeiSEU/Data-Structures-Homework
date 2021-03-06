#include<iostream>
using namespace std;

#define MAX 10

bool s[MAX];
int dist[MAX];
int length[MAX][MAX];

int Choose(const int n) {
	int temp = dist[0];
	for (int i = 1; i < n; ++i) {
		if (dist[i] < temp&&s[i] == false)
			temp = dist[i];
	}
	return temp;
}

void  BellmanFord(const int n, const int v) {
	for (int i = 0; i < n; ++i) {
		dist[i] = length[v][i];
	}
	for (int k = 2; k <= n - 1; ++k) {
		for (int u = 0; u < v; ++u) {
			if (length[k][u] != 0) {
				if (dist[u] > dist[k] + length[k][u]) {
					dist[u] = dist[k] + length[k][u];
				}
			}
		}
	}
}

int main() {
	fill(s, s + MAX, false);
	fill(dist, dist + MAX, 0);
	cout << "Input the edges.(Single source path, with negative number) (Like: u,v,w)" << endl;
	cout << "Please end with -1" << endl;
	int u, v, w;
	while (true) {
		cin >> u >> v >> w;
		if (u == -1 || v == -1 || w == -1) {
			break;
		}
		length[u][v] = w;
	}
	cout << "Searching shortest pass from 0->every point." << endl;
	BellmanFord(MAX, 0);

	for (int i = 0; i < MAX; ++i) {
		cout << dist[i] << " ";
	}
}
