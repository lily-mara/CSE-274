//============================================================================
// Name        : lab01.cpp
// Author      : Nate Mara
//============================================================================

// classes example
#include <iostream>
#include "rectangle.h"

using namespace std;

int main() {
	Rectangle rect;
	rect.set_values(3, 4);

	// Java: Rectangle rect2 = rect.clone()
	// clones object
	Rectangle rect2 = rect;

	// Java: Rectangle rectRef = rect
	// creates a reference
	Rectangle &rectRef = rect;

	// same as `Rectangle *pRect = &rect;`
	// creates a pointer
	Rectangle *pRect;
	pRect = &rect;

	// use this syntax to create a new object on the heap
	// by default, c++ objects are created on the stack
	Rectangle *rectHeap = new Rectangle();

	rect2.set_values(2, 3);
	rectRef.set_values(1, 1);

	cout << "area1: " << rect.area() << endl;
	cout << "area2: " << rect2.area() << endl;
	cout << "rect pointer: " << pRect << endl;
	cout << "rect pointer area: " << pRect->area() << endl;
	return 0;
}
