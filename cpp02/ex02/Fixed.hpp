/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 21:59:30 by sabe              #+#    #+#             */
/*   Updated: 2025/06/10 22:13:35 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int value;
		static const int fractBits = 8;

	public:
		Fixed();
		Fixed(int num);
		Fixed(float num);
		~Fixed();
		Fixed(const Fixed&);
		Fixed& operator = (const Fixed &other);
		bool operator < (const Fixed &a) const;
		bool operator > (const Fixed &a) const;
		bool operator <= (const Fixed &a) const;
		bool operator >= (const Fixed &a) const;
		bool operator == (const Fixed &a) const;
		bool operator != (const Fixed &a) const;
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream& operator << (std::ostream& os, const Fixed& fixedObj);

#endif
