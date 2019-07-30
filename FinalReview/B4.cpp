#include <iostream>
using namespace std;

class PC {
	PC(string s)  {}
};

void passByRef(const unique_ptr<PC>& pc_uPtr_R); // 1
void passByMove(const unique_ptr<PC> pc_uPtr_M); // 2
void passByShare(const shared_ptr<PC> pc_name_sPtr_S); // 3	


int main() {
	unique_ptr<PC> name_uPtr{ make_unique<PC>("T7500") };
	return 0;
}

void passByRef(const unique_ptr<PC>& pc_uPtr_R)
{
	// implementation 
}

void passByMove(const unique_ptr<PC> pc_uPtr_M)
{
	// implementation 
}

void passByShare(const shared_ptr<PC> pc_name_sPtr_S)
{
	// implementation 
}
