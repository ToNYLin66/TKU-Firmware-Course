#define _CRT_SECURE_NO_WARNINGS
//[�����ǦC/Circular Sequenc](1/2)
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
	int T, ans, n, k;
	char s[101];
	cin >> T;
	while (T--) {
		cin >> s;
		ans = 0;
		n = int(strlen(s));
		for (k = 1; k < n; k++) {
			if (sort_less(s, k, ans)) {
				ans = k;
			}
		}
		for (k = 0; k < n; k++) {
			cout << s[(ans + k) % n];
		}
		cout << endl;
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
//[�����ǦC/Circular Sequenc](2/2)
/* Work Space*/
//�����r��s���аO�kp�O�_��Хܪkq���r��Ǥp
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