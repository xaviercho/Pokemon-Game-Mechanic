/*
 * Author: Xavier Cho
 * Course: CSCE_A211_2015_01
 * Description: Logan-5 is being hunted by Francis-7.
  a simulator to determine the outcome of the hunt--which will be different each time.

 1. First, write a function called encounter() that uses a random number generate to create a number between 0 and 1.0.
 Then use that number to determine whether the bots run into each other.
 The bots run into each other with P(encounter) = 0.25.  If the bots run into each other,
 encounter should return true; otherwise it should return false.

2. Now write a function called initiative().
Initialive should return true in the case that Francis-7 gets to act first, and it will return false if Logan-5 goes first.
Each bot has a 50/50 chance of going first when an encounter begins.
 After the first turn, the bots alternate moves until the encounter is over.

3. Now, write a function called botChoice() that returns an int representing the bot's choice of action.
  Each bot uses the same algorithm to make choices during combat.
  They simply generate a renomd number between 0.0 and 1.0.
  The bots take turns making choices.
  Every time botChoice is called it return one of these actions with the following probabilities:
 */

#include <iostream>				// cout, cin, endl
#include <string>				// string
#include <cstdlib>
#include <time.h>
using namespace std;

enum botaction
{
	ATTACK,
	RUN,
	CHARGE,
	CRY
};

enum outcome
{
	DIES,
	ESCAPE,
	WIN,
	LOSE
};

inline const char* ToString(botaction v){
	switch(v){
		case ATTACK: return "ATTACK";
		case RUN: return "RUN";
		case CHARGE: return "CHARGE";
		case CRY: return "CRY";
		default:  return "0";
	}
}

 bool encounter ()
{
	int probability = rand() % 100;

	if(probability <=25)
	{
		cout << "ENCOUNTER! \n" << endl;
		return true;
	}
	else
	{
		cout << "Francis is hunting Logan \n" << endl;
		return false;
	}
}

 bool initiative() // bool for true and false for return type
{
	int probability = rand() % 100;
	if (probability <=50)
	{
		cout << " Francis has the initiative on Logan! \n" << endl;
		return true;
	}
	else
	{
		cout << "Logan has the initiative on Francis! \n" << endl;
		return false;
	}
}

botaction botChooses (string name)// <<<----- pass in  name
{
	int probability = rand() % 100;
	//int attack = 35;
	//int run = 40;
	//int charge = 15;
	//int cry = 10;
	if (probability < 35)
	{
		cout << name <<" attacks ! \n" << endl;
		return ATTACK;
	}
	else if (probability <75)
	{
		cout << name << " Runs \n" << endl;
		return RUN;
	}
	else if (probability <90)
	{
		cout << name << " Charges \n" << endl;
		return CHARGE;
	}
	else (probability <99);
	{
 		cout << name << " cries \n" << endl;
		return CRY;
	}
}

void result(string name, botaction final_action)
{
	if (ToString(final_action) == "ATTACK")
	{
		cout << name <<" kills the opponent\n"<<endl;
	}
	else if (ToString(final_action) == "RUN")
	{
		cout << name <<" Escapes! \n"<<endl;
	}
	else if (ToString(final_action) == "CHARGE")
	{
		cout << name <<" kills the opponent \n"<<endl;
	}
	else if (ToString(final_action) == "CRY")
	{
		cout << name<< "s" <<" opponent kills  \n"<< name <<endl;
	}
	else{
		cout << "ERROR!" <<endl;
	}
}

int main()
{
	srand(time(NULL));
	bool flag = false;
	botaction final_action = RUN;
	string name = "";
	while ((ToString(final_action) != "CRY") && (ToString(final_action) != "CHARGE") && (ToString(final_action) != "ATTACK"))
	{
		while(flag == false){
			flag = encounter();
		}

		flag = initiative();
		if(flag == true){
			name = "Francis";
		}else{name = "Logan";}

		final_action = botChooses(name);

		flag = false;
	}

	result(name, final_action);

	return 0;
}