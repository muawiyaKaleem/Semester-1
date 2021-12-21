#include <iostream>
using namespace std;

void Converter(int second)
{
	int hours,minute
	hours = second/3600;
	second %= 3600;
	minute = second/60;
	second %= 60;
	cout<<hours<<" Hour "<<minute<<" Minute and "<<second<<" Seconds"<<endl<<endl<<"OR"<<endl<<endl;
	cout<<hours<<" : "<<minute<<" : "<<second;
	
}

int main()
{
	int sec;
	cout<<"Enter the number of seconds => ";
	cin>>sec;
	Converter(sec);
}