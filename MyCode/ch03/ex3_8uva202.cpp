// ex3_8uva202.cpp -- Repeating Decimals
// the precision require is so high, so think about using array
// seb-question: how to find a repeating cycle in the array
#define maxn 3000
int c[maxn];
int t[maxn];

#include <stdio.h> 
#include <string.h>
int main()
{
//	freopen("test.in", "r", stdin);
//	freopen("test.out", "w", stdout);

	int a, b, j, k, end;
	
	while(scanf("%d%d", &a, &b) == 2) {
		memset(c, 0, sizeof(int) * maxn);
		memset(t, 0, sizeof(int) * maxn);
		int a_new = a;
		for (int i = 0; i < maxn; i++) {
			t[i] = a_new;
			c[i] = a_new / b;
			for (j = 1; j < i; j++) {
//				printf("t[%d] = %d, c[%d] = %d\n", i, t[i], i, c[i]);
				if (t[i] == t[j]) { k = i-j; break; } 
			} 
			if (i > 0 && i != j && t[i] == t[j]) { end = i; break; }		
			a_new = a_new % b;
			a_new *= 10;
		}
		printf ("%d/%d = ", a, b);
		if (k <= 50) {
		for (int i = 0; i < end; i++) {
			printf("%d", c[i]);
			if (i == 0) printf(".");
			if (i == j - 1) printf("(");
		}
		printf(")\n");
		}

		if (k > 50) {
			for (int i = 0; i < 51; i++) {
			printf("%d", c[i]);
			if (i == 0) printf(".");
			if (i == j - 1) printf("(");
		}
		printf("...)\n");
		}
		printf("   %d = number of digits in repeating cycle\n\n", k);
	}
	return 0;
}
