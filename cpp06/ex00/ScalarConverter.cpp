/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 00:00:00 by sabe              #+#    #+#             */
/*   Updated: 2026/01/28 23:14:38 by abesouichir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// Orthodox Canonical Form
ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter(void) {}

// Type detection functions
bool ScalarConverter::isChar(const std::string &literal)
{
	if (literal.length() == 1 && !std::isdigit(literal[0]))
		return true;
	if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
		return true;
	return false;
}

bool ScalarConverter::isInt(const std::string &literal)
{
	size_t i = 0;

	if (literal.empty())
		return false;
	if (literal[i] == '+' || literal[i] == '-')
		i++;
	if (i == literal.length())
		return false;
	while (i < literal.length())
	{
		if (!std::isdigit(literal[i]))
			return false;
		i++;
	}
	return true;
}

bool ScalarConverter::isFloat(const std::string &literal)
{
	if (literal == "-inff" || literal == "+inff" || literal == "nanf")
		return true;

	size_t len = literal.length();
	if (len < 2 || literal[len - 1] != 'f')
		return false;

	std::string withoutF = literal.substr(0, len - 1);
	size_t i = 0;
	bool hasDot = false;

	if (withoutF[i] == '+' || withoutF[i] == '-')
		i++;
	if (i == withoutF.length())
		return false;

	while (i < withoutF.length())
	{
		if (withoutF[i] == '.')
		{
			if (hasDot)
				return false;
			hasDot = true;
		}
		else if (!std::isdigit(withoutF[i]))
			return false;
		i++;
	}
	return hasDot;
}

bool ScalarConverter::isDouble(const std::string &literal)
{
	if (literal == "-inf" || literal == "+inf" || literal == "nan")
		return true;

	size_t i = 0;
	bool hasDot = false;

	if (literal[i] == '+' || literal[i] == '-')
		i++;
	if (i == literal.length())
		return false;

	while (i < literal.length())
	{
		if (literal[i] == '.')
		{
			if (hasDot)
				return false;
			hasDot = true;
		}
		else if (!std::isdigit(literal[i]))
			return false;
		i++;
	}
	return hasDot;
}

bool ScalarConverter::isPseudoLiteral(const std::string &literal)
{
	return (literal == "-inff" || literal == "+inff" || literal == "nanf" ||
			literal == "-inf" || literal == "+inf" || literal == "nan");
}

// Conversion and printing functions
void ScalarConverter::convertFromChar(char c)
{
	// char
	if (std::isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	// int
	std::cout << "int: " << static_cast<int>(c) << std::endl;

	// float
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;

	// double
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void ScalarConverter::convertFromInt(long value)
{
	// char
	if (value < 0 || value > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<int>(value)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;

	// int
	if (value < INT_MIN || value > INT_MAX)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;

	// float
	std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;

	// double
	std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
}

void ScalarConverter::convertFromFloat(float value)
{
	// char
	if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<int>(value)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;

	// int
	if (std::isnan(value) || std::isinf(value) || 
		value < static_cast<float>(INT_MIN) || value > static_cast<float>(INT_MAX))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;

	// float
	if (value == static_cast<long>(value) && !std::isinf(value) && 
		value >= -1000000 && value <= 1000000)
		std::cout << "float: " << value << ".0f" << std::endl;
	else
		std::cout << "float: " << value << "f" << std::endl;

	// double
	double dValue = static_cast<double>(value);
	if (dValue == static_cast<long>(dValue) && !std::isinf(dValue) &&
		dValue >= -1000000 && dValue <= 1000000)
		std::cout << "double: " << dValue << ".0" << std::endl;
	else
		std::cout << "double: " << dValue << std::endl;
}

void ScalarConverter::convertFromDouble(double value)
{
	// char
	if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<int>(value)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;

	// int
	if (std::isnan(value) || std::isinf(value) || 
		value < static_cast<double>(INT_MIN) || value > static_cast<double>(INT_MAX))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;

	// float
	float fValue = static_cast<float>(value);
	if (fValue == static_cast<long>(fValue) && !std::isinf(fValue) &&
		fValue >= -1000000 && fValue <= 1000000)
		std::cout << "float: " << fValue << ".0f" << std::endl;
	else
		std::cout << "float: " << fValue << "f" << std::endl;

	// double
	if (value == static_cast<long>(value) && !std::isinf(value) &&
		value >= -1000000 && value <= 1000000)
		std::cout << "double: " << value << ".0" << std::endl;
	else
		std::cout << "double: " << value << std::endl;
}

void ScalarConverter::printPseudoLiteral(const std::string &literal)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;

	if (literal == "nan" || literal == "nanf")
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (literal == "+inf" || literal == "+inff")
	{
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (literal == "-inf" || literal == "-inff")
	{
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

// Main convert function
void ScalarConverter::convert(const std::string &literal)
{
	if (literal.empty())
	{
		std::cout << "Error: empty input" << std::endl;
		return;
	}

	// Check for pseudo literals first
	if (isPseudoLiteral(literal))
	{
		printPseudoLiteral(literal);
		return;
	}

	// Detect type and convert
	if (isChar(literal))
	{
		char c;
		if (literal.length() == 1)
			c = literal[0];
		else
			c = literal[1]; // Extract char from 'c' format
		convertFromChar(c);
	}
	else if (isInt(literal))
	{
		char *endptr;
		long value = std::strtol(literal.c_str(), &endptr, 10);
		if (*endptr != '\0')
		{
			std::cout << "Error: invalid input" << std::endl;
			return;
		}
		convertFromInt(value);
	}
	else if (isFloat(literal))
	{
		std::string withoutF = literal.substr(0, literal.length() - 1);
		char *endptr;
		float value = std::strtof(withoutF.c_str(), &endptr);
		if (*endptr != '\0')
		{
			std::cout << "Error: invalid input" << std::endl;
			return;
		}
		convertFromFloat(value);
	}
	else if (isDouble(literal))
	{
		char *endptr;
		double value = std::strtod(literal.c_str(), &endptr);
		if (*endptr != '\0')
		{
			std::cout << "Error: invalid input" << std::endl;
			return;
		}
		convertFromDouble(value);
	}
	else
	{
		std::cout << "Error: invalid input" << std::endl;
	}
}
