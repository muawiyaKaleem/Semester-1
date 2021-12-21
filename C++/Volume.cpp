#include <iostream>
using namespace std;

void Volume(int a,int b,int c)
{
	cout<<"\n\nThe Volume of the Parrallelepiped => "<<a*b*c<<" m^3";
}

int main()
{
	float w,l,h;
	cout<<"\nEnter the Width(m) of the Parrallelepiped => ";
	cin>>w;
	cout<<"\nEnter the Length(m) of the Parrallelepiped => ";
	cin>>l;
	cout<<"\nEnter the Height(m) of the Parrallelepiped => ";
	cin>>h;		
	Volume(l,w,h);
}