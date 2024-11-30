#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// topping_len은 배열 topping의 길이입니다.
int solution(int topping[], size_t topping_len) {
    int cha_top[10000 + 1] = { 0, };  //철수 토핑. 혹시모를 위험대비 둘다 0으로 초기화
    int bro_top[10000 + 1] = { 0, };  //동생 토핑
    int num_left = 0;   //철수가 먹는 토핑 수
    int num_right = 0;  //동생이 먹는 토핑 수
    int num_fairs = 0;

    for (int i = 0; i < topping_len; i++) {   //동생이 모두 먹을때(선을 0에 그었을때)
        int top = topping[i];
        if (bro_top[top] == 0) num_right++;   //동생이 먹는 토핑의 가짓수를 증가시킴
        bro_top[top]++; //동생 토핑배열 [top]인덱스를 증가시킨다
    }

    for (int i = 0; i < topping_len; i++) {   //이제 철수가 먹는다 = 동생이 토핑을 뺏긴다
        int top = topping[i];
        bro_top[top]--;
        if (bro_top[top] == 0) num_right--;   //동생이 먹는 토핑의 종류를 뺏는다

        if (cha_top[top] == 0) num_left++;    //철수가 먹는 토핑의 종류는 늘어남
        cha_top[top]++;

        if (num_left == num_right) num_fairs++;
    }

    return num_fairs;
}