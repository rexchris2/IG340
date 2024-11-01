//   Created by Frank M. Carrano and Timothy M. Henry.
//   Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** ADT bag: Link-based implementation.
	 @file LinkedBag.cpp */

#include "LinkedBag.h"
#include <cstddef>
#include <memory>

// Assignment 2 functions -------------------------------------------
// TO DO: implement the two functions here

// ------------------------------------------------------------------
template <class ItemType>
bool LinkedBag<ItemType>::append(const ItemType &newEntry)
{
	std::shared_ptr<Node<ItemType>> nodePtr = std::make_shared<Node<ItemType>>(newEntry);

	if (headPtr == nullptr)
	{
		headPtr = nodePtr;
	}
	else
	{
		std::shared_ptr<Node<ItemType>> curPtr = headPtr;
		while (curPtr->getNext() != nullptr)
		{
			curPtr = curPtr->getNext();
		}
		curPtr->setNext(nodePtr);
	}

	return true;
}

template <class ItemType>
std::shared_ptr<Node<ItemType>> LinkedBag<ItemType>::findKthItem(const int &indexK) const
{

	std::shared_ptr<Node<ItemType>> curPtr = headPtr;
	for (int i = 0; i < indexK; i++)
	{
		curPtr = curPtr->getNext();
	}
	return curPtr;
}

template <class ItemType>
LinkedBag<ItemType>::LinkedBag() : headPtr(nullptr), itemCount(0) {} // end default constructor

template <class ItemType>
LinkedBag<ItemType>::LinkedBag(const LinkedBag<ItemType> &aBag)
{
	itemCount = aBag.itemCount;
	std::shared_ptr<Node<ItemType>> origChainPtr = aBag.headPtr; // Points to nodes in original chain

	if (origChainPtr == nullptr)
		headPtr = nullptr; // Original bag is empty
	else
	{
		// Copy first node
		headPtr = std::make_shared<Node<ItemType>>();
		headPtr->setItem(origChainPtr->getItem());

		// Copy remaining nodes
		std::shared_ptr<Node<ItemType>> newChainPtr = headPtr; // Points to last node in new chain
		origChainPtr = origChainPtr->getNext();								 // Advance original-chain pointer

		while (origChainPtr != nullptr)
		{
			// Get next item from original chain
			ItemType nextItem = origChainPtr->getItem();

			// Create a new node containing the next item
			std::shared_ptr<Node<ItemType>> newNodePtr = std::make_shared<Node<ItemType>>(nextItem);

			// Link new node to end of new chain
			newChainPtr->setNext(newNodePtr);

			// Advance pointer to new last node
			newChainPtr = newChainPtr->getNext();

			// Advance original-chain pointer
			origChainPtr = origChainPtr->getNext();
		} // end while

		newChainPtr->setNext(nullptr); // Flag end of chain
	} // end if
} // end copy constructor

template <class ItemType>
LinkedBag<ItemType>::~LinkedBag()
{
	clear();
} // end destructor

template <class ItemType>
bool LinkedBag<ItemType>::isEmpty() const
{
	return itemCount == 0;
} // end isEmpty

template <class ItemType>
int LinkedBag<ItemType>::getCurrentSize() const
{
	return itemCount;
} // end getCurrentSize

template <typename ItemType>
int LinkedBag<ItemType>::getSize() const
{
	return itemCount;
}

template <class ItemType>
bool LinkedBag<ItemType>::add(const ItemType &newEntry)
{
	// Add to beginning of chain: new node references rest of chain;
	// (headPtr is null if chain is empty)
	std::shared_ptr<Node<ItemType>> nextNodePtr = std::make_shared<Node<ItemType>>();
	nextNodePtr->setItem(newEntry);
	nextNodePtr->setNext(headPtr); // New node points to chain
	headPtr = nextNodePtr;				 // New node is now first node
	itemCount++;

	return true;
} // end add

template <class ItemType>
std::vector<ItemType> LinkedBag<ItemType>::toVector() const
{
	std::vector<ItemType> bagContents;
	std::shared_ptr<Node<ItemType>> curPtr = headPtr;
	int counter = 0;
	while ((curPtr != nullptr) && (counter < itemCount))
	{
		bagContents.push_back(curPtr->getItem());
		curPtr = curPtr->getNext();
		counter++;
	} // end while

	return bagContents;
} // end toVector

template <class ItemType>
bool LinkedBag<ItemType>::remove(const ItemType &anEntry)
{
	std::shared_ptr<Node<ItemType>> entryNodePtr = getPointerTo(anEntry);
	bool canRemoveItem = !isEmpty() && (entryNodePtr != nullptr);

	if (canRemoveItem)
	{
		// Copy data from first node to located node

		std::shared_ptr<Node<ItemType>> prevPtr = nullptr;
		std::shared_ptr<Node<ItemType>> curPtr = headPtr;

		// Traverve list
		while (curPtr != entryNodePtr)
		{
			prevPtr = curPtr;
			curPtr = curPtr->getNext();
		}
		if (curPtr == headPtr)
		{
			headPtr = headPtr->getNext();
		}
		else
		{
			prevPtr->setNext(curPtr->getNext());
		}

		itemCount--;
	} // end if

	return canRemoveItem;
} // end remove

template <class ItemType>
void LinkedBag<ItemType>::clear()
{
	std::shared_ptr<Node<ItemType>> nodeToDeletePtr = headPtr;
	while (headPtr != nullptr)
	{
		headPtr = headPtr->getNext();

		// Return node to the system
		nodeToDeletePtr->setNext(nullptr);

		nodeToDeletePtr = headPtr;
	} // end while
	// headPtr is nullptr; nodeToDeletePtr is nullptr

	itemCount = 0;
} // end clear

template <class ItemType>
int LinkedBag<ItemType>::getFrequencyOf(const ItemType &anEntry) const
{
	int frequency = 0;
	int counter = 0;
	std::shared_ptr<Node<ItemType>> curPtr = headPtr;
	while ((curPtr != nullptr) && (counter < itemCount))
	{
		if (anEntry == curPtr->getItem())
		{
			frequency++;
		} // end if

		counter++;
		curPtr = curPtr->getNext();
	} // end while

	return frequency;
} // end getFrequencyOf

template <class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType &anEntry) const
{
	return (getPointerTo(anEntry) != nullptr);
} // end contains

// private
// Returns either a pointer to the node containing a given entry
// or the null pointer if the entry is not in the bag.
template <class ItemType>
std::shared_ptr<Node<ItemType>> LinkedBag<ItemType>::getPointerTo(const ItemType &anEntry) const
{
	bool found = false;
	std::shared_ptr<Node<ItemType>> curPtr = headPtr;

	while (!found && (curPtr != nullptr))
	{
		if (anEntry == curPtr->getItem())
			found = true;
		else
			curPtr = curPtr->getNext();
	} // end while

	return curPtr;
} // end getPointerTo
