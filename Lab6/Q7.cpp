#include <iostream>
#include <string>

using namespace std;

struct Process{
    int id;
    int priority;
};

class Queue{
    Process arr[100];
    int front, rear;
public:
    Queue(){ 
		front = 0; 
		rear = -1; 
	}
	
    bool empty(){ 
		return front > rear; 
	}
	
    void enqueue(Process p){
    	arr[++rear] = p; 
	}
	
    Process dequeue(){  
		return arr[front++];
	}
	
    Process peek(){  
		return arr[front];
	}
	
};

class Stack{
    Process arr[100];
    int topIndex;
public:
    Stack(){  
		topIndex = -1;
	}
	
    bool empty(){ 
		return topIndex == -1; 
	}
	
    void push(Process p){ 
		arr[++topIndex] = p; 
	}
	
    Process pop(){ 
		return arr[topIndex--]; 
	}
	
    Process top(){  
		return arr[topIndex];
	}
	
};

int main(){
    Queue jobQueue;
    Stack highPriorityStack;
    int n;

    cout << "Enter number of processes: ";
    cin >> n;

    for (int i = 0; i < n; i++){
        Process p;
        cout << "\nEnter Process ID: ";
        cin >> p.id;
        cout << "Enter Priority (1=High, 2=Normal, 3=Low): ";
        cin >> p.priority;
        jobQueue.enqueue(p);
    }

    cout << "\n--- Processes Arrived (Queue Order) ---\n";
    Queue tempQueue = jobQueue;
    while (!tempQueue.empty()){
        Process p = tempQueue.dequeue();
        cout << "Process ID: " << p.id << " | Priority: " << p.priority << endl;
    }

    cout << "\n--- Scheduling Execution ---\n";
    while (!jobQueue.empty()){
        Process p = jobQueue.dequeue();
        if (p.priority == 1)
            highPriorityStack.push(p);
        else
            cout << "Executing Normal/Low Priority Process (Queue): ID=" << p.id << endl;
    }

    while (!highPriorityStack.empty()){
        Process p = highPriorityStack.pop();
        cout << "Executing High Priority Process (Stack): ID=" << p.id << endl;
    }

    cout << "\n--- Scheduling Complete ---\n";
    return 0;
}
