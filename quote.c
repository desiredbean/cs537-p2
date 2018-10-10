////////////////////////////////////////////////////////////////////////////////
// Main File: main.c
// This File: quote.c
// Other Files: main.c / quote.c / reader.c / munch1.c / munch2.c / writer.c / quote.h / reader.h / munch1.h / munch2.h / writer.h / makefile
// Semester:         CS 537 Fall 2018
//
// Author:           Ethan Lengfeld / William Pechous
// Email:            elengfeld@wisc.edu / wpechous@wisc.edu
// CS Login:         lengfeld / pechous
//
/////////////////////////// OTHER SOURCES OF HELP //////////////////////////////
//                   fully acknowledge and credit all sources of help,
//                   other than Instructors and TAs.
//
// Persons:          None
//
//
// Online sources:   None
//
//
////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include "quote.h"

Queue *CreateStringQueue(int size){

	Queue *stringQueue = (Queue *) malloc(sizeof(Queue));
	stringQueue->strings = (char**) malloc(sizeof(char*) * 10);
	stringQueue->capacity = size;
	stringQueue->numElements = 0;
	stringQueue->headIndex = 0;
	stringQueue->tailIndex = 0;
	stringQueue->enqueueCount = 0;
	stringQueue->dequeueCount = 0;
	stringQueue->enqueueBlockCount = 0;
	stringQueue->dequeueBlockCount = 0;
	
	return stringQueue;
}

void EnqueueString(Queue *q, char *string){
	if(q->numElements == q->capacity){
		q->enqueueBlockCount++;
		printf("trying to enqueue but queue is full\n");
		// BLOCK!
		
	} else {
		if(q->tailIndex == q->capacity){
			q->tailIndex = 0;
		}
		//q->strings[q->tailIndex] = (char *) malloc(sizeof(char) * sizeof(string));
		q->strings[q->tailIndex] = string;
		q->tailIndex++;
		q->numElements++;
		q->enqueueCount++;
	}
}

char * DequeueString(Queue *q){
	if(q->numElements == 0){
		q->dequeueBlockCount++;
		printf("trying to dequeue but queue is empty\n");
		// BLOCK!
		
	} else {
		if(q->headIndex == q->capacity){
			q->headIndex = 0;
		}
		char *stringToRemove = q->strings[q->headIndex];
		q->headIndex++;
		q->numElements--;
		q->dequeueCount++;
		return stringToRemove;
	}
	
	return NULL;
}

void PrintQueueStats(Queue *q){
	printf("\n\nQUEUE STATS\n");
	printf("enqueueCount = %d\n", q->enqueueCount);
	printf("dequeueCount = %d\n", q->dequeueCount);
	printf("enqueueBlockCount = %d\n", q->enqueueBlockCount);
	printf("dequeueBlockCount = %d\n", q->dequeueBlockCount);
}
