#include <stdio.h>

struct Product {
	int id;
	char name[20];
	int price;
}prod[5];				//����ü �迭�� �ִ� 5�� �޾ƿ� �� �ְ� ����

void printProduct(int stack) {
	printf("\n<<�Էµ� ��ǰ ���>>\n");
	for (int i = 0; i < stack; i++) {
		printf("��ǰ ID : %d\n", prod[i].id);
		printf("��ǰ�� : %s\n", prod[i].name);
		printf("���� : %d\n\n", prod[i].price);
	}
}

int main(void) {
	int stack = 0;		//�󸶳� ���� ��ǰ������ �޾ƿԴ��� �˱����� ��������
	for (int i = 0; i < 5; i++) {
		printf("��ǰ ������ �Է��ϼ��� (�Է� �ߴ��� id�� 0 �Է�)\n");
		printf("��ǰ ID : ");
		scanf_s("%d", &prod[i].id);

		if (prod[i].id == 0) break;

		printf("��ǰ�� : ");
		scanf_s("%s", prod[i].name, sizeof(prod[i].name));

		printf("���� : ");
		scanf_s("%d", &prod[i].price);

		printf("\n");
		stack++;		//��ǰ������ �� ����
	}

	printProduct(stack);	//��ǰ������ �޾ƿ� ��ŭ ������ֱ�

	return 0;
}