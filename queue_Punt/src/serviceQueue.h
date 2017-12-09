/*
 * serviceQueue.h
 *
 *  Created on: 29 gen 2017
 *      Author: angelo
 */

#ifndef SERVICEQUEUE_H_
#define SERVICEQUEUE_H_
#include "queue.h"

void autoAcquisition(Queue &);
void printQueue(Queue &);
void empty(Queue &);
int numberElements(Queue &);
boolean searchElement(Queue &,typeElem);
void cancElement(Queue &);




#endif /* SERVICEQUEUE_H_ */
