#include <iostream>
#include <string>

using namespace std;

int calculateFactorial(int n){
	if (n == 0 || n == 1){
		return 1;
	}
	else{
		return n * calculateFactorial(n-1);
	}
}

int main(){
	int x;
	
	cout << "Enter Number: " << endl;
	cin >> x;
	
	cout << "The factorial is: " << calculateFactorial(x) << endl;
}
