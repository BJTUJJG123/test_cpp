#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H
#include <iostream>

template <class Type> 
class redBlackTree;

template<class Type>
class redBlackNode;

template <class Type>
class redBlackTree
{
  public:
    redBlackTree(const Type &neginf);// use a neg init empty root
   ~redBlackTree();
    typedef redBlackNode<Type> Node;
    enum {RED,BLACK};
  private:
    Node *header;
    Node *nullNode;

    Node *current;
    Node *parent;
    Node *grand;
    Node *great;
};
template <class Type>
redBlackTree<Type>::redBlackTree(const Type &neginf)
{
  nullNode = new Node();
  nullNode->left = nullNode->right = nullNode;
  header = new Node();
  header->left = header->right = nullNode;
}
template <class Type>
redBlackTree<Type>::~redBlackTree()
{
  delete nullNode;
  delete header;
}

template <class Type>
class redBlackNode
{
  Type element;
  redBlackNode *left;
  redBlackNode *right;
  int color;

  redBlackNode(const Type &ele = Type(),
      redBlackNode *lt = NULL,
      redBlackNode *rt = NULL,
      int c = redBlackTree<Type>::BLACK)
      :element(ele),left(lt),right(rt),color(c){};

  friend class redBlackTree<Type>;
};
#endif
