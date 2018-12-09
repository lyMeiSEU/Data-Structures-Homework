#include<iostream>
#include<stack>
using namespace std;

#define MAX 10
stack<int> A;
stack<int> B;
void Insert(stack<int> G[MAX]) {
	while (true) {
		int u, v;
		cin >> u >> v;
		if (u == -1 || v == -1) {
			break;
		}
		G[u].push(v);
	}
}

int getElement(stack<int> stack, int position)
{
	if (stack.empty()) {
		return -1;
	}
	int result = stack.top();
	stack.pop();
	if (stack.size() == position)
	{
		//            stack.push(result);
		return result;
	}
	else {
		int element = getElement(stack, position);
		stack.push(element);
		return element;
	}
}

void Device(stack<int> G[MAX]) {
	for (int i = 0; i < MAX; ++i) {
		if (getElement(B, i) > 0) {
			
			while (!G->empty()) {
				A.push(G->top());
				G->pop();
			}
		}
		else {
			A.push(i);
			while (!G->empty()) {
				B.push(G->top());
				G->pop();
			}
		}
	}
}

int main() {
	stack<int> G[MAX];
	cout << "Input the vertex in the Graph. (Like <u,v>)" << endl;
	Insert(G);
	Device(G);
	while (!A.empty()) {
		cout << A.top() << " ";
		A.pop();
	}
	cout << endl;
	while (!B.empty()) {
		cout << B.top() << " ";
		B.pop();
	}
}