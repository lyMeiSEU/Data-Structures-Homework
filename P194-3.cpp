#include <iostream>
#include <stack>
using namespace std;

typedef struct PolyNode *Polynomial;
struct PolyNode {
	int nub;
	Polynomial link;
};

void MoveChainToArray(Polynomial first, int array[100]) {
	int i = 0;
	for (i = 0; i < 100; i++) {
		first = first->link;
		array[i] = first->nub;
	}
	for (i=0; i <100; i++) {
		cout << array[i] << " ";
	}
}

int main() {
	Polynomial P;
	cout << "Making chain P..." << endl;
	P =(Polynomial)malloc(sizeof(struct PolyNode));
	Polynomial first = P;
	P->link = NULL;
	cout << "Adding number 1-100 into chain P..." << endl;
	for (int i = 1; i < 101; ++i) {
		Polynomial temp = (Polynomial)malloc(sizeof(struct PolyNode));
		temp->link = NULL;
		temp->nub = i;
		P->link = temp;
		P = P->link;
	}
	cout << "Moving number from chain to array..." << endl;
	cout << "Numbers in the array are: ";
	int array[100];
	MoveChainToArray(first, array);

}