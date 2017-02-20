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
			long num = (((abc * 100 + de)*10000+x)*10000+y)*100000+z;
			sprintf(s_num, "%d", num);

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
printf("num = %ld, s_num = %s, s = %s\n", num, s_num, s);
					printf("%5d\nX%4d\n-----\n", abc, de);
					printf("%5d\n%5d\n-----\n%d\n", x, y, z);

			}
		}
	}
	printf("The number of solutions = %d\n");

	return 0;
}

