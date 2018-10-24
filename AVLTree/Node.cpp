#include <iostream>

#include "Node.h"

using namespace std;

Node::Node(){
    left = 0;
    right = 0;
    parent = 0;
    data = "";
    balanceFactor = 0;
    ctr = 0;
}

Node::Node(const string & str){
    left = 0;
    right = 0;
    parent = 0;
    data = str;
    balanceFactor = 0;
    ctr = 0;
}

bool Node::isLeaf() const{
    return !left && !right;
}