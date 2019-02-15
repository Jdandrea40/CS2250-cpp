#ifndef WEAPON_H  // TODO: Guard the header
#define WEAPON_H

// TODO: include the libraries this class will need

enum Color
{
	GOLD,
	SILVER,
	BRONZE
};		// TODO: create the color values

class Trophy
{
public:
	Trophy(const string& name, int& level, Color& color);
	string getName();
	int getLevel();
	Color getColor();
	void setName(const string& name);
	void setLevel(int& level);
	void setColor(const Color& color);
private:
	string m_name;
	Color m_color;
	int m_level;

};	// TODO: complete the Trophy class

// TODO: end the guard
#endif // ! WEAPON_H