#include <iostream>

using namespace std;

int main(){
    int n;
    cout << "Enter number of months: ";
    cin >> n;

    float* expenses = new float[n];

    cout << "Enter expenses for " << n << " months:" << endl;
    for (int i = 0; i < n; i++){
        cin >> expenses[i];
    }

    char choice;
    cout << "Do you want to add more months? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y'){
        int extra;
        cout << "How many more months do you want to add? ";
        cin >> extra;

        float* newArr = new float[n+extra];
        
        for (int i = 0; i < n; i++){
            newArr[i] = expenses[i];
        }

        cout << "Enter expenses for " << extra << " more months:" << endl;
        for (int i = n; i < n + extra; i++){
            cin >> newArr[i];
        }

        delete[] expenses;
        expenses = newArr;
        n += extra;
    }

    float total=0;
    for (int i = 0; i < n; i++){
        total += expenses[i];
    }
    
    float average = total/n;

    cout << "Total expenses: " << total << endl;
    cout << "Average expenses: " << average << endl;

    delete[] expenses;
}
