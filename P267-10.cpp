#include<stdlib.h>
#include<malloc.h>
#include<iostream>
#include<stack>
using namespace std;

template<class T>
struct bitree {//二叉树的节点
	T data;
	struct bitree<T> *lchild, *rchild;
};

template<class T>
class ertree {

public:
	//用递归的方式来建立二叉树
	bitree<T> *TreeBuilder() {//建立二叉树
		bitree<T> *t;
		T a;
		cin >> a;
		if (a == 0)t = NULL;
		else {
			t = (bitree<T> *)malloc(sizeof(bitree<T>));
			t->data = a;
			cout << "Enter " << t->data << "'s Left child ";
			t->lchild = TreeBuilder();
			cout << "Enter " << t->data << "'s Right child ";
			t->rchild = TreeBuilder();
		}
		return t;
	}
	virtual void Order(bitree<T> *p) = 0;

	//递归的调用方式求解结点数
	int NodesNumber(bitree<T> *p) {//结点数
		int c;
		if (p == NULL)
			c = 0;
		else
			c = 1 + NodesNumber(p->lchild) + NodesNumber(p->rchild);
		return c;
	}

	//递归的调用方式求解叶子结点数
	int LeavesNumber(bitree<T> *p, int d1) {//叶子结点数
		if (p == NULL)
			return d1;
		else {
			if (p->lchild == NULL && p->rchild == NULL)
				d1++;
			LeavesNumber(p->lchild, d1);
			LeavesNumber(p->rchild, d1);
		}
	}

	//求深度时调用该函数
	int max(int m, int n)//比较大小
	{
		if (m > n)
			return m;
		else
			return n;
	}

	//递归的调用方式求解叶子结点数
	int height(bitree<T> *p) {//二叉树的高度
		if (p != NULL) {
			return (1 + max(height(p->lchild), height(p->rchild)));
		}
		else return 0;
	}
};

template <class T>
class PreOrderTree :public ertree<T> {
	void Order(bitree<T> *p) {
		if (p != NULL) {
			Order(p->lchild);
			Order(p->rchild);
			cout << p->data << ' ';
		}
	}
};

template <class T>
class InOrderTree :public ertree<T> {
	void Order(bitree<T> *p) {
		if (p != NULL) {
			Order(p->lchild);
			cout << p->data << ' ';
			Order(p->rchild);
		}
	}
};

template <class T>
class PostOrderTree :public ertree<T> {
	void Order(bitree<T> *p) {
		if (p != NULL) {
			Order(p->lchild);
			Order(p->rchild);
			cout << p->data << ' ';
		}
	}
};

template <class T>
class LevelOrderTree :public ertree<T> {
	void Order(bitree<T> *p) {
		stack<T> s;
		while (p != NULL || s.size() != 0)
		{
			while (p != NULL) {
				s.push(p);
				if (p->lchild == NULL && p->rchild == NULL) {
					cout << s.top()->Data << " ";
				}
				p = p->lchild;
			}
			if (s.size() != 0)
			{
				p = s.top();
				s.pop();
				p = p->rchild;
			}
		}
	}
};

void main() {
	PreOrderTree<int> pretree;
	cout << "Enter nodes. Enter 0 if you Want to Stop Buliding Tree.(Enter 0 to Stop Entering any branch." << endl;
	pretree.TreeBuilder();
}
