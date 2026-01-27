/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 00:00:00 by sabe              #+#    #+#             */
/*   Updated: 2026/01/27 22:02:05 by abesouichir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class Intern
{
	private:
		AForm	*createShrubberyCreationForm(const std::string &target) const;
		AForm	*createRobotomyRequestForm(const std::string &target) const;
		AForm	*createPresidentialPardonForm(const std::string &target) const;

	public:
		// Orthodox Canonical Form
		Intern(void);
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);
		~Intern(void);

		// Member functions
		AForm	*makeForm(const std::string &formName, const std::string &target) const;
};

#endif
