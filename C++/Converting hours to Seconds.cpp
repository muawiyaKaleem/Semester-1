#include <iostream>
using namespace std;

int Converter(int days,int hours,int minute)
{
	int seconds;
	seconds =  (days*86400)+(hours*3600)+(minute*60);
	return seconds;
}
int main()
{
	int d,h,m;
	cout<<"Enter the number of days => ";cin>>d;
	cout<<"Enter the number of hours => ";cin>>h;
	cout<<"Enter the number of minutes => ";cin>>m;
	int s = Converter(d,h,m);
	cout<<"Total seconds in "<<d<<" Days "<<h<<" Hours "<<m<<" Minutes => "<<s;
	return 0;
	
}