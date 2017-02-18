// ex3_5uva227 -- Puzzle
#include <stdio.h>

void swap(char& x, char& y) {
	char t;
	x = t;
	x = y;
	y = t;
}

int main()
{
	char s[5][6] = {};
	int c;
	while ((c = getchar()) != 'Z') {
		int fi = 0, fj = 0;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				s[i][j] = getchar();
printf("%d ", s[i][j]);
				if (s[i][j] == ' ') {fi = i; fj = j;}
			}
getchar();
printf("\n");
		}
		int oper, flag = 1;
		while (flag && (oper = getchar()) != '0') {
			switch (oper) {
				case 'A':
					if (fi>0) swap(s[fi][fj], s[--fi][fj]);
					else flag = 0;
					break;
				case 'B':
					if (fi<5) swap(s[fi][fj], s[++fi][fj]);
					else flag = 0;
					break;
				case 'L':
					if (fj>0) swap(s[fi][fj], s[fi][--fj]);
					else flag = 0;
					break;
				case 'R':
					if (fj<5) swap(s[fi][fj], s[fi][++fj]);
					else flag = 0;
					break;
				default:
					break;
			}
		}
		getchar();
		int count = 0;
		printf("Puzzle #%d:\n", ++count);
		for (int i = 0; i < 5; i++) {
			int first = 1;
			for (int j = 0; j < 6; j++) {
				if (first) first = 0;
				else printf(" ");
				printf("%c", s[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}




