#include <stdio.h>

int main(void) {
	int n;

	printf("���� �Ƕ�̵带 ������� �Է����ּ��� : ");
	scanf_s("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (n - i) - 1; j++)
			printf(" ");

		for (int k = 0; k < (i*2) + 1; k++)
			printf("*");

		printf("\n");
	}

	printf("\n��¿Ϸ�. ���α׷��� �����մϴ�. ");
	return 0;
}