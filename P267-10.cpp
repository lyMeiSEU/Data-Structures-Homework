#include<stdlib.h>//ͷ�ļ�����Ľ����ṩ֧��
#include<malloc.h>
#include<iostream>
using namespace std;

template<class T>
class ertree {
public:

	typedef struct node {//�������Ľڵ�
		T data;
		struct node *lchild, *rchild;
	}bitree;

	//�õݹ�ķ�ʽ������������
	bitree *tree1() {//����������
		bitree *t;
		T a;
		cout << "����Ԫ��";
		cin >> a;
		if (a == 0)t = NULL;
		else {
			t = (bitree *)malloc(sizeof(bitree));
			t->data = a;
			cout << t->data << "��������";
			t->lchild = tree1();
			cout << t->data << "��������";
			t->rchild = tree1();
		}
		return t;
	}
	bitree *tree2() {//����������
		bitree *t;
		T a;
		cout << "����Ԫ��";
		cin >> a;
		if (a == '0')t = NULL;
		else {
			t = (bitree *)malloc(sizeof(bitree));
			t->data = a;
			cout << t->data << "��������";
			t->lchild = tree2();
			cout << t->data << "��������";
			t->rchild = tree2();
		}
		return t;
	}
	//�ݹ�ĵ��÷�ʽ�����������
	void Xxu(bitree *p) {//��������Ľ��
		if (p != NULL) {
			cout << p->data << ' ';
			Xxu(p->lchild);
			Xxu(p->rchild);
		}
	}
	//�ݹ�ĵ��÷�ʽ�����������
	void Zxu(bitree *p) {//��������Ľ��
		if (p != NULL) {
			Zxu(p->lchild);
			cout << p->data << ' ';
			Zxu(p->rchild);
		}
	}

	//�ݹ�ĵ��÷�ʽ���к������
	void Hxu(bitree *p) {//��������Ľ��
		if (p != NULL) {
			Hxu(p->lchild);
			Hxu(p->rchild);
			cout << p->data << ' ';
		}
	}
	//�ݹ�ĵ��÷�ʽ�������
	int JDS(bitree *p) {//�����
		int c;
		if (p == NULL)
			c = 0;
		else
			c = 1 + JDS(p->lchild) + JDS(p->rchild);
		return c;
	}
	//�ݹ�ĵ��÷�ʽ���Ҷ�ӽ����
	int YZJDS1(bitree *p,int d1) {//Ҷ�ӽ����
		if (p == NULL)
			return d1;
		else {
			if (p->lchild == NULL && p->rchild == NULL)
				d1++;
			YZJDS1(p->lchild,d1);
			YZJDS1(p->rchild,d1);
		}
	}
	int YZJDS2(bitree *p,int d2) {//Ҷ�ӽ����
		if (p == NULL)
			return d2;
		else {
			if (p->lchild == NULL && p->rchild == NULL)
				d2++;
			YZJDS2(p->lchild,d2);
			YZJDS2(p->rchild,d2);
		}
	}
	int YZJDS3(bitree *p,int d3) {//Ҷ�ӽ����
		if (p == NULL)
			return d3;
		else {
			if (p->lchild == NULL && p->rchild == NULL)
				d3++;
			YZJDS3(p->lchild,d3);
			YZJDS3(p->rchild,d3);
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
	//�����Ա������������������Ա����
	void fun1() {//ʵ�ָ��ֲ���
		bitree *p = tree1();
		cout << "\n����������:";
		Xxu(p);
		cout << "\n����������:";
		Zxu(p);
		cout << "\n����������:";
		Hxu(p);
		cout << "\n�����:";
		cout << JDS(p);
		cout << "\nҶ�ӽ����:";
		cout << YZJDS1(p,0);
		cout << "\n�������ĸ߶�Ϊ:";
		cout << height(p);
	}
	void fun2() {
		bitree *p = tree2();
		cout << "\n����������:";
		Xxu(p);
		cout << "\n����������:";
		Zxu(p);
		cout << "\n����������:";
		Hxu(p);
		cout << "\n�����:";
		cout << JDS(p);
		cout << "\nҶ�ӽ����:";
		cout << YZJDS2(p,0);
		cout << "\n�������ĸ߶�Ϊ:";
		cout << height(p);
	}
	void fun3() {
		bitree *p = tree1();
		cout << "\n����������:";
		Xxu(p);
		cout << "\n����������:";
		Zxu(p);
		cout << "\n����������:";
		Hxu(p);
		cout << "\n�����:";
		cout << JDS(p);
		cout << "\nҶ�ӽ����:";
		cout << YZJDS3(p,0);
		cout << "\n�������ĸ߶�Ϊ:";
		cout << height(p);
	}
};


//��������ʵ��������Ȼ����ɲ���
void main() {
	ertree<int>x;
	cout << "\n������int�͵Ķ�����";
	x.fun1();
	ertree<char>y;
	cout << "\n������char�͵Ķ�����";
	y.fun2();
	ertree<float>z;
	cout << "\n������float�͵Ķ�����";
	z.fun3();
}
