#include <iostream>

using namespace std;

class Queue{
private:
    int arr[5];
    int front, rear;

public:
    Queue(){
        front = -1;
        rear = -1;
    }

    bool isFull(){
        return rear == 4;
    }

    bool isEmpty(){
        return front == -1 || front > rear;
    }

    void enqueue(int value){
        if (isFull()){
            cout << "Queue is full!" << endl;
            return;
        }
        if (front == -1)
            front = 0;
        rear++;
        arr[rear] = value;
        cout << value << " enqueued." << endl;
    }

    void dequeue(){
        if (isEmpty()){
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << arr[front] << " dequeued." << endl;
        front++;
    }

    void display(){
        if (isEmpty()){
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue contents: ";
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main(){
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.dequeue();
    q.display();
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.display();
    return 0;
}
