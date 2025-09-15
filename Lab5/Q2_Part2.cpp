#include <iostream>
#include <string>

using namespace std;

void functionB(int n);

void functionA(int n){
	if (n == 1){
		cout << n;
		return;
	}
	else{
		cout << n << ", ";
		functionB(n - 1);
	}
}

void functionB(int n){
	if (n == 1){
		cout << n;
		return;
	}
	else{
		cout << n << ", ";
		functionA(n - 1);
	}
}

int main(){
	int x;
	
	cout << "Enter Number: " << endl;
	cin >> x;
	
	cout << "The Number order is: ";
	functionA(x);
}
