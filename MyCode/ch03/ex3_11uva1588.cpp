// ex3_11uva1588.cpp -- Kickdown
// the question can be put in another way : 
// find the shortest container to put in the two sections
// and the height should be less than 3h

// when a = ?, don't forget int
// consider two situations : move to the right and the left
 
#include <stdio.h>
#include <string.h>
#define maxn 205

int main()
{
//	freopen("test.in", "r", stdin);
//	freopen("test.out", "w", stdout);

	char s[maxn], t[maxn];
	memset(s, '0', sizeof(char) * maxn);
	memset(t, '0', sizeof(char) * maxn);
	while (scanf("%s%s", s, t) != EOF) {
		int lens = strlen(s);
		int lent = strlen(t);
		int minlen = 0, flag = 1;
	
		for (int i = 0;i < lens;) {
			flag = 1;
			for (int j = 0; j < lent; j++) {
				int sum = s[i+j] - '0' + t[j] - '0';
//				printf("<i=%d><j=%d> sum = %d\n", i, j, sum);
				if (s[i+j] - '0' + t[j] - '0' > 3) { 
					flag = 0; 
//					printf("<i=%d><j=%d> sum = %d flag = %d\n", i, j, sum, flag);
					i++; break; 
				}
			}
			if (flag) { minlen = i; break; }
		}
		if (!flag) minlen = lens;
		int result1 = (minlen + lent > lens) ? minlen + lent : lens;
		
	
		for (int i = 0;i < lent;) {
			flag = 1;
			for (int j = 0; j < lens; j++) {
				int sum = t[i+j] - '0' + s[j] - '0';
//				printf("<i=%d><j=%d> sum = %d flag = %d\n", i, j, sum, flag);
				if (t[i+j] - '0' + s[j] - '0' > 3) { 
					flag = 0; 
//					printf("<i=%d><j=%d> sum = %d flag = %d\n", i, j, sum, flag);
					i++; break; 
				}
			}
			if (flag) { minlen = i; break; }
		}
		if (!flag) minlen = lent;
		int result2 = (minlen + lens > lent) ? minlen + lens : lent;
		printf("%d\n", (result1 < result2) ? result1 : result2);	

		memset(s, '0', sizeof(s));
		memset(t, '0', sizeof(t));
	}
	return 0;
}
