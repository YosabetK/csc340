#include <iostream>
#include <functional>
using namespace std;

double sumOf(const int& x, const double& y) {
	return x + y;
}

int main() {

	// auto
	auto ptr_auto{ sumOf };

	// Actual type
	double(*ptr_actualType) (const int&, const double&) { sumOf };

	// Function object, <functional>
	function<double(const int&, const double&)> ptr_functionObj{ sumOf };

	// typedef
	typedef double(*type_doubleConstRefConstRef) (const int&, const double&); // Step 1
	type_doubleConstRefConstRef ptr_typedef{ sumOf };						  // Step 2

	// using
	using using_doubleConstRefConstRef = double(const int&, const double&);	  // Step 1
	using_doubleConstRefConstRef * ptr_using{ sumOf };						  // Step 2

	return 0;
}
