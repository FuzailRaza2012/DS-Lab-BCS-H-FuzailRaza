#include <iostream>

using namespace std;

int main(){
    int rows, cols;
    cout << "Enter number of benches (rows): ";
    cin >> rows;
    cout << "Enter number of seats per bench (columns): ";
    cin >> cols;

    int** seats = new int*[rows];
    
    for (int i = 0; i < rows; i++){
        seats[i] = new int[cols];
    }

    cout << "Enter seating chart (0 for empty, 1 for occupied): " << endl;
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            cin >> seats[i][j];
        }
    }
    
    cout << endl;
    
    cout << "Final Seating Chart: " << endl;
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            cout << seats[i][j] << " ";
        }
		cout << endl;
    }

    for (int i = 0; i < rows; i++){
        delete[] seats[i];
    }
    
    delete[] seats;
}
