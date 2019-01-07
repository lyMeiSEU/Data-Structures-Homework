#include <iostream>
#include <malloc.h>
#include <string>
using namespace std;

typedef struct tree
{
	char data;
	int hight;
	int bf;
	struct tree *lchild;
	struct tree *rchild;
	struct tree *parent;
}Node, *Tree;

void Init(Tree *T, char data)
{
	*T = (Tree)malloc(sizeof(Node));
	(*T)->data = data;
	(*T)->hight = 1;
	(*T)->bf = 0;
	(*T)->parent = (*T)->lchild = (*T)->rchild = NULL;
}

int MAX(int a, int b)
{
	if (a > b)
		return a + 1;
	return b + 1;
}

int Height(Tree T)
{
	if (T)
		return T->hight;
	return -1;
}

Tree SingleLeft(Tree k1)
{
	Tree k2 = k1->rchild;

	k1->rchild = k2->lchild;
	if (k2->lchild)
		k2->lchild->parent = k1;
	k2->lchild = k1;

	k2->parent = k1->parent;
	k1->parent = k2;

	k1->hight = MAX(Height(k1->lchild), Height(k1->rchild));
	k2->hight = MAX(Height(k2->lchild), Height(k2->rchild));
	k1->bf = Height(k1->lchild) - Height(k1->rchild);
	k2->bf = Height(k2->lchild) - Height(k2->rchild);

	return k2;
}

Tree SingleRight(Tree k1)
{
	Tree k2 = k1->lchild;

	k1->lchild = k2->rchild;
	if (k2->rchild)
		k2->rchild->parent = k1;
	k2->rchild = k1;

	k2->parent = k1->parent;
	k1->parent = k2;

	k1->hight = MAX(Height(k1->lchild), Height(k1->rchild));
	k2->hight = MAX(Height(k2->lchild), Height(k2->rchild));
	k1->bf = Height(k1->lchild) - Height(k1->rchild);
	k2->bf = Height(k2->lchild) - Height(k2->rchild);

	return k2;
}

Tree LeftRight(Tree k1)
{
	k1->lchild = SingleLeft(k1->lchild);
	return SingleRight(k1);
}

Tree RightLeft(Tree k1)
{
	k1->rchild = SingleRight(k1->rchild);
	return SingleLeft(k1);
}

Tree FindMin(Tree T)
{
	Tree temp = T;
	while (temp->lchild)
		temp = temp->lchild;
	return temp;
}

Tree Insert(Tree T, Tree pre, char data)
{
	if (!T)
	{
		T = (Tree)malloc(sizeof(Node));
		if (!T)
		{
			cout << "Can Not Init" << endl;
			return NULL;
		}
		T->hight = 1;
		T->bf = 0;
		T->data = data;
		T->parent = pre;
		T->lchild = T->rchild = NULL;
	}
	else
	{
		if (T->data < data)
		{
			T->rchild = Insert(T->rchild, T, data);
			if (T->bf == -2)
			{
				if (data < T->rchild->data)
					T = RightLeft(T);
				else if (data > T->rchild->data)
					T = SingleLeft(T);
			}
		}
		if (T->data > data)
		{
			T->lchild = Insert(T->lchild, T, data);
			if (T->bf == 2)
			{
				if (data < T->lchild->data)
					T = SingleRight(T);
				else if (data > T->lchild->data)
					T = LeftRight(T);
			}
		}
	}

	T->hight = MAX(Height(T->lchild), Height(T->rchild));
	T->bf = Height(T->lchild) - Height(T->rchild);

	return T;
}

Tree Delete(Tree T, char data)
{
	Tree temp, target = T, parent = NULL, grand;
	char ele;

	while (target)
	{
		if (target->data < data)
			target = target->rchild;
		else if (target->data > data)
			target = target->lchild;
		else if (target->lchild && target->rchild)
		{
			temp = FindMin(target->rchild);
			parent = temp->parent;
			target->data = temp->data;
			if (temp->parent->data <= temp->data)
			{
				temp->parent->rchild = temp->rchild;
				if (temp->rchild)
					temp->rchild->parent = temp->parent;
			}
			else
			{
				temp->parent->lchild = temp->rchild;
				if (temp->rchild)
					temp->rchild->parent = temp->parent;
			}

			free(temp);
			break;
		}
		else
		{
			temp = target;
			parent = temp->parent;
			if (target->lchild)
			if (parent->data < data)
			{
				parent->rchild = target->lchild;
				target->lchild->parent = parent;
			}
			else
			{
				parent->lchild = target->lchild;
				target->lchild->parent = parent;
			}
			else
			if (parent->data < data)
			{
				parent->rchild = target->rchild;
				if (target->rchild)
					target->rchild->parent = parent;
			}
			else
			{
				parent->lchild = target->rchild;
				if (target->rchild)
					target->rchild->parent = parent;
			}

			free(temp);
			break;
		}
	}

	while (parent)
	{
		ele = parent->data;
		parent->hight = MAX(Height(parent->lchild), Height(parent->rchild));
		parent->bf = Height(parent->lchild) - Height(parent->rchild);
		grand = parent->parent;
		if (parent->bf == -2)
		{
			if (parent->rchild->bf > 0)
			{
				parent = RightLeft(parent);
			}
			else
			{
				parent = SingleLeft(parent);
			}
		}
		else if (parent->bf == 2)
		{
			if (parent->lchild->bf < 0)
				parent = LeftRight(parent);
			else
				parent = SingleRight(parent);
		}

		if (grand)
		{
			if (grand->data > ele)
				grand->lchild = parent;
			else
				grand->rchild = parent;
			parent->parent = grand;
		}
		else
			T = parent;
		parent = parent->parent;
	}

	return T;
}

int main()
{
	Tree T;

	int i;
	string s = "ckbfjlaegmdh";

	Init(&T, 'i');

	for (i = 0; i < s.length(); i++)
	{
		T = Insert(T, T, s[i]);
		T = Delete(T, 'a');

	}
	cout << T << endl;


	return 0;
}
