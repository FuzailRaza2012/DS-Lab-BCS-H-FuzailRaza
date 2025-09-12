#include <iostream>

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

    for (int i = 0; i < n - 1; i++){
        int minIndex = i;
        for (int j = i + 1; j < n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
