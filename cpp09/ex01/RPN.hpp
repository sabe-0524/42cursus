#ifndef RPN_HPP
#define RPN_HPP

#include <list>
#include <stack>
#include <string>

class RPN
{
	public:
		RPN(void);
		RPN(const RPN &other);
		~RPN(void);
		RPN	&operator=(const RPN &other);

		long	evaluate(const std::string &expression) const;

	private:
		static bool	isOperator(const std::string &token);
		static long	applyOperation(long lhs, long rhs, const std::string &token);
};

#endif
