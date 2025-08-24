#include <iostream>
using namespace std;

class Box {
public:
    int* number;

    Box(){
        number = new int(0);
    }

    Box(int i){
        number = new int(i);
    }

    Box(const Box& obj){
        number = new int(*obj.number);
        cout << "Deep Copy Constructor called" << endl;
    }

    ~Box(){
        delete number;
    }

    void operator=(const Box& other){
        if (this != &other){
            delete number;
            number = new int(*other.number);
        }
        cout << "Copied using assignment operator" << endl;
    }

    void setNum(int i){
        *number = i;
    }

    int getNum(){
        return *number;
    }
};

int main() {
    cout << "Deep Copy: " << endl;
    
    Box a(10);
    Box b = a;
    b.setNum(20);
    
    cout << "a: " << a.getNum() << endl << "b: " << b.getNum() << endl;
    
    Box c;
    c = a;
    cout << "a: " << a.getNum() << endl << "c: " << c.getNum() << endl;

	cout << "Shallow Copy: " << endl;

    Box* d = new Box(50);
    Box* e = d;

    cout << "d: " << d->getNum() << endl << "e: " << e->getNum() << endl;
    e->setNum(99);
    cout << "After changing e: " << endl;
    cout << "d: " << d->getNum() << endl << "e: " << e->getNum() << endl;

    delete d;
}
