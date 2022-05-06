#define _CRT_SECURE_NO_WARNINGS
//[�j�z�ۦb����H/Where is the Marble?](1/2)
#define IN "P13IN.txt"
#define OUT "P13OUT.txt"
//***************************************
#include <iostream>
#include <ctime>
using namespace std;
void redir(void);

//***************************************
/* Work Space*/
#include <vector>
#include <algorithm>
//***************************************

int main(void) {
	redir(); //redirection

//***************************************
/* Work Space*/
	int kase = 0, N, Q, i, Z, p;

	while (scanf("%d %d", &N, &Q) == 2 && N) {
		vector<int> a; //block scope
		printf("CASE# %d:\n", ++kase);
		for (i = 0; i < N; i++) {
			scanf("%d", &Z);
			a.push_back(Z);
		}
		sort(a.begin(), a.end());		
		while (Q--) {
			scanf("%d", &Z);
			//lower_bound() �M��j��ε���Z���Ĥ@�Ӧ�m
			p = int(lower_bound(a.begin(), a.end(), Z) - a.begin());
			if (p < a.size() && a[p] == Z) {
				printf("%d found at %d\n", Z, p + 1);
			}
			else {
				printf("%d not found\n", Z);
			}
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
//[�j�z�ۦb����H/Where is the Marble?](2/2)
/* Work Space*/
//Input(IN) Sample
/*
4 1
2
3
5
1
5
5 2
1
3
3
3
1
2
3
0 0
*/

//Output(OUT)
/*
CASE# 1:
5 found at 4
CASE# 2:
2 not found
3 found at 3
*/