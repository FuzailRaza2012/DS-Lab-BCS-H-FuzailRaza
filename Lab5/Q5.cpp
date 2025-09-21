#include <iostream>

using namespace std;

const int SIZE = 9;

void showBoard(int board[SIZE][SIZE]){
    for (int r = 0; r < SIZE; r++){
        for (int c = 0; c < SIZE; c++){
            cout << board[r][c] << " ";
        }
        cout << endl;
    }
}

bool canPlace(int board[SIZE][SIZE], int row, int col, int guess){
    for (int x = 0; x < SIZE; x++){
        if (board[row][x] == guess){
        	return false;	
		} 
    }
    for (int x = 0; x < SIZE; x++){
        if (board[x][col] == guess){
        	return false;	
		}
    }
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int r = 0; r < 3; r++){
        for (int c = 0; c < 3; c++){
            if (board[startRow + r][startCol + c] == guess){
            	return false;
			}
        }
    }
    return true;
}

bool findEmpty(int board[SIZE][SIZE], int &row, int &col){
    for (row = 0; row < SIZE; row++){
        for (col = 0; col < SIZE; col++){
            if (board[row][col] == 0){
            	return true;
			}
        }
    }
    return false;
}

bool solveSudoku(int board[SIZE][SIZE]){
    int row, col;
    if (!findEmpty(board, row, col)){
		return true;
	} 
    for (int guess = 1; guess <= 9; guess++){
        if (canPlace(board, row, col, guess)){
            board[row][col] = guess;
            if (solveSudoku(board)){
            	return true;	
			}
            board[row][col] = 0;
        }
    }
    return false;
}

int main(){
    int board[SIZE][SIZE] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    if (solveSudoku(board)){
        cout << "Solved Sudoku:\n";
        showBoard(board);
    } else {
        cout << "No solution exists!";
    }
    return 0;
}
