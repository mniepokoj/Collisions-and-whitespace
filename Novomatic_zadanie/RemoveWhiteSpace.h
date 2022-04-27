#pragma once

/*
* function which delete whitespaces from begininning and end from string
* @author Mateusz Niepokoj
*/
template <typename T>
void RemoveWhiteSpace(T& s)
{
	auto iter = s.begin();
	while (isspace(*iter))
	{
		++iter;
	}
	s.erase(s.begin(), iter);


	iter = s.end() - 1;
	while (isspace(*iter))
	{
		--iter;
	}
	s.erase(++iter, s.end());
}