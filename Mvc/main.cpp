#include "HeroController.h"

int main()
{
	HeroController *pHeroController1 = new HeroController("2017", "ÍõÕßÈÙÒ«");
	pHeroController1->setHeroAtt(40);
	pHeroController1->setHeroHp(100);
	pHeroController1->show();


	HeroController *pHeroController2 = new HeroController("2018", "³Ô¼¦");
	pHeroController2->setHeroAtt(20);
	pHeroController2->setHeroHp(200);
	pHeroController2->show();

	//pHeroController1¹¥»÷pHeroController2
	pHeroController2->beAttack(pHeroController1->getHero()->getAtt());
	pHeroController2->show();

	while (pHeroController2->getHero()->dead())
	{
		pHeroController2->beAttack(pHeroController1->getHero()->getAtt());
		pHeroController2->show();
	}

	pHeroController2->dead();
	pHeroController2->show();
	pHeroController1->show();
	pHeroController1->winned();

	system("pause");
}