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

BinTree InOrderTraversal(BinTree BT) {
	BinTree T = BT;
	stack<BinTree>s;
	if (BT == NULL)
	{
		cout << "This is a Empty Tree" << endl;
		return NULL;
	}
	while (T != NULL || s.size() != 0)
	{
		while (T != NULL) {
			s.push(T);
			if (T->Left == NULL && T->Right == NULL) {
				cout << s.top()->Data << " ";
			}
			T = T->Left;
		}
		if (s.size() != 0)
		{
			T = s.top();
			s.pop();
			T = T->Right;
		}
	}
	cout << endl;
	return BT;
}


void destroy_bitree(BinTree &BT)
{
	if (BT)
	{
		//�ж��Ƿ���ڵ㣬���������ڵ�һֱ�ݹ���ȥ
		if ((BT)->Left)
			destroy_bitree(BT->Left);
		//�ж��Ƿ��ҽڵ㣬��������ҽڵ�һֱ�ݹ���ȥ
		if ((BT)->Right)
			destroy_bitree(BT->Right);
		//��һ�������������ҽ�㣬���ν��free��
		free(BT);
		BT = NULL;
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
	cout << "Traverseing the Tree in preorder without using recursive..." << endl;
	cout << "The Leaf nodes are:";
	InOrderTraversal(BT);
	cout << "Destroying Tree by recursive..." << endl;
	destroy_bitree(BT);
	cout << "Angain Traverseing the Tree in preorder without using recursive..." << endl;
	InOrderTraversal(BT);
}