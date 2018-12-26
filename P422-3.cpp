#include<iostream>
using namespace std;
template <class T>
int RadixSort(T*a, int *link, const int d, const int r, const int n) {
	int e[r],f[r];
	int first = 1;
	for (int i = 1; i < n; ++i) {
		link[i] = i + 1;
	}
	link[n] = 0;
	for (i = d - 1; i >= 0; --i) {
		fill(f, f + r, 0);
		int k;
		for (int current = first; current; current = link[current]) {
			k = digit(a[current], i, r);
			if (f[k] == 0) {
				f[k] = current
			}
			else {
				link[e[k]] = current;
				e[k] = current;
			}
		}

		for (int j = 0; !f[j]; ++j);
		first = f[j];
		int last = e[j];
		for (int k = j + 1; k < r; ++k) {
			if (f[k]) {
				link[last] = f[k];
				last = e[k];
			}
		}
		link[last] = 0;
	}
}

int main() {
	int a[] = { 12,2,16,30,8,28,4,10,20,6,18 };
	int *link;
	RadixSort(a, link, 3, 10, 11);
	for (int i = 0; i < 11; ++i) {
		cout << a[i] << " ";
	}
	cout << endl;
}