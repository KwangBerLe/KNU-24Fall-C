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
void game_draw();

void SetColor(int color) {			//컬러 지정(크롤링)
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void CursorView(char show)			//커서가 안보이게 해주는 함수(크롤링)
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void gotoxy(int x, int y) {			//UI 구현에 사용하는 포지션 이동(크롤링)
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void start_screen_print() {	//시작화면 출력
	puts("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
	puts("■                                                   ■");
	puts("■                                                   ■");
	puts("■                                                   ■");
	puts("■                                                   ■");
	puts("■                                                   ■");
	puts("■                                                   ■");
	puts("■                                                   ■");
	puts("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
	gotoxy(21, 4); printf("SNAKE 게임 ");
	gotoxy(12, 7); printf("계속하려면 아무키나 눌러주세요.");
	

	int start_input = 0;
	while (1) {
		start_input = _getch();		//아무 입력을 받아옵니다
		if (start_input >= 1) {		//무슨 입력을 받던 간에 start_input은 1보다 커지게 되있습니다
			system("cls");	
			start_input = 0;			//i 초기화
			break;
		}
	}
}

void quit_game() {
	system("cls");
	gotoxy(25, 6); printf("게임을 종료합니다.");
	gotoxy(25, 10);
	gameover = 1;
	exit(0);
}

void main_print() {
	CursorView(0);
	puts("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
	puts("■                                                   ■");
	puts("■                                                   ■");
	puts("■                                                   ■");
	puts("■                                                   ■");
	puts("■                                                   ■");
	puts("■                                                   ■");
	puts("■                                                   ■");
	puts("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
	gotoxy(7, 4); printf("새로 하기");
	gotoxy(21, 4); printf("랭킹 보기");
	gotoxy(35, 4); printf("게임 종료");
	gotoxy(6, 7); printf("ENTER : 메뉴선택      방향키 : 메뉴 이동");

	int POS = 0;
	while (1) {
		if (GetAsyncKeyState(VK_LEFT))
			if (POS == 0) POS = 2;
			else POS -= 1;
		else if (GetAsyncKeyState(VK_RIGHT))
			if (POS == 2 || POS == 4) POS = 0;
			else POS += 1;
		else if (GetAsyncKeyState(VK_RETURN)) {	//엔터를 눌렀을 때
			if (POS == 0) {
				system("cls");
				game_draw();
				break;
			}
			//else if (POS == 1) rank_print();
			else if (POS == 2) {
				quit_game();
				gameover = 1;
				break;
			}
		}
		switch (POS) {
		case 0:
			SetColor(11);
			gotoxy(7, 4); printf("새로 하기");
			SetColor(15);
			gotoxy(21, 4); printf("랭킹 보기");
			gotoxy(35, 4); printf("게임 종료");
			break;

		case 1:
			SetColor(15);
			gotoxy(7, 4); printf("새로 하기");
			SetColor(11);
			gotoxy(21, 4); printf("랭킹 보기");
			SetColor(15);
			gotoxy(35, 4); printf("게임 종료");
			break;

		case 2:
			SetColor(15);
			gotoxy(7, 4); printf("새로 하기");
			gotoxy(21, 4); printf("랭킹 보기");
			SetColor(11);
			gotoxy(35, 4); printf("게임 종료");
			SetColor(15);
			break;

		default: break;
		}
		Sleep(100);
	}
}

void gameover_print(int score) {	//게임 오버시 최종점수 저장
	system("cls");
	puts("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
	puts("■                                                   ■");
	puts("■                                                   ■");
	puts("■                                                   ■");
	puts("■                                                   ■");
	puts("■                                                   ■");
	puts("■                                                   ■");
	puts("■                                                   ■");
	puts("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
	gotoxy(21, 2); printf("GAME OVER");
	gotoxy(19, 4); printf("최종 점수 : %d", score);
	gotoxy(12, 6); printf("계속하려면 X 키를 눌러주세요.");
	
	
	while (1) {
		int go_input = 0;
		go_input = _getch();
		if (go_input == 120) {
			system("cls");
			main_print();
		}
	}
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
		fruitx = rand() % 19;
	}

	fruity = 0;
	while (fruity == 0) {
		fruity = rand() % 19;
	}

	score = 0;
}

// Function to draw the boundaries 
void draw()
{
	//system("cls");	화면을 계속 지우며 벽, 과일, 플레이어를 출력(이녀석이 화면을 깜빡이게 하는 원인)
	gotoxy(0, 0); //크롤링 해온 gotoxy 함수를 통해 화면을 지우지 않고 그대로 덮어씌우는 형식으로 작동하게 하여 화면 버퍼링을 없애준다.
	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			if (i == 0 || i == width - 1) 
				printf("ㅡ");
			else if (j == 0 || j == height - 1) {
				printf("ㅣ");
			}
			else {
				if (i == x && j == y)
					printf("0");
				else if (i == fruitx
					&& j == fruity)
					printf("!");
				else
					printf("　");
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
			gameover_print(score);
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
	//	뱀이 과일 섭취시
	// 점수 업데이트
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

void game_draw() {
	setup();
	flag = 0;
	while (1) {
		// Function Call 
		draw();
		input();
		logic();
	}
};

void main()
{
	int m, n;

	start_screen_print();
	main_print();
	 
}
