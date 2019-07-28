#include <iostream>
using namespace std;

int main() {

	int const cs = 340;
	const int* csPtr = &cs;
	const int&& course = move(*csPtr);

	// Please code a constant pointer which points to course
	const int* const constPtr = &course;


	// Please code an lvalue reference to reference course
	const int & lref = course;


	// Please code an rvalue reference to reference course
	const int&& rref = move(course);


	// Do course and rref now have a same memory address? 
	// [ ] YES		[ ] NO
	// Why?
	cout << &course << " vs. " << &rref;
}

/* OUTPUT 
 00B3F6EC vs. 00B3F6EC
 */
