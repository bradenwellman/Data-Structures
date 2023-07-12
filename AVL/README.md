## AVL Tree Project
This is a C++ implementation of an AVL (Adelson-Velsky and Landis) tree data structure. The code provides an AVL class that supports various operations for manipulating and interacting with the AVL tree.

## Features
* Insertion of nodes into the AVL tree (add)
* Removal of nodes from the AVL tree (remove)
* Clearing the AVL tree of all nodes (clear)
* Retrieving the root node of the AVL tree (getRootNode)
* Balancing the AVL tree to maintain its height balance (balance)
* Rotating nodes to maintain the AVL tree's balanced structure (rotateRight, rotateLeft)
* Accessing the left and right child nodes of a specific node (getLeftChild, getRightChild)

## Usage
To use the AVL class, follow these steps:

1. Include the necessary header files in your C++ program.
2. Create an instance of the AVL class.
3. Use the available methods to manipulate and interact with the AVL tree.

Example:

#include <iostream>
#include "AVL.h"

int main() {
    // Create an instance of AVL
    AVL avl;

    // Insert nodes
    avl.add(5);
    avl.add(10);
    avl.add(7);

    // Remove a node
    avl.remove(10);

    // Clear the AVL tree
    avl.clear();

    // Get the root node
    NodeInterface* root = avl.getRootNode();
    if (root != nullptr) {
        // Access left and right child nodes
        NodeInterface* leftChild = root->getLeftChild();
        NodeInterface* rightChild = root->getRightChild();
    }

    return 0;
}
