/*
 * random_queue.h
 *
 *  Created on: Sep 4, 2014
 *      Author: maranj
 */

#ifndef RANDOM_QUEUE_H_
#define RANDOM_QUEUE_H_

/*
 * fifo_queue.h
 *
 *  Created on: Sep 2, 2014
 *      Author: stjustpt
 */

class RandomQueue {
private:
  char array[50];
  int size;

public:
  RandomQueue();
  ~RandomQueue();
  bool Enqueue(char item);
  char Dequeue();

};

#endif /* RANDOM_QUEUE_H_ */
