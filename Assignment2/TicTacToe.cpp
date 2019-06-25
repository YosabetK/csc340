/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Kevin Zhou
 *
 * Created on June 24, 2019, 11:05 PM
 */

#include <iostream>
using namespace std;

bool isWon(char, char[][3]);
bool isDraw(char[][3]);
void displayBoard(char[][3]);
void makeAMove(char[][3], char);

bool checkHorizontal(char, char[][3]);
bool checkVertical(char, char[][3]);
bool checkDiagonal(char, char[][3]);

int main() {
	//
	//	PLEASE DO NOT CHANGE function main
	//
	char board[3][3] = { { ' ', ' ', ' ' },{ ' ', ' ', ' ' },{ ' ', ' ', ' ' } };
	displayBoard(board);

	while (true) {
		// The first player makes a move
		makeAMove(board, 'X');
		displayBoard(board);
		if (isWon('X', board)) {
			cout << "X player won" << endl;
			exit(0);
		}
		else if (isDraw(board)) {
			cout << "No winner" << endl;
			exit(0);
		}

		// The second player makes a move
		makeAMove(board, 'O');
		displayBoard(board);

		if (isWon('O', board)) {
			cout << "O player won" << endl;
			exit(0);
		}
		else if (isDraw(board)) {
			cout << "No winner" << endl;
			exit(0);
		}
	}

	return 0;
}

bool isWon(char tempPlayer, char tempBoard[][3]) {
    
    bool h = checkHorizontal(tempPlayer, tempBoard);
    bool v = checkVertical(tempPlayer, tempBoard);
    bool d = checkDiagonal(tempPlayer, tempBoard);
    
    if(h || v || d) 
        return true;
    else
        return false;
   
}

bool isDraw(char tempBoard[][3]) {
    
    
    
    //Return true if there is draw and all spaces filled up
    
    return false;
}

bool checkHorizontal(char tempPlayer, char tempBoard[][3]) {
    
    for(int i = 0; i < 3; i++) {
        
        for(int j = 0; j < 3; j++) {
            
            if(tempBoard[0][0] == tempPlayer && tempBoard[0][1] == tempPlayer && tempBoard[0][2] == tempPlayer) {
                
                return true;
            }
            else if(tempBoard[1][0] == tempPlayer && tempBoard[1][1] == tempPlayer && tempBoard[1][2] == tempPlayer) {
                
                return true;
            }
            else if(tempBoard[2][0] == tempPlayer && tempBoard[2][1] == tempPlayer && tempBoard[2][2] == tempPlayer) {
                
                return true;
            }
            else {
                return false;
            }
        }
    }
}

bool checkVertical(char tempPlayer, char tempBoard[][3]) {
    
    for(int i = 0; i < 3; i++) {
        
        for(int j = 0; j < 3; j++) {
            
            if(tempBoard[0][0] == tempPlayer && tempBoard[1][0] == tempPlayer && tempBoard[2][0] == tempPlayer) {
                
                return true;
            }
            else if(tempBoard[0][1] == tempPlayer && tempBoard[1][1] == tempPlayer && tempBoard[2][1] == tempPlayer) {
                
                return true;
            }
            else if(tempBoard[0][2] == tempPlayer && tempBoard[1][2] == tempPlayer && tempBoard[2][2] == tempPlayer) {
                
                return true;
            }
            else {
                return false;
            }
        }
    }
}

bool checkDiagonal(char tempPlayer, char tempBoard[][3]) {
    
    for(int i = 0; i < 3; i++) {
        
        for(int j = 0; j < 3; j++) {
            
            if(tempBoard[0][0] == tempPlayer && tempBoard[1][1] == tempPlayer && tempBoard[2][2] == tempPlayer) {
                
                return true;
            }
            else if(tempBoard[0][2] == tempPlayer && tempBoard[1][1] == tempPlayer && tempBoard[2][0] == tempPlayer) {
                
                return true;
            }
            else {
                return false;
            }
        }
    }
}

void makeAMove(char tempBoard[][3], char tempPlayer) {
    
    int tempRowPosition;
    int tempColPosition;
    
    cout << "Enter a row (0, 1, 2) for player " << tempPlayer << "   :  ";
    
    cin >> tempRowPosition;
    
    cout << "Enter a column (0, 1, 2) for player " << tempPlayer << "   :  ";
    
    cin >> tempColPosition;
    
    for(int i = 0; i < 3; i++) {
        
        for(int j = 0; j < 3; j++) {
            
            //Fix this line 6/25/19 3 AM
            
            if(i == tempRowPosition && j == tempColPosition && tempBoard[i][j] != 'X' && tempBoard[i][j] != 'O') 
                tempBoard[i][j] = tempPlayer;
        }
    }
}

void displayBoard(char tempBoard[][3]) {
    
    for(int i = 0; i < 3; i++) {
        
        cout << " -------------" << endl;
        
        for(int j = 0; j < 3; j++) {
            
            cout << " | " << tempBoard[i][j];
        }
        
        cout << " | "<< endl;
    }
}





