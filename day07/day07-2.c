#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(void) {

	double x = 0;				//x��ǥ
	double y = 0;				//y��ǥ

	int count = 0, circle = 0;	//���� Ƚ��, �� �ȿ� ���� �� Ƚ��
	int perc = 0, r = 1;		//���൵ ���븦 ���� ����, ������ �⺻ ����
	double pi = 0;				//������

	srand(time(NULL));

	while (count < 1000000000) {			//10��� �ݺ�..
		x = (double)rand() / (double)RAND_MAX;
		y = (double)rand() / (double)RAND_MAX;

		if (sqrt(pow(x, 2) + pow(y, 2)) < r) //���� ������ x^2 + y^2 �� 1(�⺻�� r)���� ������, circle ����
			circle++;

		count++;							// circle �������� �������� ī��Ʈ ����

		if (count % 10000000 == 0 || count == 0) {		//���൵ ǥ�� ���� 1õ������ ����.. �� 0�϶��� ����ϸ� �ȵǴ� && ���� ����ó�� 
			perc++;
			pi = 4.0 * ((double)circle / (double)count);
			printf("%3d\%% ����.. ������ : %f ", perc, pi);
			for (int i = 0; i < 10; i++) {
				if (i < perc / 10)	//���൵ ����� 10���ۿ� �����Ƿ� 10%������ ������ ���� �׸�ĭ�� ��� �ǵ��� ���ǹ�
					printf("��");
				else
					printf("��");
			}
			printf("\n");
		}
	}

	printf("������ : %f", pi);

	return 0;
}