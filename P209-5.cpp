using namespace std;
#include <stdlib.h>
#include <cmath>
#include <iostream>
#include "stdio.h"
using namespace std;
struct LinkNode      
{
	int  E;       //指数
	int A;        //系数
	LinkNode *link;    //结点指针
	LinkNode(float a, int e, LinkNode *p = NULL)     
	{
		E = e;
		A = a;
		link = p;
	}
};

class Polynomial                
{
private:
	LinkNode *first;     
public:
	Polynomial()
	{
		first = new LinkNode(0, -1);   
	}
	Polynomial(Polynomial &p);   
	~Polynomial()
	{
		makeEmpty();   
	}
	int Max1();      
	int Length();  
	void makeEmpty();    
	Polynomial &operator=(const Polynomial &p);    //赋值函数
	Polynomial operator+(Polynomial &b);
	Polynomial operator-(Polynomial &b);
	Polynomial operator*(Polynomial &b);
	friend istream &operator>>(istream &is, Polynomial &p) {
		LinkNode *p1 = p.first;
		int flag;
		cin >> flag;
		int a;
		int b;
		while (flag--)
		{
			cin >> a >> b;
			if (fabs(a) <= 1e-7 || b == -1)
			{
				continue;
			}
			if (b == -11)
			{
				break;
			}
			p1->link = new LinkNode(a, b);
			p1 = p1->link;
		}
		return is;
	}
	friend ostream &operator<<(ostream &os, Polynomial &p) {
		LinkNode *p1 = p.first->link;
		if (p1->A > 0)
		{
			if (p1->A != 1)
			{
				os << p1->A;
				if (p1->E == 1)   os << "X";
				else if (p1->E > 1)  os << "X^" << p1->E;
			}
			else
			{
				if (p1->E == 1)   os << "X";
				else if (p1->E > 1)  os << "X^" << p1->E;

			}
		}
		else if (p1->A < 0)
		{
			os << p1->A;
			if (p1->E == 1) os << "X";
			else if (p1->E > 1)  os << "X^" << p1->E;
		}
		p1 = p1->link;
		while (p1 != NULL)
		{
			if (p1->A >= 2)
			{
				os << "+" << p1->A;
				if (p1->E == 1)   os << "X";
				else if (p1->E > 1)  os << "X^" << p1->E;
			}
			else if (p1->A == 1)
			{
				os << "+";
				if (p1->E == 1)   os << "X";
				else if (p1->E > 1)  os << "X^" << p1->E;
			}
			else if (p1->A < 0)
			{
				os << p1->A;
				if (p1->E == 1) os << "X";
				else if (p1->E > 1)  os << "X^" << p1->E;
			}
			p1 = p1->link;
		}
		os << endl;
		return os;
	}
};

void Polynomial::makeEmpty()
{
	LinkNode *p = NULL;
	while (first->link != NULL)
	{
		p = first->link;
		first->link = p->link;
		delete p;
	}
}

Polynomial::Polynomial(Polynomial &p)
{
	first = new LinkNode(0, -1);
	LinkNode *tem = first;
	int a;
	int e;
	LinkNode *ptr = p.first;
	while (ptr->link != NULL)
	{
		a = ptr->link->A;
		e = ptr->link->E;
		tem->link = new LinkNode(a, e);
		ptr = ptr->link;
		tem = tem->link;
	}
}


int Polynomial::Max1()
{
	LinkNode *ptr = first;  //若为first-link，则最后一个为null，
	//null->E不存在
	while (ptr->link != NULL)
	{
		ptr = ptr->link;
	}
	return ptr->E;
}

int Polynomial::Length()
{
	LinkNode *ptr = this->first;
	int count1 = 0;
	while (ptr->link != NULL)
	{
		count1++;
		ptr = ptr->link;
	}
	return count1;
}


Polynomial &Polynomial::operator=(const Polynomial &p)
{
	Polynomial temp;
	LinkNode *p1 = p.first;
	LinkNode *first = temp.first;
	while (p1->link!=NULL) {
		temp.first->A = p1->A;
		temp.first->E = p1->E;
		temp.first = temp.first->link;
		p1 = p1->link;
	}
	temp.first->link = NULL;
	temp.first = first;
	return temp;
}

Polynomial Polynomial::operator+(Polynomial &b)
{
	Polynomial temp;
	LinkNode *pa = first->link;
	LinkNode *pb = b.first->link;
	LinkNode *pc = temp.first;
	LinkNode *ptr = NULL;
	float f;
	while (pa != NULL && pb != NULL)
	{
		if (pa->E == pb->E)
		{
			f = pa->A + pb->A;
			if (fabs(f) > 1e-2)
			{
				pc->link = new LinkNode(f, pa->E);
				pc = pc->link;
			}
			pa = pa->link;
			pb = pb->link;
		}
		else if (pa->E > pb->E)
		{
			pc->link = new LinkNode(pb->A, pb->E);
			pc = pc->link;
			pb = pb->link;
		}
		else
		{
			pc->link = new LinkNode(pa->A, pa->E);
			pc = pc->link;
			pa = pa->link;
		}
	}
	if (pa != NULL) ptr = pa;
	else ptr = pb;
	while (ptr != NULL)
	{

		pc->link = new LinkNode(ptr->A, ptr->E);
		pc = pc->link;
		ptr = ptr->link;
	}
	return temp;
}

Polynomial Polynomial::operator-(Polynomial &b)
{
	Polynomial temp;
	LinkNode *ptr = NULL;
	LinkNode *pa = this->first->link;
	LinkNode *pb = b.first->link;
	LinkNode *pc = temp.first;
	float f;
	int flag = 1;
	while (pa != NULL && pb != NULL)
	{
		if (pa->E == pb->E)
		{
			f = pa->A - pb->A;
			if (fabs(f) > 1e-2)
			{
				pc->link = new LinkNode(f, pa->E);
				pc = pc->link;
			}
			pa = pa->link;
			pb = pb->link;
		}
		else if (pa->E > pb->E)
		{
			pc->link = new LinkNode(-(pb->A), pb->E);
			pc = pc->link;
			pb = pb->link;
		}
		else
		{
			pc->link = new LinkNode(pa->A, pa->E);
			pc = pc->link;
			pa = pa->link;
		}
	}
	if (pa == NULL)
	{
		ptr = pb;
		flag = 0;
	}
	else ptr = pa;
	while (ptr != NULL)
	{
		if (flag == 1)
			pc->link = new LinkNode(ptr->A, ptr->E);
		else
			pc->link = new LinkNode(-(ptr->A), ptr->E);
		ptr = ptr->link;
		pc = pc->link;
	}
	return temp;
}

Polynomial Polynomial::operator*(Polynomial &b)
{
	int ma = this->Max1();
	int mb = b.Max1();
	int k;
	int max1 = ma + mb;
	Polynomial temp;
	LinkNode *pa = this->first->link;

	LinkNode *pc = temp.first;
	if (ma != -1 && mb != -1)
	{
		float *f = new float[ma + mb + 1];
		for (int i = 0; i <= max1; i++)  f[i] = 0;
		while (pa != NULL)
		{
			LinkNode *pb = b.first->link;
			while (pb != NULL)
			{
				k = pa->E + pb->E;
				f[k] = f[k] + (pa->A)*(pb->A);
				pb = pb->link;
			}
			pa = pa->link;
		}
		for (int i = 0; i <= max1; i++)
		{
			if (fabs(f[i]) > 0.01)
			{
				pc->link = new LinkNode(f[i], i);
				pc = pc->link;
			}
		}
		delete[]f;
	}
	pc->link = NULL;
	return temp;
}

int main()
{
	cout << "Making Polynomial P1 and P2..." << endl;
	Polynomial P1,P2;
	int n1,n2;
	cout << "Input the first Polynomial P1" << endl;
	cin >> n1 ;
	cin >> P1;
	cout << "Input the second Polynomial P2" << endl;
	cin >> n2;
	cin >> P2;
	cout << "P1 is: ";
	cout << P1;
	cout << "P2 is: ";
	cout << P2;
	cout << "Making Polynomial P3..." << endl;
	Polynomial P3;
	P3=P1 + P2;
	cout << "P3 = P1 + P2 = ";
	cout << P3;
	cout << "Making Polynomial P4..." << endl;
	Polynomial P4;
	P4 = P1 - P2;
	cout << "P4 = P1 - P2 = ";
	cout << P4;
	cout << "Making Polynomial P5..." << endl;
	Polynomial P5;
	P3 = P1 * P2;
	cout << "P5 = P1 - P2 = ";
	cout << P5;
	return 0;
}