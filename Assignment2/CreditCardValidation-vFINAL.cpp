
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

bool isvalidcc(const string& tempCreditCardNumberString) {
    
    //cout << endl;
    
    int tempTotalCreditCardValueToBeChecked = 0;
    
    int tempOddTotalValue = 0;
    int tempEvenTotalValue = 0;    
    int tempEven = 0;
    int tempOdd = 0;
    
    //Size is set to 15 for first number
    //15-2 = 13, so i at 13 is 3, since 3 * 2 is not greater than 9, move to 8 * 2, which is greater than 9
    //-2 every position because move 2 units left direction, every other position
    
    for(int i = tempCreditCardNumberString.size() - 2; i >= 0; i -=2) {
            
            //This temp value will hold the current position i is in, and only count one digit
            //Since substring is of type string, we want to convert back to type int
            tempEven = stoi(tempCreditCardNumberString.substr(i, 1));
            
            //Greater than 9 do this, else don't multiply
            if((tempEven * 2) > 9) {
                
                //Testing, 8 * 2 = 16, 16 > 9
                //16 = 1 + 6, same as 16 - 9 = 7
                tempEvenTotalValue = tempEvenTotalValue + ((tempEven * 2) - 9);
                
                //Check all the correct values that will be looped
                //cout << "Temp Even is: " << tempEven << ". Even is: " << even << endl;
            }
            else {
                
                tempEvenTotalValue = tempEvenTotalValue + (tempEven * 2);
                
                 //cout << "Temp Even is: " << tempEven << ". Even is: " << even << endl;

            }
    }
    //-1 because starting at first position, not second
    for(int j = tempCreditCardNumberString.size() - 1; j >= 0; j -=2) {
        
        tempOdd = stoi(tempCreditCardNumberString.substr(j, 1));
 
           tempOddTotalValue = tempOddTotalValue + (tempOdd);
           
           //Check all correct odd values
           //cout << "Temp odd is: " << tempOdd << ". Odd is: " << odd << endl;
    }
    //Adds both odd and even
    tempTotalCreditCardValueToBeChecked = tempOddTotalValue + tempEvenTotalValue;

    //check if divisible by 10
    if(tempTotalCreditCardValueToBeChecked % 10 == 0) {
        
        return true;
    }
    else {
        
        return false;
    }    
}





