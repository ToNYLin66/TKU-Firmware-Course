#define _CRT_SECURE_NO_WARNINGS
//[古老的密碼/Ancient Cipher](1/2)
#define IN "P08IN.txt"
#define OUT "P08OUT.txt"
//***************************************
#include <iostream>
#include <ctime>
using namespace std;
void redir(void);

//***************************************
/* Work Space*/
#include <algorithm>
#include <string>
//***************************************

int main(void) {
	redir(); //redirection

//***************************************
/* Work Space*/
	char stringA[101], stringB[101]; //依題意
	int countA[26], countB[26], len, i;
	bool ans;

	while (scanf("%s", stringA) == 1) {
		scanf("%s", stringB);		
		memset(countA, 0, sizeof(countA));
		memset(countB, 0, sizeof(countB));		
		len = int(strlen(stringA));
		for (i = 0; i < len; i++) {
			countA[stringA[i] - 'A']++;
			countB[stringB[i] - 'A']++;
		}
		//sort A[0], A[1], ..., A[25]
		sort(countA, countA + 26);
		//sort B[0], B[1], ..., B[25]
		sort(countB, countB + 26);
		ans = true;
		for (i = 0; i < 26; i++) {
			if (countA[i] != countB[i]) {
				ans = false;
				break;
			}
		}
		printf("%s\n", ans ? "YES" : "NO");
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

//Input(IN) Sample
/*
JWPUDJSTVP
VICTORIOUS
MAMA
ROME
HAHA
HEHE
AAA
AAA
NEERCISTHEBEST
SECRETMESSAGES
*/

//Output(OUT)
/*
YES
NO
YES
YES
NO
*/