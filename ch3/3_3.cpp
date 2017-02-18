// ³ÌĞò3-3 ÉßĞÎÌîÊı 
#include <iostream>
using namespace std;

const int maxn = 20;
int a[maxn][maxn] = {};

int main()
{
	int n, x, y, sum;
	cin >> n;
	sum = a[x=0][y=n-1] = 1;

	
	while (sum < n*n) {
		while (x+1 < n && !a[x+1][y]) a[++x][y] = ++sum; 
		while (y-1 >= 0 && !a[x][y-1]) a[x][--y] = ++sum;
		while (x-1 >= 0 && !a[x-1][y]) a[--x][y] = ++sum;
		while (y+1 < n && !a[x][y+1]) a[x][++y] = ++sum;
	}
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++)
			cout << a[i][j] << " ";
		cout <<endl;
	}
	
	return 0;
}
