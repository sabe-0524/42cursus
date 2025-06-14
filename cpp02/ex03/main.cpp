/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 21:04:26 by sabe              #+#    #+#             */
/*   Updated: 2025/06/14 14:53:14 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int main( void ) {
	Point a(6, 5);
	Point b(3, 1);
	Point c(9, 1);
	Point p1(5, 3);
	Point p2(10, 1);

	if (bsp(a, b, c, p1))
		std::cout << "p1 exists in triangle" << std::endl;
	else
		std::cout << "p1 doesn't exist in triangle" << std::endl;
	if (bsp(a, b, c, p2))
		std::cout << "p2 exists in triangle" << std::endl;
	else
		std::cout << "p2 doesn't exist in triangle" << std::endl;
	return 0;
}
