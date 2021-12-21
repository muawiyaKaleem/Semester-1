#include <iostream>
using namespace std;

int Checker(int x)
{
	if (x==0)
	cout<<"Number is equal to 0";
	else if (x>0)
	cout<<"Number is Greater than 0";
	else
	cout<<"Number is Less than 0";
	return 0;
}

int main()
{
	int n;
	cout<<"Enter The Number => ";cin>>n;
	Checker(n);
	return 0;
}