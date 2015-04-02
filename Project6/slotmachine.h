#include "stringlibrary.h"
#include <iostream>
using namespace std;

class symbol 
{
	private:
	char * name;
	int bonus;
	bool bonusexists;

	public:
	char * getName() const;
	void setName(char *);
	int getBonus() const;
	void setBonus(int);
	void printrand();
	void printspin();
	bool getbonusexists() const;
	void setbonusexists(bool);
	void copyconst(symbol);
	symbol();
	symbol(const symbol& old);
	~symbol(); 
};

class reel{
	public:
	symbol * getStop();
	void setStop(symbol * );
	void printreels();
	symbol spin();
	int randomnumbergenerator();                              // added this 
	reel();
	reel (const reel&);
	~reel();

	private:
	symbol * stops;
	int payline;

};
