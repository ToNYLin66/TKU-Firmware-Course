#define _CRT_SECURE_NO_WARNINGS
//[�D�l��C��/Hangman Judge](1/2)
#define IN "P09IN.txt"
#define OUT "P09OUT.txt"
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
	int rnd; //���n��round�R�W,�H�K�M���round()�V�c
	char s1[10], s2[10];
	int win, lose, left, chance, i, j, bad;

	while (scanf("%d", &rnd) == 1 && rnd != -1) {
		scanf("%s", s1);
		scanf("%s", s2);
		win = lose = 0;
		left = int(strlen(s1));
		chance = 7;

		for (i = 0; i < int(strlen(s2)); i++) {
			bad = 1;
			for (j = 0; j < int(strlen(s1)); j++) {
				if (s1[j] == s2[i]) {
					left--;
					//�q�@�Ӥw�g�q�L���r���]���
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
			//cout << "You win.\n";
			printf("You win.\n");
		}
		else if (lose) {
			//cout << "You lose.\n";
			printf("You lose.\n");
		}
		else {
			//cout << "You chickened out.\n";
			printf("You chickened out.\n");
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