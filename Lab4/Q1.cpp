#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    cout << "Enter size: ";
    cin >> n;

    int arr[1000];
    
    for (int i = 0; i < n; i++){
    	cout << "Enter array number: ";
        cin >> arr[i];
    }

    int target;
    cout << "Which num find: ";
    cin >> target;

    int found = -1;
    for (int i = 0; i < n; i++){
        if (arr[i] == target){
            found = i;
            break;
        }
    }

    if (found != -1){
        cout << "Found Index: " << found << endl;
    }
	else{
        cout << "Not in array" << endl;
	}
}
