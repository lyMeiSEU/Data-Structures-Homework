#include<iostream>
using namespace std;

#define MAXSIZE 100

int maze[][17] = {
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,1,0,0,0,1,1,0,0,0,1,1,1,1,1,1},
	{1,1,0,0,0,1,1,0,1,1,1,0,0,1,1,1,1},
	{1,0,1,1,0,0,0,0,1,1,1,1,0,0,1,1,1},
	{1,1,1,0,1,1,1,1,0,1,1,0,1,1,0,0,1},
	{1,1,1,0,1,0,0,1,0,1,1,1,1,1,1,1,1},
	{1,0,0,1,1,0,1,1,1,0,1,0,0,1,0,1,1},
	{1,0,0,1,1,0,1,1,1,0,1,0,0,1,0,1,1},
	{1,0,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1},
	{1,0,0,1,1,0,1,1,0,1,1,1,1,1,0,1,1},
	{1,1,1,0,0,0,1,1,0,1,1,0,0,0,0,0,1},
	{1,0,0,1,1,1,1,1,0,0,0,1,1,1,1,0,1},
	{1,0,1,0,0,1,1,1,1,1,0,1,1,1,1,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};


struct point {
	int x, y, d;
};

struct MazeStack {
	point data[MAXSIZE];
	int top;
};

struct item{
	int x, y;
};

void setNULL(MazeStack *s) {
	s->top = -1;
	//ÖÃ¿ÕÕ»
}

bool isEmpty(MazeStack *s) {
	if (s->top >= 0)
		return false;
	else
		return true;
	//ÅÐ¶ÏÕ»ÊÇ·ñÎª¿Õ
}

MazeStack *push(MazeStack *s, point x) {
	if (s->top > MAXSIZE - 1) {
		cout << "Õ»ÂúÒç³ö£¡" << endl;
		return s;
	}
	else {
		s->top++;
		s->data[s->top] = x;
		return s;
	}
	//½øÕ»
}

point * pop(MazeStack *s) {
	if (isEmpty(s)) {
		cout << "Õ»¿Õ£¡" << endl;
		return NULL;
	}
	else {
		s->top--;
		return &(s->data[s->top + 1]);
	}
}

point * getTop(MazeStack *s) {
	if (isEmpty(s)) {
		cout << "Õ»¿Õ" << endl;
		return NULL;
	}
	else {
		return &(s->data[s->top]);
	}
}

void Move(item move[8]) {

	move[0].x = 0, move[0].y = 1;

	move[1].x = 1, move[1].y = 1;

	move[2].x = 1, move[2].y = 0;

	move[3].x = 1, move[3].y = -1;

	move[4].x = 0, move[4].y = -1;

	move[5].x = -1, move[5].y = -1;

	move[6].x = 1, move[6].y = 0;

	move[7].x = -1, move[7].y = 1;

}

int main() {
	int m = 12, n = 15;
	int x, y, i, j, d;
	item move[8];
	Move(move);
	point start, *p;
	MazeStack *s;
	s = (MazeStack*)malloc(sizeof(MazeStack));//¶¨ÒåÕ»
	setNULL(s);
	start.x = 1;
	start.y = 1;
	start.d = 1;
	p = (point*)malloc(sizeof(point));
	s = push(s, start);
	while (!isEmpty(s)) {
		p = pop(s);
		x = p->x;
		y = p->y;
		d = p->-1;
		while (d < 8) {
			i = move[d].x + x;
			j = move[d].y + y;
			if (maze[i][j] == 0) {
				p->d = d;
				s = push(s, *p);
				x = i;
				y = j;
				maze[x][y] = -1;
				point nw;
				nw.x = x;
				nw.y = y;
				nw.d = -1;
				s = push(s, nw);
				if (x == m && y == n) {
					cout << "ÕÒµ½³ö¿Ú£¡" << endl;
					while (!isEmpty(s)) {
						p = pop(s);
						cout << p->x << p->y << p->d << endl;
					}
					return -1;
				}
				else
					break;
			}
			else
				++d;
		}
	}
	return 0;
}