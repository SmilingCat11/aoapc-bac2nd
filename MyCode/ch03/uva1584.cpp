// uva1584.cpp -- Circular Sequence
// [Error] expected ';' before '}' token
#include <stdio.h>
#include <string.h>
#define maxn 105

int cmp(const char* s, int p, int q)
{
	int len = strlen(s);
// It's not proper to use while, because if p[i] == p[j], then it won't end. 
//	while (p[i%len] == p[j%len]) { i++; j++; } 
	for (int i = 0; i < len; i++) {
		if (s[(p+i)%len] != s[(q+i)%len]) 
			return s[(p+i)%len] < s[(q+i)%len];
	}
	return 0;
}

int main()
{
//	freopen("test.in", "r", stdin);
//	freopen("test.out", "w", stdout);
	
	char s[maxn];
	int T;
	scanf("%d", &T);
	while (T--) {	
		scanf("%s", s);
		int n = strlen(s);
		int ans = 0;
		for (int i = 1; i < n; i++) {
			if (cmp(s, i, ans)) ans = i;
			}

// It doesn't need to seperate the printf
//		for (int i = ans; i < strlen(s); i++)
//			printf("%c", s[i]);	
//		for (int i = 0; i < ans; i++)
//			printf("%c", s[i]);	

		for (int i = 0; i < n; i++)
			putchar(s[(i+ans)%n]);
		putchar('\n');
	}
	return 0;
}
