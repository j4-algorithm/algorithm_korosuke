#include<stdio.h>

#define AMAX   99

typedef struct{
	char   name[20];
	int    height;
	int    age;
}PhysCheck;

double ave_height(const PhysCheck dat[], int n)
{	
	double sum = 0;
	for (int i = 0; i < n; i++)
		sum += dat[i].height;

	return sum / n;
}

void dist_age(const PhysCheck dat[], int n, int dist[])
{
	for (int i = 0; i < AMAX; i++)
		dist[i] = 0;

	for(int i = 0; i < n; i++)
		if (dat[i].age >= 0 && dat[i].age <= AMAX )
			dist[dat[i].age / 10]++;
}

int main(void)
{
	PhysCheck x[] = {
		{"01 001", 162,  5},
		{"02 002", 142, 15},
		{"03 003", 132, 13},
		{"04 004", 152, 15},
		{"05 005", 162, 21},
		{"06 006", 172, 23},
		{"07 007", 182, 15},
		{"08 008", 192, 78},
		{"09 009", 161, 89},
		{"10 010", 170, 44},
		{"11 011", 140, 53},
		{"12 012", 170, 99},
		{"13 013", 180, 74},
		{"14 014", 173, 99},
		{"15 015", 121, 32},
		{"16 016", 111, 99},
		{"17 017", 170, 34},
		{"18 018", 170, 99},
		{"19 019", 170, 72},
		{"20 020", 170, 36},
	};
	int nx = sizeof(x) / sizeof(x[0]);
	int adist[AMAX];

	for (int i = 0; i < nx; i++)
		printf("%s,%d,%d\n", x[i].name, x[i].height, x[i].age);

	printf("%5.1f\n", ave_height(x, nx));
	dist_age(x, nx, adist);
	for (int i = 0; i <= AMAX / 10; i++){
		printf("%d〜：%2d人\n", i * 10, adist[i]);
	}
	return 0;
}