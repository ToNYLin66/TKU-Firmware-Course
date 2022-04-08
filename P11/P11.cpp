#define _CRT_SECURE_NO_WARNINGS
//[訊息解碼/Message Decoding](1/2)
#define IN "P11IN.txt"
#define OUT "P11OUT.txt"
//***************************************
#include <iostream>
#include <ctime>
using namespace std;
void redir(void);

//***************************************
/* Work Space*/
int readcodes(void);
int readint(int c);
int code[8][128];
//***************************************

int main(void) {
	redir(); //redirection

//***************************************
/* Work Space*/
	int len, v;
	while (readcodes()) {
		for (;;) {
			len = readint(3);
			if (len == 0) {
				break;
			}
			for (;;) {
				v = readint(len);
				if (v == (1 << len) - 1) {
					break;
				}
				putchar(code[len][v]);
			}
		}
		putchar('\n');
	}
//***************************************

	freopen("CON", "r", stdin); //取消重新導向
	freopen("CON", "w", stdout);
	printf("Time used = %.2f\n", (double)clock() / CLK_TCK); //傳回程式目前為止執行的時間
	system("pause");
	return 0; //the end...
}

void redir(void) {
	freopen(IN, "r", stdin);
	freopen(OUT, "w", stdout);
}

//***************************************
//[訊息解碼/Message Decoding](2/2)
/* Work Space*/
//建立解碼表
int readcodes(void) {
	int len, i;
	char ch;
	memset(code, 0, sizeof(code)); //清空陣列
	while ((ch = getchar()) == '\n');//跳過分行符號
	if (ch == EOF) return 0;
	code[1][0] = ch;

	for (len = 2; len <= 7; len++) {
		for (i = 0; i< (1 << len) - 1; i++) {
			ch = getchar();
			if (ch == '\n') {
				return 1;
			}
			code[len][i] = ch;
		}
	}
}
//讀取長度為c的01字串(二進位整數), 並將其轉換為十進位整數
int readint(int c) {
	int v = 0, ch;
	while (c--) {
		while ((ch = getchar()) == '\n');//跳過分行符號, 因為編碼文字可能由多行組成
		v = v * 2 + ch - '0';
	}
	return v;
}

//Input(IN) Sample
/*
TNM AEIOU
0010101100011
1010001001110110011
11000
$#**\
0100000101101100011100101000
*/
//Output(OUT)
/*
TAN ME
##*\$
*/