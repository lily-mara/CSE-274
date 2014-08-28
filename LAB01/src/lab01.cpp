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
	cout << "area: " << rect.area();
	return 0;
}
