#include <stdio.h>

int main(void) {
	double num1, num2 = 0;
	int cac;

	printf("���ϴ� ����� �Է��Ͻÿ�.\n");
	printf("1.���ϱ� 2.���� 3.���ϱ� 4.������\n");
	printf("��� : ");
	scanf_s("%d", &cac);
	if (cac < 1 || cac > 4) {
		printf("�߸� �Է��ϼ̽��ϴ�.\n");
		printf("���α׷��� �����մϴ�.");
		return 0;
	}

	printf("���� 1�� �Է��ϼ��� : ");
	scanf_s("%lf", &num1);
	printf("���� 2�� �Է��ϼ��� : ");
	scanf_s("%lf", &num2);

	if (cac == 1) {
		printf("%lf + %lf = %lf", num1, num2, num1 + num2);
	}
	else if (cac == 2) {
		printf("%lf - %lf = %lf", num1, num2, num1 - num2);
	}
	else if (cac == 3) {
		printf("%lf * %lf = %lf", num1, num2, num1 * num2);
	}
	else if (cac == 4) {
		printf("%lf / %lf = %lf", num1, num2, num1 / num2);
	}
	

	return 0;
}