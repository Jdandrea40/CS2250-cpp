#include "TrophyCase.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Default Constructor
TrophyCase::TrophyCase()
{
	m_capacity = 10;
	m_size = 0;
	m_trophyCase = new Trophy*[m_capacity];
}
// Copy Constructor
TrophyCase::TrophyCase(const TrophyCase& trophy)
{
	m_trophyCase = new Trophy*[trophy.getAllocatedSize()];
	m_size = trophy.getNbrOfTrophies();
	m_capacity = trophy.getAllocatedSize();

}
// Assignment operator
TrophyCase& TrophyCase::operator=(const TrophyCase& trophy)
{
	*m_trophyCase = *trophy.m_trophyCase;
	return *this;
}
// Destructor
TrophyCase::~TrophyCase()
{
	delete [] m_trophyCase;
	m_trophyCase = NULL;

}
int TrophyCase::getNbrOfTrophies() const
{
	return m_size;
}
int TrophyCase::getAllocatedSize() const
{
	return m_capacity;
}
Trophy TrophyCase::addTrophy(const string& name, int level, Color color)
{
	Trophy* newTrophy = new Trophy(name, level, color);
	for (int i = 0; i < m_capacity; i++)
	{
		if (m_trophyCase == nullptr)
		{
			*m_trophyCase[i] = *newTrophy;
			++m_size;
		}
	}
	return *newTrophy;
}
bool TrophyCase::copyTrophy(const string& name)
{
	string currName;
	for (int i = 0; i < m_size; i++)
	{
		currName = m_trophyCase[i]->getName();
		if (currName == name)
		{
			return true;
		}
	}
	
	return false;
}
bool TrophyCase::deleteTrophy(const string& name)
{
	string currName;
	for (int i = 0; i < m_size; i++)
	{
		currName = m_trophyCase[i]->getName();
		if (currName == name)
		{
			delete m_trophyCase[i];
			m_trophyCase[i] = nullptr;

			return true;
		}
	}
	return false;
}
bool TrophyCase::renameTrophy(const string& name, const string& newName)
{
	string currName;
	for (int i = 0; i < m_size; i++)
	{
		currName = m_trophyCase[i]->getName();
		if (currName == name)
		{
			m_trophyCase[i]->setName(newName);
			return true;
		}
	}
	return false;
}
bool TrophyCase::relevelTrophy(const string& name, int& level)
{
	string currName;
	for (int i = 0; i < m_size; i++)
	{
		currName = m_trophyCase[i]->getName();
		if (currName == name)
		{
			m_trophyCase[i]->setLevel(level);
			return true;
		}
	}
	return false;
}
bool TrophyCase::recolorTrophy(const string& name, Color& color)
{
	string currName;
	for (int i = 0; i < m_size; i++)
	{
		currName = m_trophyCase[i]->getName();
		if (currName == name)
		{
			m_trophyCase[i]->setColor(color);
			return true;
		}
	}
	return false;
}
ostream& operator<< (ostream& sout, const TrophyCase& trophyCase)
{
	for (int i = 0; i < trophyCase.getNbrOfTrophies(); i++)
	{
		sout << *trophyCase.m_trophyCase[i];
		sout << "\n";
	}
	return sout;
}