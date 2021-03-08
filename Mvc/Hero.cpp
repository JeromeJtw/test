#include "Hero.h"

Hero::Hero()
{

}

Hero::~Hero(){}

void Hero::beAttack(int att)
{
	if ( att <= 0 )
	{
		throw "Att Number = 0";
	}
	m_nHp -= att;
	m_nHp = m_nAtt < 0 ? 0 : m_nHp;
}
