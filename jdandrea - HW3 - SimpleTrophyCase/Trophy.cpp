// implement the Trophy class
#include "Trophy.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Default constructor to intialie safe values
Trophy::Trophy()
{
	m_name = "DefaultTrophy";
	m_level = 0;
	m_color = BRONZE;
};

Trophy::Trophy(const string& name, int& level, Color color) :
	m_name(name), m_level(level), m_color(color)
{ }

// Gets the private data (NAME) of the trophy
string Trophy::getName()
{
	return m_name;
}
// Gets the private data (LEVEL) of the trophy
int Trophy::getLevel() 
{
	return m_level;
}
// Gets the private data (COLOR) of the trophy
Color Trophy::getColor()
{
	return m_color;
}
// Sets the name of the trophy
void Trophy::setName(const string& name)
{
	m_name = name;
}
// Sets the level of the trophy
void Trophy::setLevel(int& level)
{
	m_level = level;
}
// Sets the color of the trophy
void Trophy::setColor(Color color)
{
	m_color = color;
}
// Prints the trophies
void Trophy::printTrophies()
{
	// Switches what is printed based on the enumeration of the trophy
	switch (m_color)
	{
		// GOLD trophy printing
		case GOLD:
		{
			cout << "[ " << m_name << " : " << m_level << " :  GOLD  ]" << endl;
			break;
		}
		// SILVER trophy printing
		case SILVER:
		{
			cout << "[ " << m_name << " : " << m_level << " :  SILVER  ]" << endl;
			break;
		}
		// Brone trophy printing
		case BRONZE:
		{
			cout << "[ " << m_name << " : " << m_level << " :  BRONZE  ]" << endl;
			break;
		}
	}
}