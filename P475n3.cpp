#include <iostream>
using namespace std;
template<class T>
class ListNode
{
	friend class SymbolTable<T>;
public:
	ListNode()
	{
		data = 0;
		link = NULL;
	}
	T setData(T a)
	{
		data = a;
	}
private:
	T data;
	ListNode *link;
};

template <class T>
class SymbolTable
{
public:
	SymbolTable(int size = 10)
	{
		buckets = size;
		ht = new ListNode<T>[buckets];
	}
	void Init()
	{
		for(int i = 0;i<buckets-1;i++)
		{
			ht[i].link = ht[i+1];
		}
		ht[i].link = ht[0];
	}
	ListNode<T> ChainSearch(const T &x)
	{
		ListNode<T> currentNode = ht;
		currentNode = currentNode.link;
		while(currentNode != ht)
		{
			if(currentNode.data != x || currentNode.data == @)
				currentNode = currentNode.link;
			else
				return currentNode;
		}
	}
	void DeleteData(const T &x)
	{
		ListNode<T> currentNode = ChainSearch(x);
		currentNode.data = @;//@ÎªÉ¾³ý±ê¼Ç·û
	}
	void AddData(const int &x)
	{
		ListNode<T> currentNode = ht[x];
		while(currentNode != ht[x-1])
		{
			if(currentNode.data == 0 || currentNode.data == $)
				currentNode.data = x;
			else
				currentNode = currentNode.link;
		}
	}
private:
	int buckets;
	ListNode<T> *ht;
};

int main()
{
	SymbolTable<int> table;
	table.AddData(1);
	table.AddData(2);
	table.AddData(3);
	ListNode<int> node = table.ChainSearch(2);
	table.DeleteData(2);

}

