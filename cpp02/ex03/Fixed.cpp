/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 21:59:50 by sabe              #+#    #+#             */
/*   Updated: 2025/11/10 16:15:28 by abesouichir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : raw(0)
{
}

Fixed::Fixed(int num) : raw(num << this->fractBits)
{
}

Fixed::Fixed(float num) : raw(roundf(num * (1 << this->fractBits)))
{
}

Fixed::~Fixed(void)
{
}

Fixed::Fixed(const Fixed& other) : raw(other.raw)
{
}

Fixed& Fixed::operator = (const Fixed &other)
{
	if (this != &other)
		this->raw = other.getRawBits();
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
