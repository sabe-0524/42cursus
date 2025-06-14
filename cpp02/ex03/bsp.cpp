/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 14:27:12 by sabe              #+#    #+#             */
/*   Updated: 2025/06/14 14:57:12 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static bool is_positive(Point const &a, Point const &b, Point const &p)
{
	Fixed abx = b.getX() - a.getX();
    Fixed aby = b.getY() - a.getY();
    Fixed apx = p.getX() - a.getX();
    Fixed apy = p.getY() - a.getY();

	float cross = (abx * apy).toFloat()
		- (aby * apx).toFloat();

	return cross > 0;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	bool cross1, cross2, cross3;

	cross1 = is_positive(a, b, point);
	cross2 = is_positive(b, c, point);
	cross3 = is_positive(c, a, point);

	if (cross1 == cross2 && cross2 == cross3)
		return (true);
	else
		return (false);
}
