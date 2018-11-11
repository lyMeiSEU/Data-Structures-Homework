#include <iostream>
#include<stack>
using namespace std;
template<class T>
class BTree
{
public:
	class Node
	{
	public:
		T element;//Can be optimized
		Node *LTree;
		Node *RTree;
	};
	Node *root;
	bool creat(Node *&root);
	virtual void show(Node *root)const;//Read Only
	bool B_Delete(Node *&root);

	BTree();
	~BTree();
	void BTShow();
	bool BTCreat();
	void BTDelete();
};
template<class T>
BTree<T>::BTree()
{
	root = NULL;
}
template<class T>
BTree<T>::~BTree()
{
	B_Delete(root);
}
template<class T>
bool BTree<T>::BTCreat()
{
	if (creat(root));
	return true;
	return false;
}
template<class T>
void BTree<T>::BTDelete()
{
	B_Delete(root);
}
template<class T>
bool BTree<T>::creat(Node *&root)
{
	T tempaval;
	cin >> tempaval;
	if (tempaval != '#')
	{
		root = new Node;
		if (!root)
		{
			root = NULL;
			return false;
		}
		root->element = tempaval;
		if (!creat(root->LTree))
			root->LTree = NULL;
		if (!creat(root->RTree))
			root->RTree = NULL;
	}
	else
		return false;
	return true;
}

template<class T>
void BTree<T>::show(Node *root)const {
	if (root)
	{
		cout << root->element << ends;
		show(root->LTree);
		show(root->RTree);
	}
	else
		return;
}

template<class T>
bool BTree<T>::B_Delete(Node *&root)
{
	if (root)
	{
		B_Delete(root->LTree);
		B_Delete(root->RTree);
		cout << root->element << ends;
		delete root;
		return true;
	}
	else
		return false;
}
template<class T>
void BTree<T>::BTShow()
{
	show(root);
}

template<class T>
class PreOrderBTree :public BTree<T> {
	void show(Node *root)const;
};

template<class T>
void PreOrderBTree<T>::show(Node *root)const {
	if (root)
	{
		cout << root->element << ends;
		show(root->LTree);
		show(root->RTree);
	}
	else
		return;
}

template<class T>
class InOrderBTree :public BTree<T> {
	void show(Node *root)const;
};

template<class T>
void InOrderBTree<T>::show(Node *root)const {
	if (root)
	{
		show(root->LTree);
		cout << root->element << ends;
		show(root->RTree);
	}
	else
		return;
}

template<class T>
class PostOrderBTree :public BTree<T> {
	void show(Node *root)const;
};

template<class T>
void PostOrderBTree<T>::show(Node *root)const {
	if (root)
	{
		show(root->LTree);
		show(root->RTree);
		cout << root->element << ends;
	}
	else
		return;
}

template<class T>
class LevelOrderBTree :public BTree<T> {
	void show(Node *root)const;
};

template<class T>
void LevelOrderBTree<T>::show(Node *root)const {
	Node *p = root;
	stack<Node *> s;
	if (p == NULL)
	{
		cout << "This is a Empty Tree" << endl;
		return;
	}
	while (p != NULL || s.size() != 0)
	{
		while (p != NULL)
		{
			s.push(p);
			if (p->LTree == NULL && p->RTree == NULL)
			{
				cout << s.top()->element << " ";
			}
			p = p->LTree;
		}
		if (s.size() != 0)
		{
			p = s.top();
			s.pop();
			p = p->RTree;
		}

	}
	cout << endl;
}
int main()
{
	BTree<char> temp;
	PreOrderBTree<char> temp1;
	InOrderBTree<char> temp2;
	PostOrderBTree<char> temp3;
	LevelOrderBTree<char> temp4;
	temp1.BTCreat();
	temp1.BTShow();
	temp2.BTCreat();
	temp2.BTShow();
	temp3.BTCreat();
	temp3.BTShow();
	temp4.BTCreat();
	temp4.BTShow();
	cout << "Hello world!" << endl;
	return 0;
}