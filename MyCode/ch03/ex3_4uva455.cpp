// ex3_4uva455
// ***bug***
// scanf("s", str); 
// while(getchar() != '\n'); 清除回车符 
#include <stdio.h>
#include <string.h>
const int maxn = 85;
int main()
{

//	freopen("test.in", "r", stdin);
//	freopen("test.out", "w", stdout);

	int T;
	scanf("%d", &T);
//while(T--) {
	char str[maxn];
	scanf("%s", str);
	int period;
	for (period = 1; period <= strlen(str); period++) {
		int flag = 1;
//		printf("strlen(str) = %d, flag = %d\n", strlen(str), flag);
//		printf("period = %d\n", period);
		if ( !(strlen(str) % period) ) { // if1 
			for (int i = 0; i < strlen(str) - period; i++) {
//				printf("(%d) period = %d, str[%d] = %c.\n", i, period, i, str[i]);
				if (str[i+period] != str[i]) {flag = 0; break;}
			}
		
			if (flag) { printf("%d\n", period); break;} // 在if1里面 
		}
	}
//}
	return 0;
}
