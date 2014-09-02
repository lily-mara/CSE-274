/*
 * fifo_queue.cpp
 *
 *  Created on: Sep 2, 2014
 *      Author: maranj
 */

#include "fifo_queue.h"

FifoQueue::FifoQueue() {
  // complexity is O(n)
  for (int i = 0; i < sizeof(this->array); i++) {
    this->array[i] = 0;
  }
}

bool FifoQueue::Enqueue(char item) {
  for (int i = 0; i < sizeof(this->array); i++) {
    if (this->array[i] == 0) {
      this->array[i] = item;
      return true;
    }
  }
  return false;
}

char FifoQueue::Dequeue() {
  char result = this->array[0];
  for (int i = 0; i < sizeof(this->array) - 1; i++) {
    this->array[i] = this->array[i + 1];
    if (this->array[i + 1] == 0) {
      break;
    }
  }
  this->array[sizeof(this->array) - 1] = 0;
  return result;
}
