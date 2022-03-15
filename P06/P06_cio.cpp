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
	int ans[N + 1] = { 0 };
	int m, x, y, T, n;
	for (x = 1; x <= 100000; x++) {
		m = y = x;
		while (m > 0) {
			y += m % 10;
			m /= 10;
		}
		if (y > N) {
			continue;
		}
		if (ans[y] == 0) {
			ans[y] = x;
		}
	}
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		cout << ans[n] << endl;
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