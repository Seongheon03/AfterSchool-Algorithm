#include <stdio.h>

void hanoiTower(int n, char from, char tmp, char to);

int main() {
	hanoiTower(100, 'A', 'B', 'C');
	return 0;
}

void hanoiTower(int n, char from, char tmp, char to) {
	if (n == 1)
		printf("���� 1�� %c���� %c���� �ű��.\n", from, to);
	else {
		hanoiTower(n - 1, from, to, tmp);
		printf("���� %d�� %c���� %c���� �ű��.\n", n, from, to);
		hanoiTower(n - 1, tmp, from, to);
	}
}