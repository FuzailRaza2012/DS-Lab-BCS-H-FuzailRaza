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
    Node* x = y->left;
    Node* t = x->right;
    x->right = y;
    y->left = t;
    y->height = max(h(y->left), h(y->right)) + 1;
    x->height = max(h(x->left), h(x->right)) + 1;
    return x;
}

Node* lRotate(Node* x){
    Node* y = x->right;
    Node* t = y->left;
    y->left = x;
    x->right = t;
    x->height = max(h(x->left), h(x->right)) + 1;
    y->height = max(h(y->left), h(y->right)) + 1;
    return y;
}

Node* insertNode(Node* root, int key){
    if (!root) return new Node(key);

    if (key < root->key) root->left = insertNode(root->left, key);
    else if (key > root->key) root->right = insertNode(root->right, key);
    else return root;

    root->height = max(h(root->left), h(root->right)) + 1;
    int b = bal(root);

    if (b > 1 && key < root->left->key) return rRotate(root);
    if (b < -1 && key > root->right->key) return lRotate(root);

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

void rangeQuery(Node* root, int L, int R){
    if (!root) return;
    if (root->key > L) rangeQuery(root->left, L, R);
    if (root->key >= L && root->key <= R) cout << root->key << " ";
    if (root->key < R) rangeQuery(root->right, L, R);
}

int main(){
    Node* root = NULL;

    int prices[] = {1200, 500, 999, 2000, 1500, 750, 1800};
    for (int p : prices) root = insertNode(root, p);

    int x, y;
    cout << "Enter X: ";
    cin >> x;
    cout << "Enter Y: ";
    cin >> y;

    cout << "Prices between " << x << " and " << y << ": ";
    rangeQuery(root, x, y);
    cout << "\n";
}
