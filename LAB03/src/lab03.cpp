//============================================================================
// Name        : lab03.cpp
// Author      : Nate Mara
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "random_queue.h"
using namespace std;

int main() {
	RandomQueue queue;
	queue.Enqueue('a');
	queue.Enqueue('b');
	queue.Enqueue('c');
	queue.Enqueue('d');
	cout << "result: " << queue.Dequeue() << endl << endl;
	cout << "result: " << queue.Dequeue() << endl << endl;
	cout << "result: " << queue.Dequeue() << endl << endl;

	return 0;
}
