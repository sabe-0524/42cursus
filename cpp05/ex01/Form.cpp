/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 00:00:00 by sabe              #+#    #+#             */
/*   Updated: 2026/01/27 21:41:13 by abesouichir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

// Orthodox Canonical Form
Form::Form(void)
	: _name("default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	std::cout << "Form parameterized constructor called" << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &other)
	: _name(other._name), _isSigned(other._isSigned),
	  _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &other)
{
	std::cout << "Form copy assignment operator called" << std::endl;
	if (this != &other)
	{
		// _name, _gradeToSign, _gradeToExecute are const, so we cannot assign them
		this->_isSigned = other._isSigned;
	}
	return *this;
}

Form::~Form(void)
{
	std::cout << "Form destructor called" << std::endl;
}

// Getters
const std::string &Form::getName(void) const
{
	return this->_name;
}

bool Form::getIsSigned(void) const
{
	return this->_isSigned;
}

int Form::getGradeToSign(void) const
{
	return this->_gradeToSign;
}

int Form::getGradeToExecute(void) const
{
	return this->_gradeToExecute;
}

// Member functions
void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw GradeTooLowException();
	this->_isSigned = true;
}

// Exception classes
const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

// Insertion operator overload
std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << "Form: " << form.getName()
	   << ", Signed: " << (form.getIsSigned() ? "yes" : "no")
	   << ", Grade to sign: " << form.getGradeToSign()
	   << ", Grade to execute: " << form.getGradeToExecute();
	return os;
}
