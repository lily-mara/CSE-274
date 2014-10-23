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
void TestLinearHashTableRemoving();

using namespace std;
using namespace ods;

int main() {
  TestLinearHashTableAdding();
  TestLinearHashTableAddSlow();
  TestChainedHashTableLongestList();
  TestChainedHashTableAdding();
  TestLinearHashTableRemoving();
  return 0;
}

void TestLinearHashTableRemoving() {
  int null = -5000;
  int del = -7000;
  LinearHashTable<int> t(null, del);

  for (int i = 0; i < 20; i++) {
    t.add(i);
  }

  for (int i = 0; i < 20; i+=2) {
    t.remove(i);
  }

  assert(t.find(1) == 1);
  assert(t.find(2) == del || t.find(2) == null);
  assert(t.find(3) == 3);
  assert(t.find(4) == del || t.find(4) == null);
  assert(t.find(5) == 5);
  assert(t.find(6) == del || t.find(6) == null);

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
  assert(t.GetLongestList() <= 3);
}

void TestChainedHashTableAdding() {
  ChainedHashTable<int> t;
  t.add(0);
  t.add(1);
  t.add(2);
  t.add(3);
  t.add(4);
  t.add(5);
  t.add(6);
  t.add(7);
  t.add(8);
  t.add(9);

  assert(t.find(2) == 2);
  assert(t.find(1000) != 1000);
  assert(t.find(9) == 9);
  assert(t.find(5) == 5);
  assert(t.find(4128439) != 4128439);
}
