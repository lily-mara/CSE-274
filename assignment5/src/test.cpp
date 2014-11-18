#include <iostream>
#include "ChainedHashTable.h"
#include "DataStructureTester.h"
#include "LinearHashTable.h"
#include "BinarySearchTree.h"
#include "RedBlackTree.h"

#define TESTS_TO_RUN 1

using namespace std;
using namespace ods;

template<class T>
void TestOneDataStructure(DataStructureTester<T>);
void TestAllDataStructures();

int main() {
  TestAllDataStructures();

  return 0;
}

void TestAllDataStructures() {
  for (int i = 0; i < TESTS_TO_RUN; i++) {
    DataStructureTester<BinarySearchTree<BSTNode1<int>, int> > binary_search_tree;
    TestOneDataStructure(binary_search_tree);

    // TestChainedHashTable();
    // TestRedBlackTree();
    // TestLinearHashTable();
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
