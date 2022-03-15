#define _CRT_SECURE_NO_WARNINGS
//[生成元/Digit Generator](1/2)
#define IN "P06IN.txt"
#define OUT "P06OUT.txt"
//***************************************
#include <iostream>
#include <ctime>
using namespace std;
void redir(void);

//***************************************
/* Work Space*/
#define N 100000 //依題意
//***************************************

int main(void) {
	redir(); //redirection

//***************************************
/* Work Space*/
	int ans[N + 1] = {0};
	int m, x, y, T, n;

	for (m = 1; m <= 100000; m++) {
		x = y = m;
		while (x > 0) {
			y += x % 10;
			x /= 10;
		}
		if (y > N) {
			continue;
		}
		if (ans[y] == 0) {
			ans[y] = m;
		}
	}

	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		printf("%d\n", ans[n]);
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
