// //  Created by Frank M. Carrano and Timothy M. Henry.
// //  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

// /** @file Node.h
//     Listing 4-1 */
#ifndef NODE_H
#define NODE_H
#include <memory>

template <class ItemType>
class Node
{
private:
   ItemType item;                        // A data item
   std::shared_ptr<Node<ItemType>> next; // Pointer to next node

public:
   Node();
   Node(const ItemType &anItem);
   Node(const ItemType &anItem, std::shared_ptr<Node<ItemType>> nextNodePtr);

   virtual ~Node();

   void setItem(const ItemType &anItem);
   void setNext(std::shared_ptr<Node<ItemType>> nextNodePtr);
   ItemType getItem() const;
   std::shared_ptr<Node<ItemType>> getNext() const;
}; // end Node

#include "Node.cpp"
#endif
