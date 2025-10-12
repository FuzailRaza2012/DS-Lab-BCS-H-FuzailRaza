#include <iostream>
#include <string>
using namespace std;

struct Node {
    string url;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    void push(string link) {
        Node* newNode = new Node;
        newNode->url = link;
        newNode->next = top;
        top = newNode;
        cout << "Visited: " << link << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "No previous page!" << endl;
            return;
        }
        Node* temp = top;
        cout << "Going back from: " << top->url << endl;
        top = top->next;
        delete temp;
    }

    void peek() {
        if (isEmpty())
            cout << "No pages open!" << endl;
        else
            cout << "Current page: " << top->url << endl;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    ~Stack() {
        while (!isEmpty())
            pop();
    }
};

int main() {
    Stack history;

    history.push("www.abc.com");
    history.push("www.xyz.com");

    history.peek();
    history.pop();
    history.peek();
    history.pop();
    history.pop();
    

    return 0;
}
