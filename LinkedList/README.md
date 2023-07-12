## LinkedList Implementation
This is a C++ implementation of a singly linked list data structure. The code provides a LinkedList class that supports various operations for manipulating and interacting with the linked list.

## Features
* Insertion of nodes at the head (insertHead) or tail (insertTail) of the list
* Insertion of a node after a specific node (insertAfter)
* Removal of a node with a given value (remove)
* Clearing the list of all nodes (clear)
* Accessing the value of a node at a specific index (at)
* Retrieving the number of nodes in the list (size)
* Converting the list to a string representation (toString)

## Usage
To use the LinkedList class, follow these steps:

1. Include the LinkedList.h header file in your C++ program.
2. Create an instance of the LinkedList class, specifying the desired type for the elements in the list (e.g., LinkedList<int> for integer values or LinkedList<string> for string values).
3. Use the available methods to manipulate and interact with the linked list.

Example:

#include "LinkedList.h"

int main() {
    // Create an instance of LinkedList with integers
    LinkedList<int> myList;

    // Insert nodes
    myList.insertHead(5);
    myList.insertTail(10);
    myList.insertAfter(7, 5);

    // Print the list
    std::cout << "List: " << myList.toString() << std::endl;

    // Remove a node
    myList.remove(10);

    // Access a node at a specific index
    int value = myList.at(1);
    std::cout << "Value at index 1: " << value << std::endl;

    // Get the size of the list
    int size = myList.size();
    std::cout << "List size: " << size << std::endl;

    // Clear the list
    myList.clear();

    return 0;
}

