#include<iostream>
#include<time.h>
#include<queue>
#include<stack>
using namespace std;

#define ElementType int
typedef struct TreeNode *BinTree;
typedef BinTree Position;
struct  TreeNode
{
	ElementType Data;
	BinTree father;
	BinTree Left;
	BinTree Right;
};

BinTree NodeInserter(BinTree in) {
	if (in) {
		if (in->father->Data < in->Data) {
			BinTree tmp = (BinTree)malloc(sizeof(struct TreeNode));
			tmp = in;
			in = in->father;
			tmp->father = tmp;
			NodeInserter(in);
		}
		return in;
	}
	else
		return NULL;
}
static int n=0;
BinTree InOrderTraversal(BinTree BT) {
	BinTree T = BT;
	stack<BinTree>s;
	while (T != NULL || s.size() != 0)
	{
		while (T != NULL) {
			s.push(T);
			cout << s.top()->Data << " ";
			T = T->Left;
		}
		if (s.size() != 0)
		{
			T = s.top();
			s.pop();
			T = T->Right;
		}
	}
	return BT;
}

BinTree TreeBulider(int now, int N,BinTree father,BinTree &last) {
	if (now <= N) {
		BinTree tmp = (BinTree)malloc(sizeof(struct TreeNode));
		tmp->Data = N - now + 1;
		tmp->father = father;
		tmp->Left = TreeBulider(2 * now, N,tmp,last);
		tmp->Right = TreeBulider(2 * now + 1, N, tmp,last);
		if (now == N)
		{
			last = tmp;
		}
		return tmp;
	}
	else
		return NULL;
}

int main() {
	BinTree BT = (BinTree)malloc(sizeof(struct TreeNode));
	BinTree last = (BinTree)malloc(sizeof(struct TreeNode));
	BT->father = NULL;
	int N;
	cout << "Input the Node number in the Tree" << endl;
	cin >> N;
	cout << "Buliding Tree..." << endl;/*
										 1
									   2   3
									 4  5 6  7
									...........
									   */
	BT = TreeBulider(1, N,BT,last);
	InOrderTraversal(BT);
	int S;
	cout << "Input the Node you want to Insert" << endl;
	cin >> S;
	cout << "Building Node..." << endl;
	BinTree in = (BinTree)malloc(sizeof(struct TreeNode));
	in->father = last;
	in->Data = S;
	in->Left = NULL;
	in->Right = NULL;

	BT=NodeInserter(in);
	InOrderTraversal(BT);
}