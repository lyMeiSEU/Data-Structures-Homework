#include<stdlib.h>//头文件给类的建立提供支持
#include<malloc.h>
#include<iostream>
using namespace std;

template<class T>
class ertree {
public:

	typedef struct node {//二叉树的节点
		T data;
		struct node *lchild, *rchild;
	}bitree;

	//用递归的方式来建立二叉树
	bitree *tree1() {//建立二叉树
		bitree *t;
		T a;
		cout << "输入元素";
		cin >> a;
		if (a == 0)t = NULL;
		else {
			t = (bitree *)malloc(sizeof(bitree));
			t->data = a;
			cout << t->data << "的左子树";
			t->lchild = tree1();
			cout << t->data << "的右子树";
			t->rchild = tree1();
		}
		return t;
	}
	bitree *tree2() {//建立二叉树
		bitree *t;
		T a;
		cout << "输入元素";
		cin >> a;
		if (a == '0')t = NULL;
		else {
			t = (bitree *)malloc(sizeof(bitree));
			t->data = a;
			cout << t->data << "的左子树";
			t->lchild = tree2();
			cout << t->data << "的右子树";
			t->rchild = tree2();
		}
		return t;
	}
	//递归的调用方式进行先序遍历
	void Xxu(bitree *p) {//先序遍历的结果
		if (p != NULL) {
			cout << p->data << ' ';
			Xxu(p->lchild);
			Xxu(p->rchild);
		}
	}
	//递归的调用方式进行中序遍历
	void Zxu(bitree *p) {//中序遍历的结果
		if (p != NULL) {
			Zxu(p->lchild);
			cout << p->data << ' ';
			Zxu(p->rchild);
		}
	}

	//递归的调用方式进行后序遍历
	void Hxu(bitree *p) {//后序遍历的结果
		if (p != NULL) {
			Hxu(p->lchild);
			Hxu(p->rchild);
			cout << p->data << ' ';
		}
	}
	//递归的调用方式求解结点数
	int JDS(bitree *p) {//结点数
		int c;
		if (p == NULL)
			c = 0;
		else
			c = 1 + JDS(p->lchild) + JDS(p->rchild);
		return c;
	}
	//递归的调用方式求解叶子结点数
	int YZJDS1(bitree *p,int d1) {//叶子结点数
		if (p == NULL)
			return d1;
		else {
			if (p->lchild == NULL && p->rchild == NULL)
				d1++;
			YZJDS1(p->lchild,d1);
			YZJDS1(p->rchild,d1);
		}
	}
	int YZJDS2(bitree *p,int d2) {//叶子结点数
		if (p == NULL)
			return d2;
		else {
			if (p->lchild == NULL && p->rchild == NULL)
				d2++;
			YZJDS2(p->lchild,d2);
			YZJDS2(p->rchild,d2);
		}
	}
	int YZJDS3(bitree *p,int d3) {//叶子结点数
		if (p == NULL)
			return d3;
		else {
			if (p->lchild == NULL && p->rchild == NULL)
				d3++;
			YZJDS3(p->lchild,d3);
			YZJDS3(p->rchild,d3);
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
	int height(bitree *p) {//二叉树的高度
		if (p != NULL) {
			return (1 + max(height(p->lchild), height(p->rchild)));
		}
		else return 0;
	}
	//这个成员函数用来调用其他成员函数
	void fun1() {//实现各种操作
		bitree *p = tree1();
		cout << "\n先序遍历结果:";
		Xxu(p);
		cout << "\n中序遍历结果:";
		Zxu(p);
		cout << "\n后序遍历结果:";
		Hxu(p);
		cout << "\n结点数:";
		cout << JDS(p);
		cout << "\n叶子结点数:";
		cout << YZJDS1(p,0);
		cout << "\n二叉树的高度为:";
		cout << height(p);
	}
	void fun2() {
		bitree *p = tree2();
		cout << "\n先序遍历结果:";
		Xxu(p);
		cout << "\n中序遍历结果:";
		Zxu(p);
		cout << "\n后序遍历结果:";
		Hxu(p);
		cout << "\n结点数:";
		cout << JDS(p);
		cout << "\n叶子结点数:";
		cout << YZJDS2(p,0);
		cout << "\n二叉树的高度为:";
		cout << height(p);
	}
	void fun3() {
		bitree *p = tree1();
		cout << "\n先序遍历结果:";
		Xxu(p);
		cout << "\n中序遍历结果:";
		Zxu(p);
		cout << "\n后序遍历结果:";
		Hxu(p);
		cout << "\n结点数:";
		cout << JDS(p);
		cout << "\n叶子结点数:";
		cout << YZJDS3(p,0);
		cout << "\n二叉树的高度为:";
		cout << height(p);
	}
};


//主函数中实例化对象，然后完成操作
void main() {
	ertree<int>x;
	cout << "\n数据是int型的二叉树";
	x.fun1();
	ertree<char>y;
	cout << "\n数据是char型的二叉树";
	y.fun2();
	ertree<float>z;
	cout << "\n数据是float型的二叉树";
	z.fun3();
}
