#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void fillRandom(int array[SIZE][SIZE]);
void printArray(int array[SIZE][SIZE]);
void movePointer(void* array);

int main(void) {
	int array[SIZE][SIZE];

	fillRandom(array);
	printArray(array);
	movePointer(array);

	return 0;
}

void fillRandom(int array[SIZE][SIZE]) {		//2���� �迭�� ä��� �Լ�
	srand((unsigned int)time(NULL));			//�� ����� ���� �ٸ� ������ �߻��ϱ� ���� time.h �� �ҷ��� srand �Լ� ���

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			array[i][j] = rand() % 20 + 1;			//1~20���� ���� �Էµ�
		}
	}
}

void printArray(int array[SIZE][SIZE]) {			//2���� �迭��
	printf("�迭 ��� : \n");
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			printf("%3d", array[i][j]);					//���� ���� �տ� 3�ڸ� Ȯ��
		}
		printf("\n");
	}
}

void movePointer(void* array) {
	int i = 0;			//i�� ��, j�� ��
	int j = 0;
	int count = 0;	//�迭 ũ�� ������ ���� ����Ͽ� ���� �ϳ� �� ���..
	int prt;
	while (1) {
		prt = *(int*)array;
		printf("���� ��ġ : (%d, %d), �迭�� �� : %d\n", i, j, prt);

		count += prt;
		if (count >= 100) break;					//���� count�� �迭�� �ִ� ũ��(100)�� �Ѿ�ٸ� ������ �ݺ����� �����Ѵ�.

		i = count / 10;									//���� 10�� �ڸ����� �����´�.
		j = count % 10;								//���� 1�� �ڸ����� �����´�.
		array = (void*)((int*)array + prt);		//array�� �޸� �ּҸ� int �������� ���� �ٲ㼭 �����ϴ� �迭�� �� ��ŭ ���� ��, �ٽ� void ������ ������ �ٲ��ش�.
	 }

	printf("���̻� �̵��� �� �����ϴ�.\n");
	printf("���� ��ġ : (%d, %d), �迭�� �� : %d", i, j, prt);
}