#ifndef BST_H
#define BST_H

#include <iostream>
#include <iomanip>
#include "Treenode.h"
using namespace std;

class BST {
  int size;
  TreeNodePtr rootPtr;

public:
  BST();
  ~BST();
  void insert_node(int);
  void print(int = 0);
  /* 0= inOrder 1=preOrder 2=postorder 3=printeverything 4=3+ print tree*/
};

// Additional functions
void inOrder(TreeNodePtr);
void preOrder(TreeNodePtr);
void postOrder(TreeNodePtr);
void printTree(TreeNodePtr, int); 
void kill(TreeNodePtr);

BST::BST() {
  rootPtr = NULL;
  size = 0;
}

BST::~BST() { 
  cout << "\nKill BST" << endl; 
  kill(rootPtr);
}

void BST::insert_node(int value) {
  int inserted = 0;
  TreeNodePtr new_node, t;
  new_node = new TreeNode(value);
  
  if (new_node) {
      if(rootPtr == NULL){
          rootPtr = new_node;
      } else {
          t = rootPtr;
          while(!inserted){
              if (value < t->get_value()) {
                  if (t->move_left() == NULL) {
                      t->set_left(new_node);
                      inserted = 1;
                  } else {
                      t = t->move_left();
                  }
              } else {
                  if (t->move_right() == NULL) {
                      t->set_right(new_node);
                      inserted = 1;
                  } else {
                      t = t->move_right();
                  }
              }
          } 
      }
      cout << value << "inserted" << endl;
      ++size;
  }
}

void BST::print(int option) {
  switch (option) {
  case 0:
    inOrder(rootPtr);
    cout << endl;
    break;
  case 1:
    preOrder(rootPtr);
    cout << endl;
    break;
  case 2:
    postOrder(rootPtr);
    cout << endl;
    break;
  case 3:
    cout << "inOrder" << endl;
    inOrder(rootPtr);
    cout << endl;
    cout << "preOrder" << endl;
    preOrder(rootPtr);
    cout << endl;
    cout << "postOrder" << endl;
    postOrder(rootPtr);
    cout << endl;
    cout << "Tree" << endl;
    // Notice there is no 'break' here, so it falls through to default to print the tree!
  default:
    printTree(rootPtr, 0);
    cout << endl;
  }
}

void inOrder(TreeNodePtr treePtr) {
  if (treePtr) {
    inOrder(treePtr->move_left()); 
    cout << setw(3) << treePtr->get_value(); 
    inOrder(treePtr->move_right()); 
  }                                 
} 

void preOrder(TreeNodePtr treePtr) {
  if(treePtr){
    cout << setw(3) << treePtr->get_value(); 
    preOrder(treePtr->move_left()); 
    preOrder(treePtr->move_right()); 
  }                                          
} 

void postOrder(TreeNodePtr treePtr) {
  if (treePtr) {
    postOrder(treePtr->move_left()); 
    postOrder(treePtr->move_right()); 
    cout << setw(3) << treePtr->get_value(); 
  }                                          
} 

void printTree(TreeNodePtr treePtr, int l) {
  if (treePtr) {
      printTree(treePtr->move_right(), l + 1);
      for(int i = 0; i < l; i++) {
          cout << "   "; 
      }
      cout << treePtr->get_value() << endl;
      printTree(treePtr->move_left(), l + 1);
  }
}

void kill(TreeNodePtr treePtr) {
  if(treePtr){
      kill(treePtr->move_left());
      kill(treePtr->move_right());
      delete treePtr;
  }
}

#endif