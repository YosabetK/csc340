#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Stu {
public:
	// Constructor
	Stu() {
		this->langs = new vector<string>{ "C", "C++" };
	}

	// Big Five - Copy Constructor
	explicit Stu(const Stu& stu) {
		this->langs = new vector<string>{};

		vector<string>::const_iterator itr;
		for (itr = (*stu.getLangs()).begin(); itr < (*stu.getLangs()).end(); itr++) {
			(*this->langs).push_back(*itr);
		}
	}

	// Big Five - Move Constructor
	explicit Stu(Stu&& stu) {
		this->langs = new vector<string>{};
		(*this->langs).swap(*(stu.getLangs()));
	}

	// Big Five - Copy Assignment Operator
	const Stu& operator = (const Stu& stu) {
		if (this != &stu) {

			if (this->langs != nullptr) {
				delete this->langs;
			}
			
			this->langs = new vector<string>{};

			vector<string>::const_iterator itr;
			for (itr = (*stu.getLangs()).begin(); itr < (*stu.getLangs()).end(); itr++) {
				(*this->langs).push_back(*itr);
			}
		}
		return *this;
	}

	// Big Five - Move Assignment Operator
	const Stu& operator = (Stu&& stu) {
		if (this != &stu) {

			if (this->langs != nullptr) {
				delete this->langs;
			}

			this->langs = new vector<string>{};
			(*this->langs).swap(*(stu.getLangs()));
		}
		return *this;
	}

	// Big Five - Destructor
	~Stu() {
		if (this != nullptr) {
			if (this->langs != nullptr) {
				delete this->langs;
				this->langs = nullptr;
			}
		}
	}

	// OK to assume having common getters and setters

private:
	vector<string>* langs{ nullptr };
};
