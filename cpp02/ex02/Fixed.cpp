/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 21:59:50 by sabe              #+#    #+#             */
/*   Updated: 2025/06/10 22:14:36 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int num) : value(num << 8)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float num) : value(round(num * (1 << 8)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : value(other.value)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator = (const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->value = other.getRawBits();
	return (*this);
}

bool Fixed::operator < (const Fixed &a) const
{
	return (this->getRawBits() < a.getRawBits());
}

bool Fixed::operator > (const Fixed &a) const
{
	return (this->getRawBits() > a.getRawBits());
}

bool Fixed::operator <= (const Fixed &a) const
{
	return (this->getRawBits() <= a.getRawBits());
}

bool Fixed::operator >= (const Fixed &a) const
{
	return (this->getRawBits() >= a.getRawBits());
}

bool Fixed::operator == (const Fixed &a) const
{
	return (this->getRawBits() == a.getRawBits());
}

bool Fixed::operator != (const Fixed &a) const
{
	return (this->getRawBits() != a.getRawBits());
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(this->value) / (1 << 8));
}

int Fixed::toInt(void) const
{
	return (this->value >> 8);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixedObj)
{
    os << fixedObj.toFloat();
    return os;
}
