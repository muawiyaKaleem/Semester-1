#include<iostream>
using namespace std;

int main()
{
	int coffee=0,tea=0,coke=0,juice=0,i=1,n,end;
	cout<<"1. Coffee\n2. Tea\n3. Coke\n4. Orange";
	cout<<"\nChoose 1, 2, 3 or 4 from the above menu\nChoose -1 to exit the program :\n";
	while (n!=-1)
	{
		cout<<"\nPlease input the following beverage of person "<<i<<" => ";cin>>n;
    	if (n == 1)
    	{
        	coffee++;
		}
    	else if (n == 2)
    	{
        	tea++;
		}
    	else if (n == 3)
    	{
    		coke++;
		}
        	
    	else if (n == 4)
    	{
        	juice++;
		}
    	i++;	
	}
cout<<"\nBevarage\t\tNumber of votes\n---------------------------------------"<<endl;
cout<<"Coffee\t\t\t\t"<<coffee<<"\nTea\t\t\t\t"<<tea<<"\nCoke\t\t\t\t"<<coke<<"\nJuice\t\t\t\t"<<juice;
	return 0;
}


