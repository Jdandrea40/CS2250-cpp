// implement the Trophy class
#include "Trophy.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// Default constructor to intialize safe values
Trophy::Trophy()
{
	m_name = new string("");
	m_level = new int(0);
	m_color = new Color(BRONZE);
}
// copy constructor
Trophy::Trophy(const Trophy& trophy)
{
	m_name = new string(*trophy.m_name);
	m_level = new int(*trophy.m_level);
	m_color = new Color(*trophy.m_color);

}
// Trophy Constructor
Trophy::Trophy(const string& name, int level, Color color)
{
	m_name = new string(name);
	m_level = new int(level);
	m_color = new Color(color);

}

// Trophy Assignment Operator
Trophy& Trophy::operator=(const Trophy& trophy)
{
	*m_name = *trophy.m_name;
	*m_level = *trophy.m_level;
	*m_color = *trophy.m_color;

	return *this;
}

// Trophy Destructor
Trophy::~Trophy()
{
	delete m_name;
	m_name = NULL;

	delete m_level;
	m_level = NULL;

	delete m_color;
	m_color = NULL;
}

// Gets the private data (NAME) of the trophy
string Trophy::getName()
{
	return *m_name;
}
// Gets the private data (LEVEL) of the trophy
int Trophy::getLevel()
{
	return *m_level;
}
// Gets the private data (COLOR) of the trophy
Color Trophy::getColor()
{
	return *m_color;
}
// Sets the name of the trophy
void Trophy::setName(const string& name)
{
	*m_name = name;
}
// Sets the level of the trophy
void Trophy::setLevel(int level)
{
	*m_level = level;
}
// Sets the color of the trophy
void Trophy::setColor(Color color)
{
	*m_color = color;
}
// Prints the trophies
void Trophy::printTrophies()
{
	// Switches what is printed based on the enumeration of the trophy
	switch (*m_color)
	{
		// GOLD trophy printing
	case GOLD:
		cout << "[ " << *m_name << " : " << *m_level << " :  GOLD  ]" << endl;
		break;
		// SILVER trophy printing
	case SILVER:
		cout << "[ " << *m_name << " : " << *m_level << " :  SILVER  ]" << endl;
		break;
		// Bronze trophy printing
	case BRONZE:
		cout << "[ " << *m_name << " : " << *m_level << " :  BRONZE  ]" << endl;
		break;
	}
}

// Insertion operator used for printing the trophies
// returns the ostream sout
ostream& operator<< (ostream& sout, const Trophy& trophy)
{
	sout << "[ " << left << setw(30) << *trophy.m_name << " : " << right << setw(2) << *trophy.m_level << left << " : ";
	// case statemt for checking trophy color
	switch (*trophy.m_color)
	{
		// GOLD trophy printing
	case GOLD:
		sout << setw(6) << "GOLD";
		break;
		// SILVER trophy printing
	case SILVER:
		sout << setw(6) << "SILVER";
		break;
		// Bronze trophy printing
	case BRONZE:
		sout << setw(6) << "BRONZE";
		break;
	}
	sout << " ]";
	return sout;
}
// Compares trophies for sorting
// Level first, then by color (if necessary), then by name (if necessary)
// returns a value for comparison operator checks
int Trophy::compareTrophy(const Trophy& trophy) const
{
	// Level Comparison
	if (*m_level > *trophy.m_level)
	{
		return 1;
	}
	else if (*m_level < *trophy.m_level)
	{
		return -1;
	}
	// Color Comparison
	else if (*m_level == *trophy.m_level)
	{
		if (*m_color > *trophy.m_color)
		{
			return 1;
		}
		else if (*m_color < *trophy.m_color)
		{
			return -1;
		}
		// Name Comparison
		else if (*m_color == *trophy.m_color)
		{
			if (*m_name > *trophy.m_name)
			{
				return 1;
			}
			else if (*m_name < *trophy.m_name)
			{
				return -1;
			}
			else if (*m_name == *trophy.m_name)
			{
				return 0;
			}
		}
	}
}
// Comparison Operator Checks, used for trophy sorting (TrophyCase)
// Less than check
bool Trophy::operator< (const Trophy& trophyB) const
{
	if (compareTrophy(trophyB) < 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
// greater than check
bool Trophy::operator> (const Trophy& trophyB) const
{
	if (compareTrophy(trophyB) > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
// equal to check
bool Trophy::operator== (const Trophy& trophyB) const
{
	if (compareTrophy(trophyB) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
// not equal to check
bool Trophy::operator!= (const Trophy& trophyB) const
{
	if (compareTrophy(trophyB) != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
// less than or equal to check
bool Trophy::operator<= (const Trophy& trophyB) const
{
	if (compareTrophy(trophyB) <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
// greater than or equal to check
bool Trophy::operator>= (const Trophy& trophyB) const
{
	if (compareTrophy(trophyB) >= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}