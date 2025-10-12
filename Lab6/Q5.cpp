#include <iostream>
#include <string>

using namespace std;

class CharStack{
    char arr[100];
    int topIndex;
public:
    CharStack(){ 
		topIndex = -1; 
	}
	
    void push(char c){
		arr[++topIndex] = c;
	}
	
    char pop(){
		return arr[topIndex--]; 
	}
	
    char top(){ 
		return arr[topIndex];
	}
	
    bool empty(){ 
		return topIndex == -1; 
	}
};

class IntStack{
    int arr[100];
    int topIndex;
public:
    IntStack(){ 
		topIndex = -1;
	}
	
    void push(int n){ 
		arr[++topIndex] = n; 
	}
	
    int pop(){ 
		return arr[topIndex--]; 
	}
	
    int top(){ 
		return arr[topIndex]; 
	}
	
    bool empty(){ 
		return topIndex == -1; 
	}
};

int precedence(char op){
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

int applyOp(int a, int b, char op){
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return a / b;
    if (op == '^'){
        int res = 1;
        for (int i = 0; i < b; i++) res *= a;
        return res;
    }
    return 0;
}

string infixToPostfix(string infix){
    CharStack st;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++){
        char c = infix[i];
        if (c == ' ') continue;
        if (c >= '0' && c <= '9') postfix += c;
        else if (c == '(') st.push(c);
        else if (c == ')'){
            while (!st.empty() && st.top() != '('){
                postfix += st.top();
                st.pop();
            }
            st.pop();
        } else {
            while (!st.empty() && precedence(st.top()) >= precedence(c)){
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()){
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int evaluatePostfix(string postfix){
    IntStack st;

    for (int i = 0; i < postfix.length(); i++){
        char c = postfix[i];
        if (c >= '0' && c <= '9'){
            st.push(c - '0');
        } else {
            int val2 = st.pop();
            int val1 = st.pop();
            st.push(applyOp(val1, val2, c));
        }
    }
    return st.top();
}

int main(){
    string infix;
    cout << "Enter infix expression (single digits only): ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix Expression: " << postfix << endl;

    int result = evaluatePostfix(postfix);
    cout << "Evaluated Result: " << result << endl;

    return 0;
}
