#include <iostream>
using namespace std;

int main() {

	// Pointer vs. Reference Variable 
	// Please refer to the mock-up exam and the review sessions & the review materials
	// We will go over the midterm exam in class

	string csc340 = "CS Major";
	void* ptr = &csc340;
	*ptr = "CS Major Upper Division";

	// ERROR: Expression must be a pointer to complete object type
	// Access + Control

	return 0;
}
