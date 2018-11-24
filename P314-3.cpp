#include<iostream>
using namespace std;
#define HeapSize 10
class Sets {
public:
	Sets(int p[]) {
		n = (sizeof(p) / sizeof(int)) + 1;
		parent = new int[n];
		for (int i = 0; i < sizeof(p) / sizeof(int); ++i) {
			parent[i] = p[i];
		}
	}
	Sets(int sz = HeapSize) {
		n = sz;
		parent = new int[sz];
		for (int i = 0; i < n; ++i) {
			parent[i] = -1;
		}
	}
	void SimpleUnion(int i, int j) {
		parent[i] = j;
	}
	int SimpleFind(int i) {
		while (parent[i] >= 0) {
			i = parent[i];
		}
		return i;
	}

	void WeightUnion(int i, int j) {
		int temp = parent[i] + parent[j];
		if (i > j) {
			parent[i] = j;
			parent[j]=temp;
		}
		else {
			parent[j] = i;
			parent[i] = temp;
		}
	}
	int CollospingFind(int i) {
		int r;
		for (r = i; parent[r] >= 0; r = parent[r]);//Find root;
		while (i != r) {
			int s = parent[i];
			parent[i] = r;
			i = s;
		}
		return r;
	}
private:
	int *parent;
	int n;
};

int main() {
	int a[] = { 1,2,3,4,5,6 };
	int b[] = { 7,8,9,10,11 };
	Sets *A = new Sets(a);
	Sets *B = new Sets(b);
	A->WeightUnion(7,8);
	cout << A->CollospingFind(9) << endl;
}