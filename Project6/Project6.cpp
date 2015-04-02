/*************************************************************************************************/
/* PROGRAM: Project6.cpp                                                                         */
/*                                                                                               */
/* AUTHOR: SARA LYN BARNEY                                                                       */
/*                                                                                               */  
/* DATE: March 12, 2015                                                                          */
/*                                                                                               */
/* REVISIONS: 1                                                                                  */
/*                                                                                               */
/*PURPOSE:  add the reel class and undertstanding dynamic memory                                 */
/*************************************************************************************************/


#include "slotmachine.h"
#include "stringlibrary.h" // connects to my string library
#include <iostream> // the stream
#include <cstdlib>
#include <fstream> // this is the f library 
#include <ctime> // this is for the random number generator


using namespace std;
void readFile(symbol * sptr);
int randomnumbergenerator();
void slotMachine(reel * rptr, symbol * symset);
void PickandPrint (reel * rptr);
void printUserOutput (reel * rptr);
void spinthemachine (reel * rptr);                          // only one that is new
void menuforuser(char &selection);



int main()
{
	symbol * srPtr = new symbol[6];
	reel * rPtr = new reel [3];
	srand(time(NULL));
	char selection;

//according to the lecture tuesday we dont need to set the pointers to home we can just delete them

do {
menuforuser(selection);
switch (selection)
        {
        case '1':
				cout << endl;
               			cout << "1. Read File" << endl;
					readFile(srPtr);		
                break;
	case '2':
				cout << endl;		
				cout << "2. Populate a New Slot Machine"<< endl;
					slotMachine(rPtr, srPtr);
		break;						
       	case '3':
				cout << endl;
				cout << "3.Print the Machine Configuration to screen" << endl;
				cout << endl;
					 printUserOutput (rPtr);
		 break;
	case '4':
				cout << endl;
				cout << "  4. Pick the spot on the machine" << endl;	
				cout << endl;		
					PickandPrint(rPtr);
		break;

	case '5' :
				cout << endl;
				cout << "5. Lets Play" << endl << endl;
					spinthemachine(rPtr);
		break;

	case '6':    
				cout << endl;
				cout << "         " << "THANK YOU COME PLAY AGAIN" << endl;
				cout << endl;
				cout << "             "<<"ENDING COMPUTER LIFE" << endl;
				cout << endl;	
		break;
        }
}while (selection != '6' );

delete [] rPtr;
rPtr = NULL;
delete [] srPtr;
srPtr = NULL;

return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
void readFile(symbol * sPtr)
{

	char * filename = new char[20];             // allocating memory for a file
	cin >> filename;
	ifstream fin;
	int tempb;
	fin.open(filename);
	char * temp = new char[20];                 // allocationg memory for the temporary symbols

	for (int i=0; i<6; i++)
	{
		fin >> temp;
		sPtr[i].setName(temp);
		fin >> tempb;
		sPtr[i].setBonus(tempb);
	}

fin.close();
delete [] temp;
delete [] filename;
temp = NULL;
filename = NULL;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
void slotMachine (reel * rPtr, symbol * srPtr)
//this populates the slot machine...we got the ability to use brackets back so we can use arrays

{

	int x;
	for (int i=0; i<3; i++)
	{
		for(int j=0; j<10; j++)
		{

	x = randomnumbergenerator();
	rPtr[i].getStop()[j].setName(srPtr[x].getName());
	rPtr[i].getStop()[j].setBonus(srPtr[x].getBonus());
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Prints the three reels out by calling the function printrand from the class symbols

void printUserOutput (reel * rPtr)
{

	cout << "Reel 1" << '\t' << '\t' << "Reel 2" << '\t' << '\t' << "Reel 3" << endl;
	cout << "======" << '\t' << '\t' << "======" << '\t' << '\t' << "======" << endl << endl; 
	for (int i=0; i<10; i++)
	{
		
		for (int j=0; j<3; j++)
		{
			rPtr[j].getStop()[i].printrand();             // uses the printrand function in slotmachine.cpp
		}
	cout << endl;
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PickandPrint(reel * rPtr)
{

	int reel;
	int row;

	cout << "PICK A REEL (1-3)" << endl;
	cin >> reel;
	cout << "PICK A STOP FOR ROW (1-10)" << endl;
	cin >> row;


	rPtr[reel-1].getStop()[row-1].printrand();                       // uses the printrand function in slotmachine.cpp
	cout << endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void spinthemachine(reel * rPtr)
{
	int sum =0;
	for (int i=0; i <3; i++)
	{
	
	symbol spin = rPtr[i].spin();
	spin.printspin();                                               // created a different print function due to not wanting bool
	spin.getBonus();
	sum+=spin.getBonus();
	}
	cout << endl;
	cout << endl;
	cout  << "YOUR BONUS VALUE" << endl;
	cout << endl;
	cout << "     " << sum << endl;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int randomnumbergenerator()
{
int x=rand()% 6;
return x;
}

//same as always


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void menuforuser(char &selection)
{
	cout << "                                             " << endl;
        cout << "      ++++====Computer Science 202====+++++  " << endl;
        cout << "      ==========Sara Lyn Barney============= " << endl;
	cout << "    1.  Read File" << endl;      
	cout << "    2.  Populate a new slot machine"<< endl;       
	cout << "    3.  Print the machine configuration to screen" << endl;
	cout << "    4.  Pick the spot on the machine" << endl;	
	cout << "    5.  Play the Machine " << endl;
	cout << "    6.  Quit Program" << endl;        
	cout << "                                     Enter your selection: ";
        cin >> selection;

        
} 
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


