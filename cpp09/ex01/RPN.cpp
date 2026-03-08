#include "RPN.hpp"

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
		return (lhs + rhs);
	if (token == "-")
		return (lhs - rhs);
	if (token == "*")
		return (lhs * rhs);
	if (rhs == 0)
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
		if (token.length() == 1 && std::isdigit(token[0]))
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
