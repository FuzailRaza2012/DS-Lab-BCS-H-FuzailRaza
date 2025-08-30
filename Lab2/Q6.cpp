#include <iostream>

using namespace std;

class SafePointer{
	private:
	    int* ptr;
	    
	public:
	    SafePointer(){
	        ptr = nullptr;
	    }
	
	    SafePointer(int size){
	        ptr = new int[size];
	    }
	
	    void setValue(int index, int value){
	        if (ptr != nullptr){
	            ptr[index] = value;
	        }
	    }
	
	    int getValue(int index){
	        if (ptr != nullptr){
	            return ptr[index];
	        }
	        return 0;
	    }
	
	    void release(){
	        delete[] ptr;
	        ptr = nullptr;
	    }
	
	    ~SafePointer(){
	        release();
	    }
};

int main(){
    int n = 5;
    SafePointer marks(n);

    cout << "Enter marks of " << n << " students:" << endl;
    for (int i = 0; i < n; i++){
        int val;
        cin >> val;
        marks.setValue(i, val);
    }

    cout << "Marks of students:" << endl;
    for (int i = 0; i < n; i++){
        cout << marks.getValue(i) << " ";
    }
    cout << endl;

    return 0;
}
