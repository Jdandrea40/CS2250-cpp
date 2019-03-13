// Guards the header
#ifndef TROPHY_H
#define TROPHY_H

// include the libraries this class will need
#include <string>
#include <vector>

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
	//const Trophy& operator< (const Trophy& trophy);
	//const Trophy& operator> (const Trophy& trophy);
	//const Trophy& operator== (const Trophy& trophy);
	//const Trophy& operator!= (const Trophy& trophy);
	//const Trophy& operator<= (const Trophy& trophy);
	//const Trophy& operator>= (const Trophy& trophy);
	friend ostream& operator<< (ostream& sout,const Trophy& trophy);
	std::string getName();
	int getLevel();
	Color getColor();
	void setName(const std::string& name);
	void setLevel(int& level);
	void setColor(Color color);
	void printTrophies();

private:
	std::string* m_name;
	int* m_level;
	Color* m_color;

};

#endif // !TROPHY_H