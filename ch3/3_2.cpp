// 程序3-2 开灯问题 
#include <iostream> 
using namespace std;

const int maxn = 1010;
bool a[maxn] = {};

int main()
{
	int n, k, first = 1;
	cin >> n >> k;
	for (int i = 1; i <= k; i++)
		for (int j = i; j <= n; j += i) 
			a[j] = !a[j];
	for (int j = 1; j <= n; j++) { 
		if (a[j]) 
			if (first) {cout << a[j]; first = 0;}
			else cout << " " << j;
	} 
	cout << endl;
	return 0;
}
