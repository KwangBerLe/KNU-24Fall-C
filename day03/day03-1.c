#include <stdio.h>

int PrimeNum(int num);

int main() {
	int num;
	printf("소수인지 확인할 수를 입력하세요 : ");
	scanf_s("%d", &num);

	if (PrimeNum(num))
		printf("해당 수는 소수입니다.");
	else
		printf("해당 수는 소수가 아닙니다.");

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