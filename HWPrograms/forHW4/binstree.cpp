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
#include "binstree.h"

// constructor, initializes Root
BST::BST()
{
   Root = NULL;// This is an empty tree
}//Close: BST() (constructor)

// destructor must completely destroy the tree
BST::~BST()
{
   dtraverse(Root);// traverse to delete all vertices in post order
   Root = NULL;//Make Root NULL    
}//Close: ~BST() (destructor)


// PURPOSE: Does Post Order traversal of the tree and deletes each vertex
// PARAM:   V is a pointer to the vertex to be deleted
void BST::dtraverse(Vertex *V)// recursive post order traversal
{   
  if(V != NULL)
    {
      dtraverse(V->Left);// visit left sub tree of V
      dtraverse(V->Right);//  visit right sub tree of V
      delete V;//  deletes V
    }//Close: if(V != NULL)
}//Close: dtraverse(Vertex *V)

// PURPOSE: Show elements in IN order traversal from the Root
void BST::ShowInOrder()
{
  cout << "Elements in the IN order: " << endl;
  INorderTraversal(Root);//start in-order traversal from the root
}//Close: ShowInOrder() 

// PURPOSE: Does IN order traversal from V recursively
// PARAM: V is te pointer to the vertex to visit right now
void BST::INorderTraversal(Vertex *V)
{
  if(V != NULL)//V == NULL means empty
    {
      INorderTraversal(V->Left);//** traverse left sub-tree of V recursively
      cout << V->Elem << endl;//** display V's element and do endl; 
      INorderTraversal(V->Right);//** traverse right sub-tree of V recursively
    }//Close: if(V != NULL) 
}//Close: INorderTraversal(Vertex *V)

// PURPOSE:  Show elements in PRE order traversal from the Root
// This is the same as Depth First Traversal
void BST::ShowPreOrder()
{
  cout << "Elements in the PRE order:" << endl;
  PREorderTraversal(Root);  // start pre-order traversal from the root
}//Close: ShowPreOrder()

// PURPOSE: Does PRE order traversal from V recursively
// PARAM: V is the pointer to the vertex to be visited now
void BST::PREorderTraversal(Vertex *V)
{
  if(V != NULL)//V == NULL means empty
    {
      cout << V->Elem << endl;//** display V's element and do endl; 
      PREorderTraversal(V->Left);//** traverse left sub-tree of V recursively
      PREorderTraversal(V->Right);//** traverse right sub-tree of V recursively
    }//Close: if(V != NULL)
}//Close: PREorderTraversal(Vertex *V)

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
  Vertex *N;// N will point to the new vertex to be inserted
  N = new Vertex;// a new vertex is created
  N->Left  = NULL;// make sure it does not
  N->Right = NULL;// point to anything
  N->Elem  = E;// put element E in it
  cout << "Trying to insert " << E << endl;
  if(Root == NULL)//Special case: we have a brand new empty tree
    {
      Root = N;// the new vertex is added as the root
      cout << "...adding " << E << " as the root" << endl;
      return;//Done, return to client
    }//Close: if(Root == NULL) 
  else//the tree is not empty
    {
      Vertex *V;       // V will point to the current vertex
      Vertex *Parent;  // Parent will point to V's parent
      V = Root;        // start with the root as V
      while(V != NULL)  // go down the tree until you cannot go any further
	{
	  if(N->Elem == V->Elem) // the element already exists
	    {	 cout << "...error: the element already exists" << endl;
	      return;//Done, return to client  
	    }//Close: if (N->Elem == V->Elem)
	  else if(N->Elem < V->Elem)  // what I have is smaller than V
	    {  cout << "...going to the left" << endl; 
	      Parent = V;// ** change Parent to be V to go down 
	      V = V->Left;// ** change V to be V's Left 
	    }//Close: else if(N->Elem < V->Elem) 
	  else // what I have is bigger than V
	    {  cout << "...going to the right" << endl;
	      Parent = V;// ** change Parent to be V to go down
	      V = V->Right;// ** change V to be V's Right 
	    }//Close: else 
	}//Close:  while(V != NULL)
      // reached NULL -- Must add N as the Parent's child
      if(N->Elem < Parent->Elem)//new child is smaller that parent
	{
	  Parent->Left = N;//** Parent's Left points to N
	  cout << "...adding " << E << " as the left child of " 
	       << Parent->Elem << endl;
	}//Close: if (N->Elem < Parent->Elem) 
      else//new child is bigger that parent 
	{
	  Parent->Right = N;// ** Parent's Right points to N
	  cout << "...adding " << E << " as the right child of " 
	       << Parent->Elem << endl;	
	}//Close: else
    }//Close: else //the tree is not empty(normal case)
}//Close: Insertvertex(elem_t E)

// PURPOSE: Deletes a vertex that has E as its element.
// PARAM: element E to be removed
// ALGORITHM: First we must find the vertex then call Remove
void BST::DeleteVertex(elem_t E)
{
  cout << "Trying to delete " << E << endl;
  Vertex *V;              // the current vertex
  Vertex *Parent = NULL;  // its parent
  if ((E == Root->Elem) && (Root->Left == NULL) && (Root->Right == NULL))
    { 
      cout << "...deleting the lonely root" << endl;
      delete Root;//Recycle root vertex 
      Root = NULL; //Only the Root was there and deleted it, set to NULL
      return;//Done, return to client
    }//Close: if((E == Root->Elem) && (Root->Left == NULL) && (Root->Right == NULL))  
  V = Root;// start with the root to look for E
  //***********************************************************************
  /*// ** if what you want to delete is the root with one child 
    {  //** change the root to the child and return - this could
    //be the left or the right child 
    }// end of deleting the root*/              
  //***********************************************************************
  //Root with a left child
  if((E == Root->Elem)&&(Root->Left != NULL)&&(Root->Right == NULL))
    {
      Root = Root->Left;//V already pointing to root vertex, can move root left
      delete V;//Delete the previous root being pointed by V
      cout << "Deleted the Root with a Left Child\n";
      return;//Done, return tp client
    }//Close: else if((E == Root->Elem)&&(Root->Right != NULL)&&(Root->Left == NULL))
  //Root with a right child
  else if((E == Root->Elem)&&(Root->Right != NULL)&&(Root->Left == NULL))
    {
      Root = Root->Right;//V already pointing to root vertex, can move root right
      delete V;//Delete the previous root being pointed by V
      cout << "Deleted the Root with a Right Child\n";
      return;//Done, return to client
    }//Close: else if((E == Root->Elem)&&(Root->Right != NULL)&&(Root->Left == NULL)) 
  // Otherwise deleting something else
  //V = Root;  // start with the root to look for E********************************
  while(V != NULL)//Until there are no more Vertex to check
    { 
      if( E == V->Elem)// found it
	{  cout << "...removing " << V->Elem << endl;
	  remove(Parent, V);// ** call remove here to remove V
	  return;//Done, return to client 
	}//Close: if( E == V->Elem)
      else if (E < V->Elem)//Element is smaller than V, go left
	{// ** update Parent and V here to go down
	  cout << "...going to the left" << endl;
	  Parent = V;//Move Parent down to V 
	  V = V->Left;//Move V left
	}//Close: else if (E < V->Elem)
      else//Element is bigger than V, go left
	{// ** update Parent and V here to go down 
	  cout << "...going to the right" << endl;
	  Parent = V;//Move Parent down to V 
	  V = V->Right;//Move V right
	}//Close: else 
    }//Close: while(V != NULL)
  // reached NULL  -- did not find it
  cout << "Did not find the key in the tree." << endl;
}//Close: DeleteVertex(elem_t E)

// PURPOSE: Removes vertex pointed to by V
// PARAM: V and its parent  pointer P
// Case 1: it is a leaf, delete it
// Case 2: it has just one child, bypass it
// Case 3: it has two children, replace it with the max of the left subtree
void BST::remove(Vertex *V, Vertex *P)
{
  if((P->Left == NULL)&&(P->Right == NULL))//** if V is a leaf (case 1)
    {
      cout << ".. removing a leaf" << endl;
      if(V->Left == P)// ** if V is a left child of P
	{//** delete V and also make Parent's left NULL
	  delete P;
	  V->Left = NULL;
	}//Close: if(V->Left == P)
      else // V is a right child of the Parent
	{//** delete V and also make Parent's right NULL 
	  delete P;
	  V->Right = NULL;
	}//Close: else
      return;//Done, return to function
    }//Close: if((P->Left == NULL)&&(P->Right == NULL)) (leaf case)
  else if((P->Left != NULL)&&(P->Right == NULL)) // ** if V has just the left child (case 2)
    {
      cout << "removing a vertex with just the left child" << endl;
      // ** Make Parent left or right point to the left child and delete V
      //(You need if then else to determine left or right)
      if(V->Left == P)//V is parent's left child
	{
	  V->Left = P->Left;//Parent's left points to V's child
	  delete P;//Bypassed V, can delete it now
	}//Close: if(V->Left == P)
      else//V is parent's right child 
	{
	  V->Right = P->Left;//Parent's right points to V's child
	  delete P;//Bypassed V, can delete it now
	}//Close: else
      return;//Done, return to function
    }//Close: else if((P->Left != NULL)&&(P->Right == NULL))(V with left child)       
  else if((P->Right != NULL)&&(P->Left == NULL))// ** if V has just the right child
    {
      cout << "removing a vertex with just the right child" << endl;
      // ** Make Parent left or right point to the right child and delete V
      //(You need if then else to determine left or right)
      if(V->Left == P)//V is parent's left child
	{
	  V->Left = P->Right;//Parent's left points to V's child
	  delete P;//Bypassed V, can delete it now
	}//Close: if(V->Right == P)
      else//V is parent's right child
	{
	  V->Right = P->Right;//Parent's right points to V's child
	  delete P;//Bypassed V, can delete it now
	}//Close: else
      return;//Done, can return to function
    }//Close: else if((P->Right != NULL)&&(P->Left == NULL))(V with right child)
  else // V has two children (case 3)
    { 
      cout << "...removing an internal vertex with children" << endl;
      cout << ".....find the MAX of its left sub-tree" << endl;
      elem_t Melem;//To hold element deleted 
      Melem = findMax(P); // find MAX element in the left sub-tree of V
      cout << ".....replacing " << P->Elem << " with " << Melem << endl;
      // ** Replace V's element with Melem here
      P->Elem = Melem;//Replace V with biggest element in left sub-tree
    }//Close: else (V with two children)
}//Close: remove(Vertex *V, Vertex *P)

// PURPOSE: Finds the Maximum element in the left sub-tree of V
elem_t BST::findMax(Vertex *V)
{
  Vertex *Parent = V;//Points to V's previous (parent)
  V = V->Left; // start with the left child of V  
  // ** while the right child of V is still available
  // ** update Parent and V to go to the right
  for(V, Parent; V->Right != NULL; Parent = V, V = V->Right);
  // reached NULL Right  -- V now has the MAX element
  elem_t X = V->Elem;//Store max element in X
  cout << ".....Max is " << X << endl;
  remove(Parent, V);    // remove the MAX vertex 
  return X;             // return the MAX element
}//Close: findMax(Vertex *V)
