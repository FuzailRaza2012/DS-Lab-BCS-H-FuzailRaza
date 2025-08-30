#include <iostream>

using namespace std;

int main(){
    int students;
    cout << "Enter number of students: ";
    cin >> students;

    float** marks = new float*[students];
    int* courses = new int[students];

    for (int i = 0; i < students; i++){
        cout << "Enter number of courses for student " << i + 1 << ": ";
        cin >> courses[i];

        marks[i] = new float[courses[i]];
        cout << "Enter marks for " << courses[i] << " courses: ";
        for (int j = 0; j < courses[i]; j++){
            cin >> marks[i][j];
        }
    }

    cout << "Student Averages:" << endl;
    for (int i = 0; i < students; i++){
        float sum = 0;
        for (int j = 0; j < courses[i]; j++){
            sum += marks[i][j];
        }
        float avg = sum / courses[i];
        cout << "Student " << i + 1 << " average: " << avg << endl;
    }

    for (int i = 0; i < students; i++){
        delete[] marks[i];
    }
    delete[] marks;
    delete[] courses;
}
