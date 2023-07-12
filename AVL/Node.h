#ifndef NODE_H
#define NODE_H
#include <iostream>
#include "NodeInterface.h"

// #####################################################################################################################
// ##																												  ##
// ## 											  Node Class		   												  ##
// ##																												  ##
// #####################################################################################################################

class Node : public NodeInterface {

public:

	// Right and left child
	Node * leftChild;
	Node * rightChild;

	// Need to store data and height
	int data;
	int height;

	// Constructor
	Node(int value) {

		// Everything NULL (or zero) excpet for passed value
		height = 0;
		data = value;
		leftChild = NULL;
		rightChild = NULL;
	}

	// Destructor
	~Node() {}

// #####################################################################################################################
// ##																												  ##
// ## 									    Definition of Functions		   											  ##
// ##																												  ##
// #####################################################################################################################

	// Get the data (obviously)
	int getData() const;

	// Get the two childs (obviously)
	NodeInterface * getLeftChild() const;
	NodeInterface * getRightChild() const;

	// Get the height and balance (obviously)
	int getHeight();
	int getBalance();
};
#endif
