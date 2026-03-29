#pragma once

typedef int datatype;

struct Node {
    datatype key;   
    Node* parent;   
    Node* left;   
    Node* right;  
};



void ShowTree(Node* root, int level);
Node* CreateRootBST(datatype key);
Node* SearchNodeBST(Node* root, datatype key);
void InsertNodeBST(Node*& root, datatype key);
Node* SuccessorNodeBST(Node* x);
Node* PredecessorNodeBST(Node* x);
void DeleteNodeBST(Node*& root, Node* z);

Node* Minimum(Node* x);
Node* Maximum(Node* x);