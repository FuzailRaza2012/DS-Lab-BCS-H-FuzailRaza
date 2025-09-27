#include <iostream>
#include <string>

using namespace std;

bool isSafe(int** arr, int x, int y, int n, int **solArr) {
    if (x < n && y < n && x >= 0 && y >= 0 && arr[x][y] == 1 && solArr[x][y] == 0){
        return true;
    }
    
    return false;
    
}

bool ratInMaze(int** arr, int x, int y, int n, int** solArr){
    if ((x == (n - 1)) && (y == (n - 1))){
        solArr[x][y] = 1;
        return true;
    }

    if (isSafe(arr, x, y, n, solArr)){
        solArr[x][y] = 1;

        if (ratInMaze(arr, x + 1, y, n, solArr)){
            return true;
        }
		
		if (ratInMaze(arr, x - 1, y, n, solArr)){
            return true;
        }
		
        if (ratInMaze(arr, x, y + 1, n, solArr)){
            return true;
        }
        
        if (ratInMaze(arr, x, y - 1, n, solArr)){
            return true;
        }

        solArr[x][y] = 0;
        
        return false;
        
    }

    return false;
    
}

int main(){
    int n;
    cout << "Enter size of maze: ";
    cin >> n;

    int** arr = new int*[n];
    for (int i = 0; i < n; i++){
        arr[i] = new int[n];
    }

    cout << "Enter the maze (0 means block, 1 means open): " << endl;
    for (int i = 0; i < n; i++){
    	cout << "Row number " << i + 1 << ": " << endl;
        for (int j = 0; j < n; j++){
        	cout << "Column number " << j + 1 << ": " << endl;
            cin >> arr[i][j];
        }
    }

    int** solArr = new int*[n];
    for (int i = 0; i < n; i++){
        solArr[i] = new int[n];
        for (int j = 0; j < n; j++){
            solArr[i][j] = 0;
        }
    }

    if (ratInMaze(arr, 0, 0, n, solArr)){
        cout << "Path found: " << endl;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cout << solArr[i][j] << " ";
            }
            cout << endl;
        }
    }
	else{
        cout << "No path exists!" << endl;
    }

    for (int i = 0; i < n; i++){
        delete[] arr[i];
        delete[] solArr[i];
    }
    delete[] arr;
    delete[] solArr;

    return 0;
}
