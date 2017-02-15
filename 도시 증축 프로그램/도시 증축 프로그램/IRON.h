#pragma once
class IRON
{
private:
	const static char name[5];
	const static int price;
	int amount;
public:
	IRON(void);
	IRON(int amount);
	~IRON(void);
public:
	const char* getName(void);
	int getPrice(void);
	int getAmount(void);
	bool addAmount(int amount);
	bool subAmount(int amount);
};

