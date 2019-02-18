// TODO: implement the Trophy class
#include "Trophy.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;


Trophy::Trophy(const string& name, int& level, Color color) :
	m_name(name), m_level(level), m_color(color)
{
	switch (color)
	{
	case GOLD:
	{
		m_name = name;
		m_level = level;
		m_color = GOLD;

		break;
	}
	case SILVER:
	{
		m_name = name;
		m_level = level;
		m_color = SILVER;

		break;
	}
	case BRONZE:
	{
		m_name = name;
		m_level = level;
		m_color = BRONZE;

		break;
	}
	default:
	{
		m_name = "DEFAULT";
		m_level = 1;
		m_color = BRONZE;

		break;
	}

	}

}
string Trophy::getName()
{
	return m_name;
}
int Trophy::getLevel() 
{
	return m_level;
}
// Sets a string value to the proper enumeration type
// returns the proper name
Color Trophy::getColor()
{
	return m_color;
}
void Trophy::setName(const string& name)
{
	m_name = name;
}
void Trophy::setLevel(int& level)
{
	m_level = level;
}
void Trophy::setColor(Color color)
{
	m_color = color;
}
void Trophy::printTrophies(Color color)
{

	switch (color)
	{
		case GOLD:
		{
			cout << "[ " << m_name << " : " << m_level << " :  GOLD  ]" << endl;
			break;
		}
		case SILVER:
		{
			cout << "[ " << m_name << " : " << m_level << " :  SILVER  ]" << endl;
			break;
		}
		case BRONZE:
		{
			cout << "[ " << m_name << " : " << m_level << " :  BRONZE  ]" << endl;
			break;
		}
	}
}