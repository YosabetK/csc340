http://csc340.ducta.net/WEEK-10/finalExamReview/B3.cpp










#include <iostream>
#include <string>
using namespace std;

string makeGreeting(const string& event) {
	return "Happy " + event + "!";
}

string makeGreeting(const double& earning) {
	return "Happy earning $" + to_string(earning) + "!";
}

int main() {

	// Actual type
	string(*ptr_1) (const string&) { makeGreeting };
	string(*ptr_2) (const double&) { makeGreeting };

	return 0;
}
