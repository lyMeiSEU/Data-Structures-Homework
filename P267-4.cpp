#include<iostream>
#include<queue>
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

void InOrderTraversal(BinTree &BT) {
	if (BT) {
		InOrderTraversal(BT->Left);
		cout << BT->Data <<" ";
		InOrderTraversal(BT->Right);
	}
}

BinTree TreeBulider(int now,int N) {
	if (now<=N) {
		BinTree tmp = (BinTree)malloc(sizeof(struct TreeNode));
		tmp->Data = now;
		tmp->Left = TreeBulider(2*now,N);
		tmp->Right = TreeBulider(2*now+1,N);
		return tmp;
	}
	else
		return NULL;
}

int main() {
	BinTree BT=(BinTree)malloc(sizeof(struct TreeNode));
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
	cout << "Traverseing the Tree in inorder..." << endl;
	InOrderTraversal(BT);
	
}