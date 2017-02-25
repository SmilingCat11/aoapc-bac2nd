// ex3_10uva1587_ref.cpp -- another idea
/*****************************
 First, find lengths shown in the input, and there should be no more than 3 kinds of lengths.
 After that, use those lengths to generate 6 sides of the cube.
 Finally, compare the result with the input.
******************************/
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
	
	int a1[6], a2[6], a3[12] = {}, a4[12] = {};
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
				if (!find) { a4[diff] = a3[i]; diff++; }
			}


			printf("%s\n", flag? "POSSIBLE": "IMPOSSIBLE");
			i = 0, k = 0;
			memset(a1, 0, sizeof(int) * 6);
			memset(a2, 0, sizeof(int) * 6);
			memset(a3, 0, sizeof(int) * 12);
		}
	}
	
	return 0;
}
