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

int main() {
	cout << "当输入表有序时" << endl;
	int a[] = { 2,4,6,8,10,12,16,18,20,28,30 };
	QuickSort(a, 0, 10);
	for (int i = 0; i < 11; ++i) {
		cout << a[i] << " ";
	}
	cout << endl;
}