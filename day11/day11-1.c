#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

int main(void) {
	int a, b, c, D;

	printf("세 변수(a, b, c)를 입력하세요 : ");
	scanf_s("%d %d %d", &a, &b, &c);

	D = sqrt(pow(b, 2) - 4 * a * c);

	if (D > 0) {
		float res1, res2;
		res1 = ((-b) + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
		res2 = ((-b) - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
		printf("해당 방정식의 해는 %.2f, %.2f 입니다.", res1, res2);
	}
	else if (D == 0) {
		float res;
		res = ((-b) + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
		printf("해당 방정식의 해는 %.2f 으로 중근을 갖습니다.", res);
	}
	else if (D < 0) {
		printf("해당 방정식은 해가 없습니다.");
	}

	return 0;
}