#include "Tree.h"
#include <iostream>
#include <string>

using namespace std;



Node* CreateTree(int n, Node* p) {
    if (n <= 0) return nullptr;

    Node* newNode = new Node;
    cout << "Enter Value: ";
    cin >> newNode->key;
    newNode->parent = p; // Встановлюємо зв'язок з батьком

    int nl = n / 2;
    int nr = n - nl - 1;

    newNode->left = CreateTree(nl, newNode);
    newNode->right = CreateTree(nr, newNode);

    return newNode;
}

void ShowTree(Node* root, int level) {
    if (root) {
        ShowTree(root->right, level + 1);
        for (int i = 0; i < level; i++) cout << "    ";
        cout << root->key << endl;
        ShowTree(root->left, level + 1);
    }
}


void PreOrder(Node* root) {
    if (root) {
        cout << root->key << " ";
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void InOrder(Node* root) {
    if (root) {
        InOrder(root->left);
        cout << root->key << " ";
        InOrder(root->right);
    }
}

void PostOrder(Node* root) {
    if (root) {
        PostOrder(root->left);
        PostOrder(root->right);
        cout << root->key << " ";
    }
}



