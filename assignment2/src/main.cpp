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

void testPalendrome();

template <class T>
void printList(DLList<T> &list);

int main() {
  testPalendrome();
  return 0;
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
