#include<iostream>
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

int main() {
	int a[] = { 12,2,16,30,8,28,4,10,20,6,18 };
	QuickSort(a, 0, 10);
	for (int i = 0; i < 11; ++i) {
		cout << a[i] << " ";
	}
	cout << endl;
}