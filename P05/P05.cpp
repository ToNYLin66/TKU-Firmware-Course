#define _CRT_SECURE_NO_WARNINGS
//[猜數字遊戲的提示/Master-Mind Hints](1/2)
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
	int a[1000], b[1000]; //陣列大小依題目定義

	while (scanf("%d", &n) == 1 && n) { //n = 0時輸入結束
		printf("Game %d\n", ++kase);
		for (i = 0; i<n; i++) {
			scanf("%d", &a[i]);
		}

		while (1) {
			A = B = 0;
			for (i = 0; i<n; i++) {
				scanf("%d", &b[i]);
				if (a[i] == b[i]) A++; //直接統計可得A
			}
			
			if (b[0] == 0) break; //正常的猜測序列不會有0
								  //判斷第一個數是否為0即可
			for (d = 1; d <= 9; d++) { //只會出現數字1到9
				c1 = c2 = 0;
				for (i = 0; i<n; i++) { //對每個數字d, 統計在二者出現在a和b的次數: c1和c2
					if (a[i] == d) c1++;
					if (b[i] == d) c2++;
				}
				B += min(c1, c2); //min(c1, c2)就是該數字對B的貢獻
			}

			printf(" (%d,%d)\n", A, B - A); //最後要減去A的部分
		}
	}
//***************************************
	freopen("CON", "r", stdin); //取消重新導向
	freopen("CON", "w", stdout);

	printf("Time used = %.2f\n", (double)clock() / CLK_TCK); //傳回程式目前為止執行的時間

	system("pause");
	return 0; //the end...
	}

//[猜數字遊戲的提示/Master-Mind Hints](2/2)
void redir(void)
{
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
