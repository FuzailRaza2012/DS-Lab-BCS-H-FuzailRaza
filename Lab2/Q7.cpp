#include <iostream>

using namespace std;

int main(){
    int departments;
    cout << "Number of departments in the company: ";
    cin >> departments;

    float** salaries = new float*[departments];
    int* employees = new int[departments];

    for(int d = 0; d < departments; d++){
        cout << "Number of employees in department " << d+1 << ": ";
        cin >> employees[d];
        salaries[d] = new float[employees[d]];

        cout << "Enter the salaries for department " << d+1 << ": ";
        for (int e = 0; e < employees[d]; e++){
            cin >> salaries[d][e];
        }
    }
    cout << endl;
    
    for (int d = 0; d < departments; d++){
        float topSalary = salaries[d][0];
        
        for (int e = 1; e < employees[d]; e++){
            if (salaries[d][e] > topSalary){
                topSalary = salaries[d][e];
            }
        }
        cout << "Department " << d+1 << " highest salary: " << topSalary << endl;
    }

    int bestDept = 0;
    float bestAvg = 0;
    for (int d = 0; d < departments; d++){
        float sum = 0;
        for (int e = 0; e < employees[d]; e++){
            sum += salaries[d][e];
        }
        
        float avg = sum / employees[d];
        if (avg > bestAvg){
            bestAvg = avg;
            bestDept = d;
        }
    }

    cout << "Department " << bestDept + 1 << " has the best average salary of " << bestAvg << endl;

    for (int d = 0; d < departments; d++){
        delete[] salaries[d];
    }
    
    delete[] salaries;
    delete[] employees;
}
