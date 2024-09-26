#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
	int snum;
	char name[100]; //char *name;
	int score;
};

int main() {
	int input;
	/*
	struct Student person[2];

	person[0].snum = 1111;
	strcpy_s(person[0].name, 100, "철수"); //person[0].name = (char*)malloc(sizeof(char)* 100);
	person[0].score = 100;

	printf("%d %s %d\n", person[0].snum, person[0].name, person[0].score);
	*/
	
	int* stud_num;
	char** name; //char* name								다중포인터 사용 안할시 코드 주석으로 하단에 서술
	int* score;

	printf("몇명의 학생을 입력하시겠습니까? : ");
	scanf_s("%d", &input);

	stud_num = (int*)malloc(sizeof(int) * input);
	name = (char**)malloc(sizeof(char*) * input);
	//name = (char*)malloc(sizeof(char*) * 100 * input);	name 다중포인터 사용안할시
	score = (int*)malloc(sizeof(int) * input);

	//문자열 배열을 만들어야 하기 때문에 malloc 한번 더 해주기
	for (int i = 0; i < input; i++) {
		name[i] = (char*)malloc(100 * sizeof(char));
	}

	// snum name score 받아오기
	for (int i = 0; i < input; i++) {
		printf("학번: ");
		scanf_s("%d", &stud_num[i]);

		printf("이름: ");
		scanf_s("%s", name[i], 100);
		//scanf_s("%s", name+(100*i), 100);					name 다중포인터 사용안할시 코드

		printf("점수: ");
		scanf_s("%d", &score[i]);
	}
	
	for (int i = 0; i < input; i++) {
		printf("%d %s %d\n", stud_num[i], name[i], score[i]);
	}

	// 동적 메모리 해제
	free(stud_num);
	free(score);
	for (int i = 0; i < input; i++) free(name[i]);
	//free(name);											name 다중포인터 사용안할시 코드
	
	return 0;
	
}