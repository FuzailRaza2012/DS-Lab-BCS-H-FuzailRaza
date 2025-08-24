#include <iostream>
#include <string>

using namespace std;

class BankAccount{
	public:
		float balance;
		
		BankAccount(){
			balance = 10;
			cout << "Balance: " << balance << endl;
		}
		
		BankAccount(int i){
			balance = i;
		}
		
		BankAccount(BankAccount &obj){
			balance = obj.balance;
			balance -= 200;
		}	
};

int main(){
	BankAccount account1;
	BankAccount account2(1000);
	BankAccount account3 = account2;
	
	cout << "Printing Balance of Account" << endl << "2: " << account2.balance << endl << "3: " << account3.balance << endl << "2: " << account2.balance << endl;
	
}
