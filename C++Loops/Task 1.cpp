#include <iostream>
#include <cmath>
using namespace std;

int Armstrong(int num)
{
	int left,number;
	
	int count = 0; 
	int temp = num;
	while (temp!=0)
	{
		temp /= 10;
		count++;
	}
	while (num!=0)
	{
		left = num % 10;
		number += pow(left,count);
		num /= 10;
	}
	return number;
}
int main()
{
	
	int n,number;
	cout<<"Enter the number to check => ";cin>>n;
	number=Armstrong(n);
	if (number == n)
	{
		cout<<n<<" is the Armstrong number";
	}
	else
	{
		cout<<n<<" is not the Armstrong number";
	}
	return 0;	

}