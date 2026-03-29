#include "Tree.h"
#include <iostream>
#include <string>

using namespace std;



void ShowTree(Node* root, int level) {
    if (root) {
        ShowTree(root->right, level + 1);
        for (int i = 0; i < level; i++) cout << "    ";
        cout << root->key << endl;
        ShowTree(root->left, level + 1);
    }
}


Node* CreateRootBST(datatype key) {
    Node* root = new Node;
    root->key = key;
    root->parent = nullptr;
    root->left = nullptr;
    root->right = nullptr;
    return root;
}


Node* SearchNodeBST(Node* root, datatype key) {
    if (root == nullptr || key == root->key)
        return root;
    if (key < root->key)
        return SearchNodeBST(root->left, key);
    return SearchNodeBST(root->right, key);
}

void InsertNodeBST(Node*& root, datatype key) {
    Node* y = nullptr;
    Node* x = root;

    while (x != nullptr) {
        y = x;
        if (key < x->key) x = x->left;
        else x = x->right;
    }

    Node* z = new Node;
    z->key = key;
    z->parent = y;
    z->left = z->right = nullptr;

    if (y == nullptr) root = z;
    else if (z->key < y->key) y->left = z;
    else y->right = z;
}

Node* Minimum(Node* x) {
    if (!x) return nullptr;
    while (x->left != nullptr) x = x->left;
    return x;
}

Node* Maximum(Node* x) {
    if (!x) return nullptr;
    while (x->right != nullptr) x = x->right;
    return x;
}

Node* SuccessorNodeBST(Node* x) {
    if (!x) return nullptr;
    if (x->right != nullptr) return Minimum(x->right);

    Node* y = x->parent;
    while (y != nullptr && x == y->right) {
        x = y;
        y = y->parent;
    }
    return y;
}

Node* PredecessorNodeBST(Node* x) {
    if (!x) return nullptr;
    if (x->left != nullptr) return Maximum(x->left);

    Node* y = x->parent;
    while (y != nullptr && x == y->left) {
        x = y;
        y = y->parent;
    }
    return y;
}

void Transplant(Node*& root, Node* u, Node* v) {
    if (u->parent == nullptr) root = v;
    else if (u == u->parent->left) u->parent->left = v;
    else u->parent->right = v;

    if (v != nullptr) v->parent = u->parent;
}

void DeleteNodeBST(Node*& root, Node* z) {
    if (!z) return;

    if (z->left == nullptr)
        Transplant(root, z, z->right);
    else if (z->right == nullptr)
        Transplant(root, z, z->left);
    else {
        Node* y = Minimum(z->right);
        if (y->parent != z) {
            Transplant(root, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        Transplant(root, z, y);
        y->left = z->left;
        y->left->parent = y;
    }
    delete z;
}