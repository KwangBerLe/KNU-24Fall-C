#include <stdio.h>

struct Vec {
	int x;	//���� x, y, z
	int y;
	int z;
};

void vecSum(struct Vec v1, struct Vec v2) {	//������ ��
	printf("������ �� : x: %d, y: %d, z: %d\n", v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}
void vecMus(struct Vec v1, struct Vec v2) {	//������ ��
	printf("������ �� : x: %d, y: %d, z: %d\n", v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}
void vecIp(struct Vec v1, struct Vec v2) {	//������ ����
	printf("������ ���� : vec1 * vec2 = %d\n", (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z));
}
void vecOp(struct Vec v1, struct Vec v2) {	//������ ����
	printf("������ ���� : x: %d, y: %d, z: %d\n", (v1.y * v2.z - v1.z * v2.y), (v1.z * v2.x - v1.x * v2.z), (v1.x * v2.y - v1.y * v2.x));
}

int main(void) {
	struct Vec vector1;	//ù��° ����
	struct Vec vector2; //�ι�° ����
	int input;			//�Ŀ� ���ѷ��� ����� �޾ƿ� ����
	
	printf("ù��° ���� (x,y,z) : ");
	scanf_s("%d, %d, %d", &vector1.x, &vector1.y, &vector1.z);
	printf("�ι�° ���� (x,y,z) : ");
	scanf_s("%d, %d, %d", &vector2.x, &vector2.y, &vector2.z);

	printf("�Էµ� ù��° ���� : %4d, %4d, %4d\n", vector1.x, vector1.y, vector1.z);
	printf("�Էµ� �ι�° ���� : %4d, %4d, %4d\n\n", vector2.x, vector2.y, vector2.z);
	

	while (1) {
		printf("-------------------------\n");
		printf("1. ������ ��\n");
		printf("2. ������ ��\n");
		printf("3. ������ ����\n");
		printf("4. ������ ����\n");
		printf("5. ����\n");
		printf("-------------------------\n");
		printf("��� �Է� : ");
		scanf_s("%d", &input);

		switch (input) {	//swtich������ �ѹ��� ���� ����
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
				printf("���α׷��� �����մϴ�.");	//���α׷� ���� ����
				return 0;
			}

			default: {
				printf("�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���.\n");	//�߸��� �Է½� �ٽ� ���ѷ���
			}
		}
	}

	return 0;
}