#define _CRT_SECURE_NO_WARNINGS
//[救濟金發放/The Dole Queue](1/2)
#define IN "P10IN.txt"
#define OUT "P10OUT.txt"
//***************************************
#include <iostream>
#include <ctime>
using namespace std;
void redir(void);

//***************************************
/* Work Space*/
int a[20]; //依題意(致多19人)
int n;
int go(int p, int d, int t);

//***************************************
int main(void) {
	redir(); //redirection

//***************************************
/* Work Space*/
	int i, left, pA, pB, k, m;

	while(scanf("%d%d%d", &n, &k, &m) == 3 && n){
		for(i = 1; i<= n; i++){
			a[i] = i;
		}
		left = n;
		pA = n; //預備位置(回撥1步)
		pB = 1;

		while(left){
			pA = go(pA, 1, k); //1 for 逆時針
			pB = go(pB, -1, m); //-1 for 順時針		
			printf("%3d", pA);
			left--;
			if(pB != pA){
				printf("%3d", pB);
				left--;
			}
			a[pA] = a[pB] = 0; //pA, pB 離開隊伍
			if (left) {
				printf(",");
			}
		}
		printf("\n");
	}
//***************************************

	freopen("CON", "r", stdin);
	freopen("CON", "w", stdout);
	printf("Time used = %.2f\n", (double)clock()/CLK_TCK);
	system("pause");
	return 0; //the end...
}

void redir(void) {
	freopen(IN, "r", stdin);
	freopen(OUT, "w", stdout);
}

//***************************************
/* Work Space*/
//順(逆)時針前進t個人
int go(int p, int d, int t) {
	while(t--){
		do{
			p = p + d;
			if(p == (n + 1)) p = 1;
			if(p == 0) p = n;
		}while(a[p] == 0); //0 表早已離開隊伍
	}
	return p;
}

//Input(IN) Sample
/*
10 4 3
0 0 0
*/

//Output(OUT)
/*
  4  8,  9  5,  3  1,  2  6, 10,  7
*/
