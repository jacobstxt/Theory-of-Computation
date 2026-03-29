#pragma once

typedef int datatype;

struct Node {
    datatype key;  
    Node* parent;
    Node* left;
    Node* right;
};


Node* CreateTree(int n, Node* p = nullptr);
void ShowTree(Node* root, int level);
void PreOrder(Node* root);
void InOrder(Node* root);
void PostOrder(Node* root);


