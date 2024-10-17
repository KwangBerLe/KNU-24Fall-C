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

void fillRandom(int array[SIZE][SIZE]) {		//2차원 배열을 채우는 함수
	srand((unsigned int)time(NULL));			//매 실행시 마다 다른 난수를 발생하기 위해 time.h 를 불러와 srand 함수 사용

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			array[i][j] = rand() % 20 + 1;			//1~20까지 난수 입력됨
		}
	}
}

void printArray(int array[SIZE][SIZE]) {			//2차원 배열을
	printf("배열 출력 : \n");
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			printf("%3d", array[i][j]);					//보기 쉽게 앞에 3자리 확보
		}
		printf("\n");
	}
}

void movePointer(void* array) {
	int i = 0;			//i는 행, j는 열
	int j = 0;
	int count = 0;	//배열 크기 오버날 것을 우려하여 변수 하나 더 사용..
	int prt;
	while (1) {
		prt = *(int*)array;
		printf("현재 위치 : (%d, %d), 배열의 값 : %d\n", i, j, prt);

		count += prt;
		if (count >= 100) break;					//만약 count가 배열의 최대 크기(100)을 넘어간다면 강제로 반복문을 종료한다.

		i = count / 10;									//행은 10의 자릿수만 가져온다.
		j = count % 10;								//열은 1의 자릿수만 가져온다.
		array = (void*)((int*)array + prt);		//array의 메모리 주소를 int 포인터형 으로 바꿔서 참조하는 배열의 값 만큼 더한 후, 다시 void 포인터 형으로 바꿔준다.
	 }

	printf("더이상 이동할 수 없습니다.\n");
	printf("종료 위치 : (%d, %d), 배열의 값 : %d", i, j, prt);
}