#include "NodeInterface.h"
#include "Node.h"
#include "AVL.h"
#include <string>
using namespace std;

// #####################################################################################################################
// ##																												  ##
// ## 											Get the Root														  ##
// ##																												  ##
// #####################################################################################################################

// Obvious easy function lol
NodeInterface * AVL::getRootNode() const {
	return root;
}

// #####################################################################################################################
// ##																												  ##
// ## 											Adding to Tree														  ##
// ##																												  ##
// #####################################################################################################################


// Like the BST lab, this will be much easier with a separate function that requires Node* andd value
bool AVL::add(int data) {

	// Need a new bool value to return
	bool which;
	which = adding(root, data);
	return(which);
}

// The actual add function lol
bool AVL::adding(Node*& n, int value)
{

	// If the node is empty
	if (n == NULL) {

		// Create a new node and set height to zero
		n = new Node(value);
		n->height = 0;
		return true;
	}

	// If the data already exists
	if (n->data == value) {
		return false;
	}

	// If the data is greater
	if (n->data > value) {

		// Recursively call the function
		bool try_adding = adding(n->leftChild, value);
		if (try_adding) {

			// Check the balance to be greater
			if (n->getBalance() > 1) {
				balanceLeft(n);
			}

			// Check the balance to be less than
			if (n->getBalance() < -1) {
				balanceRight(n);
			}
		}
		return try_adding;
	}

	// If the data is less than the value
	if (n->data < value) {

		// Recursively call the function
		bool try_adding = adding(n->rightChild, value);
		if (try_adding) {

			// Balance the tree
			if (n->getBalance() > 1) {
				balanceLeft(n);
			}

			// Balance the tree
			if (n->getBalance() < -1) {
				balanceRight(n);
			}
		}
		return try_adding;
	}

	// Return false if nothing worked
	return false;
}

// #####################################################################################################################
// ##																												  ##
// ## 										   Remove from Tree														  ##
// ##																												  ##
// #####################################################################################################################

// This function is much easier with a function that requires node pointer as a value
bool AVL::remove(int data) {

	// Define the bool again to return
	bool which;

	// Call the function, balance and return
	which = removing(root, data);
	balance(root);
	return which;

}

// The actual remove function lol
bool AVL::removing(Node*& n, int value) {

	// If null, return false of course
	if (n == NULL) {
		return false;
	}

	// If the data is greater than the value
	if (n->data > value) {

		// Try removing, balance, and return bool
		bool try_removing = removing(n->leftChild, value);
		balance(n);
		return try_removing;
	}

	// If data is less than the value
	if (n->data < value) {

		// Same thing as above
		bool try_removing = removing(n->rightChild, value);
		balance(n);
		return try_removing;
	}

	// If there is no next of kin...
	if (n->rightChild == NULL && n->leftChild == NULL) {

		// Delete, set null, return true
		delete n;
		n = NULL;
		return true;
	}

	// If there is only one child...
	if (n->rightChild == NULL || n->leftChild == NULL) {

		// Create a new temporary pointer
		Node* temp;
		temp = n->leftChild;

		// If the left is null
		if (n->leftChild == NULL) {
			temp = n->rightChild;
		}

		// Delete n, set as temp
		delete n;
		n = temp;

		// Balance and return true
		balance(n);
		return true;
	}

	// Foster parent
	Node* temp = fosterParent(n->leftChild);

	// Reassign everything
	temp->leftChild = n->leftChild;
	temp->rightChild = n->rightChild;

	// Delete and return true
	delete n;
	n = temp;
	return true;
}

// #####################################################################################################################
// ##																												  ##
// ## 											Foster Parent														  ##
// ##																												  ##
// #####################################################################################################################

Node* AVL::fosterParent(Node*& n) {

	// If right child is null
	if (n->rightChild == NULL) {

		// Reassign everything
		Node* temp = n;
		n = n->leftChild;
		return temp;
	}

	// Recurse, balance, return
	Node* temp = fosterParent(n->rightChild);
	balance(n);
	return temp;
}

// #####################################################################################################################
// ##																												  ##
// ## 										  Clear the AVL Tree													  ##
// ##																												  ##
// #####################################################################################################################

// Another function that is much easier passign the root
void AVL::clear() {

	// Pass the root and set to null
	clearing(root);
	root = NULL;
}

// The *actual* clear function lol
void AVL::clearing(Node*& n) {

	// If n is null then this is POINTLESS
	if (n == NULL) {
		return;
	}

	// If the left child is null, clear
	if (n->leftChild != NULL){
		clearing(n->leftChild);
	}

	// If the right child is null, also clear
	if (n->rightChild != NULL){
		clearing(n->rightChild);
	}

	// Delete and return
	delete n;
	return;
}

// #####################################################################################################################
// ##																												  ##
// ## 										Balance Right Side														  ##
// ##																												  ##
// #####################################################################################################################


void AVL::balanceRight(Node*& n) {

	// If n = null, return
	if (n == NULL) {
		return;
	}

		// If balance >= 1
		if (n->leftChild->getBalance() >= 1) {

			// Rotate left
			rotateLeft(n->leftChild);
		}

		// Rotate right
		rotateRight(n);
}

// #####################################################################################################################
// ##																												  ##
// ## 										Balance Left Side														  ##
// ##																												  ##
// #####################################################################################################################

// Balance the left side of the tree
void AVL::balanceLeft(Node*& n) {

	// As always, return if null
	if (n == NULL) {
		return;
	}

		// If balance <= -1
		if (n->rightChild->getBalance() <= -1) {

			// Rotate
			rotateRight(n->rightChild);
		}

		// Rotate left
		rotateLeft(n);
}

// #####################################################################################################################
// ##																												  ##
// ## 										Rotate Right Side														  ##
// ##																												  ##
// #####################################################################################################################

void AVL::rotateRight(Node*& n) {

	// Use a temp to reassign all our values
	Node* temp = n->leftChild;
	n->leftChild = temp->rightChild;
	temp->rightChild = n;
	n = temp;
}

// #####################################################################################################################
// ##																												  ##
// ## 										Rotate Left Side														  ##
// ##																												  ##
// #####################################################################################################################

void AVL::rotateLeft(Node*& n) {

	// The same code as above
	Node* temp = n->rightChild;
	n->rightChild = temp->leftChild;
	temp->leftChild = n;
	n = temp;
}

// #####################################################################################################################
// ##																												  ##
// ## 										Balance the Tree:)														  ##
// ##																												  ##
// #####################################################################################################################

void AVL::balance(Node*& n) {

	// As always, if null then return
	if (n == NULL) {
		return;
	}

	// If balance greater than 1, balance left
	if (n->getBalance() > 1) {
		balanceLeft(n);
	}

	// Else if balance < -1, balance right
	else if (n->getBalance() < -1)
		balanceRight(n);

		// Balance
		balance(n->leftChild);
		balance(n->rightChild);
}
