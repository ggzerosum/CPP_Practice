#pragma once
class WOOD
{
private:
	const static char name[5];
	const static int price;
	int amount;
public:
	WOOD(void);
	WOOD(int amount);
	~WOOD(void);
public:
	const char* getName(void);
	int getPrice(void);
	int getAmount(void);
	bool addAmount(int amount);
	bool subAmount(int amount);
};

