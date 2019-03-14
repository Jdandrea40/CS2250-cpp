// Guards the header
#ifndef TROPHY_H
#define TROPHY_H

// include the libraries this class will need
#include <string>
#include <vector>
#include <iostream>

using namespace std;

// enumerations of trophy colors
enum Color
{
	GOLD,
	SILVER,
	BRONZE

};
// Defines the Trophy class
class Trophy
{
public:
	Trophy();
	Trophy(const Trophy& trophy);
	Trophy(const std::string& name, int& level, Color color);
	~Trophy();
	Trophy& operator=(const Trophy& trophy);
	int compareTrophy(const Trophy& trophy);
	bool operator< (const Trophy& trophyB);
	bool operator> (const Trophy& trophyB);
	bool operator== (const Trophy& trophyB);
	bool operator!= (const Trophy& trophyB);
	bool operator<= (const Trophy& trophyB);
	bool operator>= (const Trophy& trophyB);
	friend ostream& operator<< (ostream& sout,const Trophy& trophy);
	string getName();
	int getLevel();
	Color getColor();
	void setName(const string& name);
	void setLevel(int& level);
	void setColor(Color color);
	void printTrophies();

private:
	string* m_name;
	int* m_level;
	Color* m_color;

};

#endif // !TROPHY_H