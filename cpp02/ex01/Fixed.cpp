/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 20:43:46 by sabe              #+#    #+#             */
/*   Updated: 2025/11/08 11:22:26 by abesouichir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int num) : value(num << this->fractBits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float num) : value(roundf(num * (1 << this->fractBits)))
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

int Fixed::getRawBits(void) const
{
	return (this->value);
}

void Fixed::setRawBits(const int raw)
{
	this->value = raw;
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(this->value) / (1 << this->fractBits));
}

int Fixed::toInt(void) const
{
	return (this->value >> this->fractBits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixedObj)
{
    os << fixedObj.toFloat();
    return os;
}
