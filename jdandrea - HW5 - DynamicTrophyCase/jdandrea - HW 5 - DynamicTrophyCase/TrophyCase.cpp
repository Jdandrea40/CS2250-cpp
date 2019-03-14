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

	for (int i = 0; i < m_size; i++)
	{
		m_trophyCase[i] = new Trophy(*trophy.m_trophyCase[i]);
	}
}
// Assignment operator
TrophyCase& TrophyCase::operator=(const TrophyCase& trophyCase)
{
	for (int i = 0; i < m_size; ++i)
	{
		delete m_trophyCase[i];
	}

	delete[] m_trophyCase;
	m_size = trophyCase.getNbrOfTrophies();
	m_capacity = trophyCase.getAllocatedSize();
	m_trophyCase = new Trophy*[m_capacity];


	for (int i = 0; i < m_size; i++)
	{
		m_trophyCase[i] = new Trophy(*trophyCase.m_trophyCase[i]);
	}

	return *this;
}
// Destructor
TrophyCase::~TrophyCase()
{
	for (int i = 0; i < m_size; i++)
	{
		delete m_trophyCase[i];
		m_trophyCase[i] = nullptr;
	}
	delete m_trophyCase;
	m_trophyCase = NULL;
}
// gets the number of trophies in the case
// return the the member data m_size
int TrophyCase::getNbrOfTrophies() const
{
	return m_size;
}
// gets the allocated capacity of the trophy
// returns member data m_capacity
int TrophyCase::getAllocatedSize() const
{
	return m_capacity;
}
// Adds a new trophy to the case
void TrophyCase::addTrophy(const string& name, int level, Color color)
{
	Trophy* newTrophy = new Trophy(name, level, color);
	if (m_size >= m_capacity)
	{
		expandCase();
	}

	m_trophyCase[m_size] = newTrophy;
	++m_size;	
	sortTrophies();
}
// Dynamically expands the size of the trophy case
void TrophyCase::expandCase()
{
	m_capacity++;
	Trophy** tempCase = new Trophy*[m_capacity];
	for (int i = 0; i < m_size; i++)
	{
		tempCase[i] = m_trophyCase[i];
	}
	delete[] m_trophyCase;
	m_trophyCase = tempCase;
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
			expandCase();
		}
		Trophy* newTrophy = m_trophyCase[trophyPosition];
		m_trophyCase[m_size] = newTrophy;
		++m_size;
		sortTrophies();
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
		m_trophyCase[trophyPosition] = NULL;

		for (int i = trophyPosition; i < m_size; i++)
		{
			m_trophyCase[i] = m_trophyCase[i + 1];
		}

		--m_size;


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
		sortTrophies();
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
		sortTrophies();
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
		sortTrophies();
		return true;
	}
	else
	{
		return false;
	}
	return false;
}
// Sorts the Trophies by level
// using color for same leveled trophies
void TrophyCase::sortTrophies()
{
	for (int i = 0; i < m_size - 1; i++)
	{
		for (int j = 0; j < m_size - i - 1; j++)
		{
			if (*m_trophyCase[j] > *m_trophyCase[j + 1])
			{
				Trophy temp = *m_trophyCase[j];
				*m_trophyCase[j] = *m_trophyCase[j + 1];
				*m_trophyCase[j + 1] = temp;
			}
		}
	}
}
// Insertion Operator used for trophy case printing
// returns the ostream sout
ostream& operator<< (ostream& sout, const TrophyCase& trophyCase)
{
	for (int i = 0; i < trophyCase.getNbrOfTrophies(); i++)
	{
		sout << *trophyCase.m_trophyCase[i] << endl;
	}
	return sout;
}