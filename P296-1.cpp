
#include<iostream>
using namespace std;
template<class T>
struct BSTreeNode {
	BSTreeNode<T>* Left;
	BSTreeNode<T>* Right;
	T Data;
	BSTreeNode(const T& data)
		: Left(NULL)
		, Right(NULL)
		, Data(data)
	{}
};
template<class T>
class BSTree {
	typedef BSTreeNode<T> Node;
	typedef Node* PNode;
public:
	BSTree()
		: Root(NULL)
	{}
	bool Insert(const T& data)
	{
		return _Insert(Root, data);
	}
	PNode Find(const T& data)
	{
		_Find(Root, data);
	}
	bool Delete(const T& data)
	{
		return _Delete(Root, data);
	}
	void InOrder()
	{
		cout << "InOrder:";
		_InOrder(Root);
		cout << endl;
	}
private:
	bool _Insert(PNode& pRoot, const T& data)
	{
		if (NULL == pRoot) {
			pRoot = new Node(data);
			return true;
		}
		else {
			if (pRoot->Data == data)
				return false;
			else if (pRoot->Data > data)
				return _Insert(pRoot->Left, data);
			else
				return _Insert(pRoot->Right, data);
		}
	}
	PNode _Find(PNode pRoot, const T& data)
	{
		if (NULL == pRoot)
			return NULL;
		else {
			if (data == pRoot->Data)
				return pRoot;
			else if (data > pRoot->Data)
				return _Find(pRoot->Right, data);
			else
				return _Find(pRoot->Left, data);
		}
	}
	bool _Delete(PNode& pRoot, const T& data)
	{
		if (NULL == pRoot)
			return false;
		else {
			if (data > pRoot->Data)
				return _Delete(pRoot->Right, data);
			else if (data < pRoot->Data)
				return _Delete(pRoot->Left, data);
			else {
				PNode pDel = pRoot;
				if (pRoot->Right == NULL) {
					pRoot = pRoot->Left;
					delete pDel;
					return true;
				}
				else if (pRoot->Left == NULL) {
					pRoot = pRoot->Right;
					delete pDel;
					return true;
				}
				else {
					pDel = pRoot->Right;
					while (pDel->Left) {
						pDel = pDel->Left;
					}
					pRoot->Data = pDel->Data;
					return _Delete(pRoot->Right, pDel->Data);
				}
			}
		}
	}
	void _InOrder(PNode pRoot)
	{
		if (pRoot) {
			_InOrder(pRoot->Left);
			cout << pRoot->Data << " ";
			_InOrder(pRoot->Right);
		}
	}
private:
	PNode Root;
};
void test() {
	int arr[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	BSTree<int> bs;
	cout << "Making Tree..." << endl;
	for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
		bs.Insert(arr[i]);
	bs.InOrder();
	int S;
	cout << "Input the Node you want to delete. " << endl;
	cin >> S;
	if (bs.Delete(S)) {
		bs.InOrder();
	}
	else
		cout << "There is no this Node in the Tree, Be Careful!" << endl;
}
int main() {
	test();
	return 0;
}
