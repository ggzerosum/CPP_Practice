#pragma once
class STONE
{
private:
	const static char name[5];
	const static int price;
	int amount;
public:
	STONE(void);
	STONE(int amount);
	~STONE(void);
public:
	const char* getName(void);
	int getPrice(void);
	int getAmount(void);
	bool addAmount(int amount);
	bool subAmount(int amount);
};

