#define _CRT_SECURE_NO_WARNINGS
//[3n+1問題/The 3n+1Problem](1/2)
#define IN "P01IN.txt"
#define OUT "P01OUT.txt"
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
	int count;
	long long nLong;
	while (cin >> nLong) {
		count = 0;
		while (nLong > 1) {
			++count;
			if (nLong % 2 == 1) {
				nLong = nLong * 3 + 1;
			}
			else {
				nLong /= 2;
			}
		}
		cout << count << endl;
	}
//***************************************
	freopen("CON", "r", stdin);
	freopen("CON", "w", stdout);
	printf("Time used = %.2f\n", (double)clock() / CLK_TCK);
	system("pause");
	return 0;
}

void redir(void) {
	freopen(IN, "r", stdin);
	freopen(OUT, "w", stdout);
}
//**************************************
/* Work Space*/
//[3n+1問題/The 3n+1Problem](2/2)
//Input(IN) Sample
/*
3
22
987654321
*/

//Output(OUT)
/*
7
15
180
*/