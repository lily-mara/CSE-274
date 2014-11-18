#include <iostream>
#include "ChainedHashTable.h"
#include "DataStructureTester.h"
#include "LinearHashTable.h"
#include "BinarySearchTree.h"
#include "RedBlackTree.h"

using namespace std;
using namespace ods;

int main() {
  DataStructureTester<BinarySearchTree<BSTNode1<int>, int> > test;
  cout << test.AddRandom(10000) << endl;
  cout << test.DoSequentialAdd(0, 1000000, 100) << endl;

  return 0;
}
