#ifndef LISTC
	#define LISTC
	typedef struct Node Node;
	typedef struct List List;

	List* make(int d);
	void add(int d, List* list);
	void print_list(List* list);
	void destroy(List* list);
#endif
