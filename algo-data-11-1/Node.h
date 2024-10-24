#ifndef ___Node
#define ___Node

typedef struct __node {
	int         v;
	struct __node *next;
} Node;

void PrintNode(const Node* x);
void PrintLnNode(const Node* x);
Node ScanNode(void);

#endif
