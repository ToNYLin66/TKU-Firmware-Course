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
	int n, count;
	long long nLong;

	while (scanf("%d", &n) == 1) {//scanf() 傳回成功讀取資料的個數
		nLong = n; //promotion rule
		
		count = 0;
		while (nLong > 1) {
			++count;
			if (nLong % 2 == 1) {//判斷是否為奇數
				nLong = nLong * 3 + 1;
			}
			else {//偶數
				nLong /= 2;
			}
		}
		printf("%d\n", count);		
	}
//***************************************
	freopen("CON", "r", stdin); //取消重新導向
	freopen("CON", "w", stdout);

	printf("Time used = %.2f\n", (double)clock() / CLK_TCK); //傳回程式目前為止執行的時間
	
	system("pause");
	return 0; //the end...
}

void redir(void)
{
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
