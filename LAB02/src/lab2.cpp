//============================================================================
// Name        : lab2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "fifo_queue.h"
using namespace std;

int main() {
  FifoQueue queue;
  queue.Enqueue('a');
  queue.Enqueue('b');
  cout << queue.Dequeue() << endl;
  cout << queue.Dequeue() << endl;
	return 0;
}
