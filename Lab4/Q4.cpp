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

    for (int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    int target;
    cout << "Target number: ";
    cin >> target;

    int low = 0, high = n - 1, found = -1;
    while (low <= high){
        int mid = (low + high) / 2;
        if (arr[mid] == target){
            found = mid;
            break;
        } 
		else if (arr[mid] < target){
            low = mid + 1;
        } 
		else{
            high = mid - 1;
        }
    }

    if (found != -1){
        cout << "Found num at index: " << found << endl;
    } 
	else{
        cout << "Number not found" << endl;
    }
}
