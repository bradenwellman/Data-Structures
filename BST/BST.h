//
// Created by Braden Wellman on 3/10/22.
//

// #####################################################################################################################
// ##																												  ##
// ##												Includes / Defs 												  ##
// ##																												  ##
// #####################################################################################################################

#include "NodeInterface.h"
#include "Node.h"
#include "BSTInterface.h"
#ifndef BST_LAB_BST_H
#define BST_LAB_BST_H

// #####################################################################################################################
// ##																												  ##
// ##											Constructor / Destructor 											  ##
// ##																												  ##
// #####################################################################################################################

// Instantiate the class
class BST : public BSTInterface {

// Node pointer with Root = NULL
public: Node * root;
	BST() {
		root = NULL;
	}

	// Clear the data in the destructor
	~BST() {clear();}

// #####################################################################################################################
// ##																												  ##
// ##												    Functions 												      ##
// ##																												  ##
// #####################################################################################################################

	// Getting the root node
	NodeInterface * getRootNode() const;

	// Adding a node to the tree
	bool add(int data);
	bool adding(Node*& n, int data);

	// Removing a node from the tree
	bool remove(int data);
	bool removing(Node*& n, int data);

	// Clearing out the tree
	void clear();
	void clearing(Node* n);

};


#endif //BST_LAB_BST_H
