#include <iostream> 
using namespace std;

void swap(int& a, int& b)
{
	a = a + b;
	b = a - b;
	a = a - b;
	cout << a << " " 
		<< b << " " << endl;
}

int main()
{
	int a, b;
	cin >> a >> b;
//	cout << sizeof(int) ;
	swap(a, b);
	swap(a, a);
	cout << a << " " 
		<< b << " " << endl;
	
	return 0;
}
