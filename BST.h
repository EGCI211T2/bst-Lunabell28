#include "Treenode.h"

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
  void printTree(TreeNodePtr,int); //The real lab
  void kill(TreeNodePtr);

void BST::insert_node(int value) {
  int inserted = 0;
  TreeNodePtr new_node, t;
  new_node = new TreeNode(value);
  if (new_node) {
   
   /*   if(First Node){
          
      }
      else{
          t=rootPtr;
          while(!inserted){//insert =0
              //once the location is found -->inserted=1
              //1.should it go left or right
              //2. should it be inserted, if availabble inserted, if not move
              //3. once inserted make insert=1
              
              
              
          }// end while*/
      
      //}//ene else
        ++size;
  }//end  new node
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
      default:
    printTree(rootPtr,0);
    cout << endl;
  }
}


BST::BST() {
  rootPtr=NULL;
  size=0;
}

BST::~BST() { 
  cout << "Kill BST" << endl; 
    
}

void inOrder(TreeNodePtr treePtr) {
  // TreeNodePtr treePtr=rootPtr;
  if (treePtr) {
    // if tree is not empty, then traverse
    inOrder(treePtr->move_left()); // Recursion to the left
    cout << setw(3) << treePtr->get_value(); // print the value
    inOrder(treePtr->move_right()); // Recursion to the right
  }                                 // end if
} // end function
  //printTree(rootPtr,0);

void printTree(TreeNodePtr treePtr,int l) {
  // TreeNodePtr treePtr=rootPtr;
        // end if
} // end function


void postOrder(TreeNodePtr treePtr) {
  // TreeNodePtr treePtr=rootPtr;
  if (treePtr) {
 
 
   
  }                                          // end if
} // end function

void kill(TreeNodePtr treePtr) {
  // TreeNodePtr 
  if(treePtr){
       //delete everything
        
    }                                          // end if
} // end function

void preOrder(TreeNodePtr treePtr) {
  if(treePtr){
  // TreeNodePtr treePtr=rootPtr;
   
 
  }                                          // end if
} // end function

