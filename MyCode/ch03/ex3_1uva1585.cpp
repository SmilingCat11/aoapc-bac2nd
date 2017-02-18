// ex3-1 UVa 1585 Score 
#include <stdio.h>
#include <string.h>
char s[85];
int main()
{
	int n;
	scanf("%d", &n);

	while (n--) {
		int q = 0, scores = 0;
		scanf("%s", s);
		for (int i = 0; s[i]; i++) {
			if (s[i] == 'O') {q++; scores += q;}
			else q = 0;
		}
		printf("%d\n", scores);
	}
	return 0;
}