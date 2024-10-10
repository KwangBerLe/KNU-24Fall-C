#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(void) {

	double x = 0;				//x좌표
	double y = 0;				//y좌표

	int count = 0, circle = 0;	//시행 횟수, 원 안에 점이 들어간 횟수
	int perc = 0, r = 1;		//진행도 막대를 위한 변수, 반지름 기본 설정
	double pi = 0;				//원주율

	srand(time(NULL));

	while (count < 1000000000) {			//10억번 반복..
		x = (double)rand() / (double)RAND_MAX;
		y = (double)rand() / (double)RAND_MAX;

		if (sqrt(pow(x, 2) + pow(y, 2)) < r) //만약 제곱근 x^2 + y^2 이 1(기본값 r)보다 작을시, circle 증가
			circle++;

		count++;							// circle 증감식이 끝났으니 카운트 증가

		if (count % 10000000 == 0 || count == 0) {		//진행도 표시 조건 1천만으로 설정.. 단 0일때는 출력하면 안되니 && 으로 예외처리 
			perc++;
			pi = 4.0 * ((double)circle / (double)count);
			printf("%3d\%% 진행.. 원주율 : %f ", perc, pi);
			for (int i = 0; i < 10; i++) {
				if (i < perc / 10)	//진행도 막대는 10개밖에 없으므로 10%단위로 찰때만 꽉찬 네모칸이 출력 되도록 조건문
					printf("■");
				else
					printf("□");
			}
			printf("\n");
		}
	}

	printf("원주율 : %f", pi);

	return 0;
}