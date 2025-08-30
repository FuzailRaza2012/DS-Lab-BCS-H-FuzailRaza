#include <iostream>

using namespace std;

int main(){
    int totalCategories;
    cout << "Enter number of categories: ";
    cin >> totalCategories;

    string* categoryName = new string[totalCategories];
    int* totalBooks = new int[totalCategories];
    int** books = new int*[totalCategories];

    for (int i = 0; i < totalCategories; i++){
        cout << "Enter name of category " << i + 1 << ": ";
        cin >> categoryName[i];

        cout << "Enter number of books in " << categoryName[i] << ": ";
        cin >> totalBooks[i];

        books[i] = new int[totalBooks[i]];
        cout << "Enter book IDs for " << categoryName[i] << ":" << endl;
        for (int j = 0; j < totalBooks[i]; j++){
            cin >> books[i][j];
        }
    }

    int searchId;
    cout << "Enter book ID to search: ";
    cin >> searchId;

    string foundIn = "";
    for (int i = 0; i < totalCategories; i++){
        for (int j = 0; j < totalBooks[i]; j++){
            if (books[i][j] == searchId){
                foundIn = categoryName[i];
            }
        }
    }

    if (foundIn != "")
        cout << "Book found in category: " << foundIn << endl;
    else
        cout << "Book not available" << endl;

    for (int i = 0; i < totalCategories; i++){
        delete[] books[i];
    }
    
    delete[] books;
    delete[] totalBooks;
    delete[] categoryName;
    
}
