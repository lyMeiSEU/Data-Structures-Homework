#include<iostream>
#include<queue>
#include<stack>
using namespace std;

#define ElementType int
#define left 1
#define right 0
#define yes 1
#define no 0
typedef struct TreeNode *BinTree;
typedef BinTree Position;
struct  TreeNode
{
	ElementType Data;
	BinTree Left;
	BinTree Right;
};

BinTree deletNode(BinTree BT,BinTree next,int S,bool direction) {
	if (BT&&next) {
		if (direction == left) {
			if (BT->Left->Data == S) {
				BT->Left = deletNode(BT->Left,BT->Left->Left, S, left);
			}
		}
		if (direction == right) {
			if (BT->Right ->Data == S) {
				BT->Right = deletNode(BT->Right, BT->Right->Right, S, left);
			}
		}
		return next;
	}
	else if (BT) {
		if (BT->Data == S) {
			BT = NULL;
		}
		return NULL;
	}
	else {
		BT = NULL;
		return NULL;
	}
}

BinTree DoubleForkTreeBulider(int N,bool direction) {
	if (N > 0) {
		if (direction == left) {
			BinTree tmp = (BinTree)malloc(sizeof(struct TreeNode));
			tmp->Data = N*2;
			tmp->Right = NULL;
			tmp->Left=DoubleForkTreeBulider(N - 1, left);
			return tmp;
		}
		else if (direction == right) {
			BinTree tmp = (BinTree)malloc(sizeof(struct TreeNode));
			tmp->Data = N*2-1;
			tmp->Left = NULL;
			tmp->Right=DoubleForkTreeBulider(N - 1, right);
			return tmp;
		}
	}
	else
		return NULL;
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
	BT->Data = N;
	if (N % 2 == 0) {
		BT->Left = DoubleForkTreeBulider(N  / 2, left);
		BT->Right = DoubleForkTreeBulider((N / 2) - 1, right);
	}
	else {
		BT->Left = DoubleForkTreeBulider((N - 1) / 2, left);
		BT->Right = DoubleForkTreeBulider((N - 1) / 2, right);
	}
	InOrderTraversal(BT);
	cout << endl;
	int S;
	cout << "Input the Node you want to delete" << endl;
	cin >> S;
	deletNode(BT->Left,BT->Left->Left, S, left);
	deletNode(BT->Right,BT->Right->Right, S, right);
	cout << "Traverseing the Tree in preorder without using recursive..." << endl;
	InOrderTraversal(BT);
}