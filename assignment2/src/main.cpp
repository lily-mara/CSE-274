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
void testAbsorb();

int main() {
  // testPalendrome();
  // testRotate();
  testAbsorb();
  return 0;
}

void testAbsorb() {
  DLList<char> nate;
  nate.add('N');
  nate.add('a');
  nate.add('t');
  nate.add('e');
  nate.add(' ');

  DLList<char> mara;
  mara.add('M');
  mara.add('a');
  mara.add('r');
  mara.add('a');

  cout << "List 1: ";
  printList(nate);

  cout << "List 2: ";
  printList(mara);

  cout << "Combine lists into one..." << endl;
  nate.absorb(mara);

  cout << "List 1 after absorb: ";
  printList(nate);

  cout << "List 2 after absorb: ";
  printList(mara);
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

  if (list.size() > 0) {
    for (int i = 0; i < list.size() - 1; i++) {
      cout << list.get(i) << ", ";
    }

    cout << list.get(list.size() - 1);
  }
  cout << " ]" << endl;
}
