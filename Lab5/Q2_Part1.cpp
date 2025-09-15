#include <iostream>
#include <string>

using namespace std;

void printNumbers(int n){
	if (n == 1){
		cout << n;
		return;
	}
	else{
		cout << n << ", ";
		printNumbers(n - 1);
	}
}

int main(){
	int x;
	
	cout << "Enter Number: " << endl;
	cin >> x;
	
	cout << "The Number order is: ";
	printNumbers(x);
}
