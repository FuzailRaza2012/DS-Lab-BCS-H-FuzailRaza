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
		}	
};

int main(){
	BankAccount account1;
	
	cout << "Printing Balance of Account 1: " << account1.balance << endl;
	
	BankAccount account2(1000);
	BankAccount account3 = account2;
	
	account3.balance -= 200;
	
	cout << "Printing Balance of Account" << endl << "2: " << account2.balance << endl << "3: " << account3.balance << endl << "2: " << account2.balance << endl;
	
}
