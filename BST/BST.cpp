//
// Created by Braden Wellman on 3/10/22.
//

#include "BST.h"
#include "Node.h"
#include "NodeInterface.h"

// #####################################################################################################################
// ##																												  ##
// ##										  Get the Root Node (Easy) 												  ##
// ##																												  ##
// #####################################################################################################################


NodeInterface * BST::getRootNode() const {
	return root;
}

// #####################################################################################################################
// ##																												  ##
// ##											Add Node to the Tree 												  ##
// ##																												  ##
// #####################################################################################################################

// Call new function (it's easier with a root passed as a function)
bool BST::add(int data) {

	// Need a bool to determine our other function
	bool which;

	// Set equal to new function and return
	which = adding(root, data);
	return which;
}

// Function to actually add
bool BST::adding(Node*& n, int data) {

	// If our Root is null...
	if (n == NULL) {

		// Create a new Node with the data and return true
		n = new Node(data);
		return true;
	}

	// Otherwise, if root is > data
	if (n->data > data) {

		// Recursively call the function until we get a null
		return adding(n->leftChild, data);
	}

	// If our data is greater than the value
	if (n->data < data) {

		// Recursively call the function until we get a null
		return adding(n->rightChild, data);
	}

	// Return false otherwise
	return false;
}

// #####################################################################################################################
// ##																												  ##
// ##										Remove Node from the Tree 												  ##
// ##																												  ##
// #####################################################################################################################

// Call our remove function (way easier by passing in a root??? why don't we just do it that way?)
bool BST::remove(int data) {
	return removing(root, data);
}

// The actual remove function
bool BST::removing(Node*& n, int data) {

	// If the root is null, there is nothing to remove
	if (n == NULL) {
		return false;
	}

	// If the root is greater than the value
	if (n->data > data){

		// Recursively run with the left child
		return removing(n->leftChild, data);
	}

	// If the data is less than the value
	if (n->data < data) {

		// Recursively remove using the right child
		return removing(n->rightChild, data);
	}

	// If there is no more children...
	if (n->rightChild == NULL && n->leftChild == NULL) {

		// Delete, switch to null, true...
		delete n;
		n = NULL;
		return true;
	}

	// If there is one child
	if (n->rightChild == NULL || n->leftChild == NULL) {

		// Create a temporary pointer that is the left child
		Node* temp;
		temp = n->leftChild;

		// If null switch to right child
		if (n->leftChild == NULL) {
			temp = n->rightChild;
		}

		// Delete the node, return true
		delete n;
		n = temp;
		return true;
	}

	// Create a new temp as left, parent = root
	Node* temp = n->leftChild;
	Node* parent = n;

	// While you can keep gong right...
	while (temp->rightChild != NULL) {

		// Make your way down the tree
		parent = temp;
		temp = temp->rightChild;
	}

	// If root doesn't equal parent
	if (n->data != parent->data) {

		// Switch
		parent->rightChild = temp->leftChild;
	}

	// Otherwise reassign this way
	else parent->leftChild = temp->leftChild;

	// Finally able to delete
	n->data = temp->data;
	delete temp;
	return true;
}

// #####################################################################################################################
// ##																												  ##
// ##											Clearing the Tree 												  	  ##
// ##																												  ##
// #####################################################################################################################

// Again, easier by passing the root
void BST::clear() {

	// Call and set to Null
	clearing(root);
	root = NULL;
}

// The actual clear function
void BST::clearing(Node* n) {

	// Base case - if the root is finally null
	if (n == NULL) {
		return;
	}

	// If there is still a left child
	if (n->leftChild != NULL) {

		// Keep recursively calling it
		clearing(n->leftChild);
	}

	// If there is still a right child
	if (n->rightChild != NULL) {

		// Keep recursively calling it
		clearing(n->rightChild);
	}

	// Delete the Node and return
	delete n;
	return;
}
