// C program to build the complete 
// snake game 
#include <conio.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <io.h> 
#include <Windows.h>

int i, j, height = 20, width = 20;
int gameover, score;
int x, y, fruitx, fruity, flag;

void SetColor(int color) {			//�÷� ����
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
} 

void CursorView(char show)
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void gotoxy(int x, int y) {			//UI ������ ����ϴ� ������ �̵�
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void start_screen_print() {	//����ȭ�� ���
	printf("\n\n\n\n");
	printf("																	\n");
	printf("																	\n");
	printf("							SNAKE ����						\n");
	printf("																	\n");
	printf("																	\n");

	printf("\n\n\n");
	printf("																����Ϸ��� �ƹ� Ű�� �Է����ּ���.									");

	int i = 0;
	while (1) {
		i = _getch();
			if (i >= 1) {
				system("cls");
				i = 0;
				break;
		}
	}
}

void main_print() {
	CursorView(0);
	puts("������������������������������������������������������");
	puts("��                                                   ��");
	puts("��                                                   ��");
	puts("��                                                   ��");
	puts("��                                                   ��");
	puts("��                                                   ��");
	puts("��                                                   ��");
	puts("��                                                   ��");
	printf("������������������������������������������������������");
	gotoxy(7, 4); printf("���� �ϱ�");
	gotoxy(21, 4); printf("��ŷ ����");
	gotoxy(35, 4); printf("���� ����");

	int POS = 3;
	while (1) {
		if (GetAsyncKeyState(VK_LEFT))
			if (POS == 0) POS = 2;
			else POS -= 1;
		else if (GetAsyncKeyState(VK_RIGHT))
			if (POS == 2 || POS == 4) POS = 0;
			else POS += 1;
		else if (GetAsyncKeyState(VK_RETURN))	//���͸� ������ ��
			break;
		switch (POS) {
		case 0:
			SetColor(11);
			gotoxy(7, 4); printf("���� �ϱ�");
			SetColor(15);
			gotoxy(21, 4); printf("��ŷ ����");
			gotoxy(35, 4); printf("���� ����");
			break;

		case 1:
			SetColor(15);
			gotoxy(7, 4); printf("���� �ϱ�");
			SetColor(11);
			gotoxy(21, 4); printf("��ŷ ����");
			SetColor(15);
			gotoxy(35, 4); printf("���� ����");
			break;

		case 2:
			SetColor(15);
			gotoxy(7, 4); printf("���� �ϱ�");
			gotoxy(21, 4); printf("��ŷ ����");
			SetColor(11);
			gotoxy(35, 4); printf("���� ����");
			break;

		default: break;
		}
		Sleep(100);
	}
}

void gameover_print(int score) {	//���� ������ �������� ����
	system("cls");
	printf("�������� : %d", score);
}

// Function to generate the fruit 
// within the boundary 
void setup()
{
	gameover = 0;

	// Stores height and width 
	x = height / 2;
	y = width / 2;

	fruitx = 0;
	while (fruitx == 0) {
		fruitx = rand() % 20;
	}

	fruity = 0;
	while (fruity == 0) {
		fruity = rand() % 20;
	}

	score = 0;
}

// Function to draw the boundaries 
void draw()
{
	system("cls");										//ȭ���� ��� ����� ��, ����, �÷��̾ ���(�̳༮�� ȭ���� �����̰� �ϴ� ����)
	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			if (i == 0 || i == width - 1
				|| j == 0
				|| j == height - 1) {
				printf("#");
			}
			else {
				if (i == x && j == y)
					printf("0");
				else if (i == fruitx
					&& j == fruity)
					printf("��");
				else
					printf(" ");
			}
		}
		printf("\n");
	}

	// Print the score after the 
	// game ends 
	printf("score = %d", score);
	printf("\n");
	printf("press X to quit the game");
}

// Function to take the input 
void input()
{
	if (_kbhit()) {
		switch (getch()) {
		case 'a':
			flag = 1;
			break;
		case 's':
			flag = 2;
			break;
		case 'd':
			flag = 3;
			break;
		case 'w':
			flag = 4;
			break;
		case 'x':
			gameover = 1;
			break;
		}
	}
}

// Function for the logic behind 
// each movement 
void logic()
{
	Sleep(100);
	switch (flag) {
	case 1:
		y--;
		break;
	case 2:
		x++;
		break;
	case 3:
		y++;
		break;
	case 4:
		x--;
		break;
	default:
		break;
	}

	// If the game is over 
	if (x < 0 || x > height
		|| y < 0 || y > width) {
		gameover_print(score);
		gameover = 1;
	}
	//	���� ���� �����
	// ���� ������Ʈ
	if (x == fruitx && y == fruity) {

		fruitx = 0;
		while (fruitx == 0) {
			fruitx = rand() % 20;
		}

		fruity = 0;
		while (fruity == 0) {
			fruity = rand() % 20;
		}

		score += 10;
	}
}

void main()
{
	int m, n;

	start_screen_print();
	main_print();
	// Generate boundary 
	setup();

	// Until the game is over 
	while (!gameover) {

		// Function Call 
		draw();
		input();
		logic();
	}
}
