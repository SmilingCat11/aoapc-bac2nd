//ex3_7uva1368.cpp
//

#include <stdio.h> 
#include <string.h>
#define maxn 1005
int seqs[maxn][4];
char s[maxn];
const char dna[] = "ACGT"; // the sequence is important!
char consensus[maxn] = {};

int main()
{

//	freopen("test.in", "r", stdin);
//	freopen("test.out", "w", stdout);

	int T;
	scanf("%d", &T);
	
	while (T--) {
		memset(seqs, 0, sizeof(seqs));
		int m, n;
		scanf("%d%d", &m, &n);
		for(int k = 0; k < m; k++) {
			scanf("%s", s);
			for (int i = 0; i < n; i++) {
				switch (s[i]) {
					case 'A': seqs[i][0]++; break;
					case 'C': seqs[i][1]++; break;
					case 'G': seqs[i][2]++; break;
					case 'T': seqs[i][3]++; break;
					default: break;
				}
			}
		}
		int ham_dist = m*n, jmax;
		for (int i = 0; i < n; i++) {
			int maxnum = 0;
			for (int j = 0; j < 4; j++) 
				if (seqs[i][j] > maxnum) {maxnum = seqs[i][j]; jmax = j;}
			ham_dist -= seqs[i][jmax];
			consensus[i] = dna[jmax];
		}

		for (int i = 0; i < n; i++) {
			putchar(consensus[i]);
		}
		printf("\n%d\n", ham_dist);

	}
	return 0;
}
