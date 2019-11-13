#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_SIZE 60000
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))

int original[MAX_SIZE];
int list[MAX_SIZE];
int n;
int sorted[MAX_SIZE];
clock_t start, finish, used_time = 0;

int partition(int list[], int left, int right);
void quick_sort(int list[], int left, int right);
void CalcTime(void);

int main() {
	int i;

	srand((unsigned int)time(NULL));
	n = MAX_SIZE;
	for (i = 0; i < n; i++)
		original[i] = rand();
	printf("데이터의 개수 : %d\n\n", n);

	start = clock();
	printf("퀵 정렬 중...");
	quick_sort(list, 0, n);
	finish = clock();
	CalcTime();
}

int partition(int list[], int left, int right) {
	int pivot = list[left], tmp, low = left, high = right + 1;

	do {
		do
			low++;
		while (low <= right && list[low] < pivot);

		do
			high--;
		while (high >= left && list[high] > pivot);
		if (low < high)
			SWAP(list[low], list[high], tmp);
	} while (low < high);

	SWAP(list[left], list[high], tmp);
	return high;
}

void quick_sort(int list[], int left, int right) {
	if (left < right) {
		int q = partition(list, left, right);
		quick_sort(list, left, q - 1);
		quick_sort(list, q + 1, right);
	}
}

void CalcTime(void) {
	used_time = finish - start;
	printf("완료!\n소요 시간 : %f sec\n\n", (float)used_time / CLOCKS_PER_SEC);
}
