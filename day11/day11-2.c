#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

float height_func(float n) {
	float res = -log10(1 / n) + sin(n);

	return res;
}

int main(void) {
	int start, end, n, k, pw;
	double width, height, area, acr;
	
	printf("������ ���� ���� �Է��ϼ��� : ");
	scanf_s("%d", &start);
	printf("������ �� ���� �Է��ϼ��� : ");
	scanf_s("%d", &end);
	printf("������ �ִ� ������ �Է��ϼ���(2^n) : ");
	scanf_s("%d", &n);


	k = 0;
	pw = 0;
	area = 0;
	int count = 0;

	while (count <= n) {
		k = 0;
		pw = pow(2, count);							//��� �������� ���簢���� ���̸� ���Ұ���
		width = (((double)end - start) / pw);		//end - start = �׷����� ���� ����. �װ� pw ������ŭ ������ ���簢�� �������� ����

		area = 0;
		while (k < pw) {
			acr = start + width * k;				//���簢���� ���� ���� = x
			height = height_func(acr);				//f(x)�� = ���簢���� ���α���
			//height = acr*acr + 1;
			area = area + width * height;			//���±��� ����� ���簢���� ������ ��� ������
			k++;
		}
		
		printf("���� : %d ���� ��� : %f\n", pw, area);
		count++;
	}

	return 0;
}