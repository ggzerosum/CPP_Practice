#include <iostream>

namespace providence_010101010101_yoyoyo
{
	extern int my_score;
}

void main(void)
{
	namespace yo = providence_010101010101_yoyoyo;
	using std::cout;
	cout<< yo::my_score;
}