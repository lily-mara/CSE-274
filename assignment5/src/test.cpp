#include <iostream>
#include "ChainedHashTable.h"
#include "DataStructureTester.h"
#include "LinearHashTable.h"
#include "BinarySearchTree.h"
#include "RedBlackTree.h"

#define TESTS_TO_RUN 100

using namespace std;
using namespace ods;

template<class T>
void TestOneDataStructure(DataStructureTester<T>);
void TestAllDataStructures();
void TestBinarySearchTree();
void TestRedBlackTree();
void TestLinearHashTable();
void TestChainedHashTable();

int main() {
  TestAllDataStructures();

  return 0;
}

void TestBinarySearchTree() {
  DataStructureTester<BinarySearchTree<BSTNode1<int>, int> > test;
  TestOneDataStructure(test);
}

void TestRedBlackTree() {

}

void TestChainedHashTable() {

}

void TestLinearHashTable() {

}

void TestAllDataStructures() {
  for (int i = 0; i < TESTS_TO_RUN; i++) {
    TestBinarySearchTree();
    TestChainedHashTable();
    TestRedBlackTree();
    TestLinearHashTable();
  }
}

template<class T>
void TestOneDataStructure(DataStructureTester<T> tester) {
  tester.DoSequentialAdd(0, 100000, 1);
  tester.DoRandomAdd(100000);
  tester.DoSequentialFind(0, 100000, 1);
  tester.DoSequentialRemove(0, 100000, 1);

  // Do random finds on 100,000 items
  // Do random removes on 100,000 items
}
