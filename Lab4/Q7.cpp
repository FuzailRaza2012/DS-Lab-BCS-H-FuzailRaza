#include <iostream>

using namespace std;

void bubbleSort(int arr[], int n, int &comparisons, int &swaps){
    comparisons = 0;
	swaps = 0;
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            comparisons++;
            if (arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swaps++;
            }
        }
    }
}

void insertionSort(int arr[], int n, int &comparisons, int &swaps){
    comparisons = 0;
	swaps = 0;
    for (int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;
        while (j >= 0){
            comparisons++;
            if (arr[j] > key){
                arr[j+1] = arr[j];
                swaps++;
                j--;
            }
			else{
				break;
			} 
        }
        arr[j+1] = key;
    }
}

void shellSort(int arr[], int n, int &comparisons, int &swaps){
    comparisons = 0;
	swaps = 0;
    for (int gap = n/2; gap > 0; gap /= 2){
        for (int i = gap; i < n; i++){
            int temp = arr[i];
            int j = i;
            while (j >= gap){
                comparisons++;
                if (arr[j-gap] > temp){
                    arr[j] = arr[j-gap];
                    swaps++;
                    j -= gap;
                }
				else{
                	break;
				}
            }
            arr[j] = temp;
        }
    }
}

int main(){
    int n;
    cout << "Array size: ";
    cin >> n;

    int arr[1000];
    for (int i = 0; i < n; i++){
        cout << "Enter number: ";
		cin >> arr[i];
    }

    int arr1[1000], arr2[1000], arr3[1000];
    for (int i = 0; i < n; i++){
        arr1[i] = arr[i];
        arr2[i] = arr[i];
        arr3[i] = arr[i];
    }

    int comp, swp;

    bubbleSort(arr1, n, comp, swp);
    cout << "Bubble Sort: Comparisons: " << comp << ", Swaps: " << swp << endl;

    insertionSort(arr2, n, comp, swp);
    cout << "Insertion Sort: Comparisons: " << comp << ", Swaps: " << swp << endl;

    shellSort(arr3, n, comp, swp);
    cout << "Shell Sort: Comparisons: " << comp << ", Swaps: " << swp << endl;

}
