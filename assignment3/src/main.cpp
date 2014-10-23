//============================================================================
// Name        : main.cpp
// Author      : Nate Mara
//============================================================================

#include "ChainedHashTable.h"
#include "LinearHashTable.h"

void TestChainedHashTableAdding();
void TestLinearHashTableAdding();
void TestChainedHashTableLongestList();

using namespace std;
using namespace ods;

int main() {
  TestLinearHashTableAdding();
//  TestChainedHashTableLongestList();
//  TestChainedHashTableAdding();
  return 0;
}

void TestLinearHashTableAdding() {
  LinearHashTable<int> t(-500, -700);

  for (int i = 2; i < 1000; i*=i) {
    t.add(i);
  }

  cout << t.find(4) << endl;
  cout << t.find(2) << endl;
  cout << t.find(10) << endl;
  cout << t.find(99) << endl;
}

void TestChainedHashTableLongestList() {
  ChainedHashTable<int> t;
  t.SetLocalFactor(3);
  for (int i = 0; i < 10000; i++) {
    t.add(i);
  }
  cout << "Longest list (1 < x < 3): " << t.GetLongestList() << endl;
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
