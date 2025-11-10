#include <iostream>

using namespace std;

struct Node{
	Node* mother;
	Node* father;
	string name;
	
	Node (string n){
		mother = father = nullptr;
		name = n;
	}
};

Node* createNode(string n){
	return new Node(n);
}

int height(Node* r){
	if (r == nullptr){
		return 0;
	}
	else{
		return 1 + max(height(r->father), height(r->mother));
	}
}

void printLevel(Node* r, int i){
	if (r == nullptr){
		return;
	}
	if (i == 0 || i == -1){
		cout << r->name << ". ";
		return;
	}
	else{
		printLevel(r->mother, i - 1);
		printLevel(r->father, i - 1);
		return;
	}
}


void level(Node* child){
	int h = height(child);
	
	for (int i = 0; i < h; i++){
		cout << "Level: " << i << endl;
		printLevel(child, i);
		cout << endl;
	}
	return;
}

void leafNodes(Node* r){
	if (r->father == nullptr && r->mother == nullptr){
		cout << r->name << ". ";
		return;
	}
	else{
		leafNodes(r->mother);
		leafNodes(r->father);
		return;
	}
}


int main(){
	Node* child = createNode("Wilt Chamberlain");
	child->father = createNode("Hakeem Olajuwan");
	child->mother = createNode("Ayesha");
	child->mother->mother = createNode("Eliza");
	child->mother->father = createNode("Lebron James");
	child->father->mother = createNode("Stephanie");
	child->father->father = createNode("Shai Gilgious Alexander");
	
	cout << "Root is: " << child->name << endl;
	
	cout << "Leaf Nodes are: ";
	leafNodes(child);
	cout << endl;
	
	cout << "The Height is: " << height(child) << endl; 
	
	level(child);
}
