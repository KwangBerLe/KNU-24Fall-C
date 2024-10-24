#include <stdio.h>

struct Product {
	int id;
	char name[20];
	int price;
};

void printProduct(int stack, struct Product prod[]) {
	printf("\n<<입력된 상품 목록>>\n");
	for (int i = 0; i < stack; i++) {
		printf("상품 ID : %d\n", prod[i].id);
		printf("상품명 : %s\n", prod[i].name);
		printf("가격 : %d\n\n", prod[i].price);
	}
}

int main(void) {
	struct Product prod[5];
	int stack = 0;		//얼마나 많은 상품정보를 받아왔는지 알기위한 변수선언
	for (int i = 0; i < 5; i++) {
		printf("상품 정보를 입력하세요 (입력 중단은 id에 0 입력)\n");
		printf("상품 ID : ");
		scanf_s("%d", &prod[i].id);

		if (prod[i].id == 0) break;

		printf("상품명 : ");
		scanf_s("%s", prod[i].name, sizeof(prod[i].name));

		printf("가격 : ");
		scanf_s("%d", &prod[i].price);

		printf("\n");
		stack++;		//상품정보의 수 증가
	}

	printProduct(stack, prod);	//상품정보를 받아온 만큼 출력해주기

	return 0;
}