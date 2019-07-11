#include <iostream>
using namespace std;

int y, z;

void t1() {
	int x = 1;
	y++;
	cout << "\n x: " << x << "| y: " << y;
	y += 2;
}

void t2() {
	int* x = &y;
	x++;
	cout << "\n x: " << *x + y << "| y: " << y;
}

void t3() {
	static int x = 5;
	x++;
	int y = 7 + 1;
	y += x;
	cout << "\n x: " << x << "| y: " << y + x;
}

void t4() {
	int y = 7;
	int z = y;
	int* zPtr = &z;
	*zPtr += y + z;
	cout << "\n z: " << *zPtr + z << "| y: " << y;
}

int main() {
	t1();
	t2();
	t3();
	t3();
	t4();
	return 0;
}

/*
x: 1| y: 1
x: 3| y: 3
x: 6| y: 20
x: 7| y: 22
z: 42| y: 7
*/
