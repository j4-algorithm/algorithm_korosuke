#include<stdio.h>
#include<stdlib.h>

static int *buff;

static int  __mergesort(int a[], int left, int right)
{
	static int counter = 0;
	counter++;
	if (left < right){
		int center = (left + right) / 2;
		int p = 0;
		int i;
		int j = 0;
		int k = left;

		__mergesort(a, left, center);
		__mergesort(a, center + 1, right);

		for (i = left; i <= center; i++){
			buff[p++] = a[i];
		}
		while (i <= right && j < p){
			if(buff[j] <= a[i]){
				a[k++] = buff[j++];
			}else{
				a[k++] = a[i++];
			}
			
		}
		while (j < p){
			a[k++] = buff[j++];
		}
	}
	return counter;
}

int mergesort(int a[], int n)
{
	int counter = 0;
	if ((buff = calloc(n, sizeof(int))) == NULL){
		return -1;
	}
	counter = __mergesort(a, 0, n - 1);
	free(buff);
	return counter;
}

int main(void)
{
	int counter = 0;
	int nx;
	scanf("%d", &nx);
	int *x = calloc(nx, sizeof(int));
	for (int i = 0; i < nx; i++){
		scanf("%d", &x[i]);
	}
	counter = mergesort(x, nx);
	for (int i = 0; i < nx; i++){
		printf("%d ", x[i]);
	}
	free(x);
	printf("\n");
	printf("%d\n", counter);
	return 0;
}
