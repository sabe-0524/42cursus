/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 00:00:00 by sabe              #+#    #+#             */
/*   Updated: 2026/01/28 23:14:38 by abesouichir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <cmath>
#include <iomanip>

class ScalarConverter
{
	private:
		// Orthodox Canonical Form - private to prevent instantiation
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter(void);

		// Helper functions
		static bool	isChar(const std::string &literal);
		static bool	isInt(const std::string &literal);
		static bool	isFloat(const std::string &literal);
		static bool	isDouble(const std::string &literal);
		static bool	isPseudoLiteral(const std::string &literal);

		static void	convertFromChar(char c);
		static void	convertFromInt(long value);
		static void	convertFromFloat(float value);
		static void	convertFromDouble(double value);
		static void	printPseudoLiteral(const std::string &literal);

	public:
		static void	convert(const std::string &literal);
};

#endif
