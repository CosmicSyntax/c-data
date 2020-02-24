#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// struct definitions: Node and List
typedef struct Node {
	int data;
	struct Node* node;
} Node;

typedef struct List {
	Node* head;
	Node* tail;
} List;

// Function that creates a new instance of a List
List* make(int d) {
	List* new_list = malloc(sizeof(List));
	Node* new_node = malloc(sizeof(Node));

	new_node->data = d;
	new_node->node = NULL;

	new_list->head = new_node;
	new_list->tail = NULL;

	return new_list;
}

// Function that takes the instances of the List, and chains
// a new node to the linked list
void add(int d, List* list) {
	Node* new_node = malloc(sizeof(Node));
	new_node->data = d;

	if (list->tail == NULL) {
		// if it is NULL, it means it's the second entry
		// and you interact with head
		list->head->node = new_node;
		list->tail = new_node;
	} else {
		list->tail->node = new_node;
		list->tail = new_node;
	}

}

// Function that takes the linked list and traverses it
void print_list(List* list) {
	// traverse from head to end of list
	Node* current_node = list->head;
	int i = 1;
	while (1) {
		printf("Node #%d is %d.\n", i, current_node->data);
		// move to the next node
		current_node = current_node->node;
		if (current_node->node == NULL) {
			i++;
			printf("Node #%d is %d.\nEnd of List.\n",i , current_node->data);
			break;
		}
		i++;
	}
}

// Function to de-allocate memory for the linked list
void destroy(List* list) {
	// de-allocate all the nodes
	Node* current_node = list->head;
	while (1) {
		if (current_node->node != NULL) {
			Node* next_node = current_node->node;
			printf("De-allocating Node with value %d.\n", current_node->data);
			free(current_node);
			current_node = next_node;
		} else {
			// When the node of the current Node is NULL, you still need to clear
			// the current node. 
			printf("De-allocating Node with value %d.\n", current_node->data);
			free(current_node);
			break;
		}
	}
	// Now free the list
	free(list);
	// Calling the list after the destroy pops of the stack will now lead to UB
}
