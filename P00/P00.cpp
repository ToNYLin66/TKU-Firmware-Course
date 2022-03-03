//[範本/Tempate]
#define IN "P0101IN.txt"
#define OUT "P0101OUT.txt"
//**************************************
#include <iostream>
#include <ctime>
using namespace std;
void redir(void);
//**************************************
/* Work Space*/

//**************************************
int main(void)
{
	redir(); //redirection
//***************************************
/* Work Space*/
	
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
//***************************************
/* Work Space*/

//Input(IN) Sample
/*

*/

//Output(OUT)
/*

*/
