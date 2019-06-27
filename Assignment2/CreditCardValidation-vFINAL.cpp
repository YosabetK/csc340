
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

bool isvalidcc(const string&);

int main()
{
	//
	// PLEASE DO NOT CHANGE function main
	//
	vector<string> cardnumbers = {
		 "371449635398431", "4444444444444448", "4444424444444440", "4110144110144115",
		"4114360123456785", "4061724061724061", "5500005555555559", "5115915115915118",
		"5555555555555557", "6011016011016011", "372449635398431", "4444544444444448",
		"4444434444444440", "4110145110144115", "4124360123456785", "4062724061724061",
		"5501005555555559", "5125915115915118", "5556555555555557", "6011116011016011",
		 "372449635397431", "4444544444444448", "4444434444544440", "4110145110184115",
		"4124360123457785", "4062724061724061", "5541005555555559", "5125115115915118",
		"5556551555555557", "6011316011016011"
	};

	int i;
	vector<string>::iterator itr;

	for (i = 1, itr = cardnumbers.begin(); itr != cardnumbers.end(); ++itr, i++) {
		cout << setw(2)  << i << " " 
			 << setw(17) << *itr 
			 << ((isvalidcc(*itr)) ? " is valid" : " is not valid") << endl;
	}

	return 0;
}

bool isvalidcc(const string& tempCreditCardNumberVector) {
    
    int tempTotalValue = 0;
    
    int odd = 0;
    int even = 0;
     
    int tempEven = 0;
    
    for(int i = tempCreditCardNumberVector.size() - 2;  0 <= i; i -=2) {

        if(i >= 0) {
            
            tempEven = tempCreditCardNumberVector.at(i) - 48;
            
            if( (tempEven * 2 ) > 9 && (tempEven * 2) < 19) {
                
                even = even + ( ((tempCreditCardNumberVector.at(i) - 48) * 2) - 9);
            }
            else {
                
                even = even + ((tempCreditCardNumberVector.at(i) - 48) * 2);

            }
        }
    }
    
    for(int j = tempCreditCardNumberVector.size() - 1;  0 <= j; j -=2) {
        
       if(j >= 0) {
           
           odd = odd + (tempCreditCardNumberVector.at(j) - 48);
           
       }
    }

    tempTotalValue = odd + even;
     
    if( tempTotalValue % 10 == 0) {
        
        return true;
    }
    else {
        
        return false;
    }
    
}







