#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

int main(void) {
	int a, b, c, D;

	printf("�� ����(a, b, c)�� �Է��ϼ��� : ");
	scanf_s("%d %d %d", &a, &b, &c);

	D = sqrt(pow(b, 2) - 4 * a * c);

	if (D > 0) {
		float res1, res2;
		res1 = ((-b) + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
		res2 = ((-b) - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
		printf("�ش� �������� �ش� %.2f, %.2f �Դϴ�.", res1, res2);
	}
	else if (D == 0) {
		float res;
		res = ((-b) + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
		printf("�ش� �������� �ش� %.2f ���� �߱��� �����ϴ�.", res);
	}
	else if (D < 0) {
		printf("�ش� �������� �ذ� �����ϴ�.");
	}

	return 0;
}