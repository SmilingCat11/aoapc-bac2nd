//³ÌĞò3-1 ÄæĞòÊä³ö 
#include <iostream>
using namespace std;

const int maxn = 105;
int arr[maxn] = {};

int main()
{
	int num, i = 0;
	while (cin >> num)
		arr[i++] = num;
	for (i -= 1; i > 0; i--)
		cout << arr[i] << " ";
	cout << arr[0] << endl;
	
	return 0;
}
