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
	strcpy_s(person[0].name, 100, "ö��"); //person[0].name = (char*)malloc(sizeof(char)* 100);
	person[0].score = 100;

	printf("%d %s %d\n", person[0].snum, person[0].name, person[0].score);
	*/
	
	int* stud_num;
	char** name; //char* name								���������� ��� ���ҽ� �ڵ� �ּ����� �ϴܿ� ����
	int* score;

	printf("����� �л��� �Է��Ͻðڽ��ϱ�? : ");
	scanf_s("%d", &input);

	stud_num = (int*)malloc(sizeof(int) * input);
	name = (char**)malloc(sizeof(char*) * input);
	//name = (char*)malloc(sizeof(char*) * 100 * input);	name ���������� �����ҽ�
	score = (int*)malloc(sizeof(int) * input);

	//���ڿ� �迭�� ������ �ϱ� ������ malloc �ѹ� �� ���ֱ�
	for (int i = 0; i < input; i++) {
		name[i] = (char*)malloc(100 * sizeof(char));
	}

	// snum name score �޾ƿ���
	for (int i = 0; i < input; i++) {
		printf("�й�: ");
		scanf_s("%d", &stud_num[i]);

		printf("�̸�: ");
		scanf_s("%s", name[i], 100);
		//scanf_s("%s", name+(100*i), 100);					name ���������� �����ҽ� �ڵ�

		printf("����: ");
		scanf_s("%d", &score[i]);
	}
	
	for (int i = 0; i < input; i++) {
		printf("%d %s %d\n", stud_num[i], name[i], score[i]);
	}

	// ���� �޸� ����
	free(stud_num);
	free(score);
	for (int i = 0; i < input; i++) free(name[i]);
	//free(name);											name ���������� �����ҽ� �ڵ�
	
	return 0;
	
}