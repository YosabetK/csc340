#include <iostream>
using namespace std;

int x[] { 1, 3, 5, 7, 9};
int * y = &x[3];

void t1() {
	x[3] += x[3]++ + 1;
	cout << "_x: " << x[3] << " | _y: " << *y << endl;
}

void t2() {
	int x = ::x[4] % 5;
	y = ::x;
	cout << "_x: " << x << " | _y: " << y[2] << endl;
}

void t3() {
	x[4]++;
	static int y = 2 + ::y[4]++;
	cout << "_x: " << x[4] << " | _y: " << y << endl;
}

void t4() {
	int& x = ::x[0];
	::x[0]++;
	cout << "_x: " << x << " | _y: " << *y << endl;
}

int main() {
	y++;

	t1();
	t2();
	t3();
	t3();
	t4();
	return 0;
}
/* OUTPUT
_x: 16 | _y: 9
_x: 4  | _y: 5
_x: 11 | _y: 12
_x: 12 | _y: 12
_x: 2  | _y: 2
*/
