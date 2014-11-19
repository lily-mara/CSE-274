#include <iostream>
#include "ChainedHashTable.h"
#include "DataStructureTester.h"
#include "LinearHashTable.h"
#include "BinarySearchTree.h"
#include "RedBlackTree.h"

#define TESTS_TO_RUN 1
#define ADD_REMOVE_FIND_OPERATIONS 5000

using namespace std;
using namespace ods;

template<class T>
void TestOneDataStructure(DataStructureTester<T>, string, int);
void TestAllDataStructures();

int main() {
  cout << "Data Structure,time (ms),test number,test type" << endl;
  TestAllDataStructures();

  return 0;
}

void TestAllDataStructures() {
  for (int i = 0; i < TESTS_TO_RUN; i++) {
    DataStructureTester<BinarySearchTree<BSTNode1<int>, int> > binary_search_tree;
    TestOneDataStructure(binary_search_tree, "Binary Search Tree", i);

    // TestChainedHashTable();
    // TestRedBlackTree();
    // TestLinearHashTable();
  }
}

template<class T>
void TestOneDataStructure(DataStructureTester<T> tester,
    string data_structure_name, int test_number) {

  cout << data_structure_name << ","
      << tester.DoSequentialAdd(0, ADD_REMOVE_FIND_OPERATIONS, 1) << ","
      << test_number << ",sequential add" << endl;

  cout << data_structure_name << ","
      << tester.DoRandomAdd(ADD_REMOVE_FIND_OPERATIONS) << "," << test_number
      << ",random add" << endl;

  cout << data_structure_name << ","
      << tester.DoSequentialFind(0, ADD_REMOVE_FIND_OPERATIONS, 1) << ","
      << test_number << ",sequential find" << endl;

  cout << data_structure_name << ","
      << tester.DoSequentialRemove(0, ADD_REMOVE_FIND_OPERATIONS, 1) << ","
      << test_number << ",sequential remove" << endl;

  // Do random finds on 100,000 items
  // Do random removes on 100,000 items
}
