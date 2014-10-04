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
}
