#include <stdio.h.>
#include <string.h>

int main(void) {
	char str[50];							//�Է¹��� ���ڿ�
	char temp;
	int i = 0;
	printf("���ڿ� �Է� : ");
	scanf_s("%s", str, 50);

	char* pstr_start = str;	//���ڿ� �޸� �ּ��� ��������
	char* pstr_end = str;	//���ڿ� �޸� �ּ��� ������ ����
	pstr_end = pstr_end + strlen(str) - 1;	//������ ������ �����ϱ� ���� ���ڿ��� ũ�� ��ŭ ���Ѵ�. -1�� NULL(\0) ���ڸ� ���������.

	for (int i = 0; i < strlen(str) / 2; i++) {		//���ڿ��� �����ϱ����� �ݺ���. ��, �ڸ� �ٲٸ鼭 �߾����� �ٰ����� ������ ���ǹ��� ���ڿ� ������ ������ ����
		temp = *(pstr_end - i);
		*(pstr_end - i) = *(pstr_start + i);
		*(pstr_start + i) = temp;
	}

	/*while (pstr_start < pstr_end) {				//���� �� �ϼ��� �ִ� �ڵ�. while���� ���� �� �޸� ������ ���� �� ����.
		temp = *(pstr_end);
		*(pstr_end) = *(pstr_start);
		*(pstr_start) = temp;
		pstr_end--;
		pstr_start++;
	}*/

	printf("��� : %s", str);

	return 0;
}
