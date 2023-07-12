## Binary Search Tree (BST) Project
This is a C++ implementation of a Binary Search Tree (BST) data structure. The code provides a BST class that supports various operations for manipulating and interacting with the binary search tree.

## Features
* Insertion of nodes into the BST (add)
* Removal of nodes from the BST (remove)
* Clearing the BST of all nodes (clear)
* Retrieving the root node of the BST (getRootNode)
* Accessing the left and right child nodes of a specific node (getLeftChild, getRightChild)

## Usage
To use the BST class, follow these steps:

1. Include the necessary header files in your C++ program.
2. Create an instance of the BST class.
3. Use the available methods to manipulate and interact with the binary search tree.

Example:

#include <iostream>
#include "BST.h"

int main() {
    // Create an instance of BST
    BST bst;

    // Insert nodes
    bst.add(5);
    bst.add(10);
    bst.add(7);

    // Remove a node
    bst.remove(10);

    // Clear the BST
    bst.clear();

    // Get the root node
    NodeInterface* root = bst.getRootNode();
    if (root != nullptr) {
        // Access left and right child nodes
        NodeInterface* leftChild = root->getLeftChild();
        NodeInterface* rightChild = root->getRightChild();
    }

    return 0;
}
