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

//���ο� ��� ���� + �����Ҵ�

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
	//���� ����Ʈ�� ���� �޸� �������� ���ӵ� ��ġ�� �������� �ʴ´�.
	int input, score;
	int del_score;
	char stu[100];
	head = (struct NODE*)malloc(sizeof(struct NODE));
	head->link = NULL;

	while (1) {
		printf("-------------------------\n");
		printf("1. �л��� ������ �Է�\n");
		printf("2. �л� ���� ����\n");
		printf("3. ���α׷� ����\n");
		printf("input : ");
		scanf_s("%d", &input);

		switch (input) {
			case 1:
				printf("�л� �̸� : ");
				scanf_s("%s", stu, sizeof(stu));
				printf("%s�� ���� : ", stu);
				scanf_s("%d", &score);

				insert_node(create_node(stu, score));

				print_nodes();
				break;

			case 2:
				printf("����� ���� �л��� ������ �Է��ϼ��� : ");
				scanf_s("%d", &del_score);

				if (delete_node(del_score)) {
					printf("���� �Ϸ�\n");
					print_nodes();
				}
				else
					printf("�������� �ʴ� �����Դϴ�.");

				break;

			case 3:
				printf("���α׷��� �����մϴ�.");
				return 0;

			default :
				printf("�߸��� �Է��Դϴ�. �ٽ� �Է� ���ֽʽÿ�.");
		}
	}

	return 0;
}