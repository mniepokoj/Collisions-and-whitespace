#include "zad3.h"

int test_WhiteSpaceRemoving()
{
	std::string s(" 	przykladowy  string  ");
	std::cout << s << std::endl;
	RemoveWhiteSpace(s);
	std::cout << s << std::endl;

	return 0;
}