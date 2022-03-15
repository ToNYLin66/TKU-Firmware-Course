#define _CRT_SECURE_NO_WARNINGS
//[WERTYU]
#define IN "P03IN.txt"
#define OUT "P03OUT.txt"
//***************************************
#include <iostream>
#include <ctime>
using namespace std;
void redir(void);
//***************************************
/* Work Space*/
//***************************************
int main(void)
{
	redir(); //redirection
//***************************************
/* Work Space*/
	char s[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;\'ZXCVBNM,./"; //注意脫逃字元
	int i;
	char c;
	while ((c = getchar()) != EOF) {
		for (i = 1; s[i] && s[i] != c; i++);
		if (s[i]) {
			putchar(s[i - 1]); //寫入一個字元到標準輸出
		}
		else {
			putchar(c);
		}
	}
//***************************************
	freopen("CON", "r", stdin); //取消重新導向
	freopen("CON", "w", stdout);
	printf("Time used = %.2f\n", (double)clock() / CLK_TCK); //傳回程式目前為止執行的時間
	system("pause");
	return 0; //the end...
}
void redir(void)
{
	freopen(IN, "r", stdin);
	freopen(OUT, "w", stdout);
}
//***************************************
/* Work Space*/
//Input(IN) Sample
/*
O S, GOMR YPFSU/
*/
//Output(OUT)
/*
I AM FINE TODAY.
*/
