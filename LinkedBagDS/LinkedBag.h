//   Created by Frank M. Carrano and Timothy M. Henry.
//   Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** ADT bag: Link-based implementation.
	 @file LinkedBag.h
	 Listing 4-3 */
#ifndef LINKED_BAG_
#define LINKED_BAG_

#include "BagInterface.h"
#include "Node.h"
#include <vector>

template <class ItemType>
class LinkedBag : public BagInterface<ItemType>
{
private:
	std::shared_ptr<Node<ItemType>> headPtr; // Pointer to first node
	int itemCount;													 // Current count of bag items

	// Returns either a pointer to the node containing a given entry
	// or the null pointer if the entry is not in the bag.
	// Node<ItemType>* getPointerTo(const ItemType& target) const;
	std::shared_ptr<Node<ItemType>> getPointerTo(const ItemType &target) const;

public:
	LinkedBag();
	LinkedBag(const LinkedBag<ItemType> &aBag); // Copy constructor
	virtual ~LinkedBag();												// Destructor should be virtual

	// LinkedBag<ItemType> &operator=(const LinkedBag<ItemType> &aBag);
	//  Assignment 2 functions -------------------------------------------
	bool append(const ItemType &newEntry);
	std::shared_ptr<Node<ItemType>> findKthItem(const int &indexK) const;
	// ------------------------------------------------------------------
	int getSize() const;
	int getCurrentSize() const;
	bool isEmpty() const;
	bool add(const ItemType &newEntry);
	bool remove(const ItemType &anEntry);
	void clear();
	bool contains(const ItemType &anEntry) const;
	int getFrequencyOf(const ItemType &anEntry) const;
	std::vector<ItemType> toVector() const;

	void decrementItemCount()
	{
		itemCount--;
	}

}; // end LinkedBag

#include "LinkedBag.cpp"
#endif