// uva340.cpp -- Master-Mind Hints
// Not AC 
// *****BUG*****
// missing the & in scanf
// when initializing array[n], n should be const, and should not get from scanf
#include <stdio.h>
#define maxn 1010

int main()
{
//	freopen("test.in", "r", stdin);
//	freopen("test.out", "w", stdout);
	int n, actual[maxn], guess[maxn];
	int game = 0;
	while (scanf("%d", &n) == 1 && n) {
		printf("Game %d:\n", ++game);
		int c1[10] = {};

		for (int i = 0; i < n; i++) {
			scanf("%d", &actual[i]);
			c1[actual[i]]++;
//			printf("a[%d] = %d, c1: %d\n", i, actual[i], c1[actual[i]]);
		}
		
		for(;;) {
			int A = 0, B = 0;
			int c2[10] = {};
			for (int i = 0; i < n; i++) {
				scanf("%d", &guess[i]);
				if (guess[i] == actual[i]) A++;
				c2[guess[i]]++;
			}
			if (guess[0] == 0) break;

			
			for (int i = 1; i < 9; i++) {
				B += (c1[i] < c2[i]) ? c1[i] : c2[i];
			}
			
			printf("    (%d,%d)\n", A, B - A);
		}
	}
	return 0;
}
