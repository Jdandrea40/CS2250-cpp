#ifndef TROPHYCASE_H
#define TROPHYCASE_H

#include "Trophy.h"
#include <iostream>
#include <string>

using namespace std;

class TrophyCase
{
public:
	TrophyCase();
	TrophyCase(const Trophy& trophy);
	~TrophyCase();
	int getNbrOfTrophies();
	int getAllocatedSize();
	Trophy addTrophy(const string& name, int level, Color color);
	bool copyTrophy(const string& name);
private:
	int* m_capacity;
	Trophy* m_trophyCase;
	int* m_size;
};
#endif // !TROPHYCASE_H

