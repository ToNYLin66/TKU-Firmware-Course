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
int main(void) {
	redir(); //redirection
//***************************************
/* Work Space*/
	char s[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;\'ZXCVBNM,./"; //�`�N��k�r��
	int i;
	char c;
	//while ((c = getchar()) != EOF) �� while (scanf("%c", &c) != EOF) ���i
	//while (cin >> c) ���i�A�]���p�Gc���Ů�N���|����while�j��
	while ((c = getchar()) != EOF) {
		for (i = 0; i < strlen(s); i++) {
			if (s[i] == c) {
				break;
			}
		}
		if (s[i]) {
			//printf("%c", s[i - 1]); �� putchar(s[i - 1]); �� cout << s[i - 1]; ���i
			putchar(s[i - 1]); //�g�J�@�Ӧr����зǿ�X
		}
		else {
			//printf("%c", c); �� putchar(c); �� cout << c; ���i
			putchar(c);
		}
	}
	//***************************************
	freopen("CON", "r", stdin); //�������s�ɦV
	freopen("CON", "w", stdout);
	printf("Time used = %.2f\n", (double)clock() / CLK_TCK); //�Ǧ^�{���ثe������檺�ɶ�
	system("pause");
	return 0; //the end...
}
void redir(void) {
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