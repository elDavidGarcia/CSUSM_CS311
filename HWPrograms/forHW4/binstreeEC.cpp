// CS311 : This is the BST implementation file template by Rika Yoshii
// INSTRUCTIONS:
//** Look for ** comments to complete this file for HW4
// Try not to delete the ** comments
// Make sure all { } match. Doing Tab on each line helps.

// =========================================================
//HW#: HW4 BST
//Your name: David Garcia
//Complier:  g++
//File type: Implementation file
//================================================================

using namespace std;

#include <iostream>
#include "binstreeEC.h"

// constructor  initializes Root
BST::BST()
{
   Root = NULL;   // This is an empty tree
   Height = Balance = 0;
}

// destructor must completely destroy the tree
BST::~BST()
{
   dtraverse(Root); // traverse to delete all vertices in post order
   Root = NULL;    
}


// PURPOSE: Does Post Order traversal of the tree and deletes each vertex
// PARAM:   V is a pointer to the vertex to be deleted
void BST::dtraverse(Vertex *V)  // recursive post order traversal
{   
  if (V != NULL) 
    {
      dtraverse(V->Left);         // visit left sub tree of V
      dtraverse(V->Right);       //  visit right sub tree of V
      delete V;                  //  deletes V
    }
}


// PURPOSE: Show elements in IN order traversal from the Root
void BST::ShowInOrder()
{
  cout << "Elements in the IN order: " << endl;
  INorderTraversal(Root);  // start in-order traversal from the root
}

// PURPOSE: Does IN order traversal from V recursively
// PARAM: V is te pointer to the vertex to visit right now
void BST::INorderTraversal(Vertex *V)
{
    if (V != NULL)
      {
        INorderTraversal(V->Left);// ** traverse left sub-tree of V recursively
        cout << V->Elem << endl;// ** display V's element and do endl; 
        INorderTraversal(V->Right);// ** traverse right sub-tree of V recursively
      }
}

// PURPOSE:  Show elements in PRE order traversal from the Root
// This is the same as Depth First Traversal
void BST::ShowPreOrder()
{
  cout << "Elements in the PRE order:" << endl;
  PREorderTraversal(Root);  // start pre-order traversal from the root
}

// PURPOSE: Does PRE order traversal from V recursively
// PARAM: V is the pointer to the vertex to be visited now
void BST::PREorderTraversal(Vertex *V)
{
  if (V != NULL)
    {
      cout << V->Elem << endl;// ** display V's element and do endl; 
      PREorderTraversal(V->Left);// ** traverse left sub-tree of V recursively
      PREorderTraversal(V->Right);// ** traverse right sub-tree of V recursively
    }
}

void ShowPOSTOrder()
{
  cout << "Elements in the POST order:" << endl;
  POSTorderTraversal(Root);
}
void POSTorderTraversal(Vertex*)
{
  if (V != NULL)
    {
      PREorderTraversal(V->Left);// ** traverse left sub-tree of V recursively
      PREorderTraversal(V->Right);// ** traverse right sub-tree of V recursively
      cout << V->Elem << endl;// ** display V's element and do endl;
    }
}

// PURPOSE: Adds a vertex to the binary search tree for a new element 
// PARAM: the new element E
// ALGORITHM: We will do this iteratively (not recursively) to demonstrate
// the algorithm that is in the notes
//    - smaller than the current -> go to the left
//    - bigger than the current  -> go to the right
//    - cannot go any further    -> add it there
void BST::Insertvertex(elem_t E)
{
  // Set up a new vertex first
  Vertex *N;         // N will point to the new vertex to be inserted
  N = new Vertex;    // a new vertex is created
  N->Left  = NULL;   // make sure it does not
  N->Right = NULL;   // point to anything
  N->Elem  = E;      // put element E in it
  
  cout << "Trying to insert " << E << endl;
  
  if (Root == NULL)  // Special case: we have a brand new empty tree
    {
      Root = N;      // the new vertex is added as the root
      cout << "...adding " << E << " as the root" << endl; 
    }
  
  else  // the tree is not empty
    {
      Vertex *V;       // V will point to the current vertex
      Vertex *Parent;  // Parent will point to V's parent
      
      V = Root;        // start with the root as V
      
      while (V != NULL)  // go down the tree until you cannot go any further
	{
	  if (N->Elem == V->Elem) // the element already exists
	    {	 cout << "...error: the element already exists" << endl;
	      return;  
	    }
	  else if(N->Elem < V->Elem)  // what I have is smaller than V
	    {  cout << "...going to the left" << endl; 
	      Parent = V;// ** change Parent to be V to go down 
	      V = V->Left;// ** change V to be V's Left 
	    }
	  else // what I have is bigger than V
	    {  cout << "...going to the right" << endl;
	      Parent = V;// ** change Parent to be V to go down
	      V = V->Right;// ** change V to be V's Right 
	    }
	  
	}//end of while
      
      // reached NULL -- Must add N as the Parent's child
      
      if (N->Elem < Parent->Elem)
	{ // ** Parent's Left should point to the same place as N 
	  Parent->Left = N;  
	  cout << "...adding " << E << " as the left child of " 
	       << Parent->Elem << endl;
	}
        else 
	  { // ** Parent's Right should point to the same place as N
	    Parent->Right = N;
	    cout << "...adding " << E << " as the right child of " 
		 << Parent->Elem << endl;	
	  }
      
    }// end of normal case
}// end of InsertVertex


// PURPOSE: Deletes a vertex that has E as its element.
// PARAM: element E to be removed
// ALGORITHM: First we must find the vertex then call Remove
void BST::DeleteVertex(elem_t E)
{
  cout << "Trying to delete " << E << endl;
  
  Vertex *V;              // the current vertex
  Vertex *Parent = NULL;  // its parent
  
  if ((E == Root->Elem) && (Root->Left == NULL) && (Root->Right == NULL))
    { cout << "...deleting the lonely root" << endl;
      delete Root; 
      Root = NULL;
      return; }  // only the Root was there and deleted it
  
  V = Root;// start with the root to look for E
  
  /*// ** if what you want to delete is the root with one child 
    if((E == Root->Elem)&&((Root->Left != NULL)||(Root->Right != NULL)))
    {  //** change the root to the child and return - this could
    //be the left or the right child 
    }// end of deleting the root*/
  
  if((E == Root->Elem)&&(Root->Left != NULL)&&(Root->Right == NULL))
    {
      Root = Root->Left; 
      delete V;
      return;
    }
  else if((E == Root->Elem)&&(Root->Right != NULL)&&(Root->Left == NULL))
    {
      Root = Root->Right;
      delete V;
      return;
    }
  
  // Otherwise deleting something else
  
  //V = Root;  // start with the root to look for E
  
  while (V != NULL)
    { 
      if ( E == V->Elem)   // found it
	{  cout << "...removing " << V->Elem << endl;
	  remove(Parent, V);// ** call remove here to remove V
	  return; }
      
      else if (E < V->Elem)
	{  cout << "...going to the left" << endl;
	  Parent = V;// ** update Parent and V here to go down 
	  V = V->Left;}
      else
	{  cout << "...going to the right" << endl;
	  Parent = V;// ** update Parent and V here to go down
	  V = V->Right;}
      
    }// end of while
  
  // reached NULL  -- did not find it
  cout << "Did not find the key in the tree." << endl;
  
}// end of DeleteVertex


// PURPOSE: Removes vertex pointed to by V
// PARAM: V and its parent  pointer P
// Case 1: it is a leaf, delete it
// Case 2: it has just one child, bypass it
// Case 3: it has two children, replace it with the max of the left subtree
void BST::remove(Vertex *V, Vertex *P)
{
  if((P->Left == NULL)&&(P->Right == NULL))// ** if V is a leaf (case 1)
    {
      cout << ".. removing a leaf" << endl;
      if(V->Left == P)// ** if V is a left child of P
	{
	  delete P;// ** delete V and also make Parent's left NULL 
	  V->Left = NULL;
	}
      else // V is a right child of the Parent
	{ 
	  delete P;// ** delete V and also make Parent's right NULL 
	  V->Right = NULL;
	}
      return;
    }//end of leaf case
  
  else if((P->Left != NULL)&&(P->Right == NULL)) // ** if V has just the left child (case 2)
    {
      cout << "removing a vertex with just the left child" << endl;
      // ** Make Parent left or right point to the left child and delete V
      //(You need if then else to determine left or right)
      if(V->Left == P)
	{
	  V->Left = P->Left;
	  delete P;
	}
      else 
	{
	  V->Right = P->Left;
	  delete P;
	}
      return;
    }// end of V with left child       
  
  else if((P->Right != NULL)&&(P->Left == NULL))// ** if V has just the right child
    {
      cout << "removing a vertex with just the right child" << endl;
      // ** Make Parent left or right point to the right child and delete V
      //(You need if then else to determine left or right)
      if(V->Right == P)
	{
	  V->Left = P->Right;
	  delete P;
	}
      else
	{
	  V->Right = P->Right;
	  delete P;
	}
      return;
    }//end of V with right child
  
  else // V has two children (case 3)
    { 
      cout << "...removing an internal vertex with children" << endl;
      cout << ".....find the MAX of its left sub-tree" << endl;
      elem_t Melem;
      Melem = findMax(P); // find MAX element in the left sub-tree of V
      cout << ".....replacing " << P->Elem << " with " << Melem << endl;
      // ** Replace V's element with Melem here
      P->Elem = Melem;
    }//end of V with two children
  
}// end of remove

// PURPOSE: Finds the Maximum element in the left sub-tree of V
elem_t BST::findMax(Vertex *V)
{
  Vertex *Parent = V;
  V = V->Left;          // start with the left child of V
  
  // ** while the right child of V is still available
  // ** update Parent and V to go to the right
  for(V, Parent; V->Right != NULL; Parent = V, V = V->Right);
  // reached NULL Right  -- V now has the MAX element
  elem_t X = V->Elem;
  cout << ".....Max is " << X << endl;
  remove(Parent, V);    // remove the MAX vertex 
  return X;             // return the MAX element
  
}// end of FindMax

// For Extra Credit : called from Show Post Order

// returns 1 plus the greater height of
// the left and the right children (special case when no child)
int greaterof(Vertex*, Vertex*)
{

} 

// returns the right height minus the left
// height (special case when no child)
int diff(Vertex*, Vertex*)
{

}  

