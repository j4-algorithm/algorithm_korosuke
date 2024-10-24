#include <stdio.h>
#include <string.h>
#include "Node.h"

void PrintNode(const Node *x)
{
  printf("%d", x->v);
}


void PrintLnNode(const Node *x)
{
  printf("%d\n", x->v);
}

Node ScanNode(void) {
  Node temp;
  scanf("%d", &temp.v);
  return temp;
}
