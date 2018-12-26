#include<iostream>
using namespace std;
template <class T>
void Table(T*a, const int n,int*t) {
	for (int i = 1; i < n; ++i) {
		if (t[i] != i) {
			T p = a[i];
			int j = i;
			do {
				int k = t[j];
				a[j] = a[k];
				t[i] = j;
				j = k;
			} while (t[j] != i);
			a[j] = p;
			t[i] = j;
		}
	}
}

int main() {
	int a[] = { 12,2,16,30,8,28,4,10,20,6,18 };
	int t[] = { 1,2,3,4,5,6,7,8,9,10,11 };
	Table(a,10, t);
	for (int i = 0; i < 10; ++i) {
		cout << a[i] << " ";
	}
	cout << endl;
}