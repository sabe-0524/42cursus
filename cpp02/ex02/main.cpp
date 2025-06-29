/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 21:04:26 by sabe              #+#    #+#             */
/*   Updated: 2025/06/29 13:11:33 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main() {
    std::cout << "\n--- Constructors and Assignment ---\n";
    Fixed a;
    Fixed const b(10);
    Fixed const c(42.42f);
    Fixed const d(b);

    a = Fixed(1234.4321f);

    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;

    std::cout << "\n--- toInt() Conversion ---\n";
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;

    std::cout << "\n--- Comparison Operators ---\n";
    if (b < c)  std::cout << "b is less than c" << std::endl;
    if (c > b)  std::cout << "c is greater than b" << std::endl;
    if (b <= d) std::cout << "b is less than or equal to d" << std::endl;
    if (d >= b) std::cout << "d is greater than or equal to b" << std::endl;
    if (b == d) std::cout << "b is equal to d" << std::endl;
    if (a != b) std::cout << "a is not equal to b" << std::endl;

    std::cout << "\n--- Arithmetic Operators ---\n";
    std::cout << "b + c = " << (b + c) << std::endl;
    std::cout << "c - b = " << (c - b) << std::endl;
    std::cout << "b * c = " << (b * c) << std::endl;
    std::cout << "c / b = " << (c / b) << std::endl;

    std::cout << "\n--- Increment & Decrement ---\n";
    Fixed x;
    std::cout << "x = " << x << std::endl;
    std::cout << "++x = " << ++x << std::endl;
    std::cout << "x++ = " << x++ << std::endl;
    std::cout << "x = " << x << std::endl;
    std::cout << "--x = " << --x << std::endl;
    std::cout << "x-- = " << x-- << std::endl;
    std::cout << "x = " << x << std::endl;

    std::cout << "\n--- min() and max() ---\n";
    const Fixed &minAB = Fixed::min(a, b);
    const Fixed &minCD = Fixed::min(c, d);
    const Fixed &maxAB = Fixed::max(a, b);
    const Fixed &maxCD = Fixed::max(c, d);

    std::cout << "min(a, b) = " << minAB << std::endl;
    std::cout << "min(c, d) = " << minCD << std::endl;
    std::cout << "max(a, b) = " << maxAB << std::endl;
    std::cout << "max(c, d) = " << maxCD << std::endl;

    return 0;
}

