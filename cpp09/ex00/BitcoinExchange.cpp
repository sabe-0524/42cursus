#include "BitcoinExchange.hpp"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

namespace
{
	bool	isLeapYear(int year)
	{
		if (year % 400 == 0)
			return (true);
		if (year % 100 == 0)
			return (false);
		return (year % 4 == 0);
	}
}

BitcoinExchange::BitcoinExchange(void)
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}

BitcoinExchange::~BitcoinExchange(void)
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this == &other)
		return (*this);
	_exchangeRates = other._exchangeRates;
	return (*this);
}

std::string	BitcoinExchange::trim(const std::string &value)
{
	std::string::size_type	start;
	std::string::size_type	end;

	start = value.find_first_not_of(" \t\r\n");
	if (start == std::string::npos)
		return ("");
	end = value.find_last_not_of(" \t\r\n");
	return (value.substr(start, end - start + 1));
}

bool	BitcoinExchange::isValidDate(const std::string &date)
{
	static const int	daysInMonth[12] = {
		31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
	};
	std::istringstream	stream(date);
	int					year;
	int					month;
	int					day;
	char				dash1;
	char				dash2;
	int					maxDay;

	if (date.length() != 10)
		return (false);
	stream >> year >> dash1 >> month >> dash2 >> day;
	if (stream.fail() || !stream.eof() || dash1 != '-' || dash2 != '-')
		return (false);
	if (month < 1 || month > 12 || day < 1)
		return (false);
	maxDay = daysInMonth[month - 1];
	if (month == 2 && isLeapYear(year))
		maxDay = 29;
	return (day <= maxDay);
}

bool	BitcoinExchange::parseValue(const std::string &token, double &value)
{
	std::istringstream	stream(token);

	stream >> value;
	if (stream.fail() || !stream.eof())
		return (false);
	return (true);
}

std::string	BitcoinExchange::formatNumber(double value)
{
	std::ostringstream	stream;
	std::string			formatted;
	std::string::size_type	dot;

	stream.setf(std::ios::fixed);
	stream.precision(10);
	stream << value;
	formatted = stream.str();
	dot = formatted.find('.');
	if (dot == std::string::npos)
		return (formatted);
	while (!formatted.empty() && formatted[formatted.length() - 1] == '0')
		formatted.erase(formatted.length() - 1);
	if (!formatted.empty() && formatted[formatted.length() - 1] == '.')
		formatted.erase(formatted.length() - 1);
	if (formatted.empty())
		return ("0");
	return (formatted);
}

void	BitcoinExchange::loadDatabase(const std::string &filename)
{
	std::ifstream	file(filename.c_str());
	std::string		line;
	bool			firstLine;

	if (!file.is_open())
		throw std::runtime_error("Error: could not open database.");
	firstLine = true;
	while (std::getline(file, line))
	{
		std::string::size_type	comma;
		std::string				date;
		std::string				rateToken;
		double					rate;

		if (firstLine && trim(line) == "date,exchange_rate")
		{
			firstLine = false;
			continue ;
		}
		firstLine = false;
		comma = line.find(',');
		if (comma == std::string::npos)
			throw std::runtime_error("Error: invalid database.");
		date = trim(line.substr(0, comma));
		rateToken = trim(line.substr(comma + 1));
		if (!isValidDate(date) || !parseValue(rateToken, rate))
			throw std::runtime_error("Error: invalid database.");
		_exchangeRates[date] = rate;
	}
}

double	BitcoinExchange::getRateForDate(const std::string &date) const
{
	std::map<std::string, double>::const_iterator	it;

	it = _exchangeRates.lower_bound(date);
	if (it != _exchangeRates.end() && it->first == date)
		return (it->second);
	if (it == _exchangeRates.begin())
		throw std::runtime_error("Error: bad input => " + date);
	if (it == _exchangeRates.end() || it->first != date)
		--it;
	return (it->second);
}

void	BitcoinExchange::processInputFile(const std::string &filename) const
{
	std::ifstream	file(filename.c_str());
	std::string		line;
	bool			firstLine;

	if (!file.is_open())
		throw std::runtime_error("Error: could not open file.");
	firstLine = true;
	while (std::getline(file, line))
	{
		std::string::size_type	separator;
		std::string				date;
		std::string				valueToken;
		double					value;
		double					rate;

		if (firstLine && trim(line) == "date | value")
		{
			firstLine = false;
			continue ;
		}
		firstLine = false;
		if (line.empty())
			continue ;
		separator = line.find('|');
		if (separator == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue ;
		}
		date = trim(line.substr(0, separator));
		valueToken = trim(line.substr(separator + 1));
		if (!isValidDate(date) || !parseValue(valueToken, value))
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue ;
		}
		if (value < 0.0)
		{
			std::cout << "Error: not a positive number." << std::endl;
			continue ;
		}
		if (value > 1000.0)
		{
			std::cout << "Error: too large a number." << std::endl;
			continue ;
		}
		try
		{
			rate = getRateForDate(date);
			std::cout << date << " => " << formatNumber(value)
				<< " = " << formatNumber(value * rate) << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}
