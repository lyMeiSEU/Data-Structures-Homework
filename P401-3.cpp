#include<iostream>
using namespace std;
int counter = 0;
#include <stdio.h>
#include <stdlib.h>
struct ListNode {
	int value;
	ListNode* next;
};
ListNode* CreateListNode(int value) {
	ListNode* pNode = new ListNode();
	pNode->value = value;
	pNode->next = NULL;
	return pNode;
}
void ConnectListNode(ListNode* pCurrent, ListNode* pNext) {
	if (pCurrent == NULL) {
		printf("Error to connect two nodes.\n");
		exit(1);
	}
	pCurrent->next = pNext;
}
void PrintListNode(ListNode* pNode) {
	if (pNode == NULL)
		printf("The node is null.\n");
	else
		printf("The key in node is %d.\n", pNode->value);
}
void PrintList(ListNode* pHead) {
	ListNode* pNode = pHead;
	while (pNode) {
		printf("%d\t", pNode->value);
		pNode = pNode->next;
	}
	printf("\n");
}
void DestroyList(ListNode* pHead) {
	ListNode* pNode = pHead;
	while (pNode) {
		ListNode* pNext = pNode->next;
		delete pNode;
		pNode = pNext;
	}
}
void AddToTail(ListNode** pHead, int value) {
	ListNode* pNode = new ListNode();
	pNode->value = value;
	pNode->next = NULL;
	if (*pHead == NULL)
		*pHead = pNode;
	else {
		ListNode* pCurrent = *pHead;
		while (pCurrent->next)
			pCurrent = pCurrent->next;
		pCurrent->next = pNode;
	}
}
void RemoveHead(ListNode** pHead, int value) {
	if (pHead == NULL || *pHead == NULL)
		return;
	ListNode* pToBeDeleted = NULL;
	if ((*pHead)->value == value) {
		pToBeDeleted = *pHead;
		*pHead = (*pHead)->next;
	}
	else {
		ListNode* pNode = *pHead;
		while (pNode->next != NULL && pNode->next->value != value)
			pNode = pNode->next;
		if (pNode->next != NULL && pNode->next->value == value) {
			pToBeDeleted = pNode->next;
			pNode->next = pNode->next->next;
		}
	}
	if (pToBeDeleted != NULL) {
		delete pToBeDeleted;
		pToBeDeleted = NULL;
	}
}
template <class T>
void Insert(const T& e, T *a, int i) {
	a[0] = e;
	while (e < a[i]) {
		a[i + 1] = a[i];
		i--;
	}
	a[i + 1] = e;
}
template <class T>
void InsertionSort(T*a, const int n) {
	for (int j = 2; j <= n; j++) {
		T temp = a[j];
		Insert(temp, a, j - 1);
		counter++;
		cout << "第" << counter << "次:";
		for (int i = 0; i < 11; ++i) {
			cout << a[i] << " ";
		}
		cout << endl;
	}
}
int main() {
	int a[] = { 12,2,16,30,8,28,4,10,20,6,18 };
	ListNode *A = CreateListNode(12);
	for (int i = 1; i < 11; ++i) {
		AddToTail(&A, a[i]);
	}
	cout << "初始值:";
	for (int i = 0; i < 11; ++i) {
		cout << &A[i].value << " ";
	}
	cout << endl;
	InsertionSort(&A, 10);
	DestroyList(A);
}