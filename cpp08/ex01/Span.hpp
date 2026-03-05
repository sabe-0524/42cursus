#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <cstddef>
#include <exception>
#include <vector>

class Span
{
	private:
		unsigned int		_maxSize;
		std::vector<int>	_numbers;

	public:
		Span(void);
		explicit Span(unsigned int n);
		Span(Span const &other);
		~Span(void);
		Span &operator=(Span const &other);

		void			addNumber(int number);
		template <typename InputIterator>
		void			addRange(InputIterator first, InputIterator last);
		unsigned int	shortestSpan(void) const;
		unsigned int	longestSpan(void) const;

		class FullException : public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};

		class NoSpanException : public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};
};

template <typename InputIterator>
void Span::addRange(InputIterator first, InputIterator last)
{
	std::vector<int> values(first, last);

	if (_numbers.size() + values.size() > static_cast<std::size_t>(_maxSize))
		throw FullException();
	_numbers.insert(_numbers.end(), values.begin(), values.end());
}

#endif
