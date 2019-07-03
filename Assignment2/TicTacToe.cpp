
#include <iostream>
using namespace std;

bool isWon(char, char[][3]);
bool isDraw(char[][3]);
void displayBoard(char[][3]);
void makeAMove(char[][3], char);

bool tempCheckHorizontal(char, char[][3]);
bool tempCheckVertical(char, char[][3]);
bool tempCheckDiagonal(char, char[][3]);

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
    
    bool tempH = tempCheckHorizontal(tempPlayer, tempBoard);
    bool tempV = tempCheckVertical(tempPlayer, tempBoard);
    bool tempD = tempCheckDiagonal(tempPlayer, tempBoard);
    
    //If the user has won through either of these, its a win
    if(tempH || tempV || tempD) 
        return true;
    else
        return false;
}

bool isDraw(char tempBoard[][3]) {
    
    //Draw will happen if all spots are taken, meaning none are empty
    if(tempBoard[0][0] != ' ' && tempBoard[0][1] != ' ' && tempBoard[0][2] != ' ' && tempBoard[1][0] != ' ' && tempBoard[1][1] != ' ' && tempBoard[0][2] != ' ' 
            && tempBoard[2][0] != ' ' && tempBoard[2][1] != ' ' && tempBoard[2][2] != ' ') {
        return true;
    }
    else {
        return false;
    }
}

bool tempCheckHorizontal(char tempPlayer, char tempBoard[][3]) {
    
    //Check all horizontal spots and see if there's 3 in a row for horizontal
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

bool tempCheckVertical(char tempPlayer, char tempBoard[][3]) {
            
    //Check all vertical spots and see if there's 3 in a row for vertical
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

bool tempCheckDiagonal(char tempPlayer, char tempBoard[][3]) {
           
    //Check all diagonal spots and see if there's 3 in a row for diagonal
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

void makeAMove(char tempBoard[][3], char tempPlayer) {
    
    int tempRowPosition;
    int tempColPosition;
    
    bool tempCurrentTurnComplete = false;
    
    //Ask the user to pick a spot
    cout << "Enter a row (0, 1, 2) for player " << tempPlayer << "   :  ";
    cin >> tempRowPosition;
    cout << "Enter a column (0, 1, 2) for player " << tempPlayer << "   :  ";
    cin >> tempColPosition;
    
        for(int i = 0; i < 3; i++) {

            for(int j = 0; j < 3; j++) {

                //If there is a spot available and matches specific desired spot, place it
                if(i == tempRowPosition && j == tempColPosition && tempBoard[i][j] == ' ') { 
                    tempBoard[i][j] = tempPlayer;
                    tempCurrentTurnComplete = true;
                }
                //If spot is already occupied, meaning not available, change to false and not allow the next player to continue
                else if(i == tempRowPosition && j == tempColPosition && tempBoard[i][j] != ' ') { 
                    cout << "This cell is already occupied. Try a different cell" << endl;
                    tempCurrentTurnComplete = false;
                }
            }
        }
    
    //If the current player hasn't placed anything or is placing at wrong spot will tell user to pick another spot,
    //Will run again, until the user has placed in available spot
    if(tempCurrentTurnComplete == false) {
       makeAMove(tempBoard, tempPlayer);
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
    cout << " -------------" << endl;
}





