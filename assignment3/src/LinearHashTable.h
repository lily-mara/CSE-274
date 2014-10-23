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
namespace ods {

extern unsigned int tab[4][256];

template<class T>
class LinearHashTable {

  static const int w = 32;
  static const int r = 8;
  array<T> front;
  array<T> back;
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
  int FindOpenPosition(T x, array<T> &l1, array<T> &l2);

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
    front.fill(null);
    back.fill(null);
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
    front(2), back(2) {
  /*
   this->null = null;
   this->del = del;
   */
  n = 0;
  q = 0;
  d = 2;
}

template<class T>
LinearHashTable<T>::LinearHashTable(T null, T del) :
    front(2, null), back(2, null) {
  this->null = null;
  this->del = del;
  n = 0;
  q = 0;
  d = 2;
}

template<class T>
LinearHashTable<T>::~LinearHashTable() {
}

template<class T>
void LinearHashTable<T>::resize() {
  d = 1;
  while ((1 << d) < 3 * n)
    d++;
  array<T> new_front((1 << d) >> 1, null);
  array<T> new_back((1 << d) >> 1, null);
  q = n;

  // move elements out of front array to new position
  for (int k = 0; k < front.length; k++) {
    int index = FindOpenPosition(front[k], new_front, new_back);
    if (index < new_front.length) {
      new_front[index] = front[k];
    } else {
      new_back[index] = front[k];
    }
  }

// move elements out of back array to new position
  for (int k = 0; k < back.length; k++) {
    int index = FindOpenPosition(back[k], new_front, new_back);
    if (index < new_front.length) {
      new_front[index] = back[k];
    } else {
      new_back[index] = back[k];
    }
  }
  front = new_front;
  back = new_back;
}

template<class T>
int LinearHashTable<T>::FindOpenPosition(T x, array<T> &l1, array<T> &l2) {
  int i = 0;
  int m = 1 << d;
  int index = (hash(x) + i * hash2(x)) % m;

  if (index < l1.length) {
    while (l1[index] != null && l1[index] != del) {
      i++;
      index = (hash(x) + i * hash2(x)) % l1.length;
    }
    return index;

  } else {
    index = index - l1.length;
    while (l2[index] != null && l2[index] != del) {
      i++;
      index = index - l2.length;
    }
    return index + l2.length;
  }
  return -1;
}

template<class T>
int LinearHashTable<T>::FindOpenPosition(T x) {
  return FindOpenPosition(x, front, back);
}

template<class T>
void LinearHashTable<T>::clear() {
  n = 0;
  q = 0;
  d = 1;

  array<T> new_front(2, null);
  front = new_front;

  array<T> new_back(2, null);
  back = new_back;
}

template<class T>
bool LinearHashTable<T>::add(T x) {
  if (2 * (q + 1) > front.length + back.length)
    resize();   // max 50% occupancy
  if (find(x) != null)
    return false;

  int index = FindOpenPosition(x);

  if (index < front.length) {
    if (front[index] == null)
      q++;
    front[index] = x;
  } else {
    index = index - front.length;
    if (back[index] == null)
      q++;
    back[index] = x;
  }

  n++;
  return true;
}

template<class T>
T LinearHashTable<T>::find(T x) {
  int i = 0;
  int m = 1 << d;
  int index = (hash(x) + i * hash2(x)) % m;
  if (index < front.length) {
    while (front[index] != null) {
      if (front[index] != del && front[index] == x)
        return front[index];
      i++;
      index = (hash(x) + i * hash2(x)) % front.length;
    }
  } else {
    index = index - front.length;
    while (back[index] != null) {
      if (back[index] != del && back[index] == x)
        return back[index];
      i++;
      index = (hash(x) + i * hash2(x)) % back.length;
    }
  }
  return null;
}

template<class T>
T LinearHashTable<T>::remove(T x) {
  int i = hash(x);
  while (front[i] != null) {
    T y = front[i];
    if (y != del && x == y) {
      front[i] = del;
      n--;
      if (8 * n < front.length)
        resize(); // min 12.5% occupancy
      return y;
    }
    i = (i == front.length - 1) ? 0 : i + 1;  // increment i
  }
  return null;
}

template<class T>
bool LinearHashTable<T>::addSlow(T x) {
  if (2 * (q + 1) > front.length + back.length)
    resize();   // max 50% occupancy
  int i = hash(x);
  if (i < front.length) {
    while (front[i] != null) {
      if (front[i] != del && x == front[i])
        return false;
      i = (i == front.length - 1) ? 0 : i + 1; // increment i
    }
    front[i] = x;
  } else {
    i = i - back.length;
    while (back[i] != null) {
      if (back[i] != del && x == back[i])
        return false;
      i = (i == back.length - 1) ? 0 : i + 1; // increment i
    }
    back[i] = x;
  }
  n++;
  q++;
  return true;
}

} /* namespace ods */
#endif /* LINEARHASHTABLE_H_ */
