/*
 * LinearHashTable.h
 *
 *  Created on: 2011-12-16
 *      Author: morin
 */

#ifndef LINEARHASHTABLE_H_
#define LINEARHASHTABLE_H_
#include <climits>
#include <iostream>
using namespace std;
#include "array.h"
#include "DualArray.h"
namespace ods {

extern unsigned int tab[4][256];

template<class T>
class LinearHashTable {

  static const int w = 32;
  static const int r = 8;
  DualArray<T> items;
  int n;   // number of values in this hash table
  int q;   // number of non-null entries in this hash table
  int d;   // t.length = 2^d
  T null, del;
  void resize();
  int hash(T x) {
    return (unsigned) (x % (1 << d));
  }
  int hash2(T x) {
    return 1 + (hash(x) % ((1 << d) - 1));
  }
  int FindOpenPosition(T x);
  int FindOpenPosition(T x, DualArray<T> &some_array);

public:
  // FIXME: get rid of default constructor
  LinearHashTable();
  LinearHashTable(T null, T del);
  virtual ~LinearHashTable();
  bool add(T x);
  bool addSlow(T x);
  T remove(T x);
  T find(T x);
  int size() {
    return n;
  }
  void clear();
  // FIXME: yuck
  void setNull(T null) {
    this->null = null;
    items.fill(null);
  }
  void setDel(T del) {
    this->del = del;
  }
};

/**
 * FIXME: Dangerous - leaves null and del uninitialized
 */
template<class T>
LinearHashTable<T>::LinearHashTable() :
    items(2) {
  /*
   this->null = null;
   this->del = del;
   */
  n = 0;
  q = 0;
  d = 1;
}

template<class T>
LinearHashTable<T>::LinearHashTable(T null, T del) :
    items(2, null) {
  this->null = null;
  this->del = del;
  n = 0;
  q = 0;
  d = 1;
}

template<class T>
LinearHashTable<T>::~LinearHashTable() {
}

template<class T>
void LinearHashTable<T>::resize() {
  d = 1;
  while ((1 << d) < 3 * n)
    d++;
  DualArray<T> new_items((1 << d), null);
  q = n;

  // move elements out of front array to new position
  for (int k = 0; k < items.size(); k++) {
    if (items.get(k) != null && items.get(k) != del) {
      int index = FindOpenPosition(items.get(k), new_items);
      new_items.set(index, items.get(k));
    }
  }

  items = new_items;
}

template<class T>
int LinearHashTable<T>::FindOpenPosition(T x, DualArray<T> &some_array) {
  int i = 0;
  int m = 1 << d;
  int index = (hash(x) + i * hash2(x)) % m;

  while (some_array.get(index) != null && some_array.get(index) != del) {
    i++;
    index = (hash(x) + i * hash2(x)) % some_array.size();
  }
  return index;
}

template<class T>
int LinearHashTable<T>::FindOpenPosition(T x) {
  return FindOpenPosition(x, items);
}

template<class T>
void LinearHashTable<T>::clear() {
  n = 0;
  q = 0;
  d = 1;

  DualArray<T> new_items(2, null);
  items = new_items;
}

template<class T>
bool LinearHashTable<T>::add(T x) {
  if (2 * (q + 1) > items.size())
    resize();   // max 50% occupancy
  if (find(x) != null)
    return false;

  int index = FindOpenPosition(x);

  if (items.get(index) == null)
    q++;
  items.set(index, x);

  n++;
  return true;
}

template<class T>
T LinearHashTable<T>::find(T x) {
  int i = 0;
  int m = 1 << d;
  int index = (hash(x) + i * hash2(x)) % m;

  while (items.get(index) != null) {
    if (items.get(index) != del && items.get(index) == x)
      return items.get(index);
    i++;
    index = (hash(x) + i * hash2(x)) % items.size();
  }

  return null;
}

template<class T>
T LinearHashTable<T>::remove(T x) {
  int i = 0;
  int m = 1 << d;
  int index = (hash(x) + i * hash2(x)) % m;

  while (items.get(index) != null) {
    T y = items.get(index);
    if (y != del && x == y) {
      items.set(index, del);
      n--;
      if (8 * n < items.size())
        resize(); // min 12.5% occupancy
      return y;
    }
    i++;
    index = (hash(x) + i * hash2(x)) % items.size();
  }
  return null;
}

template<class T>
bool LinearHashTable<T>::addSlow(T x) {
  if (2 * (q + 1) > items.size())
    resize();   // max 50% occupancy
  int i = hash(x);

  while (items.get(i) != null) {
    if (items.get(i) != del && x == items.get(i))
      return false;
    i = (i == items.size() - 1) ? 0 : i + 1; // increment i
  }
  items.set(i, x);

  n++;
  q++;
  return true;
}

} /* namespace ods */
#endif /* LINEARHASHTABLE_H_ */
