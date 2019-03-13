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
	friend ostream& operator<< (ostream& sout, const Trophy& trophy);
	//friend istream& operator>>(istream& sin, Trophy& trophy);
	int getNbrOfTrophies() const;
	int getAllocatedSize() const;
	Trophy addTrophy(const string& name, int level, Color color);
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

