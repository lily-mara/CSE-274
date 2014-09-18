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
private:
  ods::ArrayDeque<T> front;
  ods::ArrayDeque<T> back;
public:
  Trequeue();
  ~Trequeue();
  int size();
  T get(int);
  void set(int, int);
  void add(int, int);
  T remove(int);
  void clear();
  void balance();
};

template <class T>
Trequeue<T>::Trequeue() {
}

template <class T>
Trequeue<T>::~Trequeue() {
}

template <class T>
void Trequeue<T>::clear() {
  this->front.clear();
  this->back.clear();
}

template <class T>
int Trequeue<T>::size() {
  return this->front.size() + this->back.size();
}

template <class T>
T Trequeue<T>::get(int index) {
  if (index > this->front.size()) {
    return this->back.get(index - this->front.size());
  }
  return this->front.get(index);
}

template <class T>
void Trequeue<T>::set(int index, int value) {
  if (index > this->size() / 2) {
    this->back.set(index - this->front.size(), value);
  }
  this->front.set(index, value);
}

template <class T>
void Trequeue<T>::add(int index, int value) {
  if (index > this->front.size()) {
    this->back.add(index - this->front.size(), value);
  } else {
    this->front.add(index, value);
  }
}

template <class T>
T Trequeue<T>::remove(int index) {
  if (index > this->front.size()) {
    this->back.remove(index - this->front.size());
  } else {
    this->front.remove(index);
  }
}

template <class T>
void Trequeue<T>::balance() {
  int frontSize = this->size() / 2;
  int backSize = this->size() - frontSize;

  ods::ArrayDeque<T> newFront;
  ods::ArrayDeque<T> newBack;

  for (int i = 0; i < frontSize; i++) {
    newFront.add(i, this->get(i));
  }

  for (int i = 0; i < backSize; i++) {
    newBack.add(i, this->get(frontSize + i));
  }

  this->front = newFront;
  this->back = newBack;
}

#endif
