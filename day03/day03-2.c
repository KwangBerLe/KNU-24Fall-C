#include <stdio.h>

int fac(int num);

int main() {
	int num = 0;
	printf("����� ���丮�� �� �Է� : ");
	scanf_s("%d", &num);

	printf("%d! = %d", num, fac(num));

	return 0;
}

int fac(int num) {
	int result = 0;
	if (num == 0 || num == 1)
		return result;

	result = num * fac(num - 1);

	return result;
}