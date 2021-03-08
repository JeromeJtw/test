#pragma once
#include "Hero.h"
#include "HeroView.h"

class HeroController
{
public:
	HeroController(std::string no, std::string name);
	~HeroController();

	void setHeroHp(int hp);
	void setHeroAtt(int att);
	void show();
	void beAttack(int att);
	void dead();
	void winned();

	Hero* getHero();
private:
	Hero* m_pHero;
	HeroView* m_pHeroView;
};