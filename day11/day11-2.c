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
	
	printf("적분할 시작 값을 입력하세요 : ");
	scanf_s("%d", &start);
	printf("적분할 끝 값을 입력하세요 : ");
	scanf_s("%d", &end);
	printf("시행할 최대 구간을 입력하세요(2^n) : ");
	scanf_s("%d", &n);


	k = 0;
	pw = 0;
	area = 0;
	int count = 0;

	while (count <= n) {
		k = 0;
		pw = pow(2, count);							//어느 구간까지 직사각형의 넓이를 구할건지
		width = (((double)end - start) / pw);		//end - start = 그래프의 가로 길이. 그걸 pw 구간만큼 나눠서 직사각형 여러개를 만듬

		area = 0;
		while (k < pw) {
			acr = start + width * k;				//직사각형의 가로 길이 = x
			height = height_func(acr);				//f(x)식 = 직사각형의 세로길이
			//height = acr*acr + 1;
			area = area + width * height;			//여태까지 계산한 직사각형의 면적을 계속 더해줌
			k++;
		}
		
		printf("구간 : %d 적분 결과 : %f\n", pw, area);
		count++;
	}

	return 0;
}