//============================================================================
// Name        : main.cpp
// Author      : Nate Mara
//============================================================================

#include "ChainedHashTable.h"
#include "LinearHashTable.h"
#include <assert.h>

void TestChainedHashTableAdding();
void TestLinearHashTableAdding();
void TestChainedHashTableLongestList();
void TestLinearHashTableAddSlow();

using namespace std;
using namespace ods;

int main() {
  TestLinearHashTableAdding();
  TestLinearHashTableAddSlow();
//  TestChainedHashTableLongestList();
//  TestChainedHashTableAdding();
  return 0;
}

void TestLinearHashTableAdding() {
  int null = -5000;
  int del = -7000;
  LinearHashTable<int> t(null, del);

  t.add(4);
  t.add(5);
  t.add(100008);

  assert(t.find(5) == 5);
  assert(t.find(7) == null);
  assert(t.find(4) == 4);
  assert(t.find(100008) == 100008);
  assert(t.find(1000) == null);
}

void TestLinearHashTableAddSlow() {
  int null = -5000;
  int del = -7000;
  LinearHashTable<int> t(null, del);

  t.addSlow(4);
  t.addSlow(5);
  t.addSlow(100008);

  assert(t.find(5) == 5);
  assert(t.find(7) == null);
  assert(t.find(4) == 4);
  assert(t.find(100008) == 100008);
  assert(t.find(1000) == null);
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
