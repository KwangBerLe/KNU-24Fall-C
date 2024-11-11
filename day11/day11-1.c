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
	struct Customer* temp = head;			//우선순위는 랭크 > 주문량 > 포인트 순 입니다.
	if (head->rank != new_node->rank) {	//랭크가 같지 않다면
		while (temp->next != NULL && comp_rank(new_node->rank, temp->next->rank) != 0) {
			temp = temp->next;
		}
	}
	else if (head->order_amount == new_node->order_amount) {	//랭크가 같다면 주문량 비교
		while (temp->next != NULL && comp_amount(new_node->order_amount, temp->next->order_amount) != 0) {
			temp = temp->next;
		}
	}
	else {	//주문량 마저 같다면 포인트 비교
		while (temp->next != NULL && comp_point(new_node->point, temp->next->point) != 0 && new_node->order_amount < temp->next->order_amount) {
			temp = temp->next;
		}
	}

	new_node->next = temp->next;		//이시점에서 temp->next 는 NULL or 다음 노드
	temp->next = new_node;				//temp가 new_node를 가리키도록
	new_node->prev = temp;
}

void print_nodes() {
	struct Customer* cur = head->next;
	printf("-------------------------\n");

	while (cur != NULL) {
		printf("%s\n", cur->customerName);
		printf("고객등급 : %d\n", cur->rank);
		printf("전체 주문량 : %d\n", cur->order_amount);
		printf("포인트 보유량 : %d\n\n", cur->point);
		cur = cur->next;
	}
}

struct Customer* find_node(char name[20]) {
	
	struct Customer* cur = head->next;
	while (cur != NULL) {
		if (strcmp(cur->customerName, name) == 0) {
			char cor_name[20];
			int cor_amount, cor_point, cor_rank;
			printf("수정할 고객의 이름 : ");
			scanf_s("%s", cor_name, sizeof(cor_name));
			printf("%s의 고객 등급(1~4) : ", cor_name);
			scanf_s("%d", &cor_rank);
			printf("%s의 주문량 : ", cor_name);
			scanf_s("%d", &cor_amount);
			printf("%s의 포인트 : ", cor_name);
			scanf_s("%d", &cor_point);


			insert_node(create_node(cor_name, cor_amount, cor_point, cor_rank));
			printf("고객 정보 수정 완료\n");
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
	//연결 리스트의 노드는 메모리 공간에서 연속된 위치에 존재하지 않는다.

	int input, amount, point, rank;
	char input_name[20];
	char cus[100];
	head = (struct Customer*)malloc(sizeof(struct Customer));
	head->next = NULL;

	while (1) {
		printf("-------------------------\n");
		printf("1. 고객의 정보를 입력\n");
		printf("2. 고객 정보 제거\n");
		printf("3. 고객 정보 수정\n");
		printf("4. 고객 정보 출력\n");
		printf("5. 프로그램 종료\n");
		printf("input : ");
		scanf_s("%d", &input);

		switch (input) {
		case 1:
			printf("고객 이름 : ");
			scanf_s("%s", cus, sizeof(cus));
			printf("%s의 고객 등급(1~4) : ", cus);
			scanf_s("%d", &rank);
			printf("%s의 주문 량 : ", cus);
			scanf_s("%d", &amount);
			printf("%s의 포인트 량 : ", cus);
			scanf_s("%d", &point);

			insert_node(create_node(cus, amount, point, rank));

			break;

		case 2:
			printf("지우고 싶은 고객의 이름을 입력하세요 : ");
			scanf_s("%s", input_name, sizeof(input_name));

			if (delete_node(input_name)) {
				printf("제거 완료\n");
			}
			else
				printf("존재하지 않는 고객입니다.");

			break;

		case 3:
			printf("찾고싶은 고객의 이름을 입력하세요 : ");
			scanf_s("%s", input_name, sizeof(input_name));
			
			find_node(input_name);

			break;

		case 4:
			printf("고객의 정보를 출력합니다.\n");
			print_nodes();
			
			break;

		case 5:
			printf("프로그램을 종료합니다.");
			return 0;

		default:
			printf("잘못된 입력입니다. 다시 입력 해주십시오.\n");
		}
	}

	return 0;
}