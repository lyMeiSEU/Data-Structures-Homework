#include<iostream>
#include<stack>
using namespace std;


template<class T>
void QuickSort(T*a, const int left, const int right) {
	if (left < right) {
		int i = left;
		int j = right + 1;
		T pivot = a[left];
		do {
			do i++; while (a[i] < pivot);
			do j--; while (a[j] > pivot);
			if (i < j)
				swap(a[i], a[j]);
		} while (i < j);
		swap(a[left], a[j]);

		QuickSort(a, left, j - 1);
		QuickSort(a, j + 1, right);
	}
}

template<class T>
void Adjust(T*a, const int root, const int n) {
	T e = a[root];
	int j;
	for (j = 2 * root; j <= n; j *= 2) {
		if (j < n&&a[j] < a[j] + 1)
			j++;
		if (e >= a[j])
			break;
		a[j / 2] = a[j];
	}
	a[j / 2] = e;
}

template<class T>
void HeapSort(T*a, const int n) {
	for (int i = n / 2; i >= 1; --i) {
		Adjust(a, i, n);
	}
	for (int i = n - 1; i >= 1; --i) {
		swap(a[1], a[i + 1]);
		Adjust(a, 1, i);
	}
}

int main() {
	cout << "HeapSort" << endl;
	int a[] = { 12,2,16,30,8,28,4,10,20,6,18 };
	HeapSort(a, 10);
	for (int i = 0; i < 11; ++i) {
		cout << a[i] << " ";
	}
	cout << endl;
}