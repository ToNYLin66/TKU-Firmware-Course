#define _CRT_SECURE_NO_WARNINGS
//[迴文詞/Palindromes](1/2)
#define IN "P04IN.txt"
#define OUT "P04OUT.txt"
//***************************************
#include <iostream>
#include <ctime>
using namespace std;
void redir(void);
//***************************************
/* Work Space*/
char rev[] = "A   3  HIL JM O   2TUVWXY51SE Z  8 "; //注意空白字元的數目
char *meg[] = { "not a palindrome",
				"a regular palindrome",
				"a mirrored string",
				"a mirrored palindrome" };

char mirrored(char ch);//傳回字元的鏡像
//***************************************
int main(void) {
	redir(); //redirection
//***************************************
/* Work Space*/
	char s[21]; //輸入規定至多20個字元
	int length, p, m, i;
	while (cin >> s) {
		length = strlen(s);
		p = m = 1;
		for (i = 0; i < (double)length / 2; i++) {//注意轉型
			if (p && s[i] != s[(length - 1) - i]) {//short-circuit
				p = 0;
			}
			if (m && mirrored(s[i]) != s[(length - 1) - i]) {
				m = 0;
			}
		}
		cout << s << " -- is " << meg[m * 2 + p] << "." << endl << endl;
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

//[迴文詞/Palindromes](2/2)
/* Work Space*/
char mirrored(char ch) { //傳回字元的鏡像
	if (isalpha(ch)) {
		return rev[ch - 'A'];
	}
	else {
		return rev[ch - '0' + 25];
	}
}

//Input(IN) Sample
/*
NOTAPALINDROME
ISAPALINILAPASI
2A3MEAS
TOYOTA
*/

//Output(OUT)
/*
NOTAPALINDROME -- is not a palindrome.

ISAPALINILAPASI -- is a regular palindrome.

2A3MEAS -- is a mirrored string.

ATOYOTA -- is a mirrored palindrome.
*/