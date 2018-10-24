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
#include <stdexcept>

#include "BSTree.h"
#include "Node.h"

using namespace std;

BSTree::BSTree(){
    root = 0;
}

void BSTree::insert(const string &nstr){
    Node* temp = new Node(nstr);
    if(!root){
        root = temp;
        root->incrCount();
        return;
    }
    Node* curr = root;
    while(curr->getString() != temp->getString()){
        if(temp->getString() < curr->getString()){
            if(!curr->getLeft()){
                curr->setLeft(temp);
                temp->incrCount();
                return;
            }
            curr = curr->getLeft();
        }
        else{
            if(!curr->getRight()){
                curr->setRight(temp);
                temp->incrCount();
                return;
            }
            curr = curr->getRight();
        }
    }
    curr->incrCount();
}

bool BSTree::search(const string &target) const{
    Node* curr = root;
    while(curr != 0){
        if(curr->getString() == target){
            return true;
        }
        else if(target < curr->getString()){
            curr = curr->getLeft();
        }
        else{
            curr = curr->getRight();
        }
    }
    return false;
}

string BSTree::largest() const{
    if(root == 0){
        return "";
    }
    return largest(root);
}

string BSTree::largest(Node* root) const{
    if(root->getRight()){
        return largest(root->getRight());
    }
    return root->getString();
}

string BSTree::smallest() const{
    if(root == 0){
        return "";
    }
    return smallest(root);
}

string BSTree::smallest(Node* root) const{
    if(root->getLeft()){
        return smallest(root->getLeft());
    }
    return root->getString();
}

int BSTree::height(const string &orig) const{
    if(!search(orig)){
        return -1;
    }
    Node* curr = findNode(orig);
    return nodeHeight(curr);
}
int BSTree::nodeHeight(Node* root) const{
    if(root == 0){
        return -1;
    }
    int leftHeight = nodeHeight(root->getLeft());
    int rightHeight = nodeHeight(root->getRight());
    if(leftHeight > rightHeight){
        return 1+ leftHeight;
    }
    return 1+ rightHeight;
}


void BSTree::preOrder() const{
    if(!root){
        return;
    }
    preOrder(root);
}

void BSTree::preOrder(Node* root) const{
    root->outputNode();
    if(root->getLeft()){
        preOrder(root->getLeft());
    }
    if(root->getRight()){
        preOrder(root->getRight());
    }
}

void BSTree::postOrder() const{
    if(!root){
        return;
    }
    postOrder(root);
}

void BSTree::postOrder(Node* root) const{
    if(root->getLeft()){
        postOrder(root->getLeft());
    }
    if(root->getRight()){
        postOrder(root->getRight());
    }
    root->outputNode();
}

void BSTree::inOrder() const{
    if(!root){
        return;
    }
    inOrder(root);
}

void BSTree::inOrder(Node* root) const{
    if(root->getLeft()){
        inOrder(root->getLeft());
    }
    root->outputNode();
    if(root->getRight()){
        inOrder(root->getRight());
    }
}

Node* BSTree::findNode(const string & target) const{
    Node* curr = root;
    while(curr->getString() != target){
        if(target < curr->getString()){
            curr = curr->getLeft();
        }
        else{
            curr = curr->getRight();
        }
    }
    return curr;
}

Node* BSTree::findParentNode(const string &target) const{
    Node* par = root;
    Node* curr = root;
    while(curr->getString() != target){
        if(target < curr->getString()){
            curr = curr->getLeft();
            if(curr->isLeaf()){
                return par;
            }
            
        }
        else{
            curr = curr->getRight();
            if(curr->isLeaf()){
                return par;
            }
            
        }
    }
    return par;
}

void BSTree::remove(const string &target){
    if(!search(target)){
        return;
    }
    Node* curr = findNode(target);
    if(curr->getCount() > 1){
        curr->decrCount();
        return;
    }
    Node* par = findParentNode(target);
    remove(curr, par);
}

void BSTree::remove(Node* tar, Node* parent){
    if(tar->getLeft() == 0 && tar->getRight() == 0){
        if(parent->getLeft() == tar){
            parent->deleteLeft();
            delete tar;
        }
        else if(parent->getRight() == tar){
            parent->deleteRight();
            delete tar;
        }
        else if(parent == tar){
            root = 0;
        }
    }
    else if(tar->getLeft() != 0){
        Node *temp = tar->getLeft();
        while(temp->getRight()!=0){
            temp = temp->getRight();
        }
        string str = temp->getString();
        int cnt = temp->getCount();
        //Node * p = findParentNode(str);
        remove(temp, tar);
        tar->setString(str);
        tar->setCount(cnt);
        
    }
    else if(tar->getRight() != 0){
        Node *temp = tar->getRight();
        while(temp->getLeft() != 0){
            temp = temp->getLeft();
        }
        string str = temp->getString();
        int cnt = temp->getCount();
        remove(temp, tar);
        tar->setString(str);
        tar->setCount(cnt);
    }

}
