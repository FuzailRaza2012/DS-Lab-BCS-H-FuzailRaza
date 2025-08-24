#include <iostream>

using namespace std;

class Box{
	public:
		int *number;
		
		Box(){
			number = new int(0);
		}
		
		Box(int i){
			number = new int(i);
		}
		
		Box(Box &obj){
			number = new int(*obj.number);
		}
		
		~Box(){
			delete number;
		}
		
		void operator=(const Box& other){
			if (this != &other) {
        		delete number;
        		number = new int(*other.number);
    		}
			cout << "copied using assignment" << endl;		
		}
		
		void setNum(int i){
			*number = i;
		}
		
		int getNum(){
			return *number;
		}
};

int main(){
	Box x(10);
	Box y;
	
	cout << "X is: " << x.getNum() << " and Y is: " << y.getNum() << endl; 	
	
	x = y;
	
	
	cout << "Num of X is now: " << x.getNum() << " and Y is: " << y.getNum() << endl;endl;	
}
