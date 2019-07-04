
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

map<string, vector<string>> tempKevinDictionaryMap;

void printTempDictionaryResult(string tempVector1, string tempVector2, string tempVector3, int vectorSize);

bool checkTempPartOfSpeech(string tempPartOfSpeechToBeChecked);
bool checkIfMapContains(string tempVector1, string tempVector2, string tempVector3, int vectorSize);

map<string, vector<string>> addMap(vector<string> temp);

vector<string> seperate(string tempLineToSplit, string tempStringSplitter);
string tempConvertToLowerCase(string tempString);
string tempConvertToUpperCase(string tempString);
string tempSelectPositionToCapitalize(string tempString, string spotToCapitalize);

string tempPartOfSpeechArray[] = {"noun", "pronoun", "adjective", "verb", "adverb", "preposition", "conjunction", "interjection"};

class TempDataBaseDictionaryClass {
    
private:    
    string tempKeyword, tempPartOfSpeech, tempDefinition;

public:    
    tempDataBaseDictionaryClass() {
        //Empty Constructor
    }
    void setKeyWord(string keyword) {
        tempKeyword = keyword;
    }
    string getTempKeyword() {
        return tempKeyword;
    }
    string getTempPartOfSpeech() {
        return tempPartOfSpeech;
    }
    string getTempDefinition() {
        return tempDefinition;
    }
    string toStringFormat() {
        cout << "\t" << tempKeyword << " [" << tempPartOfSpeech << "] : " << tempDefinition << endl;
    }
    
};

int main() {
    vector<string> temp;
    vector<vector<string>> tempVector;
    
    string line, line2, next;
    fstream inFile;
    cout << "! Opening data file... ./Data.CS.SFSU.txt" << endl;

    //This is the File
    inFile.open("C:\\Users\\adazh\\OneDrive\\Desktop\\Data.CS.SFSU.txt", ios::in);
    
    if(!inFile) {
        cout << "Cannot open the file: " << endl;
        exit(0);
    }
    
    cout << "! Loading data..." << endl;
    //Reading the file line by line
    while(getline(inFile, line)) {
       //Seperate keyword and part of speech by "|"
       temp = seperate(line, "|");
       //Add this to the Map with String and Vector
       addMap(temp);
    }
    inFile.close();
    cout << "! Loading completed..." << endl;
    cout << "! Closing data file... ./Data.CS.SFSU.txt" << endl;
    cout << "\n----- Dictionary 340 C++ -----\n" << endl;
    
    TempDataBaseDictionaryClass *tempDataBaseDictionaryClassObject = new TempDataBaseDictionaryClass();
    //Here is checking the user input
    
    bool tempSearchState = true;
    
    while(tempSearchState) {
        
        string tempUserInputLine;
        cout << "Search: ";
        getline(cin, tempUserInputLine);
        
        //convert all input into LowerCase
        tempUserInputLine = tempConvertToLowerCase(tempUserInputLine);
        //Convert only first letter to be capital, so the Dictionary will display first letter as capital letter
        tempUserInputLine[0] = toupper(tempUserInputLine[0]);
        //tempDataBaseDictionaryClassObject->setKeyWord(tempUserInputLine);
        //cout << tempDataBaseDictionaryClassObject->getTempKeyword() << endl;
        
        if(tempUserInputLine.find("Csc") != string::npos)
            tempUserInputLine = tempSelectPositionToCapitalize(tempUserInputLine, "Csc");
       
        if(tempUserInputLine == tempConvertToLowerCase("!q")) {
            
            tempSearchState = false; 
            cout << endl << "-----THANK YOU-----" << endl;
            exit(0); //End program when user agrees to quit
        }
        
        vector<string> tempSearchDictionary;
        tempSearchDictionary = seperate(tempUserInputLine, " ");
        
        cout << "\t|" << endl; 

        string tempEmpty;
        
        //If length 1, search the user input keyword if inside map
        if(tempSearchDictionary.size() == 1) {
            
            if(checkIfMapContains(tempSearchDictionary[0], tempEmpty, tempEmpty, tempSearchDictionary.size())) {
                
                printTempDictionaryResult(tempSearchDictionary[0], tempEmpty, tempEmpty, tempSearchDictionary.size());
            }
            else {
                
                cout << "\t <Not found>" << endl;
            }
        }
        //If 2nd argument not part of speech or distinct, display it
        //If valid 2nd argument, search for it, then else not found if can't find it in map
        if(tempSearchDictionary.size() == 2) {
            
            if(checkTempPartOfSpeech(tempSearchDictionary[1]) == false) {

                cout << "\t <2nd argument must be part of speech or \"distinct\">" << endl;
            }
            else if(checkIfMapContains(tempSearchDictionary[0], tempSearchDictionary[1], tempEmpty, tempSearchDictionary.size())) {
                
                printTempDictionaryResult(tempSearchDictionary[0], tempSearchDictionary[1], tempEmpty, tempSearchDictionary.size());
            }
            else {
                
                cout << "\t <Not Found>" << endl;
            }
        }
        
        //Accounts for argument greater than 2, if distinct, don't allow duplicated results, if multiple distinct, check if map has it or not
        if(tempSearchDictionary.size() > 2) {
            
            if(checkTempPartOfSpeech(tempSearchDictionary[1]) == false) {

                cout << "\t <2nd argument must be part of speech or \"distinct\">" << endl;
            }
            else if(checkIfMapContains(tempSearchDictionary[0], tempSearchDictionary[1], tempSearchDictionary[2], tempSearchDictionary.size())) {
                
                printTempDictionaryResult(tempSearchDictionary[0], tempSearchDictionary[1], tempSearchDictionary[2], tempSearchDictionary.size());
            }
            else {
                
                cout << "\t <Not Found>" << endl;
            }        
        }
        cout << "\t|" << endl;
    }   
    return 0;
}

void printTempDictionaryResult(string tempVector1, string tempVector2, string tempVector3, int vectorSize) {
    
    vector<string> tempSplittedVector;
    
    bool tempNotFound = false;
    
    string tempStringToAdd;
    set<string> tempSetToAdd;
    
    tempSetToAdd.clear();
    
    //Loop through Map first, then loop into the Vector and get result from there
    
    for(map<string, vector<string>>::iterator tempIterator = tempKevinDictionaryMap.begin(); tempIterator != tempKevinDictionaryMap.end(); ++tempIterator) {

            for(vector<string>::iterator kevinVector = tempIterator->second.begin(); kevinVector != tempIterator->second.end(); ++kevinVector) {
                
                //This vector will have both the part of speech and the definition
                tempSplittedVector = seperate(*kevinVector, " -=>> ");

                if(vectorSize == 1 && (tempIterator->first == tempVector1)) {

                    cout << "\t " << tempIterator->first << " [" << tempSplittedVector[0] << "] : " << tempSplittedVector[1] << endl;
                }
                
                if(vectorSize == 2 && (tempIterator->first == tempVector1) && (tempSplittedVector[0] == tempVector2) ) {
                    
                    cout << "\t " << tempIterator->first << " [" << tempSplittedVector[0] << "] : " << tempSplittedVector[1] << endl;
                }
                //2nd word is "distinct" or 3rd word is, remove duplicates
                else if(vectorSize == 2 && (tempVector2 == "distinct") && (tempIterator->first == tempVector1)) {
                 
                    tempStringToAdd.clear();
                    tempStringToAdd = "\t " + tempIterator->first + " [" + tempSplittedVector[0] + "] : " + tempSplittedVector[1];
                    tempSetToAdd.insert(tempStringToAdd);
                }
                
                if(vectorSize == 3 && (tempIterator->first == tempVector1) && (tempSplittedVector[0] == tempVector2) && tempVector3 == "distinct") {
                    
                    tempStringToAdd.clear();
                    tempStringToAdd = "\t " + tempIterator->first + " [" + tempSplittedVector[0] + "] : " + tempSplittedVector[1];
                    tempSetToAdd.insert(tempStringToAdd);
                }
            }
        } 
    
    //Display the Distinct results
    if(vectorSize == 2 && tempVector2 == "distinct") {
        
        for(set<string>::iterator tempIterator = tempSetToAdd.begin(); tempIterator != tempSetToAdd.end(); ++tempIterator) {
            
            cout << *tempIterator << endl; 
        }
    }
    else if(vectorSize == 3 && tempVector3 == "distinct") {
        
        for(set<string>::iterator tempIterator = tempSetToAdd.begin(); tempIterator != tempSetToAdd.end(); ++tempIterator) {
            
            cout << *tempIterator << endl; 
        }
    }

}

bool checkTempPartOfSpeech(string tempPartOfSpeechToBeChecked) {
    
    bool tempFoundPartOfSpeech = false;
    //If Distinct it is valid

    if(tempPartOfSpeechToBeChecked == ("distinct")) {
        
        return true;
    }
    //Loop through array and see if second argument is valid, or if it matches a correct part of speech
    for(int i = 0; i < sizeof(tempPartOfSpeechArray) / sizeof(tempPartOfSpeechArray[0]); i++) {
        
        if(tempPartOfSpeechArray[i] == (tempPartOfSpeechToBeChecked)) {
            
            return true;
        }
        else {
            
            tempFoundPartOfSpeech = false; 
        }
    }
    
    return tempFoundPartOfSpeech;
}

//Check if the Map contains user input or not. If doesn't just put not found in main
bool checkIfMapContains(string tempVector1, string tempVector2, string tempVector3, int vectorSize) {
    
    bool tempContains;
    
    vector<string> tempSplittedVector;
    
    for(map<string, vector<string>>::iterator tempIterator = tempKevinDictionaryMap.begin(); tempIterator != tempKevinDictionaryMap.end(); ++tempIterator) {
        
        if((vectorSize == 1) && tempKevinDictionaryMap.find(tempVector1) != tempKevinDictionaryMap.end() ) {
                   
            return true;
        }
        else {
            
            tempContains = false;
        }
        
        //Will return true if there is such valid argument, then false if not
        for(vector<string>::iterator kevinVector = tempIterator->second.begin(); kevinVector != tempIterator->second.end(); ++kevinVector) {
        
            tempSplittedVector = seperate(*kevinVector, " -=>> ");
            
            if( (vectorSize == 2) && (tempVector1 == (tempIterator->first)) && ((tempSplittedVector[0] == tempVector2) || (tempVector2 == "distinct")) ) {
                
                return true;
            }
            else {
                
                tempContains = false;
            }   
            if( (vectorSize > 2) && (tempVector1 == (tempIterator->first)) && (tempSplittedVector[0] == tempVector2) && (tempVector3 == "distinct") ) {
                
                return true;
            }
            else {
                
                tempContains = false;
            }            
        }

    } 
     return tempContains;   
}

//Adding the Map from the File
map<string, vector<string>> addMap(vector<string> kevin) {
   
    vector<string> temp;
    vector<string>::iterator tempIterator;
    
    string tempKey;
    string tempValue;
    
    for(tempIterator = kevin.begin(); tempIterator != kevin.end(); ++tempIterator) {
        
        //currently looping through the vector
        //If Contains -=>> count this as a value, put inside vector of strings
        
        if((*tempIterator).find(" -=>> ") != string::npos) {
            
            //Sort Vectors in order
            sort(tempIterator, kevin.end());

            tempValue = (*tempIterator);
            
            //Finding the correct key to add the vector of strings to
            if(tempKevinDictionaryMap.find(tempKey) == tempKevinDictionaryMap.end()) {
                //Adding value
                tempKevinDictionaryMap[tempKey].push_back(tempValue);
            }
            else {
                tempKevinDictionaryMap[tempKey].push_back(tempValue);
            }        
            //Insert both the key and value together in the map, temp is the vector that holds part of speech and definition
            tempKevinDictionaryMap.insert({tempKey, {temp}});
        }
        //If Doesn't contain -=>> set the key as the given value from for loop
        else {
            //Key is the String inside map as the key inside key and value pairs 
            tempKey = (*tempIterator);
            
            //This changes the first letter to capital
            tempKey[0] = toupper(tempKey[0]); 
            
            //If we find, Csc part, we want to specific part to be capitalized
            if(tempKey.find("Csc") != string::npos) {
                
                tempKey = tempSelectPositionToCapitalize(tempKey, "Csc");
            }
        } 
    }    
    return tempKevinDictionaryMap;
}

vector<string> seperate(string tempLineToSplit, string tempStringSplitter) {
    
    vector<string> tempSplittedVector;

    string tempCurrentLineToBeChecked;
  
    bool tempLeftOverRemainingString = false;
    
    //My own notes
    //"kevin->map===student"
    //Find -> at 5 position, but is length 6
    //Add (0-4) which is kevin
    //Remove (0-6) which is kevin-> which is size 7, (0, 5 + 2)
    //once it reaches student, no more string to be seperated, leftover is true and will add remaining to the vector
    
    //length of tempLineToSplit must be greater than 1 in order to even break string apart and seperate it, else it won't be able to break it apart
    
    if(tempLineToSplit.length() > 0) {
        
        //Checking and making sure that the position it is looping is not at the end of position, if still room to loop, continue 
        
        while(tempLineToSplit.find(tempStringSplitter) != string::npos) {
            
            //False once it finds something, false because part of string will be added into victor and part of it will be removed, so length may or may not be greater than 1
            
            tempLeftOverRemainingString = false;
            
            //We are getting the starting position and the end position of the string that doesn't contain the string to be seperated, stops before the first position it finds

            tempCurrentLineToBeChecked = tempLineToSplit.substr(0, tempLineToSplit.find(tempStringSplitter) - 0);
            
            //Adds that part

            tempSplittedVector.push_back(tempCurrentLineToBeChecked);
            
            //Removes the seperated string part, so we can start back at the beginning, adding so it will not only include the added string, but also the seperated string

            tempLineToSplit.erase(0, tempLineToSplit.find(tempStringSplitter) + tempStringSplitter.size());
        }
        
        //If there is leftover string without a seperated one, add the remaining
        
        if(tempLineToSplit.length() > 0) {
        
            tempLeftOverRemainingString = true;
        }
    }
    
    if(tempLeftOverRemainingString == true) {
        
        tempSplittedVector.push_back(tempLineToSplit);
    }
    
    return tempSplittedVector;     
}

string tempConvertToLowerCase(string tempString) {
    
    char tempChar;
    
    //tolower() takes in a char and we can loop through string and change each char in string to lowercase
    for(int i = 0; i < tempString.size(); i++) {
        
        //char will be assigned lowercase character
        
        tempChar = tolower(tempString[i]);
        
        //Then now assign the string the lowercase char
        
        tempString[i] = tempChar;
    }   
    return tempString;
}

string tempConvertToUpperCase(string tempString) {  
    char tempChar;
    //convert to uppercase
    for(int i = 0; i < tempString.size(); i++) {
        
        tempChar = toupper(tempString[i]);
        
        tempString[i] = tempChar;
    }   
    return tempString;
}

string tempSelectPositionToCapitalize(string tempString, string spotToCapitalize) {
    
    //Allows you to capitalize which part you want
    //Maybe not always be needed, but can be used to capitalize parts of a word
    
    if(tempString.find(spotToCapitalize) != string::npos) {
        
        for(int i = 0; i < spotToCapitalize.size(); i++) {
            
            tempString[i] = toupper(tempString[i]);
        }
    }
    return tempString;
}







