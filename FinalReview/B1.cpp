http://csc340.ducta.net/WEEK-10/finalExamReview/B1.cpp

#include <iostream>
using namespace std;

int main() {

	static int y = 5;

	int i = 13, j = 17, m = 9, n = 11;

	int a = [](int x, int y = 1) { return x * y; } (y);

	int b = [=](int x) { return [=](int y) { return y % j; }(x)-7; }(a);

	int c = [&](int x) mutable -> int {
		m = 10;
		return [=](int j) -> int {
			y = a + b;
			return y + j;
		}(x)-m;
	}(b);

	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << m << endl;
	cout << y << endl;

	return 0;
}

/*
5
-2
-9
10
3
*/
