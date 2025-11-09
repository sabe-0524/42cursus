/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 14:27:12 by sabe              #+#    #+#             */
/*   Updated: 2025/11/09 22:12:41 by abesouichir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed calculateSign(Point const &p1, Point const &p2, Point const &p3)
{
	return ((p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) 
		- (p2.getX() - p3.getX()) * (p1.getY() - p3.getY()));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed d1, d2, d3;
	bool has_neg, has_pos;

	d1 = calculateSign(point, a, b);
	d2 = calculateSign(point, b, c);
	d3 = calculateSign(point, c, a);

	if (d1.getRawBits() == 0 || d2.getRawBits() == 0 || d3.getRawBits() == 0)
		return (false);

	has_neg = (d1.getRawBits() < 0) || (d2.getRawBits() < 0) || (d3.getRawBits() < 0);
	has_pos = (d1.getRawBits() > 0) || (d2.getRawBits() > 0) || (d3.getRawBits() > 0);

	return (!(has_neg && has_pos));
}
