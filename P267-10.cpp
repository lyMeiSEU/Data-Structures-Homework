#include<stdlib.h>//ͷ�ļ�����Ľ����ṩ֧��
#include<malloc.h>
#include<iostream>
using namespace std;

template<class T>
struct bitree {//�������Ľڵ�
	T data;
	struct bitree<T> *lchild, *rchild;
};

template<class T>
class ertree {

public:

	//�õݹ�ķ�ʽ������������
	bitree *TreeBuilder() {//����������
		bitree *t;
		T a;
		cout << "����Ԫ��";
		cin >> a;
		if (a == 0)t = NULL;
		else {
			t = (bitree *)malloc(sizeof(bitree));
			t->data = a;
			cout << t->data << "��������";
			t->lchild = TreeBuilder();
			cout << t->data << "��������";
			t->rchild = TreeBuilder();
		}
		return t;
	}
	virtual void Order(bitree *p) = 0;

	//�ݹ�ĵ��÷�ʽ�������
	int NodesNumber(bitree *p) {//�����
		int c;
		if (p == NULL)
			c = 0;
		else
			c = 1 + NodesNumber(p->lchild) + NodesNumber(p->rchild);
		return c;
	}

	//�ݹ�ĵ��÷�ʽ���Ҷ�ӽ����
	int LeavesNumber(bitree *p, int d1) {//Ҷ�ӽ����
		if (p == NULL)
			return d1;
		else {
			if (p->lchild == NULL && p->rchild == NULL)
				d1++;
			LeavesNumber(p->lchild, d1);
			LeavesNumber(p->rchild, d1);
		}
	}

	//�����ʱ���øú���
	int max(int m, int n)//�Ƚϴ�С
	{
		if (m > n)
			return m;
		else
			return n;
	}

	//�ݹ�ĵ��÷�ʽ���Ҷ�ӽ����
	int height(bitree *p) {//�������ĸ߶�
		if (p != NULL) {
			return (1 + max(height(p->lchild), height(p->rchild)));
		}
		else return 0;
	}
};

template <class T>
class PreOrderTree :public ertree<T> {
	void Order(bitree *p) {
		if (p != NULL) {
			PostOrder(p->lchild);
			PostOrder(p->rchild);
			cout << p->data << ' ';
		}
	}
};

template <class T>
class InOrderTree :public ertree<T> {
	void Order(bitree *p) {
		if (p != NULL) {
			InOrder(p->lchild);
			cout << p->data << ' ';
			InOrder(p->rchild);
		}
	}
};

template <class T>
class PostOrderTree :public ertree {
	void Order(bitree *p) {
		if (p != NULL) {
			PostOrder(p->lchild);
			PostOrder(p->rchild);
			cout << p->data << ' ';
		}
	}
};

template <class T>
class LevelOrderTree :public ertree<T> {
	void Order(bitree *p) {
		stack<node>s;
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

//��������ʵ��������Ȼ����ɲ���
void main() {

}
