#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// topping_len�� �迭 topping�� �����Դϴ�.
int solution(int topping[], size_t topping_len) {
    int cha_top[10000 + 1] = { 0, };  //ö�� ����. Ȥ�ø� ������ �Ѵ� 0���� �ʱ�ȭ
    int bro_top[10000 + 1] = { 0, };  //���� ����
    int num_left = 0;   //ö���� �Դ� ���� ��
    int num_right = 0;  //������ �Դ� ���� ��
    int num_fairs = 0;

    for (int i = 0; i < topping_len; i++) {   //������ ��� ������(���� 0�� �׾�����)
        int top = topping[i];
        if (bro_top[top] == 0) num_right++;   //������ �Դ� ������ �������� ������Ŵ
        bro_top[top]++; //���� ���ι迭 [top]�ε����� ������Ų��
    }

    for (int i = 0; i < topping_len; i++) {   //���� ö���� �Դ´� = ������ ������ �����
        int top = topping[i];
        bro_top[top]--;
        if (bro_top[top] == 0) num_right--;   //������ �Դ� ������ ������ ���´�

        if (cha_top[top] == 0) num_left++;    //ö���� �Դ� ������ ������ �þ
        cha_top[top]++;

        if (num_left == num_right) num_fairs++;
    }

    return num_fairs;
}