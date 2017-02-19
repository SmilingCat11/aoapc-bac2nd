// ex3_5uva227 -- Puzzle
// 使用while(```getchar())时里尽量不再用getchar()，易出匪夷所思的bug
// 也不要再用循环，因为控制字符读取的只在最外面的while里
// 尽可能只一次读取字符
// 数组间如何交换，swap(s[i][j], s[i++][j])是否合理
// 二维数组如何全置零
// A denotes that the square above the empty position moves. So you have mixed up which one should move.
// that means A denotes that the empty moves below. 

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void swap(char * x, char * y) {
	char t;
	t = *x;
	*x = *y;
	*y = t;
}

int main()
{
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	char s[5][5] = {};
	int c;
	int fi = 0, fj = 0;
	int i = 0, j = 0;
	int count = 0; // the ith test
	int flag = 1; // decide whether there is a wrong move
	
	while ((c = getchar()) != 'Z') {
		if (i <= 4) {
			if ( isalpha(c) || c == ' ' ) {
				if (c == ' ') {fi = i; fj = j;}
				s[i][j++] = c;
			}
			if (j > 4) {j = 0; i++;}
		} 

		if (i > 4 && c != '0') {
			if (flag) { switch (c) {
				case 'A':
					if (fi>0) { swap(&s[fi][fj], &s[fi-1][fj]); fi--; }
					else flag = 0;
					break;
				case 'B':
					if (fi<4) { swap(&s[fi][fj], &s[fi+1][fj]); fi++; }
					else flag = 0;
					break;
				case 'L':
					if (fj>0) { swap(&s[fi][fj], &s[fi][fj-1]); fj--; }
					else flag = 0;
					break;
				case 'R':
					if (fj<4) { swap(&s[fi][fj], &s[fi][fj+1]); fj++; }
					else flag = 0;
					break;
				default:
					break;
			}
			}
		}

		if (i > 4 && c == '0') {
			if (count) printf("\n");
			printf("Puzzle #%d:\n", ++count);
			if (flag) { 
				for (int i = 0; i < 5; i++) {
					int first = 1;
					for (int j = 0; j < 5; j++) {
						if (first) first = 0;
						else printf(" ");
						printf("%c", s[i][j]);
						s[i][j] = 0; 
					}
				printf("\n");
				}
//			printf("\n");
			}
			else printf("This puzzle has no final configuration.\n");
			i = 0; j = 0;  // initialation
			fi = 0; fj = 0;
			flag = 1; // initialation
		}
	}
	return 0;
}




