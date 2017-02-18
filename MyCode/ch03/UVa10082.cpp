// 例题3-2 WERTYU, UVa10082
#include <stdio.h>
char s[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
int main()
{

	int i, c;	
	while ((c=getchar()) != EOF) {
		for (i = 1; s[i] && s[i] != c; i++); // 在s中查找c，这个空循环有意思，控制循环的语句也从未见过
		if (s[i]) putchar(s[i-1]); // 找到则输出前一值
		else putchar(c); // 未找到则输出原值
	}
	return 0;
}