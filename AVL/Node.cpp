#include <iostream>
#include "Node.h"

// #####################################################################################################################
// ##																												  ##
// ## 										  Getter Functions		   												  ##
// ##																												  ##
// #####################################################################################################################

	// The data
	int Node::getData() const {
    return data;
  }

  	// Left child
	NodeInterface * Node::getLeftChild() const {
    return leftChild;
  }

  	// Right child
	NodeInterface * Node::getRightChild() const {
    return rightChild;
  }

// #####################################################################################################################
// ##																												  ##
// ## 											  Get Height		   												  ##
// ##																												  ##
// #####################################################################################################################

	int Node::getHeight() {

		// Set left and right = zero
		int leftHeight = 0;
		int rightHeight = 0;

		// If null...
		if (leftChild != NULL) {
			leftHeight = leftChild->getHeight();
		}

		// If null...
		if (rightChild != NULL) {
			rightHeight = rightChild->getHeight();
		}

		// Return the maximum height
		return max(leftHeight, rightHeight) + 1;
	}

// #####################################################################################################################
// ##																												  ##
// ## 											  Get Balance		   												  ##
// ##																												  ##
// #####################################################################################################################

	int Node::getBalance() {

		// Define
		int right;
		int left;

		// If null
		if (rightChild != NULL) {
			right = rightChild->getHeight();
		}
		else {
			right = 0;
		}

		// If left is null
		if (leftChild != NULL) {
			left = leftChild->getHeight();
		}
		else {
			left = 0;
		}

		// Return the difference
		return right - left;
	}
