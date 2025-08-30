#include <iostream>
#include <string>

using namespace std;

int main(){
	int a;
	
	cout << "Enter the number of indexes: " << endl;
	cin >> a;
	
	int *arr = new int[a];
	
	for (int i = 0; i < a; i++){
		arr[i] = 0;
	}
	
	for (int i = 0; i < a; i++){
        cout << "Enter value for index " << i << ": " << endl;
        cin >> arr[i];
    }

    cout << "Final array: ";
    for (int i = 0; i < a; i++) {
        cout << arr[i] << " ";
    }
    
    cout << endl;

    delete[] arr;
    return 0;
}
	
}
