/*
 * main.cpp
 *
 *  Created on: Sep 8, 2014
 *      Author: Nate Mara
 */

#include <iostream>

#include "trequeue.h"

using namespace std;

int main() {
  Trequeue<int> queue;
  queue.set(0, 3);
  queue.set(1, 4);
  queue.set(2, 8);
  queue.set(0, 9);

  cout << queue.size() << endl;
  cout << queue.front.size() << endl;

  queue.front.set(0, 9);
  cout << queue.front.size() << endl;
}
