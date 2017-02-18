// ex3-1 UVa 1585 Score 
// 读入数据遇到了许多问题，scanf与getchar的用法
#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	while(getchar() != '\n'); // 清空scanf后的回车
	for (int i = 1; i <= n; i++) {
		int c, q = 0, scores = 0;
		while ((c = getchar()) != '\n')
			if (c == 'O') {q++; scores += q; printf("c = %d, q = %d\n", c, q);}
			else { q = 0; printf("c = %d, q = %d\n", c, q); }
		printf("%d\n", scores);
		printf("(%d) q = %d\n", i, q);
	}
	return 0;
}

// getchar()可读取空格、Enter键
// 先用scanf后Enter键留在缓冲区，再使用getchar()读取的是Enter的ASCII值10
// 因Enter键不为O，所以每行后q重置为0
// 变量声明范围一定要尽可能小，在使用前声明
// 此例中c, q, scores都应该在for中声明