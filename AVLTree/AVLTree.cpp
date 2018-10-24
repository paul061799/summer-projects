#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

#include "AVLTree.h"

using namespace std;

AVLTree::AVLTree(){
    root = 0;
}

void AVLTree::insert(const string &nstr){
    Node* temp = new Node(nstr);
    if(!root){
        root = temp;
        root->balanceFactor = balanceFactor(root);
        return;
    }
    Node* curr = root;
    while(curr->data != temp->data){
        if(temp->data < curr->data){
            if(!curr->left){
                curr->left = temp;
                temp->parent = curr;
                temp->balanceFactor = balanceFactor(temp);
                break;
            }
            curr = curr->left;
        }
        else{
            if(!curr->right){
                curr->right = temp;
                temp->parent = curr;
                temp->balanceFactor = balanceFactor(temp);
                break;
            }
            curr = curr->right;
        }
    }
    if(curr->data == temp->data){
        curr->ctr = curr->ctr + 1;
        return;
    }
    curr = root;
    while(curr != temp){
        curr->balanceFactor = balanceFactor(curr);
        if(temp->data < curr->data){
            curr = curr->left;
        }
        else{
            curr = curr->right;
        }
    }
    
    while(findUnbalancedNode() != 0){
        rotate(findUnbalancedNode());
    }
}

void AVLTree::rotate(Node* pivot){
    if(pivot->balanceFactor > 1){
        if(pivot->left->balanceFactor >= 1){
            rotateRight(pivot);
        }
        else if(pivot->left->balanceFactor <= -1){
            rotateLeft(pivot->left);
            rotateRight(pivot);
        }
    } else {
        if(pivot->right->balanceFactor <= -1){
            rotateLeft(pivot);
        } else if(pivot->right->balanceFactor >= 1) {
            rotateRight(pivot->right);
            rotateLeft(pivot);
        }
    }
    Node* curr = root;
    while(curr != pivot){
        curr->balanceFactor = balanceFactor(curr);
        if(pivot->data < curr->data){
            curr = curr->left;
        }
        else{
            curr = curr->right;
        }
    }
}

Node* AVLTree::rotateRight(Node* pivot){
    Node* temp = pivot->left;
    if(temp->right){
        pivot->left = temp->right;
        pivot->left->parent = pivot;
    }
    if(pivot->parent){
        temp->parent = pivot->parent;
    }
    pivot->parent = temp;
    temp->right = pivot;
    return temp;
}

Node* AVLTree::rotateLeft(Node* pivot){
    Node* temp = pivot->right;
    if(temp->left){
        pivot->right = temp->left;
        pivot->right->parent = pivot;
    }
    if(pivot->parent){
        temp->parent = pivot->parent;
    }
    pivot->parent = temp;
    temp->left = pivot;
    pivot->balanceFactor = balanceFactor(pivot);
    temp->balanceFactor = balanceFactor(temp); 
    temp->right->balanceFactor = balanceFactor(temp->right);
    return temp;
}

void AVLTree::visualizeTree(const string &outputFilename){
    ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open()){
        cout<<"Error"<<endl;
        return;
    }
    outFS<<"digraph G {"<<endl;
    visualizeTree(outFS,root);
    outFS<<"}";
    outFS.close();
    string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
    string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
    system(command.c_str());
}

void AVLTree::visualizeTree(ofstream & outFS, Node *n){
    if(n){
        if(n->left){
            visualizeTree(outFS,n->left);
            outFS<<n->data <<" -> " <<n->left->data<<";"<<endl;    
        }

        if(n->right){
            visualizeTree(outFS,n->right);
            outFS<<n->data <<" -> " <<n->right->data<<";"<<endl;    
        }
    }
}

void AVLTree::printBalanceFactors() const{
    inOrder(root);
}

void AVLTree::inOrder(Node* root) const{
    if(root->left){
        inOrder(root->left);
    }
    printBalanceFactors(root);
    if(root->right){
        inOrder(root->right);
    }
}

void AVLTree::printBalanceFactors(Node* curr) const{
    cout << curr->data << "(" << curr->balanceFactor << "), ";
}

Node* AVLTree::findUnbalancedNode() const{
    return findUnbalancedNode(root);
}

Node* AVLTree::findUnbalancedNode(Node* root) const{
    if(root->balanceFactor > 1 || root->balanceFactor < -1){
        return root;
    }
    if(root->left){
        return findUnbalancedNode(root->left);
    }
    if(root->right){
        return findUnbalancedNode(root->right);
    }
    return 0;
}


//----------------------------------------------------------------------------------Balance Factor
int AVLTree::balanceFactor(Node*here){
    int left = 0;
    int right = 0;
    if(here){
        
        if(here->left){
            left = height(here->left);
        }
        if(here->right){
            right = height(here->right);
        }
        
        
    }
    
    return (left - right);
}
//---------------------------------------------------------------------------------Height
int AVLTree::height(const string &word) const{
    if(!search(word)){
        return -1;
    }
    Node* temp = searchNode(word,root);
    
    return height(temp);
}
int AVLTree::height(Node* here)const{
    
    if(here){
        if(here->isLeaf()){
            return 0;
        }
        int left = height(here->left)+1;
        int right = height(here->right)+1;
        
        if(left < right){
            return right;
        }else{
            return left;
        }
    }
    return -1;
}


//---------------------------------------------------------------------------------Search
bool AVLTree::search(const string &find) const{
    
    return search(find,root);
}
bool AVLTree::search(const string& find, Node* here)const{
    if(here){
        
        if(here->data==find){
            return true;
        }
        
        if(find < here->data){
            return search(find,here->left);
        }else{
            return search(find,here->right);
        }
    }
    return false;
}

Node* AVLTree::searchNode(const string& word,Node* here)const{
    
    if(here){
        
        if(here-> data == word){
            return here;
        }else{
            if(word < here->data){
                return searchNode(word,here->left);
            }else{
                return searchNode(word,here->right);
            }
        }
    }
    return 0;
}