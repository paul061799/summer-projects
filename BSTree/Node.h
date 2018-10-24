#ifndef NODE_H
#define NODE_H

using namespace std;

class Node{
    private:
        Node* right;
        Node* left;
        string str;
        int ctr;
        
    public:
        Node();
        ~Node();
        Node(const string &);
        int getCount() const;
        const string & getString() const;
        void decrCount();
        void setString(const string &);
        void setCount(int);
        void incrCount();
        Node* getLeft() const;
        Node* getRight() const;
        void setLeft(Node*);
        void setRight(Node*);
        void deleteLeft();
        void deleteRight();
        void outputNode() const;
        bool isLeaf() const;
};

#endif