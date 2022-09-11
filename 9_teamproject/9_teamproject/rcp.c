#include "common.h"

extern char word_begin[WORDMAX][WORD_SIZE];
extern char word_medium[WORDMAX][WORD_SIZE];
extern char word_high[WORDMAX][WORD_SIZE];

extern int restart;
extern int level; //사용자가 선택한 난이도

int word_total_score_rcp; //낱말 연습 총 점수
int word_each_score_rcp; //각 단어 별로 얻은 점수

int start_time_rcp, end_time_rcp;
int i_word_rcp1; //인덱스 값
int i_word_rcp2; //인덱스 값
int i_word_rcp3; //인덱스 값

int true_rcp = 0;
int word_num_rcp = 10;

int l_rcp_1;//문자열 길이
int l_rcp_2;
int l_rcp_3;

int computer;

int pt_rcp = 0;

int T_rcp;//각 단어 입력하는 데 걸린 시간
int wn_rcp = 0;

char  ch_rcp, word_input_rcp[WORD_SIZE];

void wordgame_main_rcp() {

	srand(time(0));

	if (level == 1) {
		printword_rcp();
		scanword_rcp(word_begin);
	}
	else if (level == 2) {
		printword_rcp();
		scanword_rcp(word_medium);
	}
	else if (level == 3) {
		printword_rcp();
		scanword_rcp(word_high);
	}
	else if (level == 4) {
		ask_restart();
		if (restart == 1) {
			main();
		}
		else {
			exit(0);
		}
	}
}

void printword_rcp() {
	int check = WORDMAX;

	computer = rand() % 3;

	i_word_rcp1 = rand() % WORDMAX;
	i_word_rcp2 = rand() % WORDMAX;
	i_word_rcp3 = rand() % WORDMAX;

	gotoxy(35, 27);
	printf("                           ");

	gotoxy(17, 23);
	printf("                        ");
	gotoxy(35, 23);
	printf("                        ");
	gotoxy(55, 23);
	printf("               ");

	gotoxy(10, 6);
	printf("                                                    ");
	gotoxy(10, 7);
	printf("                                                    ");
	gotoxy(10, 8);
	printf("                                                    ");
	gotoxy(10, 9);
	printf("                                                    ");
	gotoxy(10, 10);
	printf("                                                    ");
	gotoxy(10, 11);
	printf("                                                    ");
	gotoxy(10, 12);
	printf("                                                    ");
	gotoxy(10, 13);
	printf("                                                    ");

	start_time_rcp = time(0);

	textcolor(10);
	gotoxy(38, 13);
	printf("VS");
	textcolor(15);

	rock_rcp(0, 0);
	scissors_rcp(0, 0);
	paper_rcp(0, 0);

	if (level == 1) {
		gotoxy(17, 23);
		l_rcp_1 = strlen(word_begin[i_word_rcp1]);
		printf("%s ", word_begin[i_word_rcp1]);
		gotoxy(35, 23);
		l_rcp_2 = strlen(word_begin[i_word_rcp2]);
		printf("%s ", word_begin[i_word_rcp2]);
		gotoxy(55, 23);
		l_rcp_3 = strlen(word_begin[i_word_rcp3]);
		printf("%s ", word_begin[i_word_rcp3]);
	}
	if (level == 2) {
		gotoxy(17, 23);
		l_rcp_1 = strlen(word_medium[i_word_rcp1]);
		printf("%s ", word_medium[i_word_rcp1]);
		gotoxy(35, 23);
		l_rcp_2 = strlen(word_medium[i_word_rcp2]);
		printf("%s ", word_medium[i_word_rcp2]);
		gotoxy(55, 23);
		l_rcp_3 = strlen(word_medium[i_word_rcp3]);
		printf("%s ", word_medium[i_word_rcp3]);
	}
	if (level == 3) {
		gotoxy(17, 23);
		l_rcp_1 = strlen(word_high[i_word_rcp1]);
		printf("%s ", word_high[i_word_rcp1]);
		gotoxy(35, 23);
		l_rcp_2 = strlen(word_high[i_word_rcp2]);
		printf("%s ", word_high[i_word_rcp2]);
		gotoxy(55, 23);
		l_rcp_3 = strlen(word_high[i_word_rcp3]);
		printf("%s ", word_high[i_word_rcp3]);
	}

}

void scanword_rcp(const char wordlevel[][WORD_SIZE]) {
	// 매 게임마다 30개 단어 출력
	int j = 0;
	int result_rcp;
	int resume = 0, qe = 0;

	while (1) {
		if (time(0) >= start_time_rcp) {    //잔여 시간 출력
			CursorView(FALSE);
			gotoxy(6, 4);
			printf("남은 시간 : %d초  ", TIME_LIMIT_RCP - (time(0) - start_time_rcp - pt_rcp));
		}
		if (wn_rcp >= word_num_rcp) {
			gotoxy(6, 4);
			printf("                                  ");
			gotoxy(35, 13);
			printf("                                  ");

			gotoxy(17, 23);
			printf("                        ");
			gotoxy(35, 23);
			printf("                        ");
			gotoxy(55, 23);
			printf("              ");

			gotoxy(10, 6);
			printf("                                                    ");
			gotoxy(10, 7);
			printf("                                                    ");
			gotoxy(10, 8);
			printf("                                                    ");
			gotoxy(10, 9);
			printf("                                                    ");
			gotoxy(10, 10);
			printf("                                                    ");
			gotoxy(10, 11);
			printf("                                                    ");
			gotoxy(10, 12);
			printf("                                                    ");
			gotoxy(10, 13);
			printf("                                                    ");
			gotoxy(10, 14);
			printf("                                                    ");
			gotoxy(10, 15);
			printf("                                                    ");
			gotoxy(10, 16);
			printf("                                                    ");
			gotoxy(10, 17);
			printf("                                                                ");
			gotoxy(10, 18);
			printf("                                                                ");
			gotoxy(10, 19);
			printf("                                                                ");
			gotoxy(10, 20);
			printf("                                                                ");
			gotoxy(10, 21);
			printf("                                                    ");
			gotoxy(10, 22);
			printf("                                                    ");
			gotoxy(10, 23);
			printf("                                                    ");

			gotoxy(31, 10);
			printf("---게 임 종 료---");
			gotoxy(32, 12);
			textcolor(14);
			printf("최종 점수: %d점", word_total_score_rcp);
			textcolor(15);
			if (level < 3) {
				gotoxy(20, 16);
				printf("*아무키나 누르시면 다음레벨로 넘어갑니다*");
			}
			else if (level == 3) {
				gotoxy(30, 16);
				printf("*아무키나 눌러주세요*");
			}

			word_total_score_rcp = 0;
			wn_rcp = 0;

			_getch();

			gotoxy(31, 10);
			printf("                                  ");
			gotoxy(32, 12);
			printf("                                  ");
			gotoxy(20, 16);
			printf("                                           ");

			CursorView(TRUE);
			level++;
			if (level < 4) {
				game1_screen_sp(level);
				waiting();
			}
			wordgame_main_rcp();
		}
		if (time(0) == start_time_rcp + TIME_LIMIT_RCP + pt_rcp) {

			if (!strncmp(wordlevel[i_word_rcp1], word_input_rcp, l_rcp_1)) {
				if (j > l_rcp_1)
				{
					true_rcp = 3;
				}
				else {
					true_rcp = 0; //사용자 입력값 가위
					scissors_rcp(27, -9);//가위 함수 출력/gotoxy	
				}
			}
			else if (!strncmp(wordlevel[i_word_rcp2], word_input_rcp, l_rcp_2)) {
				if (j > l_rcp_2)
				{
					true_rcp = 3;
				}
				else {
					true_rcp = 1;// 사용자 입력값 바위
					rock_rcp(13, -9);//바위 함수 출력/gotoxy
				}
			}
			else if (!strncmp(wordlevel[i_word_rcp3], word_input_rcp, l_rcp_3)) {
				if (j > l_rcp_3)
				{
					true_rcp = 3;
				}
				else {
					true_rcp = 2; //사용자 입력값 보
					paper_rcp(-7, -8);//보 함수 출력/gotoxy
				}
			}
			else {
				true_rcp = 3; // 그냥 오타로 기권처리
			}

			switch (computer)
			{
			case 0:
				scissors_rcp(8, -9);//가위 그림 출력/gotoxy
				break;
			case 1:
				rock_rcp(-8, -9);//바위 그림 출력/gotoxy
				break;
			case 2:
				paper_rcp(-32, -8);//보 그림 출력(함수)
				break;
			}
			wn_rcp++;
			result_rcp = decision(computer, true_rcp);

			wordscore_rcp(result_rcp);    //점수 계산
			textcolor(15);

			Sleep(2000);
			gotoxy(36, 4);
			printf("          ");

			word_total_score_rcp += word_each_score_rcp;     //단어게임 총점수 초기화
			cal_word_rcp(T_rcp, word_input_rcp, wordlevel, word_num_rcp);

			j = 0;

			printword_rcp();
			gotoxy(35, 27);

			pt_rcp = 0;
		}
		if (_kbhit()) {
			gotoxy(35 + j, 27);
			ch_rcp = _getch();
			if ((ch_rcp >= 'a' && ch_rcp <= 'z') || (ch_rcp >= 'A' && ch_rcp <= 'Z')) {
				printf("%c", ch_rcp);
				word_input_rcp[j] = ch_rcp;
				j++;
			}
			if ((ch_rcp == 8) && (j != 0)) {
				printf("\b");
				j--;
				printf(" ");
				printf("\b");
			}
			if (ch_rcp == 27) {
				int pt_rcp_each = 0;
				pause(&pt_rcp_each, &resume, &qe, 32);
				pt_rcp += pt_rcp_each;
				if (resume == 1) {
					gotoxy(35, 27);
					continue;
				}
				if (qe == 1) {
					word_total_score_rcp = 0;
					wn_rcp = 0;
					pt_rcp = 0;
					CursorView(TRUE);
					break;
				}
			}
			if (ch_rcp == 13) {
				end_time_rcp = time(0);
				T_rcp = end_time_rcp - start_time_rcp - pt_rcp;
			}

		}
		if (j > WORD_SIZE) {
			j = 0;
			gotoxy(35, 27);
			printf("                    ");
			gotoxy(35, 27);

		}

	}
}

void wordscore_rcp(int n) {
	switch (n)
	{
	case 0: //무승부
		word_each_score_rcp = 6;
		gotoxy(36, 4);
		textcolor(11);
		printf("무승부");
		break;

	case 1: //승리
		word_each_score_rcp = 10;
		gotoxy(37, 4);
		textcolor(14);
		printf("승리");
		break;

	case 2://패배
		word_each_score_rcp = 2;
		gotoxy(37, 4);
		textcolor(12);
		printf("패배");
		break;

	case 3://기권
		word_each_score_rcp = 0;
		gotoxy(37, 4);
		textcolor(13);
		printf("기권");
		break;
	}
}


int decision(int ascomputer, int asuser)
{
	if (asuser == 3) {
		return 3; //기권
	}
	else if (ascomputer == asuser) {
		return 0; //무승부
	}
	else if ((ascomputer == 0 && asuser == 1) || (ascomputer == 1 && asuser == 2) || (ascomputer == 2 && asuser == 0)) {
		return 1; //이김
	}
	else {
		return 2; //짐
	}
}

void scissors_rcp(int a, int b) {
	gotoxy(10 + a, 15 + b);
	printf("       ■     ■");
	gotoxy(10 + a, 16 + b);
	printf("        ■   ■");
	gotoxy(10 + a, 17 + b);
	printf("         ■ ■");
	gotoxy(10 + a, 18 + b);
	printf("       ■■■■");
	gotoxy(10 + a, 19 + b);
	printf("      ■■■■■");
	gotoxy(10 + a, 20 + b);
	printf("       ■■■■");
	gotoxy(10 + a, 21 + b);
	printf("         ■■");
}
void rock_rcp(int a, int b) {
	gotoxy(26 + a, 17 + b);
	printf("         ■■■");
	gotoxy(26 + a, 18 + b);
	printf("       ■■■■■");
	gotoxy(26 + a, 19 + b);
	printf("      ■■■■■■");
	gotoxy(26 + a, 20 + b);
	printf("       ■■■■■");
	gotoxy(26 + a, 21 + b);
	printf("         ■■■ ");
}
void paper_rcp(int a, int b) {
	gotoxy(47 + a, 14 + b);
	printf("          ■ ");
	gotoxy(47 + a, 15 + b);
	printf("        ■■■");
	gotoxy(47 + a, 16 + b);
	printf("     ■ ■■■");
	gotoxy(47 + a, 17 + b);
	printf("     ■ ■■■   ■");
	gotoxy(47 + a, 18 + b);
	printf("     ■■■■■ ■");
	gotoxy(47 + a, 19 + b);
	printf("     ■■■■■■");
	gotoxy(47 + a, 20 + b);
	printf("      ■■■■■");
	gotoxy(47 + a, 21 + b);
	printf("        ■■■");
}

void cal_word_rcp(int timespent, char* word_input, char answer[][WORD_SIZE], int num)
{
	int correct = 0;
	int error = 0;
	float speed, accuracy, processivity;
	int s;
	int len;
	int i_cal = 0;

	if (true_rcp == 0) {
		i_cal = i_word_rcp1;
	}
	else if (true_rcp == 1) {
		i_cal = i_word_rcp2;
	}
	else if (true_rcp == 2) {
		i_cal = i_word_rcp3;
	}
	len = strlen(answer[i_cal]);

	for (s = 0; s < len; s++) //오타수 측정:
	{
		if (word_input[s] != answer[i_cal][s])// 사용자입력 각각의 알파벳과 정답 알파벳을 비교해서 같지 않으면
		{
			error += 1;
		}
	}

	//오타가 아닌 정타수
	correct = len - error;

	//타자속도 : (타자수/걸린시간)*60 = 분당 타자속도
	speed = (len / (float)(timespent)) * 60;

	//정확도= 정타수/문자열의 길이 *100
	accuracy = ((float)correct / strlen(answer[i_cal])) * 100;

	//진행도
	processivity = ((float)(wn_rcp) / num) * 100;

	if (time(0) == start_time_rcp + TIME_LIMIT_RCP + pt_rcp) {
		speed = 0;
	}

	if (true_rcp == 3) {
		error = 0;
		accuracy = 0;
	}

	//기존 출력 지우기
	gotoxy(79, 22);
	printf("                   ");
	gotoxy(79, 23);
	printf("                 ");
	gotoxy(79, 24);
	printf("                   ");
	gotoxy(79, 25);
	printf("                   ");
	gotoxy(79, 26);
	printf("                   ");
	gotoxy(79, 27);
	printf("                   ");

	//출력
	if (timespent <= 0)//걸린시간이 0이면
	{
		gotoxy(79, 22);
		printf("타자속도: too fast");
		gotoxy(79, 24);
		printf("정확도 : %.f (%%)", accuracy);
		gotoxy(79, 25);
		printf("오타수: %d (개)", error);
		gotoxy(79, 26);
		printf("진행도: %.1f (%%)", processivity);
		gotoxy(79, 28);
		printf("SCORE: %d ", word_total_score_rcp);
	}

	else {
		gotoxy(79, 22);
		printf("타자속도: %.f (타)", speed);
		gotoxy(79, 24);
		printf("정확도 : %.f (%%)", accuracy);
		gotoxy(79, 25);
		printf("오타수: %d (개)", error);
		gotoxy(79, 26);
		printf("진행도: %.1f (%%)", processivity);
		gotoxy(79, 28);
		printf("SCORE: %d ", word_total_score_rcp);
	}

	correct = 0;
	error = 0;
	accuracy = 0;
	speed = 0;
}
/* <가위 바위 보 게임>
-난이도는 배열의 난이도만 바뀜.
-화면에 반복적으로 5 4 3 2 1 의 시간 제한 초가 출력되도록 함
-10판

-컴퓨터의 선택에 가위바위보 게임을 구현했던 것처럼 숫자로 랜덤값을 부여해 (예: 가위-0 바위-1 보-2)
 가위, 바위, 보 중 하나의 이미지 값을 제한시간(예:5초)에 출력되도록 함

 사용자는 제한시간 안에 입력하지 못하면 <(입력자체x)기권>-0점
		  제한시간 안에 입력하면 <이김>-10점 <무승부> -6점 <(입력했으나)패배>-2점 부여

 사용자가 올바른 값을 입력하지 못하면
 아무리 타자를 쳐도 미리 설정한 버퍼수를 넘지 못하게 하고,
 올바른 값을 입력하면 제한시간에 승패를 가림. 엔터를 눌러야 타자를 다 친 시간을 구해 타자속도를 출력할 수 있어 단어를 제한 시간 안에 다 썼으면 엔터키를 눌러야 함.

 입력을 해 놓으면 endtime=time(0)을 사용해 시작시간+제한시간 (예: start_time+TIMELIMIsT)에
 strcmp로 랜덤으로 출력된 세 문자열과 사용자가 입력한 문자열을 비교해

 맞다면
 사용자가 입력한 값이 가위, 바위, 보 중에 어떤 값에 해당하는지를 알아내어 가위 바위 보 중 해당하는 숫자로 바꾼다.
 바꾼 후 사용자가 입력한 가위바위보의 값과 컴퓨터의 값을 비교해 무승부/승/패를 가려 점수를 부여한 후, score에 부여된 점수를 더해준 후, 다음 게임이 뜬다.

 세 문자열 중 맞는 문자열이 하나도 없다면(입력이 틀림)
 기권으로 처리해 점수를 부여한다. score에 부여된 점수를 더해준 후, 다음 게임이 뜬다.
*/