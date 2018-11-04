#include<iostream>
#include<string.h>
using namespace std;

typedef int ElemData;

struct node { //节点类
	ElemData data;
	node *next;
	node *prev;
};

class DblList //双向链表类
{
public:
	node *head;//指向头结点
	node *tail;//指向尾节点
	int len;//链表长度
public:
	DblList();//构造函数
	DblList(const DblList &l);//拷贝函数
	~DblList();//析构函数
	void addNode(ElemData data);//往尾部添加元素
	void Concatenate(DblList m);
	void upSort();//升序排序
	void findNode(int n);//查找某个节点
	void delNode(int n);//删除某个节点
	void showNode();//输出所有节点数据
};

void DblList::Concatenate(DblList m)
{
	node *m2 = m.head;
	while (m2 != NULL) {
		this->addNode(m2->data);
		m2 = m2->next;
	}
}

DblList::DblList()
{
	head = NULL;
	tail = NULL;
	len = 0;
}

DblList::DblList(const DblList &l)
{
	if (l.head != NULL)
	{
		node *pHc = l.head;
		head = new node();//为节点申请空间
		head->data = pHc->data;
		len++;
		pHc = pHc->next;
		node *pH = head;
		while (pHc != l.tail)
		{
			pH->next = new node();
			len++;
			pH->data = pHc->data;
			pHc = pHc->next;
		}
	}
	else
	{
		head = tail = NULL;
		len = 0;
	}
}
DblList::~DblList()
{
	node *bgn = head;
	while (head != tail)
	{
		head = head->next;
		delete bgn;//释放内存
		bgn = head;
	}
	len = 0;
}

void DblList::addNode(ElemData data)
{
	if (head == NULL)
	{
		head = new node();
		head->data = data;
		len++;
		tail = head;
	}
	else
	{
		tail->next = new node();
		tail->next->data = data;
		len++;
		tail->next->prev = tail;
		tail = tail->next;
	}
}

void DblList::showNode()
{
	node *p;
	p = head;
	if (p == NULL)
		cout << "List id empty" << endl;
	else
	{
		while (p != tail->next)
		{
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
}

void DblList::upSort()
{
	node *p, *q;
	ElemData temp;
	for (p = head; p != tail->next; p = p->next)
	{
		for (q = p->next; q != tail->next; q = q->next)
		{
			if (p->data > q->data)
			{
				temp = p->data;
				p->data = q->data;
				q->data = temp;
			}
		}
	}
}
void DblList::findNode(int n)
{
	node *p;
	p = head;
	if (n > len)
		cout << "超出链表长度";
	else
	{
		for (int i = 1; i < n; i++)
		{
			p = p->next;
		}
		cout << "该节点是:" << p->data << endl;
	}
}
void DblList::delNode(int n)
{
	node *p, *q;
	p = head;
	q = head->next;
	if (n > len)
		cout << "超出链表长度";
	else
	{
		for (int i = 2; i < n; i++)
		{
			p = p->next;
			q = q->next;
		}
		p->next = q->next;
		q->next->prev = p;
		delete q;
	}
}

int main()
{
	cout << "Bulding list1 and list2..." << endl;
	DblList list1,list2;
	cout << "Inputing nodes into list1... " << endl;
	for (int i = 0; i < 8; ++i) {
		list1.addNode(i);
	}
	cout << "The nodes of list1 are: ";
	list1.showNode();
	cout << "Inputing nodes into list2... " << endl;
	for (int i = 8; i < 16; ++i) {
		list1.addNode(i);
	}
	cout << "The nodes of list2 are: ";
	list2.showNode();
	cout << "Pushing list2 into list1..." << endl;
	list1.Concatenate(list2);
	cout << "The nodes of list1 are: ";
	list1.showNode();
	cout << "Bulding empty list list3..." << endl;
	DblList list3;
	cout << "Pushing list3 into list1..." << endl;
	list1.Concatenate(list3);
	cout << "The nodes of list1 are: ";
	list1.showNode();
	cout << "Nothing changed!" << endl;
	return 0;
}