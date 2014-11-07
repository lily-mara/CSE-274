//============================================================================
// Name        : test.cpp
// Author      : Nate Mara
// Version     :
// Copyright   : Your copyright notice
// Description : Test code for the Binary Search Tree classes
//============================================================================

#include <iostream>

#include "BinarySearchTree.h"
#include "BinaryTree.h"

using namespace std;
using namespace ods;

void TestBinaryTreeSize2();

int main() {
  TestBinaryTreeSize2();
  return 0;
}

void TestBinaryTreeSize2() {
  BinarySearchTree<BSTNode1<int>, int> b;

  for(int i = 0; i < 1000; i++) {
    b.add(rand() % 100000);
  }

  assert(b.height2(b.getRoot()) == b.size());
}
