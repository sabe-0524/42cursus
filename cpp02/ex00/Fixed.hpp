/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 15:44:21 by sabe              #+#    #+#             */
/*   Updated: 2025/06/09 17:30:31 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

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
