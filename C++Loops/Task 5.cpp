#include<iostream>
using namespace std;

int again();
int GPA_Calculator(string sub,int cr)
{
    if (sub=="A")
    {
        return 4.0*cr;
	}
    else if (sub=="A-")
    {
        return 3.67*cr;
	}
    else if (sub=="B+")
    {
        return 3.33*cr;
	}
    else if (sub=="B")
    {
        return 3*cr;
	}
    else if (sub=="B-")
    {
        return 2.67*cr;
	}
    else if (sub=="C+")
    {
        return 2.33*cr;
	}
    else if (sub=="C")
    {
        return 2.0*cr;
	}
    else if (sub=="C-")
    {
        return 1.67*cr;
	}
    else if (sub=="D+")
    {
        return 1.33*cr;
	}
    else if (sub=="D")
    {
        return 1.0*cr;
	}
    else
    {
        return 0*cr;
	}
}

int input()
{
	int subjects,c,ch;
	string s;
    float result = 0;
    
    cout<<"Enter the number of subjects do you want to calculate GPA of => ";cin>>subjects;
    
	for (int i=1;i<=subjects;i++)
	{
        cout<<"Enter the grade of subject "<<i<<" => ";cin>>s;
        cout<<"Enter the cradit hours of subject "<<i<<" => ";cin>>c;
        ch += c;
        result += GPA_Calculator(s,c);
	}
	
	cout<<"----------------\nYour GPA is "<<result/ch<<"\n----------------";
	again();
}
int again()
{
	string select;
    cout<<"\nPress y/Y If you want to use the GPA Calculator again\nOR\npress any key  If you do not want to use the Calculator again => ";cin>>select;
    
	if (select == "y" || select == "Y")
        {	
			input();
		}
    else
    {
        cout<<"\nThank You for using our GPA Calculator  BYE!";
	}
    return 0;
}
int main()
{
	input();
	return 0;
}
