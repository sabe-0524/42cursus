#include <iostream>
#include <vector>

#include "Span.hpp"

int main(void)
{
	Span sp(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	try
	{
		sp.addNumber(42);
	}
	catch (const std::exception &e)
	{
		std::cout << "addNumber error: " << e.what() << std::endl;
	}

	Span big(10000);
	std::vector<int> values;
	for (int i = 0; i < 10000; ++i)
		values.push_back(i * 10);
	big.addRange(values.begin(), values.end());
	std::cout << "big shortest span: " << big.shortestSpan() << std::endl;
	std::cout << "big longest span: " << big.longestSpan() << std::endl;

	Span tooSmall(3);
	try
	{
		tooSmall.addRange(values.begin(), values.begin() + 4);
	}
	catch (const std::exception &e)
	{
		std::cout << "addRange error: " << e.what() << std::endl;
	}

	Span empty(2);
	try
	{
		std::cout << empty.shortestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "shortestSpan error: " << e.what() << std::endl;
	}

	return (0);
}
