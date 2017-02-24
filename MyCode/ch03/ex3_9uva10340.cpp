// ex3_9uva10340.cpp -- All in all
// There should not be & when scanf in string
#include <stdio.h>
#include <string.h>
#define maxn 1000005 
// #define maxn 10 // see what will happen if the array is overflowed

int main()
{
//	freopen("test.in", "r", stdin);
//	freopen("test.out", "w", stdout);
	char s[maxn], t[maxn];
	while(scanf("%s%s", s, t) != EOF) {
		int k = -1, result = 1;
		for (int i = 0; i < strlen(s); i++) {
			int j;
			for (j = k+1; j < strlen(t); j++) {
				if (t[j] == s[i]) { k = j; break; }
//				if (t[j] == s[i]) { k = j; printf("s[%d] = %c, t[%d] = %c, k = %d\n", i, s[i], j, t[j], k); break; }
			}
//			printf("s[%d] = %c, t[%d] = %c, k = %d\n", i, s[i], j, t[j], k);
			if (k != j) { result = 0; break; }
		}
//		printf(result ? "Yes\n": "No\n");
		printf("%s\n", result ? "Yes": "No"); 
	}
	return 0;
}
