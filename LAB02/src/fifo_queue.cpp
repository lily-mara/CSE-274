/*
 * fifo_queue.cpp
 *
 *  Created on: Sep 2, 2014
 *      Author: maranj
 */

#include "fifo_queue.h"

FifoQueue::FifoQueue() {
  // complexity is O(n)
  for (int i = 0; i < 50; i++) {
    this->array[i] = 0;
  }
}

bool FifoQueue::Enqueue(char item) {
  for (int i = 0; i < 50; i++) {
    if (this->array[i] == 0) {
      this->array[i] = item;
      return true;
    }
  }
  return false;
}

char FifoQueue::Dequeue() {
  return 0;
}
