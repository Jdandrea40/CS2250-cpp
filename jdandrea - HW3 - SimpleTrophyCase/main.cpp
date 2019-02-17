#include <iostream>
#include <string>
#include <vector>
#include "Trophy.h"
using namespace std;

// Reusable strings
const string PROMPT_FOR_NAME = "Please enter the name of the Trophy";
const string PROMPT_FOR_LEVEL = "Please enter the level of your Trophy (between 1 and 10)";
const string PROMPT_FOR_COLOR = "Please enter the color of your Trophy (GOLD, SILVER, or BRONZE)";

// Menu choice handlers
void addTrophy(vector<Trophy>& trophy);
void copyTrophy(vector<Trophy>& trophy);
void deleteTrophy(vector<Trophy>& trophy);
void renameTrophy(vector<Trophy>& trophy);
void relevelTrophy(vector<Trophy>& trophy);
void recolorTrophy(vector<Trophy>& trophy);
void printTrophies(vector<Trophy>& trophy);

// Input handlers
int printMenu();
void /* TODO: Return a Trophy instead of void */ promptForTrophy();
string promptForString(const string& message);
int promptForInt(const string& message, int minimum, int maximum);
Color promptForColor(const string& message);

// Useful helper methods
string stringToUpper(string value);
int searchForTrophy(vector<Trophy>& trophy);

// This application allows for the management of a trophy collection
int main()
{
	cout << "***********************************************" << endl
		<< "Welcome to the Trophy editor!" << endl
		<< "With this application, you can manage your trophy" << endl
		<< "collection - add, modify, or remove trophies by" << endl
		<< "using this simple menu!" << endl
		<< "***********************************************" << endl;

	// TODO: Create a vector of Trophy objects
	vector<Trophy> trophies;								// A vector of trophy objects

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

	return 0;
}

// Print the menu to the user and accept their menu choice
int printMenu()
{
	int input;
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
	cin >> input;
	cin.ignore();
	return input;
}

// Add a new Trophy to the collection
void addTrophy(vector<Trophy>& trophy)
{
	cout << "You have chosen to add a trophy." << endl;
	string name = promptForString(PROMPT_FOR_NAME);
	int level = promptForInt(PROMPT_FOR_LEVEL, 0, 10);
	Color color = promptForColor(PROMPT_FOR_COLOR);

	//Trophy::setName(name);
	//Trophy::setLevel(level);
	//Trophy::setColor(color);
	// TODO: Ask the user for the Trophy info (hint: there's a function for this...) and add it to the vector
	trophy.push_back(Trophy(name, level, color));
}

// Delete an existing Trophy from the collection
void deleteTrophy(vector<Trophy>& trophies)
{
	cout << "You have chosen to delete an existing trophy." << endl;

	
	
	int deletedTrophy = searchForTrophy(trophies);
	if (deletedTrophy == -1)
	{
		return;
	}
	else
	{
	}
	// TODO: Find the trophy and if it exists, erase it to the vector
}

// Copy an existing Trophy in the collection
void copyTrophy(vector<Trophy>& trophy)
{
	cout << "You have chosen to copy an existing trophy." << endl;

	int copiedTrophy = searchForTrophy(trophy);						// searches vector for a trophy name

	// if no trophy matches the searched name
	// return out of function
	if (copiedTrophy == -1)
	{
		return;
	}
	// if it exists, duplicate it into the vector
	else
	{
		trophy.push_back(trophy[copiedTrophy]);
	}
}

// Rename an existing Trophy (change the name)
void renameTrophy(vector<Trophy>& trophy)
{
	cout << "You have chosen to rename an existing trophy." << endl;
	string name = promptForString(PROMPT_FOR_NAME);
	// TODO: Find the trophy and if it exists, change its name
}

// Relevel an existing Trophy (change the level)
void relevelTrophy(vector<Trophy>& trophy)
{
	cout << "You have chosen to change the level of an existing trophy." << endl;
	string name = promptForString(PROMPT_FOR_NAME);
	// TODO: Find the trophy and if it exists, change its level
}

// Recolor an existing Trophy (change the color)
void recolorTrophy(vector<Trophy>& trophy)
{
	cout << "You have chosen to change the color of an existing trophy." << endl;
	string name = promptForString(PROMPT_FOR_NAME);
	// TODO: Find the trophy and if it exists, change its color
}

// Print all of the Trophies in the collection
void printTrophies(vector<Trophy>& trophy)
{
	cout << "You have chosen to print all of the trophies." << endl;

	// Prints all the trophies in the order they are stored in the vector
	for (int i = 0; i < trophy.size(); i++)
	{
		string trophyColor;						// initialize string val

		// Checks the enum val, and sets it to approp string
		if (trophy[i].getColor() == GOLD)
		{
			trophyColor = "GOLD";
		}
		else if (trophy[i].getColor() == SILVER)
		{
			trophyColor = "SILVER";
		}
		else
		{
			trophyColor = "BRONZE";
		}
		cout << trophy[i].getName() << " | " << trophy[i].getLevel() << " | " << trophyColor << endl;
	}
}

// Ask the user for a Trophy, validate their responses
// Return the Trophy
void /* TODO: Return a Trophy instead of void */ promptForTrophy()
{
	string name = promptForString(PROMPT_FOR_NAME);
	int level = promptForInt(PROMPT_FOR_LEVEL, 1, 10);
	/* TODO: Store the color the user selected = */ promptForColor(PROMPT_FOR_COLOR);

	// TODO: Create a new trophy with the above info

	// TODO: Return a Trophy
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
	while(value == "")
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

	// prompt/ read in of trophy level
	cout << message << endl;
	cin >> value;

	// proper input check / error message
	while (value < minimum || value > maximum)
	{
		cout << "That value is outside the acceptable range.  Try again." << endl;
		cin >> value;
	}
	cin.ignore();

	// returns the trophies level
	return value;
}

// Convert a string to all uppercase (so that we can compare the
// user's entered color to the official color)
string stringToUpper(string value)
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

	// TODO: while the color is not acceptable
	while (value != "GOLD" || value != "SILVER" || value != "BRONZE")
	{	
		// Prompt and read in of user color value
		cout << message << endl;
		cin >> value;
	
		// converts string to Upper Case
		value = stringToUpper(value);
		cout << value << endl;

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
	cin.ignore();

	return color;
}

// Search for a trophy in the collection by name
int searchForTrophy(vector<Trophy>& trophy)
{
	string name = promptForString(PROMPT_FOR_NAME);
	int trophyPosition = 0;

	// TODO: Find the trophy in the collection by its name
	for (int i = 0; i < trophy.size(); i++)
	{
		if (trophy[i].getName() == name)
		{
			trophyPosition = i;
			return i;
		}
	}
	// TODO: If you find the trophy, return its position in the collection
	// TODO: if the trophy was not found, print this error, return -1
	cout << "ERROR: The Trophy was not found" << endl;
	return -1;
}