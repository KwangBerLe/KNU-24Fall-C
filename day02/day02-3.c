#include <stdio.h>

int main(void) {
	int num;

	for (num = 0; num < 100; num++) {
		if (num % 3 == 0 && num % 4 == 0 || num % 7 == 0) {
			printf("%2d ", num);
		}
	}

	return 0;
}