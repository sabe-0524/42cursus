/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 00:00:00 by sabe              #+#    #+#             */
/*   Updated: 2026/01/27 00:00:00 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << "=== Test 1: Normal Bureaucrat creation ===" << std::endl;
	try
	{
		Bureaucrat bob("Bob", 50);
		std::cout << bob << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== Test 2: Grade too high (0) ===" << std::endl;
	try
	{
		Bureaucrat alice("Alice", 0);
		std::cout << alice << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== Test 3: Grade too low (151) ===" << std::endl;
	try
	{
		Bureaucrat charlie("Charlie", 151);
		std::cout << charlie << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== Test 4: Increment grade ===" << std::endl;
	try
	{
		Bureaucrat dave("Dave", 5);
		std::cout << dave << std::endl;
		dave.incrementGrade();
		std::cout << "After increment: " << dave << std::endl;
		dave.incrementGrade();
		std::cout << "After increment: " << dave << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== Test 5: Decrement grade ===" << std::endl;
	try
	{
		Bureaucrat eve("Eve", 148);
		std::cout << eve << std::endl;
		eve.decrementGrade();
		std::cout << "After decrement: " << eve << std::endl;
		eve.decrementGrade();
		std::cout << "After decrement: " << eve << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== Test 6: Increment at highest grade (1) ===" << std::endl;
	try
	{
		Bureaucrat frank("Frank", 1);
		std::cout << frank << std::endl;
		frank.incrementGrade();
		std::cout << "After increment: " << frank << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== Test 7: Decrement at lowest grade (150) ===" << std::endl;
	try
	{
		Bureaucrat grace("Grace", 150);
		std::cout << grace << std::endl;
		grace.decrementGrade();
		std::cout << "After decrement: " << grace << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== Test 8: Copy constructor ===" << std::endl;
	try
	{
		Bureaucrat henry("Henry", 42);
		std::cout << "Original: " << henry << std::endl;
		Bureaucrat henryCopy(henry);
		std::cout << "Copy: " << henryCopy << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== Test 9: Copy assignment operator ===" << std::endl;
	try
	{
		Bureaucrat ivan("Ivan", 100);
		Bureaucrat jane("Jane", 50);
		std::cout << "Before assignment:" << std::endl;
		std::cout << "Ivan: " << ivan << std::endl;
		std::cout << "Jane: " << jane << std::endl;
		ivan = jane;
		std::cout << "After ivan = jane:" << std::endl;
		std::cout << "Ivan: " << ivan << std::endl;
		std::cout << "Jane: " << jane << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
