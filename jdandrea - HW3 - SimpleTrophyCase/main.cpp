#include <iostream>
#include <string>
#include <vector>
#include "Trophy.h"
#include <vld.h>
using namespace std;

// Reusable strings
const string PROMPT_FOR_NAME = "Please enter the name of the Trophy";
const string PROMPT_FOR_NEW_NAME = "Please enter the new name of the Trophy";
const string PROMPT_FOR_LEVEL = "Please enter the level of your Trophy (between 1 and 10)";
const string PROMPT_FOR_COLOR = "Please enter the color of your Trophy (GOLD, SILVER, or BRONZE)";

// Menu choice handlers
void addTrophy(vector<Trophy*>& trophy);
void copyTrophy(vector<Trophy*>& trophy);
void deleteTrophy(vector<Trophy*>& trophy);
void renameTrophy(vector<Trophy*>& trophy);
void relevelTrophy(vector<Trophy*>& trophy);
void recolorTrophy(vector<Trophy*>& trophy);
void printTrophies(vector<Trophy*>& trophy);

// Input handlers
int printMenu();
Trophy* promptForTrophy();
string promptForString(const string& message);
int promptForInt(const string& message, int minimum, int maximum);
Color promptForColor(const string& message);

// Useful helper methods
string stringToUpper(string& value);
int searchForTrophy(vector<Trophy*>& trophy, string& name);

// This application allows for the management of a trophy collection
int main()
{
	cout << "***********************************************" << endl
		<< "Welcome to the Trophy editor!" << endl
		<< "With this application, you can manage your trophy" << endl
		<< "collection - add, modify, or remove trophies by" << endl
		<< "using this simple menu!" << endl
		<< "***********************************************" << endl;

	vector<Trophy*> trophies;								// A vector of trophy objects

	// Loop the menu, allowing the user to select an action each time
	int input;
	do
	{
		input = printMenu();
		switch (input)
		{
		case 1:		// Add a new Trophy
			addTrophy(trophies);
			break;
		case 2:		// Copy an existing Trophy
			copyTrophy(trophies);
			break;
		case 3:		// Delete an existing Trophy
			deleteTrophy(trophies);
			break;
		case 4:		// Rename a Trophy
			renameTrophy(trophies);
			break;
		case 5:		// Change the level of a Trophy
			relevelTrophy(trophies);
			break;
		case 6:		// Change the color of a Trophy
			recolorTrophy(trophies);
			break;
		case 7:		// Print all Trophies
			printTrophies(trophies);
			break;
		case 8:		// Exit
			cout << "You have chosen to exit the application, good-bye!" << endl;
			break;
		default:
			cout << "That is not a recognized menu selection, choose again." << endl;
			break;
		}

	} while (input != 8);

	// Deletes all trophies when application closes
	for (int i = trophies.size() - 1; i >= 0; i--)
	{
		delete trophies[i];
	}
	return 0;
}

// Print the menu to the user and accept their menu choice
// takes in as string
// returns as int (menu choice)
int printMenu()
{
	int input;											// input value for menu choice
	string inputString;									// initialized for menu select safety

	cout << "-----------------------------------------" << endl
		<< "Please select an option :" << endl
		<< "1 - Add a new Trophy" << endl
		<< "2 - Copy a Trophy" << endl
		<< "3 - Delete a Trophy" << endl
		<< "4 - Rename a Trophy" << endl
		<< "5 - Change the level of a Trophy" << endl
		<< "6 - Change the color of a Trophy" << endl
		<< "7 - Print All the Trophies" << endl
		<< "8 - Exit the program" << endl
		<< "-----------------------------------------" << endl;
	// ensures that all invalid menu options
	// do not crash program
	try
	{
		// gets the input as a string
		getline(cin, inputString);
		// converts it to an int
		input = stoi(inputString);
	}
	catch (exception& e)
	{
		// will return an invalid option
		return -1;
	}
	// returns the choice
	return input;
}

// Add a new Trophy to the collection
// by calling the promptForTrophy function
void addTrophy(vector<Trophy*>& trophy)
{
	// prompt for trophy creation
	cout << "You have chosen to add a trophy." << endl;
	Trophy* newTrophy = promptForTrophy();						// creates a new trophy

	// adds the new trophy to the vector
	trophy.push_back(newTrophy);
}

// Delete an existing Trophy from the collection
// by comparing the m_name of the iterators position
// to a given vector locations m_name
void deleteTrophy(vector<Trophy*>& trophies)
{
	// Prompt for delting trophy
	cout << "You have chosen to delete an existing trophy." << endl;
	string name = promptForString(PROMPT_FOR_NAME);						// trophy to delete

	int deletedTrophy = searchForTrophy(trophies, name);				// position of trophy

	// breaks from function if no trophy found
	if (deletedTrophy == -1)
	{
		return;
	}
	// if found, iterate through vector
	// erase the matching trophy
	else
	{
		vector<Trophy*>::iterator it = trophies.begin();					// iterator for searching

		// so long as the iterator isn't at the end of the vecotr
		// and its current name is not the same as the searched name
		// continue searching
		while (it != trophies.end() && (*it)->getName() != trophies[deletedTrophy]->getName())
		{
			++it;
		}
		// if the iterator broke from loop
		// not due to reaching the end of the vector
		if (it != trophies.end())
		{
			delete(*it);
			// delete its position
			trophies.erase(it);
		}
	}
}

// Copy an existing Trophy in the collection
// by searching the vector for a given m_name
// and pushing the same values back into the vector
void copyTrophy(vector<Trophy*>& trophy)
{
	Trophy* trophyToCopy = NULL;
	cout << "You have chosen to copy an existing trophy." << endl;
	string name = promptForString(PROMPT_FOR_NAME);							// the name of the copies trophy
	int copiedTrophy = searchForTrophy(trophy, name);						// searches vector for a trophy name

	// if no trophy matches the searched name
	// return out of function
	if (copiedTrophy == -1)
	{
		return;
	}
	// if it exists, duplicate it into the vector
	else
	{
		trophyToCopy = new Trophy(*trophy[copiedTrophy]);
		trophy.push_back(trophyToCopy);
	}
}

// Rename an existing Trophy (change the name)
// by searching the vector for a given m_name
void renameTrophy(vector<Trophy*>& trophies)
{
	// Prompt for trophy renaming
	cout << "You have chosen to rename an existing trophy." << endl;
	string name = promptForString(PROMPT_FOR_NAME);					// name to search for in vector
	int renameTrophy = searchForTrophy(trophies, name);				// location of searched trophy
	string newName = promptForString(PROMPT_FOR_NEW_NAME);			// new name to create

	// breaks from function if trophy not found
	if (renameTrophy == -1)
	{
		return;
	}
	// if found, iterates through and changes the name
	else
	{
		vector<Trophy*>::iterator it = trophies.begin();				// iterator for vector searching (pointer)

		// loops through Trophies until there is a matched name
		while (it != trophies.end() && (*it)->getName() != trophies[renameTrophy]->getName())
		{
			++it;
		}
		// if the loop ends due to match
		if (it != trophies.end())
		{
			// sets the new name
			(*it)->setName(newName);
		}
	}
}

// Relevel an existing Trophy (change the m_level)
// by searching for a given m_name
void relevelTrophy(vector<Trophy*>& trophies)
{
	// Prompt for releveling of trophies
	cout << "You have chosen to change the level of an existing trophy." << endl;
	string name = promptForString(PROMPT_FOR_NAME);					// name to search for
	int relevelTrophy = searchForTrophy(trophies, name);			// position of desired trophy
	int newLevel = promptForInt(PROMPT_FOR_LEVEL, 1, 10);			// new level

		// breaks from function if trophy not found
	if (relevelTrophy == -1)
	{
		return;
	}
	// if found, iterates through and changes the level
	else
	{
		vector<Trophy*>::iterator it = trophies.begin();				// iterator for vector searching (pointer)

		// loops through Trophies until there is a matched name
		while (it != trophies.end() && (*it)->getName() != trophies[relevelTrophy]->getName())
		{
			++it;
		}
		// if the loop ends due to match
		if (it != trophies.end())
		{
			// sets new level
			(*it)->setLevel(newLevel);
		}
	}
}

// Recolor an existing Trophy (change the m_color)
// of a given m_name
void recolorTrophy(vector<Trophy*>& trophies)
{
	cout << "You have chosen to change the color of an existing trophy." << endl;
	string name = promptForString(PROMPT_FOR_NAME);					// name if the searched trophy
	int recolorTrophy = searchForTrophy(trophies, name);			// position of desired trophy
	Color newColor = promptForColor(PROMPT_FOR_COLOR);				// new color

	// breaks from function if trophy not found
	if (recolorTrophy == -1)
	{
		return;
	}
	// if found, iterates through and changes the color
	else
	{
		vector<Trophy*>::iterator it = trophies.begin();				// iterator for vector searching (pointer)

		// loops through Trophies until there is a matched name
		while (it != trophies.end() && (*it)->getName() != trophies[recolorTrophy]->getName())
		{
			++it;
		}
		// if the loop ends due to match
		if (it != trophies.end())
		{
			// sets new color
			(*it)->setColor(newColor);
		}
	}
}

// Print all of the Trophies in the collection
// by using a for loop to iterate through the vector
void printTrophies(vector<Trophy*>& trophies)
{
	// prompt for printing
	cout << "You have chosen to print all of the trophies." << endl;

	// Prints all the trophies in the order they are stored in the vector
	for (int i = 0; i < trophies.size(); i++)
	{
		trophies[i]->printTrophies();
	}
}

// Ask the user for a Trophy, validate their responses
// Return the Trophy
Trophy* promptForTrophy()
{
	// Trophy information
	string name = promptForString(PROMPT_FOR_NAME);					// name of trophy
	int level = promptForInt(PROMPT_FOR_LEVEL, 1, 10);				// level of trophy
	Color color = promptForColor(PROMPT_FOR_COLOR);					// color of trophy

	// Creates a new trophy with the above info
	Trophy* newTrophy = new Trophy(name, level, color);

	// Return a Trophy
	return newTrophy;
}

// Ask the user for a string, validate their response
// Return the string
string promptForString(const string& message)
{
	string value;							// initialize the trophy name

	// prompt/read in of trophy name
	cout << message << endl;
	getline(cin, value);

	// validity check / error message
	while (value == "")
	{
		cout << "That is not a valid name.  Try again.";
		getline(cin, value);

	}
	// returns the trophy name
	return value;
}

// Ask the user for an int, validate their response by
// checking that it is between minimum and maximum values
// Return the int
int promptForInt(const string& message, int minimum, int maximum)
{
	int value = 0;							// initialize trophy level
	string valueString;

	// prompt/ read in of trophy level
	cout << message << endl;
	// ensures proper level entry
	try
	{
		// gets input as a string
		getline(cin, valueString);
		// converts in to int
		value = stoi(valueString);
	}
	catch (exception& e)
	{
		// makes inproper input a negatve value
		value = -1;
	}

	// proper input check / error message
	while (value < minimum || value > maximum)
	{
		cout << "That value is outside the acceptable range.  Try again." << endl;
		// ensures all retries are checked by same conditions
		try
		{
			getline(cin, valueString);
			value = stoi(valueString);
		}
		catch (exception& e)
		{
			value = -1;
		}
	}

	// returns the trophies level
	return value;
}

// Convert a string to all uppercase (so that we can compare the
// user's entered color to the official color)
string stringToUpper(string& value)
{
	// TODO: Convert the string parameter into all uppercase
	for (int i = 0; i < value.length(); i++)
	{
		// Checks the current letter for lower case
		if (value[i] >= 'a' && value[i] <= 'z')
		{
			// Converts the letter to its Upper case form
			value[i] = value[i] - 32;
		}
	}
	// returns the string in full upper case
	return value;
}

// Ask the user for a color, validate the response
// Return the color
Color promptForColor(const string& message)
{
	Color color;					// initialize Color variable
	string value;					// initilaize input value

	// Prompt for user color value
	cout << message << endl;
	// while the color is not acceptable
	while (value != "GOLD" || value != "SILVER" || value != "BRONZE")
	{
		// read in the color value
		getline(cin, value);

		// converts string to Upper Case
		value = stringToUpper(value);

		// Checks whether the upper case value is right
		if (value == "GOLD")
		{
			color = GOLD;
			break;
		}
		else if (value == "SILVER")
		{
			color = SILVER;
			break;
		}
		else if (value == "BRONZE")
		{
			color = BRONZE;
			break;
		}
		// prints an error
		else
		{
			cout << "That is not an acceptable color.  Try again." << endl;
		}
	}

	return color;
}

// Search for a trophy in the collection by name
// compares the user inputted name, to current name
// in the search 
int searchForTrophy(vector<Trophy*>& trophy, string& name)
{
	// Finds the trophy in the collection by its name
	for (int i = 0; i < trophy.size(); i++)
	{
		// returns the trophies position if names matches
		if (trophy[i]->getName() == name)
		{
			return i;
		}
	}
	// returns -1 if no matching trophy was found
	cout << "ERROR: The Trophy was not found" << endl;
	return -1;
}