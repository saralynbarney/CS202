#include <iostream>
#include <exception>
#include <stdexcept>

using namespace std;

int main()

{

double a,b,c;
char d;
int controller =1;

cout << "Please Enter Two Integer Values: ";


while (controller == 1)
{
try{

cin >> a;
cin >> b;

if (cin.fail())
	
	throw "Please Only Enter Two Integer Values: " ;
	


	c = a * b;
	
	cout << a << "*" << b << " = " << c << endl;
	controller =0;

}

catch (const char * message)
{
cout << message << endl;
cin.clear(); // clears cin error state
cin.ignore(); // clears cin buffer
}
}
}
