#ifndef _BianryTree_H
#define _BianryTree_H

#include <iostream>
enum Boolean{False, True} ;
/* key */
template <class type> class BST;
template <class type>
class Element
{
  public:
    type key;
};
/* tree node */
template <class type>
class bstNode
{
  friend class BST<type>; // 定义为友元类.可以访问私有数据成员了
  private:
    Element<type> data;
    bstNode *leftChild;
    bstNode *rightChild;
  public:
    void display(int i);
    void display();
};

template <class type>
void bstNode<type>::display()
{
  std::cout << "key: " << data.key << "\n";
}
template <class type>
void bstNode<type>::display(int i)
{
  std::cout << "position:" << i << ", key: " << data.key << "\n";
  if(leftChild) leftChild->display(2*i);
  if(rightChild) rightChild->display(2*i + 1);
}
/* BinaryTree */
template <class type>
class BST
{
  public:
    BST(bstNode<type> *init = 0)
    {
      root = init;
    }
    Boolean insert(const Element<type> &node);
    bstNode<type>* search(const Element<type> &node);
    bstNode<type>* search(bstNode<type> *tree, const Element<type> &node);
    bstNode<type>* iter_search(const Element<type> &node);
    void display()
    {
      std::cout <<"\n";
      if (root)
        root->display(1);
      else
        std::cout << "this is an empty tree" << "\n";
    }
  private:
    bstNode<type> *root;

};
template <class type>
Boolean BST<type>::insert(const Element<type> &node)
{
  bstNode<type> *p = root;
  bstNode<type> *q = 0;
  while(p)
  {
    q = p;
    if (node.key == p->data.key) return False;
    if (node.key < p->data.key) p = p->leftChild;
    else p= p->rightChild;
  }

  p = new bstNode<type>;
  p->leftChild = p->rightChild = 0;
  p->data = node;

  if (!root) root = p;
  else if (node.key < q->data.key) q->leftChild = p;
  else
  q->rightChild = p;

  return True;
}
template <class type>
bstNode<type>* BST<type>::search(const Element<type> &node)
{
  return search(root, node);
}

template <class type>
bstNode<type>* BST<type>::search(bstNode<type> *tree, const Element<type> &node)
{
  if (!tree) return 0;
  if (node.key == tree->data.key) return tree;
  else if (node.key < tree->data.key) return search(tree->leftChild, node);
  else return search(tree->rightChild, node);

}
template <class type>
bstNode<type>* BST<type>::iter_search(const Element<type> &node)
{
  if (!root) return 0;
  for (bstNode<type> p = root; p;)
  {
    //if (node.data == )
  }
}

#endif
