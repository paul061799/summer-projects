#ifndef AVLTREE_H
#define AVLTREE_H

#include "Node.h"

class AVLTree{
    private:
        Node* root;
        
        Node* findUnbalancedNode() const;
        void rotate(Node*);
        Node* rotateLeft(Node*);
        Node* rotateRight(Node*);
        void printBalanceFactors(Node *) const;
        void visualizeTree(ofstream &, Node *);
        void inOrder(Node*) const;
        Node* findUnbalancedNode(Node*) const;
       //Helper functions  
        int height(Node*)const;
        bool search(const string&,Node*)const;
        Node* searchNode(const string&, Node*)const;
    public:
    
        AVLTree();
        void insert(const string &);
        int balanceFactor(Node*);
        void printBalanceFactors() const;
        void visualizeTree(const string &);
        
        int height(const string&)const;
        bool search(const string &) const;
};

#endif