#include "RPN.hpp"

#include <climits>
#include <cctype>
#include <cstdlib>
#include <sstream>
#include <stdexcept>

RPN::RPN(void)
{
}

RPN::RPN(const RPN &other)
{
	(void)other;
}

RPN::~RPN(void)
{
}

RPN	&RPN::operator=(const RPN &other)
{
	(void)other;
	return (*this);
}

bool	RPN::isOperator(const std::string &token)
{
	return (token == "+" || token == "-" || token == "*" || token == "/");
}

long	RPN::applyOperation(long lhs, long rhs, const std::string &token)
{
	if (token == "+")
	{
		if ((rhs > 0 && lhs > LONG_MAX - rhs)
			|| (rhs < 0 && lhs < LONG_MIN - rhs))
			throw std::runtime_error("Error");
		return (lhs + rhs);
	}
	if (token == "-")
	{
		if ((rhs > 0 && lhs < LONG_MIN + rhs)
			|| (rhs < 0 && lhs > LONG_MAX + rhs))
			throw std::runtime_error("Error");
		return (lhs - rhs);
	}
	if (token == "*")
	{
		if (lhs > 0)
		{
			if ((rhs > 0 && lhs > LONG_MAX / rhs)
				|| (rhs < 0 && rhs < LONG_MIN / lhs))
				throw std::runtime_error("Error");
		}
		else if (lhs < 0)
		{
			if ((rhs > 0 && lhs < LONG_MIN / rhs)
				|| (rhs < 0 && lhs != 0 && rhs < LONG_MAX / lhs))
				throw std::runtime_error("Error");
		}
		return (lhs * rhs);
	}
	if (rhs == 0)
		throw std::runtime_error("Error");
	if (lhs == LONG_MIN && rhs == -1)
		throw std::runtime_error("Error");
	return (lhs / rhs);
}

long	RPN::evaluate(const std::string &expression) const
{
	std::istringstream					stream(expression);
	std::string							token;
	std::stack<long, std::list<long> >	values;

	while (stream >> token)
	{
		if (token.length() == 1
			&& std::isdigit(static_cast<unsigned char>(token[0])))
		{
			values.push(token[0] - '0');
			continue ;
		}
		if (!isOperator(token) || values.size() < 2)
			throw std::runtime_error("Error");
		long rhs = values.top();
		values.pop();
		long lhs = values.top();
		values.pop();
		values.push(applyOperation(lhs, rhs, token));
	}
	if (values.size() != 1)
		throw std::runtime_error("Error");
	return (values.top());
}
