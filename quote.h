////////////////////////////////////////////////////////////////////////////////
// Main File: main.c
// This File: quote.h
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

#ifndef QUOTE
#define QUOTE

typedef struct{
	char **strings;
	int capacity;
	int numElements;
	int headIndex;
	int tailIndex;
	int enqueueCount;
	int dequeueCount;
	int enqueueBlockCount;
	int dequeueBlockCount;
}Queue;	

Queue *CreateStringQueue(int size);

void EnqueueString(Queue *q, char *string);

char * DequeueString(Queue *q);

void PrintQueueStats(Queue *q);

#endif
