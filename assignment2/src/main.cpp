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
void PrintList(DLList<T> &list);
void TestPalendrome();
void TestRotate();
void TestAbsorb();
void TestDeal();

int main() {
  cout << "Test IsPalendrome..." << endl;
  TestPalendrome();

  cout << endl << "Test Rotate..." << endl;
  TestRotate();

  cout << endl << "Test absorb..." << endl;
  TestAbsorb();

  cout << endl << "Test deal..." << endl;
  TestDeal();
  return 0;
}

void TestDeal() {
  DLList<int> nums;
  nums.add(0);
  nums.add(1);
  nums.add(2);
  nums.add(3);
  nums.add(4);
  nums.add(5);
  nums.add(6);
  nums.add(7);
  nums.add(8);
  nums.add(9);

  cout << "List before deal: ";
  PrintList(nums);

  DLList<int> oddNums = nums.deal();
  cout << "List after deal: ";
  PrintList(nums);

  cout << "New list created by deal: ";
  PrintList(oddNums);
}

void TestAbsorb() {
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
  PrintList(nate);

  cout << "List 2: ";
  PrintList(mara);

  cout << "Combine lists into one..." << endl;
  nate.absorb(mara);

  cout << "List 1 after absorb: ";
  PrintList(nate);

  cout << "List 2 after absorb: ";
  PrintList(mara);
}

void TestRotate() {
  DLList<char> nate;
  nate.add('n');
  nate.add('a');
  nate.add('t');
  nate.add('e');

  cout << "Before rotation: ";
  PrintList(nate);

  nate.Rotate(1);

  cout << "After rotation of 1: ";
  PrintList(nate);

  nate.Rotate(2);

  cout << "After rotation of 2: ";
  PrintList(nate);
}

void TestPalendrome() {
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
void PrintList(DLList<T> &list) {
  cout << "[ ";

  if (list.size() > 0) {
    for (int i = 0; i < list.size() - 1; i++) {
      cout << list.get(i) << ", ";
    }

    cout << list.get(list.size() - 1);
  }
  cout << " ]" << endl;
}
