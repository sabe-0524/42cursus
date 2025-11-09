/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 15:44:21 by sabe              #+#    #+#             */
/*   Updated: 2025/11/09 22:12:40 by abesouichir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int raw;
		static const int fractBits = 8;

	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed&);
		Fixed& operator = (const Fixed &other);
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif
