#pragma once

class RESOURCES
{
public:
	IRON iron;
	STONE stone;
	WOOD wood;
public:
	RESOURCES(void);
	RESOURCES(int AmountOfIron, int AmountOfStone, int AmountOfWood);
	~RESOURCES(void);
};