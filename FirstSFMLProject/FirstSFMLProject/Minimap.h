#ifndef _MINIMAP_H_
#define _MINIMAP_H_

#include "SFML\Graphics.hpp"

using namespace std;



class MiniMap
{
private:
	static bool instanceFlag;
	static MiniMap* instance;
	sf::View view;
	sf::View staticView;

	MiniMap()
	{
	}
public:
	static MiniMap* GetInstance();
	~MiniMap()
	{
		instanceFlag = false;

	}
	void Init(int w, int h);
	sf::View getView();
	sf::View getStaticView();
	void setView(sf::View v);
	void setViewPosition(sf::Vector2f pos);

};
#endif