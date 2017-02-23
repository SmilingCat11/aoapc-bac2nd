// ex3_9uva10340.cpp -- All in all
#include <stdio.h>
#include <string.h>
#define maxn 105

int main()
{
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	char s[maxn], t[maxn];
	while(scanf("%s%s", &s, &t) == 2) {
		int k = -1, result = 1;
		for (int i = 0; i < strlen(s); i++) {
			int j;
			for (j = k+1; j < strlen(t); j++) {
				if (t[j] == s[i]) { k = j; break; }
//				if (t[j] == s[i]) { k = j; printf("s[%d] = %d, t[%d] = %d, k = %d\n", i, s[i], j, t[j], k); break; }
			}
//			printf("s[%d] = %d, t[%d] = %d, k = %d\n", i, s[i], j, t[j], k);
			if (k != j) { result = 0; break; }
		}
//		printf(result ? "Yes\n": "No\n");
		printf("%s\n", result ? "Yes": "No"); 
	}
	return 0;
}
