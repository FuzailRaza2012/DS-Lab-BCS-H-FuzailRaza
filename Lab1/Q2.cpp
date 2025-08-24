#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Exam{
	public:
		char* studentName;
		char* examDate;
		int score;
		
		Exam(){
			studentName = NULL;
			examDate = NULL;
			score = 0;
		}
		
		Exam(const char* n, const char* d, int s){
			studentName = new char[strlen(n) + 1];
			strcpy(studentName, n);
			
			examDate = new char[strlen(d) + 1];
			strcpy(examDate, d);
			
			score = s;
		}
		
		void setDeets(const char* n, const char* d, int s){
			if (studentName == NULL || examDate == NULL){
				studentName = new char[strlen(n) + 1];
				strcpy(studentName, n);
			
				examDate = new char[strlen(d) + 1];
				strcpy(examDate, d);
			
				score = s;
				
				cout << "Details Inserted" << endl;
			}
			else{
				cout << "Details already Exist" << endl;
			}
		}
		
		void ShowDeets(){
			cout << "Details: " << endl;
			cout << "Name: " << studentName << endl;
			cout << "Exam date: " << examDate << endl;
			cout << "Score: " << score << endl;
		}
};

int main(){
	Exam exam2;
	Exam exam1("Fuzail Raza", "20-12-2024", 67);
	exam1.ShowDeets();
	
	exam2.setDeets("Sudheer Rathore", "27-08-2024", 67);
	exam2.ShowDeets();
}
