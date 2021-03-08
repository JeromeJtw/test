#pragma once
#include <string>

class Hero
{
public:
	Hero();
	~Hero();
	void beAttack(int att);
	bool dead() { return m_nHp = 0 ? true : false; }

	void setNo(std::string no) { m_sNo = no; }
	std::string getNo() { return m_sNo; }

	void setName(std::string name) { m_sName = name; }
	std::string getName() { return m_sName; }

	void setHp(int hp) { m_nHp = hp; }
	int getHp() { return m_nHp; }

	void setAtt(int att) { m_nAtt = att; }
	int getAtt() { return m_nAtt; }




private:
	std::string m_sName;//英雄姓名
	std::string m_sNo;//游戏场号码
	int m_nHp;//血量
	int m_nAtt;//攻击力
};
