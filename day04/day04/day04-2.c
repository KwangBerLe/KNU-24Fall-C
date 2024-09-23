#include <stdio.h>

void swap(int *num1, int *num2);

int main() {
	int num1 = 100, num2 = 50;

	printf("swap Àü\n");
	printf("num1 = %d, num2 = %d\n", num1, num2);
	swap(&num1, &num2);
	printf("swap ÀÌÈÄ\n");
	printf("num1 = %d, num2 = %d\n", num1, num2);

	return 0;
}

void swap(int* num1, int* num2) {
	int temp;

	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}