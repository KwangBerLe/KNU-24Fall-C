#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct NODE {
	char name[20];
	int data;
	struct NODE* link;
};

struct NODE* head = NULL;

//새로운 노드 생성 + 동적할당

struct NODE* create_node(char name[20], int data) {
	struct NODE* new_node = (struct NODE*)malloc(sizeof(struct NODE));
	strcpy(new_node->name, name);
	new_node->data = data;
	new_node->link = NULL;

	return new_node;
}

int comp_node(int n1, int n2) {
	if (n1 < n2) 
		return 1;
	else
		return 0;
}

void insert_node(struct NODE* new_node) {
	struct NODE* temp = head;
	while (temp->link != NULL && comp_node(new_node->data, temp->link->data) != 0) {
		temp = temp->link;
	}

	new_node->link = temp->link;
	temp->link = new_node;
}

void print_nodes() {
	struct NODE* cur = head->link;
	printf("-------------------------\n");

	while (cur != NULL) {
		printf("%s : %d\n", cur->name, cur->data);
		cur = cur->link;
	}
}

struct NODE* find_node(int value) {
	struct NODE* cur = head->link;
	while (cur != NULL) {
		if (cur->data == value) return cur;

		cur = cur->link;
	}
	return NULL;
}

int delete_node(int value) {
	struct NODE* prev = head;
	struct NODE* cur = head->link;
	while (cur != NULL) {
		if (cur->data == value) {
			prev->link = cur->link;
			free(cur);
			return 1;
		}

		prev = cur;
		cur = cur->link;
	}
	return 0;
}

int main() {
	//연결 리스트의 노드는 메모리 공간에서 연속된 위치에 존재하지 않는다.
	int input, score;
	int del_score;
	char stu[100];
	head = (struct NODE*)malloc(sizeof(struct NODE));
	head->link = NULL;

	while (1) {
		printf("-------------------------\n");
		printf("1. 학생의 성적을 입력\n");
		printf("2. 학생 정보 제거\n");
		printf("3. 프로그램 종료\n");
		printf("input : ");
		scanf_s("%d", &input);

		switch (input) {
			case 1:
				printf("학생 이름 : ");
				scanf_s("%s", stu, sizeof(stu));
				printf("%s의 성적 : ", stu);
				scanf_s("%d", &score);

				insert_node(create_node(stu, score));

				print_nodes();
				break;

			case 2:
				printf("지우고 싶은 학생의 성적을 입력하세요 : ");
				scanf_s("%d", &del_score);

				if (delete_node(del_score)) {
					printf("제거 완료\n");
					print_nodes();
				}
				else
					printf("존재하지 않는 점수입니다.");

				break;

			case 3:
				printf("프로그램을 종료합니다.");
				return 0;

			default :
				printf("잘못된 입력입니다. 다시 입력 해주십시오.");
		}
	}

	return 0;
}