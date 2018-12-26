#include<iostream>
using namespace std;
template <class T>
void Permute(T*a, const int n) {
	for (int i = n; i >= 2; --i) {
		int j = rand() % i + 1;
		swap(a[j], a[i]);
	}
}

int main() {
	int a[] = { 12,2,16,30,8,28,4,10,20,6,18 };
	Permute(a,10);
	for (int i = 0; i < 10; ++i) {
		cout << a[i] << " ";
	}
	cout << endl;
}