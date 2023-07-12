#pragma once
#include <array>
#include "QSInterface.h"

class QS :public QSInterface {
public:

// #####################################################################################################################
// ##																												  ##
// ##										  Constructor / Destructor												  ##
// ##																												  ##
// #####################################################################################################################

	QS() : myArray(nullptr), myArrayLength(0) {};
	~QS() { clear(); };

// #####################################################################################################################
// ##																												  ##
// ##										  		 Functions												  		  ##
// ##																												  ##
// #####################################################################################################################

	bool createArray(int capacity);
	bool addToArray(int value);
	string getArray() const;
	int getSize() const;
	void sortAll();
	int medianOfThree(int left, int right);
	int partition(int left, int right, int pivotIndex);
	void clear();
	void recursion(int left, int right);
	void swapVal(int first, int second);

// #####################################################################################################################
// ##																												  ##
// ##										 	   Private Values													  ##
// ##																												  ##
// #####################################################################################################################

private:
	int* myArray;
	int myArrayLength;
};