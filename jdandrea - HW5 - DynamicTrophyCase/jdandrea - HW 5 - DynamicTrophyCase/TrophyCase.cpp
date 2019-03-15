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

	// Loops through and copies trophies
	for (int i = 0; i < m_size; i++)
	{
		m_trophyCase[i] = new Trophy(*trophy.m_trophyCase[i]);
	}
}
// Assignment operator
TrophyCase TrophyCase::operator=(const TrophyCase& trophyCase)
{
	// Self Assignment protection
	if (this != &trophyCase)
	{
		// Loops through and deletes all data
		// in case
		for (int i = 0; i < m_size; ++i)
		{
			delete m_trophyCase[i];
		}

		// delete the array, and creates a new one
		delete[] m_trophyCase;
		m_size = trophyCase.getNbrOfTrophies();
		m_capacity = trophyCase.getAllocatedSize();
		m_trophyCase = new Trophy*[m_capacity];

		// copies the trophies into a new array
		for (int i = 0; i < m_size; i++)
		{
			m_trophyCase[i] = new Trophy(*trophyCase.m_trophyCase[i]);
		}
	}
	return *this;
}
// Destructor
TrophyCase::~TrophyCase()
{
	// loops through and deletes all values
	for (int i = 0; i < m_size; i++)
	{
		delete m_trophyCase[i];
		m_trophyCase[i] = nullptr;
	}
	// deletes the array
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
	// creation of a new trophy
	Trophy* newTrophy = new Trophy(name, level, color);
	// expands if necessary
	if (m_size >= m_capacity)
	{
		expandCase();
	}
	// adds the new trophy to the array
	// increments the size
	// then sorts
	m_trophyCase[m_size] = newTrophy;
	++m_size;
	sortTrophies();
}
// Dynamically expands the size of the trophy case
void TrophyCase::expandCase()
{
	// expands the capacity by 10%
	m_capacity = m_capacity * 1.1;
	// storage of the array for dynamic expansion
	Trophy** tempCase = new Trophy*[m_capacity];
	// copies old values into temp array
	for (int i = 0; i < m_size; i++)
	{
		tempCase[i] = m_trophyCase[i];
	}
	// deletes old array and adds old values to new array
	delete[] m_trophyCase;
	m_trophyCase = tempCase;
}
// Searches for a trophy
// returns its position
int TrophyCase::searchForTrophy(const string& name)
{
	// loops through array and compares name given, to current
	// trophy name
	// returns its position
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
	// if the returned value is an acutal position
	if (trophyPosition > -1)
	{
		// expand if necessary
		if (m_size >= m_capacity)
		{
			expandCase();
		}
		// copy that trophy into the array, increment size, and sort
		Trophy* newTrophy = new Trophy(*m_trophyCase[trophyPosition]);
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
	// if the returned value is an acutal position
	if (trophyPosition > -1)
	{
		// delete that trophy
		delete m_trophyCase[trophyPosition];
		m_trophyCase[trophyPosition] = NULL;
		// backfill if necessary
		for (int i = trophyPosition; i < m_size; i++)
		{
			m_trophyCase[i] = m_trophyCase[i + 1];
		}
		// decrement the size
		// and set the outside range value to null
		--m_size;
		m_trophyCase[m_size] = nullptr;

		

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
	// if the returned value is an acutal position
	if (trophyPosition > -1)
	{
		// set the current name to new name
		// resort the trophies
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
bool TrophyCase::relevelTrophy(const string& name, int level)
{
	int trophyPosition = searchForTrophy(name);
	// if the returned value is an acutal position
	if (trophyPosition > -1)
	{
		// set the new name
		// resort trophies
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
bool TrophyCase::recolorTrophy(const string& name, Color color)
{
	int trophyPosition = searchForTrophy(name);
	// if the returned value is an acutal position
	if (trophyPosition > -1)
	{
		// set the new color
		// resort
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
	// Bubble Sort
	for (int i = 0; i < m_size - 1; i++)
	{
		for (int j = 0; j < m_size - i - 1; j++)
		{
			// checks if current is greater than the next
			if (*m_trophyCase[j] > *m_trophyCase[j + 1])
			{
				// temporary trophy holder
				Trophy temp = *m_trophyCase[j];
				// swaps the trophy positions
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