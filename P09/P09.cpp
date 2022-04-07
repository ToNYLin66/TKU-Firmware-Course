#define _CRT_SECURE_NO_WARNINGS
//[劊子手遊戲/Hangman Judge](1/2)
#define IN "P09IN.txt"
#define OUT "P09OUT.txt"
//***************************************
#include <iostream>
#include <ctime>
using namespace std;
void redir(void);

//***************************************
/* Work Space*/
#include <string>
//***************************************

int main(void) {
	redir(); //redirection

//***************************************
/* Work Space*/
	int rnd; //不要用round命名,以免和函數round()混淆
	string s1, s2;
	int win, lose, left, chance, i, j, bad;

	while (scanf("%d", &rnd) == 1 && rnd != -1) {
		cin >> s1 >> s2;
		win = lose = 0;
		left = s1.length();
		chance = 7;

		for (i = 0; i<s2.length(); i++) {
			bad = 1;
			for (j = 0; j<s1.length(); j++) {
				if (s1[j] == s2[i]) {
					left--;
					//猜一個已經猜過的字母也算錯
					s1[j] = ' ';
					bad = 0;
				}
			}			
			if (bad) chance--;
			if (!chance) lose = 1;
			if (!left) win = 1;
			if (win || lose) break;
		}

		printf("Round %d\n", rnd);
		if (win) {
			cout << "You win.\n";
		}
		else if (lose) {
			cout << "You lose.\n";
		}
		else {
			cout << "You chickened out.\n";
		}
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
/* Work Space*/
//Input(IN) Sample
/*
1
cheese
chese
2
cheese
abcdefg
3
cheese
abcdefgij
-1
*/

//Output(OUT)
/*
Round 1
You win.
Round 2
You chickened out.
Round 3
You lose.
*/
