#define _CRT_SECURE_NO_WARNINGS
//[醜數/Ugly Numbers](進階)
#define IN "P19IN.txt"
#define OUT "P19OUT.txt"
//***************************************
#include <iostream>
#include <time.h>
using namespace std;
void redir(void);

//***************************************
/* Work Space*/
#include <queue>
#include <vector>
#include <set>
//***************************************
int main(void) {
	redir(); //redirection

//***************************************
/* Work Space*/
	priority_queue<long long> pq;//愈小的(整數)優先權愈低
	set<long long> s;
	int i, j;
	long long x, x0;
	int coef[] = { 2, 3, 5 }; //2x, 3x, 5x
	pq.push(-1);
	s.insert(-1);
	for (i = 1;; i++) {
		x = pq.top();
		pq.pop();
		if (i == 1500) {
			cout << "The 1500'th ugly number is " << -x << endl;
			break;
		}
		for (j = 0; j<sizeof(coef) / sizeof(int); j++) {
			x0 = x * coef[j]; //compute 2x, 3x, 5x
			if (!s.count(x0)) {
				s.insert(x0);
				pq.push(x0);
			}
		}
	}
//***************************************
		
	//freopen("CON", "r", stdin); //取消重新導向
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
/* Work Space*/
//Input(IN) Sample
/*
   64
   65
*/
