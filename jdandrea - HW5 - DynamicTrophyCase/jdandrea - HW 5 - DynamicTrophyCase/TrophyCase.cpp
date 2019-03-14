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
	m_size = trophy.getNbrOfTrophies();
	m_capacity = trophy.getAllocatedSize();
	m_trophyCase = new Trophy*[m_capacity];
}
// Assignment operator
TrophyCase& TrophyCase::operator=(const TrophyCase& trophy)
{
	if (this != &trophy)
	{
		delete[] m_trophyCase;

		m_trophyCase = new Trophy*[trophy.getAllocatedSize()];

		for (int i = 0; i < trophy.getAllocatedSize(); ++i)
		{
			*m_trophyCase[i] = *trophy.m_trophyCase[i];
		}
	}
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
void TrophyCase::addTrophy(const string& name, int level, Color color)
{
	Trophy* newTrophy = new Trophy(name, level, color);
	if (m_size >= m_capacity)
	{
		// Expand
	}
	m_trophyCase[m_size] = newTrophy;
	++m_size;
}
// Searches for a trophy
// returns its position
int TrophyCase::searchForTrophy(const string& name)
{
	for (int i = 0; i < m_size; i++)
	{
		if (m_trophyCase[i]->getName() == name)
		{
			return i;
		}
	}
	return -1;
}
// Copies a Trophy
// returns true if done
// else false
bool TrophyCase::copyTrophy(const string& name)
{
	int trophyPosition = searchForTrophy(name);
	if (trophyPosition > -1)
	{
		if (m_size >= m_capacity)
		{
			// Expand
		}
		Trophy* newTrophy = m_trophyCase[trophyPosition];
		m_trophyCase[m_size] = newTrophy;
		++m_size;
		return true;
	}
	else
	{
		return false;
	}
}
// Deletes a trophy
// returns true if done
// else false
bool TrophyCase::deleteTrophy(const string& name)
{
	int trophyPosition = searchForTrophy(name);

	if (trophyPosition > -1)
	{
		delete m_trophyCase[trophyPosition];
		m_trophyCase[trophyPosition] = nullptr;

		return true;
	}
	else
	{
		return false;
	}

}
// Renames Trophies
// returns true if done
// else false
bool TrophyCase::renameTrophy(const string& name, const string& newName)
{
	int trophyPosition = searchForTrophy(name);
	if (trophyPosition > -1)
	{
		m_trophyCase[trophyPosition]->setName(newName);
		return true;
	}
	else
	{
		return false;
	}

}
// Relevels trophies
// returns true if done
// else false
bool TrophyCase::relevelTrophy(const string& name, int& level)
{
	int trophyPosition = searchForTrophy(name);
	if (trophyPosition > -1)
	{
		m_trophyCase[trophyPosition]->setLevel(level);
		return true;
	}
	else
	{
		return false;
	}
}
// Recolors Trophies
// returns true if done
// else false
bool TrophyCase::recolorTrophy(const string& name, Color& color)
{
	int trophyPosition = searchForTrophy(name);
	if (trophyPosition > -1)
	{
		m_trophyCase[trophyPosition]->setColor(color);
		return true;
	}
	else
	{
		return false;
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