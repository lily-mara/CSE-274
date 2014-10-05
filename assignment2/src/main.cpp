/*
 * main.cpp
 *
 *  Created on: Sep 23, 2014
 *      Author: maranj
 */

#include <iostream>
#include <assert.h>

#include "DLList.h"

using ods::DLList;
using std::cout;
using std::endl;
using std::cin;

template <class T>
void printList(DLList<T> &list);
void testPalendrome();
void testRotate();

int main() {
  testPalendrome();
  testRotate();
  return 0;
}

void testRotate() {
  DLList<char> nate;
  nate.add('n');
  nate.add('a');
  nate.add('t');
  nate.add('e');

  cout << "Before rotation: ";
  printList(nate);

  nate.Rotate(1);

  cout << "After rotation of 1: ";
  printList(nate);
}

void testPalendrome() {
  DLList<char> bob;
  bob.add('b');
  bob.add('o');
  bob.add('b');

  assert(bob.IsPalendrome());

  DLList<int> nums;
  nums.add(0);
  nums.add(1);
  nums.add(2);
  nums.add(3);
  nums.add(3);
  nums.add(2);
  nums.add(1);
  nums.add(0);

  assert(nums.IsPalendrome());

  DLList<int> notNums;
  notNums.add(0);
  notNums.add(1);
  notNums.add(3);
  notNums.add(2);
  notNums.add(1);
  notNums.add(0);

  assert(!notNums.IsPalendrome());
}

template <class T>
void printList(DLList<T> &list) {
  cout << "[ ";

  for (int i = 0; i < list.size() - 1; i++) {
	cout << list.get(i) << ", ";
  }

  cout << list.get(list.size() - 1) << " ]" << endl;
}
