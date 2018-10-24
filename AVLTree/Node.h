#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

class Node{
    friend class AVLTree;
    private:
        Node* left;
        Node* right;
        Node* parent;
        string data;
        int balanceFactor;
        int ctr;
        
    public:
        Node();
        Node(const string &);
        bool isLeaf() const;
};

#endif