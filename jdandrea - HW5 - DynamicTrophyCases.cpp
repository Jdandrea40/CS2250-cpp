#include "TrophyCase.h"
#include <iostream>
#include <string>

using namespace std;

// Default Constructor
TrophyCase::TrophyCase()
{
	*m_capacity = 10;
	m_trophyCase = new Trophy[*m_capacity];
}
// Copy Constructor
TrophyCase::TrophyCase(const Trophy& trophy)
{
	m_trophyCase = new Trophy(trophy);
}
TrophyCase::~TrophyCase()
{
	delete [] m_trophyCase;
	m_trophyCase = NULL;

}
int TrophyCase::getNbrOfTrophies()
{
	return *m_size;
}
int TrophyCase::getAllocatedSize()
{
	return *m_capacity;
}
Trophy TrophyCase::addTrophy(const string& name, int level, Color color)
{
	Trophy* newTrophy = new Trophy(name, level, color);
	for (int i = 0; i < *m_capacity; i++)
	{
		if (m_trophyCase != nullptr)
		{
			m_trophyCase[i] = *newTrophy;
		}
	}
}
bool TrophyCase::copyTrophy(const string& name)
{
	
	return false;
}