// TODO: Guard the header
#ifndef TROPHY_H
#define TROPHY_H

// TODO: include the libraries this class will need
#include <string>
#include <vector>


enum Color
{
	GOLD,
	SILVER,
	BRONZE

};		// TODO: create the color values
class Trophy
{
public:
	Trophy(const std::string& name, int& level, Color color);
	std::string getName();
	int getLevel();
	Color getColor();
	void setName(const std::string& name);
	void setLevel(int& level);
	void setColor(Color color);
	void printTrophies(Color color);

private:
	std::string m_name;
	int m_level;
	Color m_color;
	//vector<Trophy> trophy;
};	// TODO: complete the Trophy class

// TODO: end the guard

#endif // !TROPHY_H