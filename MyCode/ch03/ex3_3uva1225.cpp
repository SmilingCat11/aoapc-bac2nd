// ex3_3uva1225.cpp -- digit counting
// 忘记初始化T和N，即没写scanf函数
#include <stdio.h>

int main()
{
// 调试用
#ifdef ONLINE_JUDGE
#else
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	char str[10] = {};
	while (T--) {
		int N;
		scanf("%d", &N);
		int counts[10] = {};
		for (int i = 1; i <= N; i++) {
			sprintf(str, "%d", i);
			for (int j = 0; str[j]; j++)
				counts[str[j] - '0']++; 
		}
		for (int i = 0; i < 9; i++)
			printf("%d ", counts[i]);
		printf("%d\n", counts[9]);
	}
	return 0;
}