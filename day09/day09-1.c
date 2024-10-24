#include <stdio.h>

struct Vec {
	int x;	//벡터 x, y, z
	int y;
	int z;
};

void vecSum(struct Vec v1, struct Vec v2) {	//벡터의 합
	printf("벡터의 합 : x: %d, y: %d, z: %d\n", v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}
void vecMus(struct Vec v1, struct Vec v2) {	//벡터의 차
	printf("벡터의 차 : x: %d, y: %d, z: %d\n", v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}
void vecIp(struct Vec v1, struct Vec v2) {	//벡터의 내적
	printf("벡터의 내적 : vec1 * vec2 = %d\n", (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z));
}
void vecOp(struct Vec v1, struct Vec v2) {	//벡터의 외적
	printf("벡터의 외적 : x: %d, y: %d, z: %d\n", (v1.y * v2.z - v1.z * v2.y), (v1.z * v2.x - v1.x * v2.z), (v1.x * v2.y - v1.y * v2.x));
}

int main(void) {
	struct Vec vector1;	//첫번째 벡터
	struct Vec vector2; //두번째 벡터
	int input;			//후에 무한루프 명령을 받아올 변수
	
	printf("첫번째 벡터 (x,y,z) : ");
	scanf_s("%d, %d, %d", &vector1.x, &vector1.y, &vector1.z);
	printf("두번째 벡터 (x,y,z) : ");
	scanf_s("%d, %d, %d", &vector2.x, &vector2.y, &vector2.z);

	printf("입력된 첫번째 벡터 : %4d, %4d, %4d\n", vector1.x, vector1.y, vector1.z);
	printf("입력된 두번째 벡터 : %4d, %4d, %4d\n\n", vector2.x, vector2.y, vector2.z);
	

	while (1) {
		printf("-------------------------\n");
		printf("1. 벡터의 합\n");
		printf("2. 벡터의 차\n");
		printf("3. 벡터의 외적\n");
		printf("4. 벡터의 내적\n");
		printf("5. 종료\n");
		printf("-------------------------\n");
		printf("명령 입력 : ");
		scanf_s("%d", &input);

		switch (input) {	//swtich문으로 한번에 조건 결정
			case 1: {
				vecSum(vector1, vector2);
				break;
			}
			case 2: {
				vecMus(vector1, vector2);
				break;
			}
			case 3: {
				vecOp(vector1, vector2);
				break;
			}
			case 4: {
				vecIp(vector1, vector2);
				break;
			}
			case 5: {
				printf("프로그램을 종료합니다.");	//프로그램 종료 조건
				return 0;
			}

			default: {
				printf("잘못된 입력입니다. 다시 입력해주세요.\n");	//잘못된 입력시 다시 무한루프
			}
		}
	}

	return 0;
}