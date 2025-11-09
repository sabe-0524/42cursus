/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 21:59:50 by sabe              #+#    #+#             */
/*   Updated: 2025/11/09 22:12:40 by abesouichir      ###   ########.fr       */
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

Fixed Fixed::operator + (const Fixed &a) const
{
	Fixed result;

	result.setRawBits(this->getRawBits() + a.getRawBits());
	return (result);
}

Fixed Fixed::operator - (const Fixed &a) const
{
	Fixed result;

	result.setRawBits(this->getRawBits() - a.getRawBits());
	return (result);
}

Fixed Fixed::operator * (const Fixed &a) const
{
	Fixed result;

	int64_t tmp = (int64_t)this->getRawBits() * (int64_t)a.getRawBits();

	tmp >>= fractBits;
	result.setRawBits((int)tmp);
	return (result);
}

Fixed Fixed::operator / (const Fixed &a) const
{
	Fixed result;

	int64_t tmp = (int64_t)this->getRawBits() << fractBits;
	tmp /= a.getRawBits();
	result.setRawBits((int)tmp);
	return (result);
}

Fixed& Fixed::operator ++ (void)
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed Fixed::operator++(int dummy)
{
	(void)dummy;
	Fixed tmp = *this;
	this->setRawBits(this->getRawBits() + 1);
	return (tmp);
}

Fixed& Fixed::operator -- (void)
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed Fixed::operator--(int dummy)
{
	(void)dummy;
	Fixed tmp = *this;
	this->setRawBits(this->getRawBits() - 1);
	return (tmp);
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a >= b)
		return (a);
	else
		return (b);
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
