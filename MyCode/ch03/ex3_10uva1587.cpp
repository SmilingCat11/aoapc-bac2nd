// ex3_10uva1587.cpp -- Box
// subquestion: count how many different numbers there are in the array.
// remember to initialize the array using memset.

#include <stdio.h>
#include <string.h>

int issame (int a, int b, int c, int d) 
{
	return a == c && b == d;
}

int main()
{
//	freopen("test.in", "r", stdin);
//	freopen("test.out", "w", stdout);
	
	int a1[6], a2[6], a3[12] = {};
	int i = 0, k = 0, x, y;
	while (scanf("%d%d", &x, &y) != EOF) { 

		a1[i] = (x <= y) ? x : y;
		a2[i++] = (x > y) ? x : y;
		a3[k++] = a1[i-1];
		a3[k++] = a2[i-1];

		if (i == 6) {
			int flag = 1; // possible
			int diff = 0;
			for (i = 0; i < 12; i++){
				int j, find = 0;
//				printf("%d ", a3[i]);
				for (j = 0; j < i; j++) {
					if (a3[i] == a3[j]) { find = 1; break; }
				}
				if (!find) diff++;
			}

			int square = 0;
			for (i = 0; i < 6; i++) {
				square += ( a1[i] == a2[i] );
//				printf("\n%d %d", a1[i], a2[i]);
			} 
//			printf("diff = %d, square = %d\n", diff, square);
			if (diff == 3 && square == 0) {
				for (i = 0; i < 6; i++) {
					int samefallet = 0;
					for (int j = 0; j < 6; j++) {
						if (issame(a1[i], a2[i], a1[j], a2[j])) samefallet++;
					}
					if (samefallet != 2) {flag = 0; break;}				
				}
			}
			else if (diff == 2 && square == 2) { flag = 1;/* printf("diff2\n");*/ }
			else if (diff == 1) { flag = 1; /*printf("diff1\n");*/}
			else { flag = 0; /*printf("else\n");*/ }

			printf("%s\n", flag? "POSSIBLE": "IMPOSSIBLE");
			i = 0, k = 0;
			memset(a1, 0, sizeof(int) * 6);
			memset(a2, 0, sizeof(int) * 6);
			memset(a3, 0, sizeof(int) * 12);
		}
	}
	return 0;
}
