#define _CRT_SECURE_NO_WARNINGS
//[�q�Ʀr�C��������/Master-Mind Hints](1/2)
#define IN "P05IN.txt"
#define OUT "P05OUT.txt"
//***************************************
#include <iostream>
#include <ctime>
using namespace std;
void redir(void);
//***************************************
/* Work Space*/
#include <algorithm>
//***************************************
int main(void)
{
	redir(); //redirection
//***************************************
/* Work Space*/
	int n, i, A, B, d, c1, c2;
	int kase = 0;
	int a[1000], b[1000];

	while ((cin >> n) && n) {
		//���Game
		cout << "Game " << ++kase << endl;
		//Ū�����ׯx�}
		for (i = 0; i < n; i++) {
			cin >> a[i];
		}
		while (1) {
			//A
			A = B = 0;
			for (i = 0; i < n; i++) {
				cin >> b[i];
				if (a[i] == b[i]) {
					A++;
				}
			}
			if (b[0] == 0) {
				break;
			}
			//B
			for (d = 1; d <= 9; d++) {
				c1 = c2 = 0;
				for (i = 0; i < n; i++) {
					if (a[i] == d) {
						c1++;
					}
					if (b[i] == d) {
						c2++;
					}
				}
				B += min(c1, c2);
			}
			cout << " (" << A << "," << B - A << ")" << endl;
		}
	}
	//***************************************
	freopen("CON", "r", stdin); //�������s�ɦV
	freopen("CON", "w", stdout);
	printf("Time used = %.2f\n", (double)clock() / CLK_TCK); //�Ǧ^�{���ثe������檺�ɶ�
	system("pause");
	return 0; //the end...
}

//[�q�Ʀr�C��������/Master-Mind Hints](2/2)
void redir(void) {
	freopen(IN, "r", stdin);
	freopen(OUT, "w", stdout);
}
//***************************************
/* Work Space*/
//Input(IN) Sample
/*
4
1 3 5 5
1 1 2 3
4 3 3 5
6 5 5 1
6 1 3 5
1 3 5 5
0 0 0 0
10
1 2 2 2 4 5 6 6 6 9
1 2 3 4 5 6 7 8 9 1
1 1 2 2 3 3 4 4 5 5
1 2 1 3 1 5 1 6 1 9
1 2 2 5 5 5 6 6 6 7
0 0 0 0 0 0 0 0 0 0
0
*/

//Output(OUT)
/*
Game 1
(1,1)
(2,0)
(1,2)
(1,2)
(4,0)
Game 2
(2,4)
(3,2)
(5,0)
(7,0)
*/