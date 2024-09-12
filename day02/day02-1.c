#include <stdio.h>

int main(void) {
	double num1, num2 = 0;
	int cac;

	printf("원하는 기능을 입력하시오.\n");
	printf("1.더하기 2.빼기 3.곱하기 4.나누기\n");
	printf("기능 : ");
	scanf_s("%d", &cac);
	if (cac < 1 || cac > 4) {
		printf("잘못 입력하셨습니다.\n");
		printf("프로그램을 종료합니다.");
		return 0;
	}

	printf("숫자 1을 입력하세요 : ");
	scanf_s("%lf", &num1);
	printf("숫자 2를 입력하세요 : ");
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