#include <iostream>
#include "ChainedHashTable.h"
#include "DataStructureTester.h"
#include "LinearHashTable.h"
#include "BinarySearchTree.h"
#include "RedBlackTree.h"

using namespace std;
using namespace ods;

int main() {
  DataStructureTester<BinarySearchTree<BSTNode1<int>,int> > test;
  test.AddRandom(10);

  for (int i = 0; i < 100000; i++) {
    test.AddRandom(i);
  }

  DataStructureTester<RedBlackTree<RedBlackNode1<int>,int> > test2;
   test2.AddRandom(10);
}
