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

int h(Node* n){
    return n ? n->height : 0;
}

int bal(Node* n){
    return n ? h(n->left) - h(n->right) : 0;
}

Node* rRotate(Node* y){
    cout << "Rotation: RIGHT on " << y->key << "\n";
    Node* x = y->left;
    Node* t = x->right;
    x->right = y;
    y->left = t;
    y->height = max(h(y->left), h(y->right)) + 1;
    x->height = max(h(x->left), h(x->right)) + 1;
    return x;
}

Node* lRotate(Node* x){
    cout << "Rotation: LEFT on " << x->key << "\n";
    Node* y = x->right;
    Node* t = y->left;
    y->left = x;
    x->right = t;
    x->height = max(h(x->left), h(x->right)) + 1;
    y->height = max(h(y->left), h(y->right)) + 1;
    return y;
}

Node* insertNode(Node* root, int key){
    if (!root){
        cout << "Inserted patient severity: " << key << "\n";
        return new Node(key);
    }

    if (key < root->key) root->left = insertNode(root->left, key);
    else if (key > root->key) root->right = insertNode(root->right, key);
    else return root;

    root->height = max(h(root->left), h(root->right)) + 1;

    int b = bal(root);
    if (b > 1 || b < -1)
        cout << "Tree became unbalanced at node " << root->key << "\n";

    if (b > 1 && key < root->left->key)
        return rRotate(root);

    if (b < -1 && key > root->right->key)
        return lRotate(root);

    if (b > 1 && key > root->left->key){
        root->left = lRotate(root->left);
        return rRotate(root);
    }

    if (b < -1 && key < root->right->key){
        root->right = rRotate(root->right);
        return lRotate(root);
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
        cout << "Discharged patient with severity: " << key << "\n";
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

    root->height = max(h(root->left), h(root->right)) + 1;
    int b = bal(root);

    if (b > 1 && bal(root->left) >= 0)
        return rRotate(root);

    if (b > 1 && bal(root->left) < 0){
        root->left = lRotate(root->left);
        return rRotate(root);
    }

    if (b < -1 && bal(root->right) <= 0)
        return lRotate(root);

    if (b < -1 && bal(root->right) > 0){
        root->right = rRotate(root->right);
        return lRotate(root);
    }

    return root;
}

Node* getMax(Node* root){
    while (root && root->right) root = root->right;
    return root;
}

void printHeight(Node* root){
    cout << "Tree height: " << h(root) << "\n";
}

int main(){
    Node* root = NULL;

    int arrivals[] = {50, 20, 70, 10, 30, 60, 90, 80};
    int discharge[] = {30, 70, 10};

    for (int x : arrivals){
        root = insertNode(root, x);
        printHeight(root);
        Node* m = getMax(root);
        if (m) cout << "Most critical patient severity: " << m->key << "\n\n";
    }

    for (int x : discharge){
        root = deleteNode(root, x);
        printHeight(root);
        Node* m = getMax(root);
        if (m) cout << "Most critical patient severity: " << m->key << "\n\n";
        else cout << "No patients remaining.\n\n";
    }

    return 0;
}
