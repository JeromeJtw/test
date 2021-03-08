#include "HeroController.h"

HeroController::HeroController(std::string no, std::string name)
{
	m_pHeroView = new HeroView;
	m_pHero = new Hero;
	m_pHero->setNo(no);
	m_pHero->setName(name);
}

HeroController::~HeroController()
{
	if (m_pHero)
	{
		delete m_pHero;
	}
	m_pHero = nullptr;

	if (m_pHeroView)
	{
		delete m_pHeroView;
	}
	m_pHeroView = nullptr;
}

void HeroController::setHeroHp(int hp)
{
	if (m_pHero)
	{
		m_pHero->setHp(hp);
	}
}

void HeroController::setHeroAtt(int att)
{
	if (m_pHero)
	{
		m_pHero->setAtt(att);
	}
}

void HeroController::show()
{
	if (m_pHero)
	{
		m_pHeroView->show(m_pHero->getNo(), m_pHero->getName(), m_pHero->getAtt(), m_pHero->getHp());
	}
}

void HeroController::beAttack(int att)
{
	if (m_pHero)
	{
		m_pHero->beAttack(att);
	}
}

void HeroController::dead()
{
	if (m_pHeroView && m_pHero)
	{
		m_pHeroView->dead(m_pHero->getNo(), m_pHero->getName());
	}
}

void HeroController::winned()
{
	if (m_pHeroView && m_pHero)
	{
		m_pHeroView->winned(m_pHero->getNo(), m_pHero->getName());
	}
}

Hero* HeroController::getHero()
{
	if (m_pHero)
	{
		return m_pHero;
	}
	return nullptr;
}

