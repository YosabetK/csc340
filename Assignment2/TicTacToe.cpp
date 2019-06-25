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

bool isWon(char player, char num2[][3]) {
    
    return false;
}

bool isDraw(char num1[][3]) {
    
    return false;
}

void makeAMove(char tempBoard[][3], char player) {
    
    //Takes input from user using cin
    /*
        Enter a row (0, 1, 2) for player X   : 0
        Enter a column (0, 1, 2) for player X: 0
     */
    
    char tempPlayer;
    //May not be used, but is a variable to track current player making a move
    
    int tempRow;
    int tempCol;
    
    cout << "Enter a row (0, 1, 2) for player " << player << "   :  ";
    
    tempPlayer = player;
    
    cin >> tempRow;
    
    cout << "Enter a column (0, 1, 2) for player " << player << "   :  ";
    
    cin >> tempCol;
    
    for(int i = 0; i < 3; i++) {
        
        for(int j = 0; j < 3; j++) {
            
            if(i == tempRow && j == tempCol)
                tempBoard[i][j] = tempBoard[tempRow][tempCol];
        }
    }
    
    //exit(0);
}

void displayBoard(char board[][3]) {
    
    for(int i = 0; i < 3; i++) {
        
        cout << " -------------" << endl;
        
        for(int j = 0; j < 3; j++) {
            
            cout << " | " << board[i][j];
        }
        
        cout << " | "<< endl;
    }
    
    //exit(0);
}



