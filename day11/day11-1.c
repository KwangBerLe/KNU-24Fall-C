#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Rank {
	platinum = 1, gold, silver, common
};

struct Customer {
	char customerName[20];
	enum Rank rank;
	int order_amount;
	int point;
	struct Customer* prev;
    struct Customer* next;
};

struct Customer* head = NULL;

struct Customer* create_node(char name[20], int amount, int point, int rank) {
	struct Customer* new_node = (struct Customer*)malloc(sizeof(struct Customer));
	strcpy(new_node->customerName, name);
	new_node->order_amount = amount;
	new_node->point = point;
	new_node->rank = rank;
	new_node->next = NULL;

	return new_node;
}

int comp_rank(int n1_rank, int n2_rank) {
	if (n1_rank > n2_rank)
		return 1;
	else
		return 0;
}
int comp_amount(int n1_amount, int n2_amount) {
	if (n1_amount < n2_amount)
		return 1;
	else
		return 0;
}
int comp_point(int n1_point, int n2_point) {
	if (n1_point < n2_point)
		return 1;
	else
		return 0;
}

void insert_node(struct Customer* new_node) {
	struct Customer* temp = head;			//�켱������ ��ũ > �ֹ��� > ����Ʈ �� �Դϴ�.
	if (head->rank != new_node->rank) {	//��ũ�� ���� �ʴٸ�
		while (temp->next != NULL && comp_rank(new_node->rank, temp->next->rank) != 0) {
			temp = temp->next;
		}
	}
	else if (head->order_amount == new_node->order_amount) {	//��ũ�� ���ٸ� �ֹ��� ��
		while (temp->next != NULL && comp_amount(new_node->order_amount, temp->next->order_amount) != 0) {
			temp = temp->next;
		}
	}
	else {	//�ֹ��� ���� ���ٸ� ����Ʈ ��
		while (temp->next != NULL && comp_point(new_node->point, temp->next->point) != 0 && new_node->order_amount < temp->next->order_amount) {
			temp = temp->next;
		}
	}

	new_node->next = temp->next;		//�̽������� temp->next �� NULL or ���� ���
	temp->next = new_node;				//temp�� new_node�� ����Ű����
	new_node->prev = temp;
}

void print_nodes() {
	struct Customer* cur = head->next;
	printf("-------------------------\n");

	while (cur != NULL) {
		printf("%s\n", cur->customerName);
		printf("����� : %d\n", cur->rank);
		printf("��ü �ֹ��� : %d\n", cur->order_amount);
		printf("����Ʈ ������ : %d\n\n", cur->point);
		cur = cur->next;
	}
}

struct Customer* find_node(char name[20]) {
	
	struct Customer* cur = head->next;
	while (cur != NULL) {
		if (strcmp(cur->customerName, name) == 0) {
			char cor_name[20];
			int cor_amount, cor_point, cor_rank;
			printf("������ ���� �̸� : ");
			scanf_s("%s", cor_name, sizeof(cor_name));
			printf("%s�� �� ���(1~4) : ", cor_name);
			scanf_s("%d", &cor_rank);
			printf("%s�� �ֹ��� : ", cor_name);
			scanf_s("%d", &cor_amount);
			printf("%s�� ����Ʈ : ", cor_name);
			scanf_s("%d", &cor_point);


			insert_node(create_node(cor_name, cor_amount, cor_point, cor_rank));
			printf("�� ���� ���� �Ϸ�\n");
			delete_node(name);

			break;
		}
		cur = cur->next;
	}


	return NULL;
}

int delete_node(char name[20]) {
	struct Customer* prev = head;
	struct Customer* cur = head->next;
	while (cur != NULL) {
		if (strcmp(cur->customerName, name) == 0) {
			prev->next = cur->next;
			free(cur);
			return 1;
		}
		prev = cur;
		cur = cur->next;
	}
	return 0;
}

int main() {
	//���� ����Ʈ�� ���� �޸� �������� ���ӵ� ��ġ�� �������� �ʴ´�.

	int input, amount, point, rank;
	char input_name[20];
	char cus[100];
	head = (struct Customer*)malloc(sizeof(struct Customer));
	head->next = NULL;

	while (1) {
		printf("-------------------------\n");
		printf("1. ���� ������ �Է�\n");
		printf("2. �� ���� ����\n");
		printf("3. �� ���� ����\n");
		printf("4. �� ���� ���\n");
		printf("5. ���α׷� ����\n");
		printf("input : ");
		scanf_s("%d", &input);

		switch (input) {
		case 1:
			printf("�� �̸� : ");
			scanf_s("%s", cus, sizeof(cus));
			printf("%s�� �� ���(1~4) : ", cus);
			scanf_s("%d", &rank);
			printf("%s�� �ֹ� �� : ", cus);
			scanf_s("%d", &amount);
			printf("%s�� ����Ʈ �� : ", cus);
			scanf_s("%d", &point);

			insert_node(create_node(cus, amount, point, rank));

			break;

		case 2:
			printf("����� ���� ���� �̸��� �Է��ϼ��� : ");
			scanf_s("%s", input_name, sizeof(input_name));

			if (delete_node(input_name)) {
				printf("���� �Ϸ�\n");
			}
			else
				printf("�������� �ʴ� ���Դϴ�.");

			break;

		case 3:
			printf("ã����� ���� �̸��� �Է��ϼ��� : ");
			scanf_s("%s", input_name, sizeof(input_name));
			
			find_node(input_name);

			break;

		case 4:
			printf("���� ������ ����մϴ�.\n");
			print_nodes();
			
			break;

		case 5:
			printf("���α׷��� �����մϴ�.");
			return 0;

		default:
			printf("�߸��� �Է��Դϴ�. �ٽ� �Է� ���ֽʽÿ�.\n");
		}
	}

	return 0;
}