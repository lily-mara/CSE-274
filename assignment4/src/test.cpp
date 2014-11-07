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
void TestBinarySearchTreePreOrder();
void TestBinarySearchTreeInOrder();
void TestBinarySearchTreePostOrder();

int main() {
  TestBinaryTreeSize2();
  TestBinaryTreeIsBalanced();
  TestBinarySearchTreePreOrder();
  TestBinarySearchTreeInOrder();
  TestBinarySearchTreePostOrder();
  return 0;
}

void TestBinarySearchTreePreOrder() {
  BinarySearchTree<BSTNode1<int>, int> b;

  b.add(4);
  b.add(2);
  b.add(5);
  b.add(1);
  b.add(3);
  b.add(6);

  b.preOrderNumber();

  assert(b.getNode(4)->pre_order_ == 0);
  assert(b.getNode(2)->pre_order_ == 1);
  assert(b.getNode(1)->pre_order_ == 2);
  assert(b.getNode(3)->pre_order_ == 3);
  assert(b.getNode(5)->pre_order_ == 4);
  assert(b.getNode(6)->pre_order_ == 5);
}

void TestBinarySearchTreeInOrder() {
  BinarySearchTree<BSTNode1<int>, int> b;

  b.add(4);
  b.add(2);
  b.add(5);
  b.add(1);
  b.add(3);
  b.add(6);

  b.inOrderNumber();

  assert(b.getNode(1)->in_order_ == 0);
  assert(b.getNode(2)->in_order_ == 1);
  assert(b.getNode(3)->in_order_ == 2);
  assert(b.getNode(4)->in_order_ == 3);
  assert(b.getNode(5)->in_order_ == 4);
  assert(b.getNode(6)->in_order_ == 5);
}

void TestBinarySearchTreePostOrder() {
  BinarySearchTree<BSTNode1<int>, int> b;

  b.add(4);
  b.add(2);
  b.add(5);
  b.add(1);
  b.add(3);
  b.add(6);

  b.postOrderNumbers();

  assert(b.getNode(1)->post_order_ == 0);
  assert(b.getNode(3)->post_order_ == 1);
  assert(b.getNode(2)->post_order_ == 2);
  assert(b.getNode(6)->post_order_ == 3);
  assert(b.getNode(5)->post_order_ == 4);
  assert(b.getNode(4)->post_order_ == 5);
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
