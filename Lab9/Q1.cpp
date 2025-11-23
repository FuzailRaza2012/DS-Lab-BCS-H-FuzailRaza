#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
    Node(int k){
        key = k;
        left = right = NULL;
        height = 1;
    }
};

int getHeight(Node* n){
    return n ? n->height : 0;
}

int getBalance(Node* n){
    return n ? getHeight(n->left) - getHeight(n->right) : 0;
}

Node* rightRotate(Node* y){
    cout << "Rotation: RIGHT on " << y->key << "\n";
    Node* x = y->left;
    Node* t = x->right;
    x->right = y;
    y->left = t;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    return x;
}

Node* leftRotate(Node* x){
    cout << "Rotation: LEFT on " << x->key << "\n";
    Node* y = x->right;
    Node* t = y->left;
    y->left = x;
    x->right = t;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    return y;
}

Node* insertNode(Node* root, int key){
    if (!root){
        cout << "Inserted: " << key << "\n";
        return new Node(key);
    }
    if (key < root->key) root->left = insertNode(root->left, key);
   { if (key > root->key) root->right = insertNode(root->right, key);
    else return root;

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

    int bal = getBalance(root);
    cout << "Balance(" << root->key << ") = " << bal << "\n";

    if (bal > 1 && key < root->left->key)
        return rightRotate(root);

    if (bal < -1 && key > root->right->key)
        return leftRotate(root);

    if (bal > 1 && key > root->left->key){
        cout << "Rotation: LEFT on " << root->left->key << "\n";
        root->left = leftRotate(root->left);
        cout << "Rotation: RIGHT on " << root->key << "\n";
        return rightRotate(root);
    }

    if (bal < -1 && key < root->right->key){
        cout << "Rotation: RIGHT on " << root->right->key << "\n";
        root->right = rightRotate(root->right);
        cout << "Rotation: LEFT on " << root->key << "\n";
        return leftRotate(root);
    }

    return root;
}

Node* getMin(Node* n){
    while (n->left) n = n->left;
    return n;
}

Node* deleteNode(Node* root, int key){
    if (!root) return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        cout << "Deleted: " << key << "\n";
        if (!root->left || !root->right){
            Node* t = root->left ? root->left : root->right;
            delete root;
            return t;
        } else {
            Node* t = getMin(root->right);
            root->key = t->key;
            root->right = deleteNode(root->right, t->key);
        }
    }

    if (!root) return root;

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

    int bal = getBalance(root);
    cout << "Balance(" << root->key << ") after delete = " << bal << "\n";

    if (bal > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (bal > 1 && getBalance(root->left) < 0){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (bal < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (bal < -1 && getBalance(root->right) > 0){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void printH(Node* root){
    cout << "Tree Height: " << getHeight(root) << "\n\n";
}

int main(){
    Node* root = NULL;

    int add[] = {30, 20, 40, 10, 25, 35, 50};
    int del[] = {20, 40, 35};

    for (int x : add){
        root = insertNode(root, x);
        printH(root);
    }

    for (int x : del){
        root = deleteNode(root, x);
        printH(root);
    }

    return 0;
}
