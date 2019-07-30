http://csc340.ducta.net/WEEK-10/finalExamReview/B5.cpp


#include <iostream>
using namespace std;


class Name {
public:
	Name() {}
	~Name() {
		cout << "Destroyed." << endl;
	}
private:
	string name{ "CS" };
};

weak_ptr<Name> wPtr;
shared_ptr<Name> sPtr{ nullptr };

void func() {
	unique_ptr<Name> obj{ make_unique<Name>() };
	// #1 Insert Code
	sPtr = move(obj);
	wPtr = sPtr;

}


int main() {
	// #2 Insert Code
	func();
	cout << "Dangling: " << wPtr.expired() << endl;
	sPtr.reset();

	return 0;
}

/*
Dangling: 0
Destroyed.
*/
