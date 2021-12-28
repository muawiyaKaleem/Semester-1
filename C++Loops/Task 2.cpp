#include<iostream>
using namespace std;

int Pelindrome(int num)
{
	int left,final=0;
	while(num!=0)
	{
		left = num%10;
		final = (final*10) + left;
		num/=10;
	}	
	return final;
}
int main()
{
	int n,final;
	cout<<"Enter the number to check => ";cin>>n;
	final = Pelindrome(n);
	if (final == n)
	{
		cout<<n<<" is a Pelindrome Number";
	}
	else
	{
		cout<<n<<" is not a Pelindrome Number";
	}
	return 0;
}
