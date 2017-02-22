#include <stdio.h>
#include <string.h>
#define maxn 30
const char rev[] = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
const char *msg[] = { "is not a palindrome", "is a regular palindrome", "is a mirrored string", "is a mirrored palindrome" };
char r(char c) 
{
	if(c >= 'A' && c <= 'Z') 
		return rev[c - 'A'];
	else 
		return rev[c - '1' + 26];
}

int main()
{
//	freopen("test.in", "r", stdin);
//	freopen("test.out", "w", stdout);
	char s[maxn] = {};
	while (scanf("%s", s) != EOF) {
		int len = strlen(s);
		int p = 1, m = 1;
		for (int i = 0; i < (len+1)/2; i++) {
			if (s[i] != s[len-1-i]) p = 0;
			if (r(s[i]) != s[len-1-i]) m = 0;
		}
		printf("%s -- %s.\n\n", s, msg[m*2+p]);
	}
	return 0;
}
