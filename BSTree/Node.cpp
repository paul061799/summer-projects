#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#include <climits>
#include <fstream>
#include <queue>
#include <stack>
#include <list>
#include <stdexcept>

#include "Node.h"

using namespace std;

Node::Node(){
    right = 0;
    left = 0;
    str = "";
    ctr = 0;
}

Node::Node(const string &data){
    right = 0;
    left = 0;
    str = data;
    ctr = 0;
}

Node::~Node(){
    delete left;
    delete right;
}

int Node::getCount() const{
    return ctr;
}

const string & Node::getString() const{
    return str;
}

void Node::decrCount(){
    ctr--;
}

void Node::setString(const string & data){
    str = data;
}

void Node::setCount(int count){
    ctr = count;
}

void Node::incrCount(){
    ctr++;
}

Node* Node::getLeft() const{
    return left;
}

Node* Node::getRight() const{
    return right;
}

void Node::deleteLeft(){
    left = 0;
}

void Node::deleteRight(){
    right = 0;
}

void Node::outputNode() const{
    cout << getString() << "(" << getCount() << "), ";
}

void Node::setLeft(Node* temp){
    left = temp;
}

void Node::setRight(Node* temp){
    right = temp;
}
bool Node::isLeaf() const{
    return !getLeft() && !getRight();
}