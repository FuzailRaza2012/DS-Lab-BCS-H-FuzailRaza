#include <iostream>
using namespace std;

class Node{
public:
    int id;
    Node* next;

    Node(int val){
        id = val;
        next = NULL;
    }
};

class Circular{
private:
    Node* head;
    Node* tail;

public:
    Circular(){
        head = NULL;
        tail = NULL;
    }

    void createList(int n){
        head = new Node(1);
        tail = head;

        for (int i = 2; i <= n; i++){
            Node* temp = new Node(i);
            tail->next = temp;
            tail = temp;
        }
        tail->next = head;
    }

    int survivor(int k){
        Node* ptr = head;
        Node* before = tail;

        while (ptr->next != ptr){
            for (int count = 1; count < k; count++){
                before = ptr;
                ptr = ptr->next;
            }

            before->next = ptr->next;

            if (ptr == head){
                head = ptr->next;
            }
            if (ptr == tail){
                tail = before;
            }

            Node* del = ptr;
            ptr = ptr->next;
            delete del;
        }

        int s = ptr->id;
        delete ptr;
        return s;
    }
};

int main(){
    int N = 7, K = 3;
    Circular circle;
    circle.createList(N);

    cout << "Survivor is at: " << circle.survivor(K) << endl;
    return 0;
}
