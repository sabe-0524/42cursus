/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 20:43:46 by sabe              #+#    #+#             */
/*   Updated: 2025/11/10 16:15:28 by abesouichir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : raw(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int num) : raw(num << this->fractBits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float num) : raw(roundf(num * (1 << this->fractBits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : raw(other.raw)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator = (const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->raw = other.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const
{
	return (this->raw);
}

void Fixed::setRawBits(const int raw)
{
	this->raw = raw;
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(this->raw) / (1 << this->fractBits));
}

int Fixed::toInt(void) const
{
	return (this->raw >> this->fractBits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixedObj)
{
    os << fixedObj.toFloat();
    return os;
}
