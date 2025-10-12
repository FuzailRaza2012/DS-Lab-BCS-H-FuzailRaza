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

bool isRightAssociative(char op){
    return (op == '^');
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

string reverseString(string s){
    string r = "";
    for (int i = s.length() - 1; i >= 0; i--) r += s[i];
    return r;
}

string infixToPrefix(string infix){
    CharStack st;
    string prefix = "";

    infix = reverseString(infix);

    for (int i = 0; i < infix.length(); i++){
        char c = infix[i];
        if (c == ' ') continue;

        if (c >= '0' && c <= '9') prefix += c;
        else if (c == ')') st.push(c);
        else if (c == '('){
            while (!st.empty() && st.top() != ')'){
                prefix += st.top();
                st.pop();
            }
            st.pop();
        } else {
            while (!st.empty() &&
                  ((precedence(st.top()) > precedence(c)) ||
                  (precedence(st.top()) == precedence(c) && !isRightAssociative(c))) &&
                  st.top() != ')'){
                prefix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()){
        prefix += st.top();
        st.pop();
    }

    prefix = reverseString(prefix);
    return prefix;
}

int evaluatePrefix(string prefix){
    IntStack st;
    for (int i = prefix.length() - 1; i >= 0; i--){
        char c = prefix[i];
        if (c >= '0' && c <= '9'){
            st.push(c - '0');
        } else {
            int val1 = st.pop();
            int val2 = st.pop();
            st.push(applyOp(val1, val2, c));
        }
    }
    return st.top();
}

int main(){
    string infix;
    cout << "Enter infix expression (single digits only): ";
    cin >> infix;

    string prefix = infixToPrefix(infix);
    cout << "Prefix Expression: " << prefix << endl;

    int result = evaluatePrefix(prefix);
    cout << "Evaluated Result: " << result << endl;

    return 0;
}
