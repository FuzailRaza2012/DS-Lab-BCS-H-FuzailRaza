#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    cout << "Array size: ";
    cin >> n;

    int arr[1000];
    for (int i = 0; i < n; i++){
        cout << "Enter number: ";
		cin >> arr[i];
    }

    cout << "Unsorted array: ";
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
