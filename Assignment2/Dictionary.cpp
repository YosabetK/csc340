
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <algorithm>
#include <set>


using namespace std;

vector<string> seperate(string line, string str);
//map<string, vector<vector<string>> addMap();
//map<string, map<string, vector<string>>> addMap

map<string, vector<string>> kevinMap;
//bool checkIfMapContains(vector<string> tempVectorToCheck);

void printTempDictionaryResult(string tempVector1, string tempVector2, string tempVector3, int size);

bool checkPartOfSpeech(string tempPartOfSpeechToBeChecked);

bool checkIfMapContains(string vec1, string vec2, string tempVector3, int vecSize);

map<string, vector<string>> addMap(vector<string> temp);
vector<string> seperate(string tempLineToSplit, string tempStringSplitter);
string tempConvertToLowerCase(string tempString);


string tempPartOfSpeechArray[] = {"noun", "pronoun", "adjective", "verb", "adverb", "preposition", "conjunction", "interjection"};

class TempDataBaseDictionaryClass {
    
private:    
    string tempKeyword, tempPartOfSpeech, tempDefinition;
    
    //map<string, vector<string>> tempStorageMap;

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
    if(!inFile) {
        cout << "Cannot open the file: " << endl;
    }
    cout << "! Loading data..." << endl;
    inFile.open("C:\\Users\\adazh\\OneDrive\\Desktop\\Data.CS.SFSU.txt", ios::in);
    
    while(getline(inFile, line)) {
        
        //cout << line << endl;
        //getline(inFile, line2, '-=>>');
        
       //cout << line << endl;
       
       temp = seperate(line, "|");
       
       addMap(temp);
    }
    inFile.close();
    cout << "! Closing data file... ./Data.CS.SFSU.txt" << endl;
    
    //TempDataBaseDictionaryClass temp;
    //getTempKeyword();
    
    //Here is checking the user input
    
    bool tempSearchState = true;
    
    while(tempSearchState) {
        
        string tempUserInputLine;
        cout << "Search: ";
        getline(cin, tempUserInputLine);
        
        if(tempUserInputLine == tempConvertToLowerCase("!q")) {
            
            tempSearchState = false; 
            cout << endl << "-----THANK YOU-----" << endl;
            exit(0);
        }
        
        vector<string> tempSearchDictionary;
        tempSearchDictionary = seperate(tempUserInputLine, " ");
        
        cout << "\t|" << endl;

        string tempEmpty;
        
        if(tempSearchDictionary.size() == 1) {
            
            if(checkIfMapContains(tempSearchDictionary[0], tempEmpty, tempEmpty, tempSearchDictionary.size())) {
                
                printTempDictionaryResult(tempSearchDictionary[0], tempEmpty, tempEmpty, tempSearchDictionary.size());
            }
            else {
                
                cout << "\t <Not found>" << endl;
            }
        }
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
    
    for(map<string, vector<string>>::iterator it = kevinMap.begin(); it != kevinMap.end(); ++it) {

            for(vector<string>::iterator vec = it->second.begin(); vec != it->second.end(); ++vec) {
                
                tempSplittedVector = seperate(*vec, " -=>> ");
                
                //works for sure
                if(size == 1 && (it->first == tempVector1)) {
                
                    cout << "\t " << it->first << " [" << tempSplittedVector[0] << "] : " << tempSplittedVector[1] << endl;
                }
                
                if(size == 2 && (it->first == tempVector1) && (tempSplittedVector[0] == tempVector2) ) {
                    
                    cout << "\t " << it->first << " [" << tempSplittedVector[0] << "] : " << tempSplittedVector[1] << endl;
                }
                //2nd word is "distinct" remove duplicates
                else if(size == 2 && tempVector2 == "distinct" && (it->first == tempVector1)) {
                 
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
    
    if(tempPartOfSpeechToBeChecked.compare("distinct") == 0) {
        
        return true;
    }
    
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
            
        for(vector<string>::iterator vec = it->second.begin(); vec != it->second.end(); ++vec) {
        
            tempSplittedVector = seperate(*vec, " -=>> ");
            
            if( (vectorSize == 2) && (tempSplittedVector[0] == tempVector2) || (tempVector2 == "distinct") ) {
                
                return true;
            }
            else {
                
                tempContains = false;
            }   
            if( (vectorSize > 2) && (tempSplittedVector[0] == tempVector2) && (tempVector3 == "distinct") ) {
                
                return true;
            }
            else {
                
                tempContains = false;
            }            
        }

    } 
     return tempContains;   
}

map<string, vector<string>> addMap(vector<string> kevin) {
   
    vector<string> temp;
    vector<string>::iterator itr;
    
    string tempKey;
    string tempValue;
    
    for(itr = kevin.begin(); itr != kevin.end(); ++itr) {
        
        //currently looping through the vector
        
        //If Contains -=>> count this as a value, put inside vector of strings
        if((*itr).find(" -=>> ") != string::npos) {

            tempValue = (*itr);
            
            //Finding the correct key to add the vector of strings to
            if(kevinMap.find(tempKey) == kevinMap.end()) {

                kevinMap[tempKey].push_back(tempValue);
                //kevinMap[tempKey].push_back(tempValue);
            }
            else {
                kevinMap[tempKey].push_back(tempValue);
            }        
            //Insert both they key and value together in the map
            kevinMap.insert({tempKey, {temp}});
        }
        //If Doesn't contain -=>> set the key as the given value from for loop
        else {
 
            tempKey = (*itr);
        } 
    }    
    return kevinMap;
}

vector<string> seperate(string tempLineToSplit, string tempStringSplitter) {
    
    vector<string> tempSplittedVector;
    size_t tempCurrentPosition = 0;
    string line;
    
    while((tempCurrentPosition = tempLineToSplit.find(tempStringSplitter)) != string::npos) {
        
        line = tempLineToSplit.substr(0, tempCurrentPosition);
        //Same as adding string to a vector
        tempSplittedVector.push_back(line);
        tempLineToSplit.erase(0, tempCurrentPosition + tempStringSplitter.length());
    }
    tempSplittedVector.push_back(tempLineToSplit);

    return tempSplittedVector;     
}

string tempConvertToLowerCase(string tempString) {
    
    transform(tempString.begin(), tempString.end(), tempString.begin(), ::tolower);
    
    return tempString;
}




