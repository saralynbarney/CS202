#include "slotmachine.h"
#include <cstdlib>
/*************symbol***************/
symbol :: symbol()
{
	name = NULL;
	bonus =0;
	bonusexists = false;
}
symbol :: symbol (const symbol& old)
{
	int length = stringlength (old.getName());
	
	name = new char[length +1];
	stringcopy(name, old.getName());
	
	bonus = old.getBonus();
	bonusexists = old.getbonusexists();
}




symbol :: ~symbol()
{

	delete [] name;
	name = NULL;
	bonus=0;
}

char * symbol :: getName() const
{
	return name;
}

void symbol :: setName(char* diffName)
{

	int length = stringlength(diffName);
	if(name !=NULL)
	{
		delete [] name;
	}
	name = new char[length + 1];
	stringcopy(name, diffName);
}

int symbol :: getBonus() const
{
	return bonus;
}

void symbol :: setBonus(int newbonus)
{
	bonus=newbonus;
	if(bonus==0)
	{
		bonusexists=false;
	}
	else
	{
		bonusexists=true;
	}
}

void symbol :: printrand()
{

	cout << name << " " << bonus << " " ;
if(bonusexists)
{
	cout << "True" << '\t';
}
else
{
	cout << "False" << '\t';
}
}

void symbol :: printspin()
{
cout << name << " " << bonus << "     ";
}




bool symbol :: getbonusexists() const
{
	return bonusexists;
}

void symbol :: setbonusexists(bool values)
{
	bonusexists = values;
}

void symbol :: copyconst(symbol old)
{
	int length = stringlength(old.getName());
	if(name !=NULL)
	{
		delete[]name;
	}
	name = new char[length +1];
	stringcopy(name, old.getName());
	
	bonus = old.getBonus();
	bonusexists = old.getbonusexists();

}



/******************************************************reel********************************************/

reel::reel()
{
	stops = new symbol[10];
	payline=0;
}

reel::reel(const reel& oldreel)
{
	stops = new symbol[10];
	setStop(oldreel.stops);
	payline = oldreel.payline;
}


reel::~reel()
{
	delete [] stops;
	stops = NULL;
	payline = 0;
}



symbol * reel :: getStop() 
{
	return stops;
}




int reel::randomnumbergenerator()
{


int x=rand()% 6;                                                          // moved this over because of the error so had to put it in the class

return x;

}



void reel :: setStop (symbol * oldstops)
{

int x;
symbol * randPtr;
 		for (int j=0; j<10; j++)                                             // got help with this on monday from you
	{
		x=randomnumbergenerator();
		

	stops[j].setName(oldstops[x].getName())  ;
	stops[j].setBonus(oldstops[x].getBonus()) ;
	

		
	}
}

void reel :: printreels()
{
	for (int i=0; i<10; i++)
	{
		stops[i].printrand();
	}
	cout << endl;
}

symbol reel :: spin()
{

int x = rand() % 10;
	return stops[x];
}






