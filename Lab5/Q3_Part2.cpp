#include <iostream>
#include <string>

using namespace std;

int sumNonTail(int n){
	if (n == 1){
		return 1;
	}
	else if (n == 0){
		return 0;
	}
	else{
		return n + sumNonTail(n - 1);
	}
}

int main(){
	int x;
	
	cout << "Enter Number: " << endl;
	cin >> x;
	
	cout << "The Sum is: " << sumNonTail(x) << endl;
	
}
