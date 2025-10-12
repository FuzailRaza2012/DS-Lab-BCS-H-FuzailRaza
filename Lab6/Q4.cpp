#include <iostream>
using namespace std;

class CircularQueue{
private:
    int arr[5];
    int front, rear, size;

public:
    CircularQueue(){
        front = -1;
        rear = -1;
        size = 5;
    }

    bool isFull(){
        return (front == 0 && rear == size - 1) || (rear + 1 == front);
    }

    bool isEmpty(){
        return front == -1;
    }

    void enqueue(int value){
        if (isFull()){
            cout << "Queue is full!" << endl;
            return;
        }
        if (isEmpty())
            front = 0;
        rear = (rear + 1) % size;
        arr[rear] = value;
        cout << value << " enqueued." << endl;
    }

    void dequeue(){
        if (isEmpty()){
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << arr[front] << " dequeued." << endl;
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % size;
    }

    void display(){
        if (isEmpty()){
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue contents: ";
        int i = front;
        while (true){
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main(){
    CircularQueue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.display();
    q.dequeue();
    q.dequeue();
    q.enqueue(60);
    q.enqueue(70);
    q.display();
    q.dequeue();
    q.display();
    return 0;
}
