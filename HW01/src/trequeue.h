/*
 * trequeue.h
 *
 *  Created on: Sep 11, 2014
 *      Author: Nate Mara
 */

#ifndef TREQUEUE_H_
#define TREQUEUE_H_
#include "ArrayDeque.h"

template <class T>
class Trequeue {
protected:
  ArrayDeque front;
  ArrayDeque back;
public:
  int size();
  T get(int);
  T set(int, int);
  void add(int, int);
  T remove(int);
}

#endif
