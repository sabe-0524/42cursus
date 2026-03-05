#include <deque>
#include <iostream>
#include <list>
#include <vector>
#include "easyfind.hpp"

int main(void)
{
	std::vector<int> numbers;
	numbers.push_back(10);
	numbers.push_back(20);
	numbers.push_back(30);
	numbers.push_back(40);

	try
	{
		std::vector<int>::iterator it = easyfind(numbers, 30);
		std::cout << "found in vector: " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "vector error: " << e.what() << std::endl;
	}

	try
	{
		easyfind(numbers, 99);
	}
	catch (const std::exception &e)
	{
		std::cout << "vector error: " << e.what() << std::endl;
	}

	std::list<int> values;
	values.push_back(-3);
	values.push_back(0);
	values.push_back(4);

	try
	{
		std::list<int>::iterator it = easyfind(values, 0);
		std::cout << "found in list: " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "list error: " << e.what() << std::endl;
	}

	const std::deque<int> fixedValues(3, 7);
	try
	{
		std::deque<int>::const_iterator it = easyfind(fixedValues, 7);
		std::cout << "found in const deque: " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "deque error: " << e.what() << std::endl;
	}

	return (0);
}
