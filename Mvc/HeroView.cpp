#include "HeroView.h"

HeroView::HeroView()
{}

HeroView::~HeroView(){}

void HeroView::show(std::string no, std::string name, int att, int hp)
{
	std::cout << "Hero info(" << "no: " << no << ", name£º" << name << ", att£º" << att << ", hp£º" << hp <<")"<< std::endl;
}

void HeroView::dead(std::string no, std::string name)
{
	std::cout << "Hero dead(" << "no£º" << no << ", name£º" << name << ")" << std::endl;
}

void HeroView::winned(std::string no, std::string name)
{
	std::cout << "Hero winned(" << "no£º" << no << ", name£º" << name << ")" << std::endl;
}
