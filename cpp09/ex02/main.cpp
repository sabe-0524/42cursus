#include <exception>
#include <iostream>

#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	PmergeMe	pmergeMe;

	try
	{
		pmergeMe.run(argc, argv);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}
