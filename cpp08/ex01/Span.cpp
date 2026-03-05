#include "Span.hpp"

#include <climits>

Span::Span(void) : _maxSize(0)
{
}

Span::Span(unsigned int n) : _maxSize(n)
{
}

Span::Span(Span const &other)
{
	*this = other;
}

Span::~Span(void)
{
}

Span &Span::operator=(Span const &other)
{
	if (this == &other)
		return (*this);
	_maxSize = other._maxSize;
	_numbers = other._numbers;
	return (*this);
}

void Span::addNumber(int number)
{
	if (_numbers.size() >= static_cast<std::size_t>(_maxSize))
		throw FullException();
	_numbers.push_back(number);
}

unsigned int Span::shortestSpan(void) const
{
	if (_numbers.size() < 2)
		throw NoSpanException();

	std::vector<int> sorted(_numbers);
	std::sort(sorted.begin(), sorted.end());

	unsigned int minSpan = UINT_MAX;
	for (std::size_t i = 1; i < sorted.size(); ++i)
	{
		unsigned int diff = static_cast<unsigned int>(
			static_cast<double>(sorted[i]) - static_cast<double>(sorted[i - 1])
		);
		if (diff < minSpan)
			minSpan = diff;
	}
	return (minSpan);
}

unsigned int Span::longestSpan(void) const
{
	if (_numbers.size() < 2)
		throw NoSpanException();

	std::vector<int>::const_iterator minIt = std::min_element(
		_numbers.begin(), _numbers.end()
	);
	std::vector<int>::const_iterator maxIt = std::max_element(
		_numbers.begin(), _numbers.end()
	);

	return (static_cast<unsigned int>(
		static_cast<double>(*maxIt) - static_cast<double>(*minIt)
	));
}

const char *Span::FullException::what(void) const throw()
{
	return ("Span is already full");
}

const char *Span::NoSpanException::what(void) const throw()
{
	return ("Not enough numbers stored to compute a span");
}
