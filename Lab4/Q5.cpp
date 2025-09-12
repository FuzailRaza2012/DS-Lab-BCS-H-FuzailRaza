#include <iostream>

using namespace std;

int main(){
    int n;
    cout << "Array size: ";
    cin >> n;

    int arr[1000];
    for (int i = 0; i < n; i++){
    	cout << "Enter sorted numbers: ";
        cin >> arr[i];
    }

    int target;
    cout << "Target number: ";
    cin >> target;

    int low = 0, high = n - 1, found = -1;

    while (low <= high && target >= arr[low] && target <= arr[high]){
        if (low == high){
            if(arr[low] == target) found = low;
            break;
        }

        int pos = low + ((double)(target - arr[low]) * (high - low) / (arr[high] - arr[low]));

        if (arr[pos] == target){
            found = pos;
            break;
        }
        if( arr[pos] < target){
            low = pos + 1;
        } 
		else{
            high = pos - 1;
        }
    }

    if (found != -1){
        cout << "Found num at index: " << found << endl;
    }
	else{
        cout << "Number not found" << endl;
    }
}
