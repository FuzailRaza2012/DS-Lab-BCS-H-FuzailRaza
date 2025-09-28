#include <iostream>
#include <string>

using namespace std;

void printBoard(int** board, int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (board[i][j] == 1){
                cout << "1 ";
            }
            else{
                cout << "0 ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(int** board, int row, int col, int n){
    for (int i = 0; i < row; i++){
        if (board[i][col] == 1){
            return false;
        }
    }
    
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--){
        if (board[i][j] == 1){
            return false;
        }
    }
    
	for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++){
        if (board[i][j] == 1){
            return false;
        }
    }
    
    return true;
}

void solveNQueens(int** board, int row, int n){
    if (row == n){
        printBoard(board, n);
        return;
    }
    
    for (int col = 0; col < n; col++){
        if (isSafe(board, row, col, n)){
            board[row][col] = 1;
            solveNQueens(board, row + 1, n);
            board[row][col] = 0;
        }
    }
}

int main(){
    int n;
    cout << "Enter value of N: ";
    cin >> n;
    
    int** board = new int*[n];
    for (int i = 0; i < n; i++){
        board[i] = new int[n];
        for (int j = 0; j < n; j++){
            board[i][j] = 0;
        }
    }
    
    solveNQueens(board, 0, n);
    
    for (int i = 0; i < n; i++){
        delete[] board[i];
    }
    
    delete[] board;
}
