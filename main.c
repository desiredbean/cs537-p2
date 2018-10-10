////////////////////////////////////////////////////////////////////////////////
// Main File: main.c
// This File: main.c
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
#include "quote.h"
#include "reader.h"
#include "munch1.h"
#include "munch2.h"
#include "writer.h"

const int QUEUE_SIZE = 10;

// TODO REMOVE BEFORE SUBMISSION!
void printQueue(Queue *queue){
	//printf("The HEAD of queue is at element %d\n", queue->headIndex);
	//printf("The TAIL of queue is at element %d\n", queue->tailIndex);
	int pos = queue->headIndex;
	for(int i = 0; i < queue->numElements; i++){
		if(pos == queue->capacity){
			pos=0;
		}
		printf("element %d = %s\n", pos, queue->strings[pos]);
		pos++;
	}
	printf("-----------------------------------------\n-----------------------------------------\n");
}

// TODO REMOVE BEFORE SUBMISSION!
void testQueueFunctionality(Queue *testQueue){
	EnqueueString(testQueue, "apple");
	printQueue(testQueue);
	EnqueueString(testQueue, "orange");
	printQueue(testQueue);
	EnqueueString(testQueue, "rabbit");
	printf("dequeued string = %s\n", DequeueString(testQueue));
	EnqueueString(testQueue, "cold");
	printQueue(testQueue);
	EnqueueString(testQueue, "turkey");
	printf("dequeued string = %s\n", DequeueString(testQueue));
	printQueue(testQueue);
	printf("dequeued string = %s\n", DequeueString(testQueue));
	EnqueueString(testQueue, "diet");
	printQueue(testQueue);
	EnqueueString(testQueue, "queues are really interesting to code and can be difficult");
	printQueue(testQueue);
	EnqueueString(testQueue, "blueberries are honestly the most swell berry that one could ever enjoy with a large smile on their pretty little noodle-head looking face");
	printQueue(testQueue);
	EnqueueString(testQueue, "that last one was pretty long huh....");
	printQueue(testQueue);
	EnqueueString(testQueue, "boi");
	printQueue(testQueue);
	EnqueueString(testQueue, "final entry");
	printQueue(testQueue);
	EnqueueString(testQueue, "let's get full again");
	printQueue(testQueue);
	EnqueueString(testQueue, "one more uhhhhhh");
	printQueue(testQueue);
	
	// queue full message
	EnqueueString(testQueue, "I think I'm full");
	
	DequeueString(testQueue);//1
	DequeueString(testQueue);//2
	DequeueString(testQueue);//3
	DequeueString(testQueue);//4
	DequeueString(testQueue);//5
	DequeueString(testQueue);//6
	DequeueString(testQueue);//7
	DequeueString(testQueue);//8
	DequeueString(testQueue);//9
	DequeueString(testQueue);//10
	
	// queue empty message
	DequeueString(testQueue);
}

//int main(int argc, char *argv[]){
int main(){
	// create queue
	
	// lock the threads


	// TEST QUEUE
	Queue *testQueue = CreateStringQueue(QUEUE_SIZE);
	testQueueFunctionality(testQueue);
	
	
	PrintQueueStats(testQueue);
}
