//
// Created by Braden Wellman on 3/10/22.
//

// #####################################################################################################################
// ##																												  ##
// ##												Includes / Defs 												  ##
// ##																												  ##
// #####################################################################################################################

#ifndef BST_LAB_NODE_H
#define BST_LAB_NODE_H
#include <iostream>
#include "NodeInterface.h"

// #####################################################################################################################
// ##																												  ##
// ##											Constructor / Destructor 											  ##
// ##																												  ##
// #####################################################################################################################


// Instantiate the class
class Node: public NodeInterface {

public:

	// Public values
	int data;
	Node * leftChild;
	Node * rightChild;

	// Constructor set to null
	Node(int value) {
		data = value;
		leftChild = NULL;
		rightChild = NULL;
	}

	// Destructor
	~Node() {}

// #####################################################################################################################
// ##																												  ##
// ##												    Functions 												      ##
// ##																												  ##
// #####################################################################################################################

	// Get all of the data (easy)
	int getData() const;
	NodeInterface * getLeftChild() const;
	NodeInterface * getRightChild() const;

};


#endif //BST_LAB_NODE_H
