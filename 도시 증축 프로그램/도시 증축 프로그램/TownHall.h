#pragma once
class TOWN_HALL
{
	friend class CITY;
private:
	static int RequiredIron;
	static int RequiredStone;
	static int RequiredWood;
	int upgrade;
public:
	TOWN_HALL(void);
	~TOWN_HALL(void);
public:
	int getRequiredResource(Enums::SORT resource);
	int getUpgrade(void);
	void plusUpgrade(void);
};