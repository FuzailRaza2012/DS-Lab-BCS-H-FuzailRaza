#include <iostream>
#include <string>

using namespace std;

int sumTail(int n, int total){
	if (n == 1){
		return total + 1;
	}
	else if (n == 0){
		return total;
	}
	else{
		sumTail(n - 1, total + n);
	}
}

int main(){
	int x;
	
	cout << "Enter Number: " << endl;
	cin >> x;
	
	cout << "The Sum is: " << sumTail(x, 0) << endl;
	
}
