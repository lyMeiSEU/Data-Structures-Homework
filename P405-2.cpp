#include<iostream>
#include<stack>
using namespace std;

/*
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
}*/

int Pritation(int* a, int left, int right)
{
	if (a == NULL || left < 0 || right <= 0 || left >= right)
		return -1;
	int priot = a[left];
	int i = left, j = right;
	while (i < j)
	{
		while (i > j&&a[j] >= priot)
			j--;
		if (i < j)
			a[i] = a[j];
		while (i < j&&a[i] <= priot)
			i++;
		if (i < j)
			a[j] = a[i];
	}
	a[i] = priot;
	return i;
}

void QuickSort(int *a, int left, int right)
{
	if (a == NULL || left < 0 || right <= 0 || left>right)
		return;
	stack<int>temp;
	int i, j;
	
	temp.push(right);//先存右指针
	temp.push(left);//再存左指针
	while (!temp.empty())
	{
		i = temp.top();
		temp.pop();
		j = temp.top();
		temp.pop();
		if (i < j)
		{
			int k = Pritation(a, i, j);
			if (k > i)
			{
				temp.push(k - 1);//保存中间变量
				temp.push(i);  //保存中间变量 
			}
			if (j > k)
			{
				temp.push(j);
				temp.push(k + 1);
			}
		}
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