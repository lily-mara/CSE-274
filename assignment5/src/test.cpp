#include <iostream>
#include "ChainedHashTable.h"
#include "DataStructureTester.h"
#include "LinearHashTable.h"
#include "BinarySearchTree.h"
#include "RedBlackTree.h"

const int TESTS_TO_RUN = 1;
const int ADD_REMOVE_FIND_OPERATIONS = 5000;

using namespace std;
using namespace ods;

template<class T>
void TestOneDataStructure(DataStructureTester<T>&, string, int);
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

    DataStructureTester<ChainedHashTable<int> > chained_hash_table;
    TestOneDataStructure(chained_hash_table, "Chained Hash Table", i);

    DataStructureTester<LinearHashTable<int> > linear_hash_table;
    TestOneDataStructure(linear_hash_table, "Linear Hash Table", i);

    DataStructureTester<RedBlackTree<RedBlackNode1<int>, int> > red_black_tree;
    TestOneDataStructure(red_black_tree, "Red Black Tree", i);
  }
}

template<class T>
void TestOneDataStructure(DataStructureTester<T>& tester,
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

  cout << data_structure_name << ","
      << tester.DoRandomFind(ADD_REMOVE_FIND_OPERATIONS) << ","
      << test_number << ",random find" << endl;

  cout << data_structure_name << ","
      << tester.DoRandomRemove(ADD_REMOVE_FIND_OPERATIONS) << ","
      << test_number << ",random remove" << endl;
}
