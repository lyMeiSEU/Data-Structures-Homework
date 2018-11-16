#include<iostream>
#include<queue>
#include<stack>
using namespace std;

#define ElementType int
typedef struct TreeNode *BinTree;
typedef BinTree Position;
struct  TreeNode
{
	ElementType Data;
	BinTree Left;
	BinTree Right;
};

void NodeInserter(BinTree BT, int N) {
	if (BT) {
		if (BT->Data == N)
		{
			BinTree tmp = (BinTree)malloc(sizeof(struct TreeNode));
			tmp = BT->Left;
			BinTree in = (BinTree)malloc(sizeof(struct TreeNode));
			BT->Left = in;
			in->Data = 1;
			in->Left = tmp;
			in->Right = NULL;
			return;
		}
		NodeInserter(BT->Left, N);
		NodeInserter(BT->Right, N);
	}
}

void InOrderTraversal(BinTree BT) {
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
}

BinTree TreeBulider(int now, int N) {
	if (now <= N) {
		BinTree tmp = (BinTree)malloc(sizeof(struct TreeNode));
		tmp->Data = now;
		tmp->Left = TreeBulider(2 * now, N);
		tmp->Right = TreeBulider(2 * now + 1, N);
		return tmp;
	}
	else
		return NULL;
}

int main() {
	BinTree BT = (BinTree)malloc(sizeof(struct TreeNode));
	int N;
	cout << "Input the Node number in the Tree" << endl;
	cin >> N;
	cout << "Buliding Tree..." << endl;/*
										 1
									   2   3
									 4  5 6  7
									...........
									   */
	BT = TreeBulider(1, N);
	int S;
	cout << "Enter the Number of Node S you Want to insert after" << endl;
	cin >> S;
	NodeInserter(BT, S);
	cout << "Traverseing the Tree in preorder without using recursive..." << endl;
	InOrderTraversal(BT);
}