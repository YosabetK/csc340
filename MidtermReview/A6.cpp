#include <iostream>
#include <typeinfo>
using namespace std;

void swapPlus1(int n1, int n2) {
	int temp = n1 + 3;
	n1 = n2 + 7;
	n2 = temp;
}

void swapPlus2(int& n1, int& n2) {
	int temp = n1 + 3;
	n1 = n2 + 7;
	n2 = temp;
}

void swapPlus3(const int& n1, const int& n2) {
	int n1val, n2val, temp = n1 + 3;
	n1val = n2 + 7;
	n2val = temp;
}

void swapPlus4(int* p1, int* p2) {
	int temp = *p1 + 3;
	*p1 = *p2 + 7;
	*p2 = temp;
}

void swapPlus5(int* &p1, int* &p2) {
	int* temp = p1 + 3;
	p1 = p2 + 7;
	p2 = temp;
}

void print(const int& x, const int& y) {
	cout << "\n x: " << x << " |y: " << y;
}

int main() {
	int x = 3, y = 7;
	swapPlus1(x, y);	print(x, y);
	swapPlus2(x, y);	print(x, y);
	swapPlus3(x, y);	print(x, y);
	swapPlus4(&x, &y);	print(x, y);
	int *px = &x, *py = &y;
	swapPlus5(px, py);	print(x, y);
	return 0;
}

/*
x: 3 |y: 7
x: 14 |y: 6
x: 14 |y: 6
x: 13 |y: 17
x: 13 |y: 17
*/
