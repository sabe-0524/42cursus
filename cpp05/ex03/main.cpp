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
#include "Intern.hpp"

int main(void)
{
	std::cout << "========== Test 1: Intern creates RobotomyRequestForm ==========" << std::endl;
	{
		Intern someRandomIntern;
		AForm *rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		if (rrf)
		{
			std::cout << *rrf << std::endl;
			delete rrf;
		}
	}

	std::cout << std::endl << "========== Test 2: Intern creates ShrubberyCreationForm ==========" << std::endl;
	{
		Intern intern;
		AForm *form;
		form = intern.makeForm("shrubbery creation", "garden");
		if (form)
		{
			std::cout << *form << std::endl;
			delete form;
		}
	}

	std::cout << std::endl << "========== Test 3: Intern creates PresidentialPardonForm ==========" << std::endl;
	{
		Intern intern;
		AForm *form;
		form = intern.makeForm("presidential pardon", "Ford Prefect");
		if (form)
		{
			std::cout << *form << std::endl;
			delete form;
		}
	}

	std::cout << std::endl << "========== Test 4: Intern creates unknown form ==========" << std::endl;
	{
		Intern intern;
		AForm *form;
		form = intern.makeForm("unknown form", "target");
		if (form)
		{
			std::cout << *form << std::endl;
			delete form;
		}
		else
		{
			std::cout << "Form creation failed (returned NULL)" << std::endl;
		}
	}

	std::cout << std::endl << "========== Test 5: Full workflow with Intern ==========" << std::endl;
	{
		Intern intern;
		Bureaucrat boss("Boss", 1);
		AForm *form;

		form = intern.makeForm("presidential pardon", "Arthur Dent");
		if (form)
		{
			std::cout << *form << std::endl;
			boss.signForm(*form);
			boss.executeForm(*form);
			delete form;
		}
	}

	std::cout << std::endl << "========== Test 6: Multiple forms created by Intern ==========" << std::endl;
	{
		Intern intern;
		Bureaucrat bureaucrat("John", 5);
		AForm *forms[3];

		forms[0] = intern.makeForm("shrubbery creation", "home");
		forms[1] = intern.makeForm("robotomy request", "Marvin");
		forms[2] = intern.makeForm("presidential pardon", "Zaphod");

		for (int i = 0; i < 3; i++)
		{
			if (forms[i])
			{
				std::cout << *forms[i] << std::endl;
				bureaucrat.signForm(*forms[i]);
				bureaucrat.executeForm(*forms[i]);
				delete forms[i];
			}
		}
	}

	return 0;
}
