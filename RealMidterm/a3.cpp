#include <iostream>
#include <string>
using namespace std;

class CMS {
public:
	CMS() {};
	CMS(string name, string type = "File Manager") :
		type(type), name(name) {}

	string getInfo() const {
		return this->type + " - " + this->name;
	}

	void setName(const string& name) {
		this->name = name;
	}

private:
	static int sysTotal;
	string name{ "iLearn" };
	string type{ "Multi-Use" };
};

int CMS::sysTotal = 0;

CMS * confSys(const string& type) {
	CMS * sys1 = new CMS{"CSC340"};
	cout << sys1->getInfo() << endl;
	sys1->setName("<confSys-created>");
	static CMS * sys2 = new CMS { *sys1 };
	CMS sys3{ *sys2 };
	cout << sys3.getInfo() << endl;
	return sys2;
}

int main() {
	CMS *sys4 = new CMS { *confSys("e-Portfolio") };
	cout << sys4->getInfo() << endl;
	CMS* sys5 = sys4;
	sys5->setName("<main-created-1st>");
	static CMS& sys6 = *sys5;
	sys5->setName("<main-created-2nd>");
	cout << sys5->getInfo() << endl;
	cout << sys6.getInfo() << endl;
	return 0;
}

/* OUTPUT
File Manager - CSC340
File Manager - <confSys-created>
File Manager - <confSys-created>
File Manager - <main-created-2nd>
File Manager - <main-created-2nd>
 */
