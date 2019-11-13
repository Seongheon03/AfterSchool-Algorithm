#include <stdio.h>

int max(int a, int b);
int knapSack(int W, int wt[], int val[], int n);
int main() {
	int val[] = { 60, 100, 120 }; // 보석의 가치
	int wt[] = { 10, 20, 30 }; // 보석의 무게
	int W = 50; // 보석을 담을 수 있는 가방의 무게(용량)
	int n = sizeof(val) / sizeof(val[0]); // val 배열의 개수

	printf("최대값은 %d", knapSack(W, wt, val, n));
}

int max(int a, int b) {
	return (a > b) ? a : b;
}

//int knapSack(int W, int wt[], int val[], int n) {
//	int i, w;
//	int K[n + 1][W + 1]; // W나 n을 +1을 해줘야지 그 값에 알맞은 값이 들어간다.
//
//	for (i = 0; i <= n; i++) {
//		for (w = 0; w <= W; w++) {
//			if (i == 0 || W == 0)
//				K[i][w] = 0;
//			else if (wt[i - 1] <= w)
//				K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
//			else
//				K[i][w] = K[i - 1][w];
//		}
//	}
//	return K[n][W];
//}

int knapSack(int W, int wt[], int val[], int n) {
	if (n == 0 || W == 0)
		return 0;
	if (wt[n - 1] > W)
		return knapSack(W, wt, val, n - 1);
	else
		return max(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1), knapSack(W, wt, val, n - 1));
}