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
void TestBinaryTreeIsBalanced();

int main() {
  TestBinaryTreeSize2();
  TestBinaryTreeIsBalanced();
  return 0;
}

void TestBinaryTreeSize2() {
  BinarySearchTree<BSTNode1<int>, int> b;

  for(int i = 0; i < 10000; i++) {
    b.add(rand() % 100000);
  }

  assert(b.height2(b.getRoot()) == b.height());
}

void TestBinaryTreeIsBalanced() {
  BinarySearchTree<BSTNode1<int>, int> b;

  b.add(4);
  b.add(2);
  b.add(5);
  b.add(1);
  b.add(3);
  b.add(6);

  assert(b.isBalanced());
}
