#include <stdio.h>

int main(void) {
	int n;

	printf("몇층 피라미드를 만들건지 입력해주세요 : ");
	scanf_s("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (n - i) - 1; j++)
			printf(" ");

		for (int k = 0; k < (i*2) + 1; k++)
			printf("*");

		printf("\n");
	}

	printf("출력완료");
	return 0;
}