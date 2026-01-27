/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 00:00:00 by sabe              #+#    #+#             */
/*   Updated: 2026/01/27 21:41:13 by abesouichir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	std::cout << "=== Test 1: Normal Form creation ===" << std::endl;
	try
	{
		Form form("Tax Form", 50, 25);
		std::cout << form << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== Test 2: Form with grade too high (0) ===" << std::endl;
	try
	{
		Form form("Invalid Form", 0, 25);
		std::cout << form << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== Test 3: Form with grade too low (151) ===" << std::endl;
	try
	{
		Form form("Invalid Form", 50, 151);
		std::cout << form << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== Test 4: Bureaucrat signs Form successfully ===" << std::endl;
	try
	{
		Bureaucrat bob("Bob", 40);
		Form form("Application Form", 50, 25);
		std::cout << bob << std::endl;
		std::cout << form << std::endl;
		bob.signForm(form);
		std::cout << form << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== Test 5: Bureaucrat fails to sign Form (grade too low) ===" << std::endl;
	try
	{
		Bureaucrat alice("Alice", 100);
		Form form("Confidential Form", 50, 25);
		std::cout << alice << std::endl;
		std::cout << form << std::endl;
		alice.signForm(form);
		std::cout << form << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== Test 6: Bureaucrat with exact grade to sign ===" << std::endl;
	try
	{
		Bureaucrat charlie("Charlie", 50);
		Form form("Border Case Form", 50, 25);
		std::cout << charlie << std::endl;
		std::cout << form << std::endl;
		charlie.signForm(form);
		std::cout << form << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== Test 7: Form beSigned directly ===" << std::endl;
	try
	{
		Bureaucrat dave("Dave", 1);
		Form form("Top Secret Form", 1, 1);
		std::cout << dave << std::endl;
		std::cout << form << std::endl;
		form.beSigned(dave);
		std::cout << "After beSigned: " << form << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== Test 8: Form beSigned throws exception ===" << std::endl;
	try
	{
		Bureaucrat eve("Eve", 150);
		Form form("High Security Form", 1, 1);
		std::cout << eve << std::endl;
		std::cout << form << std::endl;
		form.beSigned(eve);
		std::cout << "After beSigned: " << form << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== Test 9: Copy constructor and assignment ===" << std::endl;
	try
	{
		Form form1("Original Form", 50, 25);
		Form form2(form1);
		std::cout << "Form1: " << form1 << std::endl;
		std::cout << "Form2 (copy): " << form2 << std::endl;

		Bureaucrat frank("Frank", 40);
		frank.signForm(form1);
		std::cout << "Form1 after signing: " << form1 << std::endl;
		std::cout << "Form2 (unchanged): " << form2 << std::endl;

		form2 = form1;
		std::cout << "Form2 after assignment: " << form2 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
