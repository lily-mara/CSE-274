//============================================================================
// Name        : main.cpp
// Author      : Nate Mara
//============================================================================

#include "ChainedHashTable.h"

void TestChainedHashTableAdding();
void TestChainedHashTableLongestList();

using namespace std;
using namespace ods;

int main() {
  TestChainedHashTableLongestList();
//  TestChainedHashTableAdding();
  return 0;
}

void TestChainedHashTableLongestList() {
  ChainedHashTable<int> t;
  t.SetLocalFactor(3);
  for (int i = 0; i < 1000; i++) {
    t.add(i);
  }
  cout << t.GetLongestList() << endl;
}

void TestChainedHashTableAdding() {
  ChainedHashTable<int> t;
  t.add(3);
  t.add(4);
  t.add(5);
  t.add(6);
  t.add(7);
  t.add(8);
  t.add(9);
  t.add(0);
  t.add(1);
  t.add(2);

  cout << t.find(0) << endl;
  cout << t.find(2) << endl;
  cout << t.find(10) << endl;
  cout << t.find(100) << endl;
}
