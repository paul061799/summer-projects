#ifndef __BSTREE_H__
#define __BSTREE_H__

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
#include "Node.h"

using namespace std;

class BSTree {

private:
  Node *root;

private:
  void preOrder(Node *) const;
  void postOrder(Node*) const;
  void inOrder(Node*) const;
  int nodeHeight(Node*) const;
  Node* findNode(const string &) const;
  Node* findParentNode(const string &) const;
  string smallest(Node*) const;
  string largest(Node*) const;
  void remove(Node*, Node*);

public:
  BSTree();
  void insert(const string &);
  bool search(const string &) const;
  void inOrder( ) const;
  void postOrder( ) const;
  void preOrder( ) const;
  string largest( ) const;
  string smallest( ) const;
  int height(const string &) const;
  void remove(const string &);
};

#endif
