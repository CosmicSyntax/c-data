// Implementing singly linked list in C
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "lib/list.h"

int main(void) {

	List* mylist = make(20);

	// Generate 499 random numbers and append to list
	time_t t;
	srand((unsigned int) time(&t));
	for (int i = 0; i < 499; i++) {
		add(rand(), mylist);
	}

	print_list(mylist);

	destroy(mylist);
	return 0;

}
