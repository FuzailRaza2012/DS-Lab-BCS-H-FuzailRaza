#include <iostream>

using namespace std;

int main(){
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    int** a = new int*[rows];
    int** b = new int*[rows];
    int** sum = new int*[rows];
    int** diff = new int*[rows];

    for (int i = 0; i < rows; i++){
        a[i] = new int[cols];
        b[i] = new int[cols];
        sum[i] = new int[cols];
        diff[i] = new int[cols];
    }

    cout << "Enter values of Matrix a:" << endl;
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            cin >> a[i][j];
        }
    }

    cout << "Enter values of Matrix B:" << endl;
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            cin >> b[i][j];
        }
    }

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            sum[i][j] = a[i][j] + b[i][j];
            diff[i][j] = a[i][j] - b[i][j];
        }
    }
    
    cout << "Sum of Matrix a and b: " << endl;
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            cout << sum[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Difference of Matrix a and b: " << endl;
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            cout << diff[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < rows; i++){
        delete[] a[i];
        delete[] b[i];
        delete[] sum[i];
        delete[] diff[i];
    }
    delete[] a;
    delete[] b;
    delete[] sum;
    delete[] diff;

    return 0;
}
