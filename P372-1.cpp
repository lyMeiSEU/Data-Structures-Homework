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

void ShortestPath(const int n, const int v) {
	for (int i = 0; i < n; ++i) {
		s[i] = false;
		dist[i] = length[v][i];
	}
	s[v] = true;
	
	for (int i = 0; i < n - 2; ++i) {
		int u = Choose(n);
		s[u] = true;
		for (int w = 0; w < n; ++w) {
			if (!s[w] && dist[u] + length[u][w] < dist[w]) {
				dist[w] = dist[u] + length[u][w];
			}
		}
	}
}

int main() {
	fill(s, s + MAX, false);
	fill(dist, dist + MAX, 0);
	cout << "Input the edges. (Like: u,v,w)" << endl;
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
	for (int i = 1; i < MAX; ++i) {
		ShortestPath(0, i);
	}
	for (int i = 0; i < MAX; ++i) {
		cout << dist[i] << " " ;
	}
}
