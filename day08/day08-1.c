#include <stdio.h.>
#include <string.h>

int main(void) {
	char str[50];							//입력받을 문자열
	char temp;
	int i = 0;
	printf("문자열 입력 : ");
	scanf_s("%s", str, 50);

	char* pstr_start = str;	//문자열 메모리 주소의 시작지점
	char* pstr_end = str;	//문자열 메모리 주소의 마지막 지점
	pstr_end = pstr_end + strlen(str) - 1;	//마지막 지점을 설정하기 위해 문자열의 크기 만큼 더한다. -1은 NULL(\0) 문자를 지우기위함.

	for (int i = 0; i < strlen(str) / 2; i++) {		//문자열을 스왑하기위한 반복문. 앞, 뒤를 바꾸면서 중앙으로 다가가기 때문에 조건문은 문자열 길이의 반으로 설정
		temp = *(pstr_end - i);
		*(pstr_end - i) = *(pstr_start + i);
		*(pstr_start + i) = temp;
	}

	/*while (pstr_start < pstr_end) {				//조금 더 완성도 있는 코드. while문이 조금 더 메모리 차지가 적을 것 같다.
		temp = *(pstr_end);
		*(pstr_end) = *(pstr_start);
		*(pstr_start) = temp;
		pstr_end--;
		pstr_start++;
	}*/

	printf("출력 : %s", str);

	return 0;
}
