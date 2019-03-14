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
	TrophyCase(const TrophyCase& trophy);
	~TrophyCase();
	TrophyCase& operator=(const TrophyCase& trophy);
	friend ostream& operator<< (ostream& sout,const TrophyCase& trophyCase);
	int getNbrOfTrophies() const;
	int getAllocatedSize() const;
	int searchForTrophy(const string& name);
	void addTrophy(const string& name, int level, Color color);
	bool copyTrophy(const string& name);
	bool deleteTrophy(const string& name);
	bool renameTrophy(const string& name, const string& newName);
	bool relevelTrophy(const string& name, int& level);
	bool recolorTrophy(const string& name, Color& color);
private:
	int m_capacity;
	Trophy** m_trophyCase;
	int m_size;
};
#endif // !TROPHYCASE_H

