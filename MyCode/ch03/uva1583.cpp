// uva1583.cpp --  Digit Gernerator
// ****BUG****
// missing % in scanf
// forget initializing p = 0 in the for

#include <stdio.h>
#include <string.h>
//#include <limits.h>
const int maxn = 100000;
int ans[maxn+100];

int main()
{
//	printf("The value of INT_MAX is %i\n", INT_MAX);
//	freopen("test.in", "r", stdin);
//	freopen("test.out", "w", stdout);
	memset(ans, 0, sizeof(ans));
	for (int m = 1; m < maxn; m++) {
		int x = m, y = m;
//		printf("\n<%ld>\n", m);
		while(x > 0) { y += x % 10; x /= 10; }
		if(ans[y] == 0 || m < ans[y]) ans[y] = m;
	}

	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		printf("%d\n", ans[n]);
	}
	
	return 0;
}
