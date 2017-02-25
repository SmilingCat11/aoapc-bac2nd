// ex3_6uva232.cpp -- Crossword Answers
// if the exe stop working, there must be something wrong with the loop

#include <stdio.h>
#include <string.h>
#define maxn 20

int main()
{

//	freopen("test.in", "r", stdin);
//	freopen("test.out", "w", stdout);
	int r, c;
	char words[maxn][maxn];
	int num[maxn][maxn];
	int puzzle = 1;
	while (scanf("%d%d", &r, &c) == 2) {
		memset(words, 0, sizeof(words));
		memset(num, 0, sizeof(num));

		for (int i = 0; i < r; i++) 
			scanf("%s", words[i]);
		int count = 1;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (i == 0 && words[0][j] != '*') num[i][j] = count++;
				if (i != 0 && j == 0 && words[i][j] != '*') num[i][j] = count++;
				if (i != 0 && j != 0) {
					if ( words[i][j] != '*' && (words[i-1][j] == '*' || words[i][j-1] == '*') )
						num[i][j] = count++;
				}
//				printf("%3d", num[i][j]);
//				printf("%c", words[i][j]);
//				if (j == c-1) printf("\n");
			}
		}
		
		if (puzzle != 1) printf("\n");
		printf("puzzle #%d:\n", puzzle++);
		printf("Across\n");
		
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (num[i][j] != 0) {
					printf("%3d.", num[i][j]);
					while(j < c && words[i][j] != '*') {
						printf("%c", words[i][j++]);
					} 
					printf("\n");
				}
			}
		}

		printf("Down\n");
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < r; j++) {
				int i2 = i;
				if( num[i][j] != 0 && (i == 0 || words[i-1][j] == '*') ) {
					printf("%3d.", num[i][j]);
					while(i2 < r && words[i2][j] != '*') {
						printf("%c", words[i2++][j]);
					} 
					printf("\n");
				}
			}
		}
			
	}
	return 0;
}
