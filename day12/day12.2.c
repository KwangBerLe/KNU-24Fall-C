#include <stdio.h>

int solution(int n)
{
    int ans = 0;        //���Ǵ� �������� ��

    while (n > 0) {
        if (n % 2 == 0) { //�����̵� ������ �ȴٸ� �����̵��� �ִ��� ���̽����
            n = n / 2;
        }
        else {          //Ȧ���϶� ������ �ݵ�� �ؾ���
            n--;
            ans++;
            n = n / 2;
        }
    }

    return ans;
}