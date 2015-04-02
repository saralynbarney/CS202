#include <iostream>
#include <fstream>
#include <exception>
#include <stdexcept>
#include <string>
using namespace std;

int main(int argc, char* argv[])

{


try{

if (argc !=2 )
{

throw runtime_error ("Invalid Number of Arguments");

}


	ifstream fin;
	fin.open(argv[1]);

if (!fin.good())
{

throw runtime_error ("Error Opening File" );
}
	string temp;
	while (fin.good())
	{
	fin >> temp;
	cout << temp << " ";
	
	}

	cout << endl;
}

catch (runtime_error error)
{
cout << error.what() << endl;
}




return 0;
}
