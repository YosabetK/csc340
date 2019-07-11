#include <iostream>
using namespace std;

int main() {

	double n = 25;
	double * const ptr = &n;
	double & lref = n;
	double && rref = move(n);
	
	// *ptr = 75;

	cout << lref << endl;
	lref = 75;
	cout << n << endl;

	cout << rref << endl;
	rref = 95;
	cout << rref << endl;

	double x = 3;
	double * const ptr = &n;

	return 0;
}
