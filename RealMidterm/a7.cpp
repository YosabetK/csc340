#include <iostream>
using namespace std;

int x = 1;
int y = x + 3;

void swapplus1(int n1, int n2) {
	int temp = n1 - 2;
	n1 = n2 + 2;
	n2 = temp;
	x = x + n1;
	y = y + n2;
}

void swapplus2(int& n1, int& n2) {
	int temp = n1 + 2;
	n1 += n2 + 2;
	n2 -= temp;
}

void swapplus3(const int& n1, const int& n2) {
	int n1val, n2val, temp = n1 + 2;
	n1val = temp;
	n2val = n2 + 2;
	x += n1;
	y -= n2;
}

void swapplus4(int* p1, int* p2) {
	int temp = *p1 + 2;
	*p1 = *p2 + 2;
	*p2 = temp;
	x = *p1 + y;
	y = *p2 + x;
}

void swapplus5(int*& p1, int*& p2) {
	int* temp = p1 + 2;
	p1 = p2 + 2;
	p2 = temp;
}

void print(const int& x, const int& y) {
	cout << "\n x: " << x << " |y: " << y;
}

int main() {
	int x = 3;
	int y = x + 1;
	swapplus1(x, y);	print(x, y);
	swapplus2(x, y);	print(x, y);
	swapplus3(x, y);	print(x, y);
	swapplus4(&x, &y);	print(x, y);
	int* px = &x, * py = &y;
	(*px)++;
	(*py)--;
	swapplus5(px, py);	print(x, y);
	return 0;
}

/* OUTPUT
 x: 3 |y: 4
 x: 9 |y: -1
 x: 9 |y: -1
 x: 1 |y: 11
 x: 2 |y: 10
*/
