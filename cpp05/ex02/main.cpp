/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 00:00:00 by sabe              #+#    #+#             */
/*   Updated: 2026/01/27 22:02:05 by abesouichir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	std::cout << "========== Test 1: ShrubberyCreationForm ==========" << std::endl;
	try
	{
		Bureaucrat bob("Bob", 130);
		ShrubberyCreationForm shrub("home");
		std::cout << bob << std::endl;
		std::cout << shrub << std::endl;
		bob.signForm(shrub);
		bob.executeForm(shrub);
		std::cout << "Check home_shrubbery file!" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "========== Test 2: RobotomyRequestForm ==========" << std::endl;
	try
	{
		Bureaucrat alice("Alice", 40);
		RobotomyRequestForm robot("Marvin");
		std::cout << alice << std::endl;
		std::cout << robot << std::endl;
		alice.signForm(robot);
		alice.executeForm(robot);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "========== Test 3: PresidentialPardonForm ==========" << std::endl;
	try
	{
		Bureaucrat president("President", 1);
		PresidentialPardonForm pardon("Arthur Dent");
		std::cout << president << std::endl;
		std::cout << pardon << std::endl;
		president.signForm(pardon);
		president.executeForm(pardon);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "========== Test 4: Execute without signing ==========" << std::endl;
	try
	{
		Bureaucrat charlie("Charlie", 1);
		ShrubberyCreationForm shrub("garden");
		std::cout << charlie << std::endl;
		std::cout << shrub << std::endl;
		charlie.executeForm(shrub);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "========== Test 5: Grade too low to sign ==========" << std::endl;
	try
	{
		Bureaucrat dave("Dave", 150);
		ShrubberyCreationForm shrub("office");
		std::cout << dave << std::endl;
		std::cout << shrub << std::endl;
		dave.signForm(shrub);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "========== Test 6: Grade too low to execute ==========" << std::endl;
	try
	{
		Bureaucrat eve("Eve", 140);
		Bureaucrat frank("Frank", 1);
		ShrubberyCreationForm shrub("park");
		std::cout << eve << std::endl;
		std::cout << frank << std::endl;
		std::cout << shrub << std::endl;
		frank.signForm(shrub);
		eve.executeForm(shrub);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "========== Test 7: Presidential pardon - grade too low ==========" << std::endl;
	try
	{
		Bureaucrat grace("Grace", 10);
		PresidentialPardonForm pardon("Ford Prefect");
		std::cout << grace << std::endl;
		std::cout << pardon << std::endl;
		grace.signForm(pardon);
		grace.executeForm(pardon);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "========== Test 8: All forms with one bureaucrat ==========" << std::endl;
	try
	{
		Bureaucrat boss("Boss", 1);
		ShrubberyCreationForm shrub("headquarters");
		RobotomyRequestForm robot("Employee");
		PresidentialPardonForm pardon("Criminal");

		std::cout << boss << std::endl;
		std::cout << shrub << std::endl;
		std::cout << robot << std::endl;
		std::cout << pardon << std::endl;

		boss.signForm(shrub);
		boss.signForm(robot);
		boss.signForm(pardon);

		boss.executeForm(shrub);
		boss.executeForm(robot);
		boss.executeForm(pardon);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
