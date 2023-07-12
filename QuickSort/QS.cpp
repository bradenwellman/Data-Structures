#include "QS.h"

// #####################################################################################################################
// ##																												  ##
// ##											 CREATE ARRAY														  ##
// ##																												  ##
// #####################################################################################################################

bool QS::createArray(int capacity) {

	// Can not be less than zero
	if (capacity <= 0) {
		return false;
	}

	// Clear
	clear();

	// Create a new array
	myArray = new int[capacity];
	myArrayLength = capacity;

	// Fill it full of a bunch of nulls
	for (int i = 0; i < capacity; i++) {
		myArray[i] = -999999999;
	}

	return true;
}

// #####################################################################################################################
// ##																												  ##
// ##											ADD TO ARRAY														  ##
// ##																												  ##
// #####################################################################################################################

bool QS::addToArray(int value) {

	// Loop through the entire array
	for (int i = 0; i < myArrayLength; i++) {

		// If the index is "null"
		if (myArray[i] == -999999999) {

			// Assign the value and return true
			myArray[i] = value;
			return true;
		}
	}
	return false;
}

// #####################################################################################################################
// ##																												  ##
// ##												  GET ARRAY														  ##
// ##																												  ##
// #####################################################################################################################

string QS::getArray() const{

	// If it is null, or of size zero...
	if (myArray == nullptr || getSize() == 0) {

		// Return nothing
		return "";
	}

	// Create a temporary string variable with first val
	string temp_string = to_string(myArray[0]);

	// Loop through the entire array
	for (int i = 1; i < getSize(); i++) {

		// If it isn't null
		if (myArray[i] != -999999999) {

			// Add a comma and string version of the value
			temp_string += ",";
			temp_string += to_string(myArray[i]);
		}
	}

	return temp_string;
}

// #####################################################################################################################
// ##																												  ##
// ##												  GET SIZE														  ##
// ##																												  ##
// #####################################################################################################################

int QS::getSize() const{

	// As long as it isn't null
	if (myArray != nullptr) {

		// Start counter, loop through the array
		int counter = 0;
		for (int i = 0; i < myArrayLength; i++) {

			// Count non-null values
			if (myArray[i] != -999999999) {
				counter += 1;
			}
		}
		return counter;
	}
	return 0;
}

// #####################################################################################################################
// ##																												  ##
// ##												  SORT ALL														  ##
// ##																												  ##
// #####################################################################################################################


// This is easier just taking a new function that..
void QS::sortAll() {

	// Takes left and right as parameters
	recursion(0, getSize() - 1);
	return;
}

// Recursion function
void QS::recursion(int left, int right) {

	// If left is less than right
	if (left < right) {

		// Median of three and then partition
		int pivot = medianOfThree(left, right);
		pivot = partition(left, right, pivot);

		// If right - left is greater than 5 recursion
		if (right - left > 5) {
			recursion(left, pivot - 1);
			recursion(pivot + 1, right);
		}
	}
	return;
}

// #####################################################################################################################
// ##																												  ##
// ##											 MEDIAN OF THREE													  ##
// ##																												  ##
// #####################################################################################################################


int QS::medianOfThree(int left, int right) {

	// These are all of the problem cases (Empty, Null, Equal, Out of Bounds, Etc)
	if (getSize() == 0 || myArray == nullptr || left + 1 == right || left == right || left < 0 || right > getSize() - 1 || left > right) {
		return -1;
	}

	// Get our values for middle left and right
	int middle = (left + right) / 2;
	int val1 = myArray[left];
	int val2 = myArray[middle];
	int val3 = myArray[right];

	// If Middle is lower than left
	if (val2 < val1) {

		// Switch the two around
		myArray[left] = val2;
		myArray[middle] = val1;

		// Reassign the values
		val1 = myArray[left];
		val2 = myArray[middle];
		val3 = myArray[right];
	}

	// If right is then than "middle"
	if (val3 < val2) {

		// Switch values around
		myArray[middle] = val3;
		myArray[right] = val2;

		// Reassign
		val1 = myArray[left];
		val2 = myArray[middle];
		val3 = myArray[right];
	}

	if (val2 < val1) {

		// Easiest case
		myArray[left] = val2;
		myArray[middle] = val1;
	}

	// Return the middle value
	return middle;
}

// #####################################################################################################################
// ##																												  ##
// ##												  PARTITION														  ##
// ##																												  ##
// #####################################################################################################################

int QS::partition(int left, int right, int pivotIndex) {

	// These are all of the problem cases (Empty, Null, Equal, Out of Bounds, Etc)
	if (getSize() == 0 || myArray == nullptr || left + 1 == right || left == right || left < 0 || right > getSize() - 1 || left > right) {
		return -1;
	}


	// Assign the 2 values
	int val1 = myArray[pivotIndex];
	int val2 = myArray[left];

	// Add to the array
	myArray[left] = val1;
	myArray[pivotIndex] = val2;

	// Augment left
	int i = left + 1;
	int j = right;

	// While the left is less than the right
	while (i < j) {

		// Augment i
		while (myArray[i] < myArray[left]) {
			i++;
		}

		// While j is greater than left
		while (myArray[j] > myArray[left]) {

			// Decrease j
			j--;
		}

		// If they are equal, augment i
		if (myArray[i] == myArray[left]) {
			i++;
		}

		// If j equals left, and j doesn't equal left
		if (myArray[j] == myArray[left] && j != left) {

			// Decrease j
			j--;
		}

		// If i is less than j
		if (i < j) {

			// Swap our values around
			val1 = myArray[i];
			val2 = myArray[j];

			// Reassign
			myArray[i] = val2;
			myArray[j] = val1;
		}
	}

	// If i is greater than j
	if (i >= j) {

		// Swap values around
		val1 = myArray[j];
		val2 = myArray[left];

		// Reassign
		myArray[j] = val2;
		myArray[left] = val1;

		// Retrun J
		return j;
	}
}


// #####################################################################################################################
// ##																												  ##
// ##												  CLEAR															  ##
// ##																												  ##
// #####################################################################################################################

// Clear function
void QS::clear() {

	// Create a temp and set array = to null
	int* temp = myArray;
	myArray = nullptr;


	// Delete the temp
	delete[] temp;

	// Set length = 0
	myArrayLength = 0;
	return;
}