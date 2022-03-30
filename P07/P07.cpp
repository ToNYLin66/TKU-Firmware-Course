#define _CRT_SECURE_NO_WARNINGS
//[環狀序列/Circular Sequenc](1/2)
#define IN "P07IN.txt"
#define OUT "P07OUT.txt"
//***************************************
#include <iostream>
#include <ctime>
using namespace std;
void redir(void);

//***************************************
/* Work Space*/
bool sort_less(char *s, int p, int q);
//***************************************

int main(void) {
	redir(); //redirection

//***************************************
/* Work Space*/
	int T, ans, n, i;
	char s[101]; //依題意

	scanf("%d", &T);
	while (T--) {
		scanf("%s", s);
		ans = 0;
		n = int(strlen(s));
		for (i = 1; i<n; i++) {
			if (sort_less(s, i, ans)) {
				ans = i;
			}
		}

		for (i = 0; i<n; i++) {
			putchar(s[(ans + i) % n]);
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
//[環狀序列/Circular Sequenc](2/2)
/* Work Space*/
//環狀字串s的標記法p是否比標示法q的字典序小
bool sort_less(char *s, int p, int q) {
	int n, i;

	n = int(strlen(s));
	for (i = 0; i < n; i++) {
		if (s[(p + i) % n] != s[(q + i) % n]) {
			return s[(p + i) % n] < s[(q + i) % n];
		}
	}
	return false;
}
//***************************************

//Input(IN) Sample
/*
2
CTCC
CGAGTCAGCT
*/

//Output(OUT)
/*
CCCT
AGCTCGAGTC
*/
