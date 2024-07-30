// Bucket（ソース部）

#include <stdio.h>
#include <string.h>
#include "Bucket.h"

int BucketCmp(const Bucket *x, const Bucket *y)
{
  if (x->v > y->v) {
    return 1;
  } else if (x->v == y->v) {
    return 0;
  } else {
    return -1;
  }
}


void PrintBucket(const Bucket *x)
{
  printf("%d", x->v);
}


void PrintLnBucket(const Bucket *x)
{
  printf("%d\n", x->v);
}

Bucket ScanBucket() {
  Bucket temp;

  scanf("%d", &temp.v);

  return temp;
}
