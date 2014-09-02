/*
 * fifo_queue.h
 *
 *  Created on: Sep 2, 2014
 *      Author: maranj
 */

#ifndef FIFO_QUEUE_H_
#define FIFO_QUEUE_H_

class FifoQueue {
private:
  char array[50];

public:
  FifoQueue();
  void Enqueue(char item);
  char Dequeue();

};

#endif /* FIFO_QUEUE_H_ */
