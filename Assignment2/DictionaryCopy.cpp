
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

map<string, vector<string>> kevinMap;

void printTempDictionaryResult(string tempVector1, string tempVector2, string tempVector3, int size);

bool checkPartOfSpeech(string tempPartOfSpeechToBeChecked);
bool checkIfMapContains(string vec1, string vec2, string tempVector3, int vecSize);

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
            
            if(checkPartOfSpeech(tempSearchDictionary[1]) == false) {

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
            
            if(checkPartOfSpeech(tempSearchDictionary[1]) == false) {

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

void printTempDictionaryResult(string tempVector1, string tempVector2, string tempVector3, int size) {
    
    vector<string> tempSplittedVector;
    
    bool tempNotFound = false;
    
    string tempStringToAdd;
    vector<string> tempVectorToAdd;
    set<string> tempSetToAdd;
    
    tempSetToAdd.clear();
    
    //Loop through Map first, then loop into the Vector and get result from there
    
    for(map<string, vector<string>>::iterator it = kevinMap.begin(); it != kevinMap.end(); ++it) {

            for(vector<string>::iterator kevinVector = it->second.begin(); kevinVector != it->second.end(); ++kevinVector) {
                
                //This vector will have both the part of speech and the definition
                tempSplittedVector = seperate(*kevinVector, " -=>> ");

                if(size == 1 && (it->first == tempVector1)) {

                    cout << "\t " << it->first << " [" << tempSplittedVector[0] << "] : " << tempSplittedVector[1] << endl;
                }
                
                if(size == 2 && (it->first == tempVector1) && (tempSplittedVector[0] == tempVector2) ) {
                    
                    cout << "\t " << it->first << " [" << tempSplittedVector[0] << "] : " << tempSplittedVector[1] << endl;
                }
                //2nd word is "distinct" or 3rd word is, remove duplicates
                else if(size == 2 && (tempVector2 == "distinct") && (it->first == tempVector1)) {
                 
                    tempStringToAdd.clear();
                    tempStringToAdd = "\t " + it->first + " [" + tempSplittedVector[0] + "] : " + tempSplittedVector[1];
                    tempSetToAdd.insert(tempStringToAdd);
                }
                
                if(size == 3 && (it->first == tempVector1) && (tempSplittedVector[0] == tempVector2) && tempVector3 == "distinct") {
                    
                    tempStringToAdd.clear();
                    tempStringToAdd = "\t " + it->first + " [" + tempSplittedVector[0] + "] : " + tempSplittedVector[1];
                    tempSetToAdd.insert(tempStringToAdd);
                }
            }
        } 
    
    //Display the Distinct results
    if(size == 2 && tempVector2 == "distinct") {
        for(set<string>::iterator it = tempSetToAdd.begin(); it != tempSetToAdd.end(); ++it) {
            cout << *it << endl; 
        }
    }
    else if(size == 3 && tempVector3 == "distinct") {
        for(set<string>::iterator it = tempSetToAdd.begin(); it != tempSetToAdd.end(); ++it) {
            cout << *it << endl; 
        }
    }

}

bool checkPartOfSpeech(string tempPartOfSpeechToBeChecked) {
    
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
    
    for(map<string, vector<string>>::iterator it = kevinMap.begin(); it != kevinMap.end(); ++it) {
        
        if((vectorSize == 1) && kevinMap.find(tempVector1) != kevinMap.end() ) {
                   
            return true;
        }
        else {
            
            tempContains = false;
        }
        
        //Will return true if there is such valid argument, then false if not
        for(vector<string>::iterator kevinVector = it->second.begin(); kevinVector != it->second.end(); ++kevinVector) {
        
            tempSplittedVector = seperate(*kevinVector, " -=>> ");
            
            if( (vectorSize == 2) && (tempVector1 == (it->first)) && ((tempSplittedVector[0] == tempVector2) || (tempVector2 == "distinct")) ) {
                
                return true;
            }
            else {
                
                tempContains = false;
            }   
            if( (vectorSize > 2) && (tempVector1 == (it->first)) && (tempSplittedVector[0] == tempVector2) && (tempVector3 == "distinct") ) {
                
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
    vector<string>::iterator itr;
    
    string tempKey;
    string tempValue;
    
    for(itr = kevin.begin(); itr != kevin.end(); ++itr) {
        
        //currently looping through the vector
        //If Contains -=>> count this as a value, put inside vector of strings
        
        if((*itr).find(" -=>> ") != string::npos) {
            
            //Sort Vectors in order
            sort(itr, kevin.end());

            tempValue = (*itr);
            
            //Finding the correct key to add the vector of strings to
            if(kevinMap.find(tempKey) == kevinMap.end()) {
                //Adding value
                kevinMap[tempKey].push_back(tempValue);
            }
            else {
                kevinMap[tempKey].push_back(tempValue);
            }        
            //Insert both the key and value together in the map, temp is the vector that holds part of speech and definition
            kevinMap.insert({tempKey, {temp}});
        }
        //If Doesn't contain -=>> set the key as the given value from for loop
        else {
            //Key is the String inside map as the key inside key and value pairs 
            tempKey = (*itr);
            
            tempKey[0] = toupper(tempKey[0]); 
            
            if(tempKey.find("Csc") != string::npos) {
                tempKey = tempSelectPositionToCapitalize(tempKey, "Csc");
            }
        } 
    }    
    return kevinMap;
}

vector<string> seperate(string tempLineToSplit, string tempStringSplitter) {
    
    vector<string> tempSplittedVector;
    size_t tempCurrentPosition = 0;
    string line;
    
    //So position starts at 0, continues to loop until it finds the string in the given in the function, then seperate it into vector
    while((tempCurrentPosition = tempLineToSplit.find(tempStringSplitter)) != string::npos) {
        //substring will get part of the string that contains the desired position
        line = tempLineToSplit.substr(0, tempCurrentPosition);
        //Same as adding string to a vector
        tempSplittedVector.push_back(line);
        //Erase the stuff we don't need anymore
        tempLineToSplit.erase(0, tempCurrentPosition + tempStringSplitter.length());
    }
    //Since the line has been seperated, we can push the seperated line back
    tempSplittedVector.push_back(tempLineToSplit);
    //Return seperated vector by user input
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







