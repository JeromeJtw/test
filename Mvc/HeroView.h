#pragma once
#include <iostream>
#include <string>


class HeroView
{
public:
	HeroView();
	~HeroView();

	void show(std::string no, std::string name, int att, int hp);
	void dead(std::string no, std::string name);
	void winned(std::string no, std::string name);
};