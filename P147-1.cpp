#include<iostream>
using namespace std;

template<class KeyType>
class Queue
{
	int front, rear;
	KeyType * queue;
	int MaxSize;
	bool LastOp=0;
public:
	Queue<KeyType>(int MaxQueueSize):MaxSize(MaxQueueSize)
	{
		queue = new KeyType[MaxSize];
		front = rear;
	}
	bool IsFull();
	
	bool IsEmpty();
	
	void Add(const KeyType& x);
	
	KeyType * Delete(KeyType& x);
};

template<class KeyType>
void Queue<KeyType>::Add(const KeyType& x)
{
	LastOp = 1;
	int k = (rear + 1) % MaxSize;
	if (Queue::IsFull())
	{
		cout << "Stack is Full" << endl;
	}
	else
	{
		queue[rear == k] = x;
	}
}

template<class KeyType>
bool Queue<KeyType>::IsEmpty()
{
	if (front == rear && LastOp == false)
		return true;
	else
		return false;
}

template<class KeyType>
bool Queue<KeyType>::IsFull()
{
	if (front == rear && LastOp == true)
		return true;
	else
	{
		return false;
	}
}

template<class KeyType>
KeyType * Queue<KeyType>::Delete(KeyType& x)
{
	
	if (Queue::IsEmpty())
	{
		cout<<"Stack is Empty"<<endl;
		return 0;
	}
	else
	{
		LastOp = 0;
		x = queue[++front];
		return &x;
	}
}

int main()
{
	Queue<int> QU(13);
	for (int i = 0; i < 13; ++i)
		QU.Add(i);
	for (int j = 0; j < 13; ++j)
		QU.Delete(j);
}