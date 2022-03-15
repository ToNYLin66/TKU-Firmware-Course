#define _CRT_SECURE_NO_WARNINGS
//[TeX中的引號/TeX Quotes]
#define IN "P02IN.txt"
#define OUT "P02OUT.txt"
//***************************************
#include <iostream>
#include <ctime>
using namespace std;
void redir(void);
//***************************************
/* Work Space*/

//***************************************
int main(void)
{
	redir(); //redirection
//***************************************
/* Work Space*/
	char c;
	bool flag = true; //true for left, false for right
	
	//while ((c = getchar()) != EOF) 或 while (scanf("%c", &c) != EOF) 都可
	//while (cin >> c) 不可，因為如果c為空格就不會執行while迴圈
	while ((c = getchar()) != EOF) {
		if (c == '"') {
			printf("%s", flag ? "``" : "''");
			flag = !flag;
		}
		else {
			//printf("%c", c); 或 putchar(c); 或 cout << c; 都可
			printf("%c", c);
		}
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
/* Work Space*/
//Input(IN) Sample
/*
"To be or not to be," quoth the Bard, "that
is the question".
The programming contestant replied: "I must disagree.
To `C' or not to `C', that is The Question!"
*/
//Output(OUT)
/*
``To be or not to be,'' quoth the Bard, ``that
is the question''.
The programming contestant replied: ``I must disagree.
To `C' or not to `C', that is The Question!''
*/