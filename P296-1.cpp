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
<<<<<<< HEAD
	int max(int a, int b) {
		if (a > b) {
			return a;
		}
		else
			return b;
	}
	void Reset() {
		_Reset(Root);
	}
	int Height() {
		return _Height(Root);
	}
private:
	void _Reset(PNode &pRoot) {
		pRoot = NULL;
	}
	bool _Insert(PNode& pRoot, const T& data)
	{
		if (NULL == pRoot) {
			pRoot = new Node(data);
			return true;
=======
}

BinTree DoubleForkTreeBulider(int N,bool direction) {
	if (N > 0) {
		if (direction == left) {
			BinTree tmp = (BinTree)malloc(sizeof(struct TreeNode));
			tmp->Data = N*2;
			tmp->Right = NULL;
			tmp->Left=DoubleForkTreeBulider(N - 1, left);
			return tmp;
>>>>>>> parent of bdb48fd... Update P296-1.cpp
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
<<<<<<< HEAD
	int _Height(PNode pRoot)
	{
		int deepl = 1, deepr = 1;
		PNode pRootl = pRoot, pRootr = pRoot;
		while (pRootl) {
			deepl++;
			pRootl = pRootl->Left;
		}
		while (pRootr) {
			deepr++;
			pRootr = pRootr->Right;
		}
		return max(deepl, deepr);
	}
private:
	PNode Root;
};
void test() {
	int arr[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	BSTree<int> bs;
	cout << "Making Tree..." << endl;
	cout << "The Number N is from 100-10000, When it comes to 10000,it may take some times..." << endl;
	int N=100;
	for (int i = 0; i < 2; ++i) {
		bs.Reset();
		cout << "For the number " << N << endl;
		for (size_t i = 0; i < N; ++i)
			bs.Insert(rand() % N);
		bs.InOrder();
		cout << "The Deep of the Tree is " << bs.Height() << endl;
		if (i == 0) {
			N *= 5;
		}
		if (i == 1) {
			N *= 2;
		}
	}
	while (N <= 10000) {
		bs.Reset();
		cout << "For the number N = " << N << endl;
		for (size_t i = 0; i < N; ++i)
			bs.Insert(rand()%N);
		bs.InOrder();
		cout <<"The Deep of the Tree is "<< bs.Height() << endl;
		N += 1000;
	}
}
int main() {
	test();
	return 0;
}
=======
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
>>>>>>> parent of bdb48fd... Update P296-1.cpp
