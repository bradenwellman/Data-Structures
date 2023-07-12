#include "NodeInterface.h"
#include "Node.h"
#include "AVLInterface.h"
#include <string>

using namespace std;

// #####################################################################################################################
// ##																												  ##
// ## 											  AVL Class		   													  ##
// ##																												  ##
// #####################################################################################################################

class AVL : public AVLInterface {
public:

	// Root node
	Node * root;

	// Constructor
	AVL() {
		root = NULL;
	}

	// Destructor
	~AVL() {
		clear();
	}

// #####################################################################################################################
// ##																												  ##
// ## 										Definition of Functions													  ##
// ##																												  ##
// #####################################################################################################################

	// Get root node
	NodeInterface * getRootNode() const;

	// Add functions
	bool add(int data);
	bool adding(Node*& n, int value);

	// Remove functions
	bool remove(int data);
	bool removing(Node*& n, int value);

	// Clear Functions
	void clear();
	void clearing(Node*& n);

	// Balancing Functions
	void balanceRight(Node*& n);
	void balanceLeft(Node*& n);
	void balance(Node*& n);

	// Rotating Functions
	void rotateRight(Node*& n);
	void rotateLeft(Node*& n);

	// Foster Parent
	Node* fosterParent(Node*& n);
};
