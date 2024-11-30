#include <stdio.h>

int solution(int n)
{
    int ans = 0;        //사용되는 건전지의 량

    while (n > 0) {
        if (n % 2 == 0) { //순간이동 조건이 된다면 순간이동을 최대한 많이써야함
            n = n / 2;
        }
        else {          //홀수일때 점프를 반드시 해야함
            n--;
            ans++;
            n = n / 2;
        }
    }

    return ans;
}