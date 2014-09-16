/*
 * main.cpp
 *
 *  Created on: Sep 8, 2014
 *      Author: Nate Mara
 */

#include <iostream>

#include "trequeue.h"

using namespace std;

template <class T>
void printQueue(Trequeue<T>);

int main() {
  Trequeue<int> queue;
  queue.add(0, 3);
  queue.add(1, 4);
  queue.add(2, 8);
  queue.add(0, 9);
  queue.add(0, 10);
  queue.add(0, 11);
  queue.add(0, 12);

  printQueue(queue);

  return 0;
}

template <class T>
void printQueue(Trequeue<T> queue) {
//  cout << "[";

//  for (int i = 0; i < queue.size() - 1; i++) {
//    cout << queue.get(i) << ", ";
//  }

//  cout << queue.get(queue.size() - 1) << "]" << endl;
}
