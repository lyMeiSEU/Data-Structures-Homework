#include <iostream>
#include <stack>
using namespace std;

typedef struct PolyNode *Polynomial;
struct PolyNode {
	int nub;
	Polynomial l;
	Polynomial r;
};

void Mover(Polynomial left, int n, int position) {
	cout << "Moving to position..." << endl;
	while (position--) {
		left = left->l;
	}
	cout << "The number you passed are:";
	while (n--) {
		if (left->l == NULL) {
			cout << endl;
			cout << "There is no more position,set left=0" << endl;
			left = 0;
			break;
		}
		cout << left->nub << " ";
		left = left->l;
	}
	cout << endl;
	if (left != NULL) {
		cout << "Now we end at:" << left->nub << endl;
	}
	cout << endl;
}

void Movel(Polynomial right, int n, int position) {
	cout << "Moving to position..." << endl;
	while (position--) {
		right = right->r;
	}
	cout << "The number you passed are:";
	while (n--) {
		if (right->r == NULL) {
			cout << endl;
			cout << "There is no more position,set right=0" << endl;
			right = 0;
			break;
		}
		cout << right->nub << " ";
		right = right->r;
	}
	cout << endl;
	if (right != NULL) {
		cout << "Now we end at:" << right->nub << endl;
	}
	cout << endl;
}
void ChainAdder(Polynomial P,int n,int &sum)
{
	while (n < 95) {
		Polynomial tmp = (Polynomial)malloc(sizeof(struct PolyNode));
		tmp = P;
		for (int i = 0; i < 5; ++i) {
			tmp = tmp->l;
		}
		sum += (tmp->nub)*(P->nub);
		P = P->l;
		n++;
	}
}
int main() {
	Polynomial left,P;
	cout << "Making chain P..." << endl;
	left = (Polynomial)malloc(sizeof(struct PolyNode));
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	P->r = NULL;
	int flag = 1;
	for (int i = 1; i < 101; ++i) {
		Polynomial temp = (Polynomial)malloc(sizeof(struct PolyNode));
		temp->r = P;
		temp->l = NULL;
		temp->nub = i;
		P->l = temp;
		P = P->l;
		if (flag) {
			left = P;
			flag = 0;
		}
	}
	cout << "Accumulating (xi*xi+5) from 0-95..." << endl;
	cout << "The sum is: ";
	int sum = 0;
	ChainAdder(left, 0, sum);
	cout << sum << endl;
}