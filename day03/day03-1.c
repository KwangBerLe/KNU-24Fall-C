#include <stdio.h>

int PrimeNum(int num);

int main() {
	int num;
	printf("�Ҽ����� Ȯ���� ���� �Է��ϼ��� : ");
	scanf_s("%d", &num);

	if (PrimeNum(num))
		printf("�ش� ���� �Ҽ��Դϴ�.");
	else
		printf("�ش� ���� �Ҽ��� �ƴմϴ�.");

	return 0;
}

int PrimeNum(int num) {
	int sum = 0;
	for (int i = 2; i < num; i++) {
		if (num % i == 0)
			return 0;
	}
	return 1;
}