#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange
{
	private:
		std::map<std::string, double>	_exchangeRates;

		static bool		isValidDate(const std::string &date);
		static bool		parseValue(const std::string &token, double &value);
		static std::string	trim(const std::string &value);
		static std::string	formatNumber(double value);

	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &other);
		~BitcoinExchange(void);
		BitcoinExchange	&operator=(const BitcoinExchange &other);

		void	loadDatabase(const std::string &filename);
		void	processInputFile(const std::string &filename) const;
		double	getRateForDate(const std::string &date) const;
};

#endif
