/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 00:00:00 by sabe              #+#    #+#             */
/*   Updated: 2026/01/27 22:02:05 by abesouichir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// Orthodox Canonical Form
Intern::Intern(void)
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &other)
{
	std::cout << "Intern copy constructor called" << std::endl;
	(void)other;
}

Intern &Intern::operator=(const Intern &other)
{
	std::cout << "Intern copy assignment operator called" << std::endl;
	(void)other;
	return *this;
}

Intern::~Intern(void)
{
	std::cout << "Intern destructor called" << std::endl;
}

// Private helper functions
AForm *Intern::createShrubberyCreationForm(const std::string &target) const
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomyRequestForm(const std::string &target) const
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidentialPardonForm(const std::string &target) const
{
	return new PresidentialPardonForm(target);
}

// Member functions
AForm *Intern::makeForm(const std::string &formName, const std::string &target) const
{
	const std::string formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm *(Intern::*formCreators[3])(const std::string &) const = {
		&Intern::createShrubberyCreationForm,
		&Intern::createRobotomyRequestForm,
		&Intern::createPresidentialPardonForm
	};

	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			AForm *form = (this->*formCreators[i])(target);
			std::cout << "Intern creates " << form->getName() << std::endl;
			return form;
		}
	}

	std::cout << "Error: Form name \"" << formName << "\" does not exist." << std::endl;
	return NULL;
}
