// TODO: implement the Trophy class
#include "Trophy.h"
#include <iostream>
#include <string>

using namespace std;

Trophy::Trophy(const string& name, int& level, Color& color)
{
	switch (color)
	{
	case(GOLD):
		{
		m_name = "Super Mega Trophy";
		m_level = 9001;
			break;
		}
	case(SILVER):
		{
		m_name = "If you aint First, you're Last!";
		m_level = 69;
			break;
		}
	case(BRONZE):
	{
		m_name = "I mean, you tried...right?";
		m_level = 0;
		break;
	}
	}
}
string Trophy::getName() 
{
	string name;
	return m_name;
}
int Trophy::getLevel()
{
	int level;
	return m_level;
}
Color Trophy::getColor()
{
	Color color;

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
void Trophy::setColor(const Color& color)
{
	m_color = color;
}

