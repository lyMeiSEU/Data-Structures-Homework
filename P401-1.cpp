#include<iostream>
using namespace std;

int counter = 0;

template <class T>
void Insert(const T& e, T *a, int i) {
	a[0] = e;
	while (e < a[i]) {
		a[i + 1] = a[i];
		i--;
	}
	counter++;
	cout << "第" << counter << "次:";
	a[i + 1] = e;
	for (int i = 0; i < 11; ++i) {
		cout << a[i] << " ";
	}
	cout << endl;
}

template <class T>
void InsertionSort(T*a, const int n) {
	for (int j = 2; j <= n; j++) {
		T temp = a[j];
		Insert(temp, a, j - 1);
	}
}

int main() {
	int a[] = { 12,2,16,30,8,28,4,10,20,6,18 };
	cout << "初始值:";
	for (int i = 0; i < 11; ++i) {
		cout << a[i] << " ";
	}
	cout << endl;
	InsertionSort(a, 11);
}