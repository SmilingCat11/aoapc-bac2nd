// example3-4
#include <stdio.h>
#include <string.h>

int main()
{
	char s[11] = {};
	char s_num[20] = {};
	scanf("%s", s);

	int count = 0;
	int abc, de;
	int x, y, z;
	for (abc = 100; abc < 1000; abc++) {
		for (de = 10; de < 100; de++) {
			x = abc * (de % 10);
			y = abc * (de / 10);
			z = abc * de;
			sprintf(s_num, "%d%d%d%d%d", abc, de, x, y, z);

			int i = 0, j = 0;
			int flag = 1;
			for (i = 0; i < strlen(s_num); i++) {
				for (j = 0; j < strlen(s); j++) {
					if (s_num[i] == s[j]) break;
				}
				if (j == strlen(s) && s_num[i] != s[j-1]) {flag = 0; break;}
			}
			if (i == strlen(s_num)) {
					printf("<%d>\n", ++count);

					printf("%5d\nX%4d\n-----\n", abc, de);
					printf("%5d\n%5d\n-----\n%d\n", x, y, z);

			}
		}
	}
	printf("The number of solutions = %d\n", count);

	return 0;
}

