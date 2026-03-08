#include "PmergeMe.hpp"

#include <climits>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>

namespace
{
	std::vector<PairData>::iterator	findVectorPairPositionById(
		std::vector<PairData> &chain,
		std::size_t maxId
	)
	{
		std::vector<PairData>::iterator	it;

		it = chain.begin();
		while (it != chain.end())
		{
			if (it->id == maxId)
				return (it);
			++it;
		}
		return (chain.end());
	}

	std::deque<PairData>::iterator	findDequePairPositionById(
		std::deque<PairData> &chain,
		std::size_t maxId
	)
	{
		std::deque<PairData>::iterator	it;

		it = chain.begin();
		while (it != chain.end())
		{
			if (it->id == maxId)
				return (it);
			++it;
		}
		return (chain.end());
	}

	std::vector<PairData>::iterator	upperBoundVectorPairs(
		std::vector<PairData> &chain,
		int value,
		std::vector<PairData>::iterator end
	)
	{
		std::vector<PairData>::iterator	left;
		std::vector<PairData>::iterator	right;
		std::vector<PairData>::iterator	middle;

		left = chain.begin();
		right = end;
		while (left < right)
		{
			middle = left + (right - left) / 2;
			if (middle->larger <= value)
				left = middle + 1;
			else
				right = middle;
		}
		return (left);
	}

	std::deque<PairData>::iterator	upperBoundDequePairs(
		std::deque<PairData> &chain,
		int value,
		std::deque<PairData>::iterator end
	)
	{
		std::deque<PairData>::iterator	left;
		std::deque<PairData>::iterator	right;
		std::deque<PairData>::iterator	middle;

		left = chain.begin();
		right = end;
		while (left < right)
		{
			middle = left + (right - left) / 2;
			if (middle->larger <= value)
				left = middle + 1;
			else
				right = middle;
		}
		return (left);
	}

	std::vector<OutputValue>::iterator	findVectorValuePartner(
		std::vector<OutputValue> &chain,
		std::size_t maxId
	)
	{
		std::vector<OutputValue>::iterator	it;

		it = chain.begin();
		while (it != chain.end())
		{
			if (it->isMainChain && it->pairId == maxId)
				return (it);
			++it;
		}
		return (chain.end());
	}

	std::deque<OutputValue>::iterator	findDequeValuePartner(
		std::deque<OutputValue> &chain,
		std::size_t maxId
	)
	{
		std::deque<OutputValue>::iterator	it;

		it = chain.begin();
		while (it != chain.end())
		{
			if (it->isMainChain && it->pairId == maxId)
				return (it);
			++it;
		}
		return (chain.end());
	}

	std::vector<OutputValue>::iterator	upperBoundVectorValues(
		std::vector<OutputValue> &chain,
		int value,
		std::vector<OutputValue>::iterator end
	)
	{
		std::vector<OutputValue>::iterator	left;
		std::vector<OutputValue>::iterator	right;
		std::vector<OutputValue>::iterator	middle;

		left = chain.begin();
		right = end;
		while (left < right)
		{
			middle = left + (right - left) / 2;
			if (middle->value <= value)
				left = middle + 1;
			else
				right = middle;
		}
		return (left);
	}

	std::deque<OutputValue>::iterator	upperBoundDequeValues(
		std::deque<OutputValue> &chain,
		int value,
		std::deque<OutputValue>::iterator end
	)
	{
		std::deque<OutputValue>::iterator	left;
		std::deque<OutputValue>::iterator	right;
		std::deque<OutputValue>::iterator	middle;

		left = chain.begin();
		right = end;
		while (left < right)
		{
			middle = left + (right - left) / 2;
			if (middle->value <= value)
				left = middle + 1;
			else
				right = middle;
		}
		return (left);
	}
}

PmergeMe::PmergeMe(void) : _vectorTimeUs(0.0), _dequeTimeUs(0.0)
{
}

PmergeMe::PmergeMe(int argc, char **argv) : _vectorTimeUs(0.0), _dequeTimeUs(0.0)
{
	int	i;
	int	value;

	if (argc < 2)
		throw std::runtime_error("Error");
	i = 1;
	while (i < argc)
	{
		if (!parsePositiveInt(argv[i], value))
			throw std::runtime_error("Error");
		_vectorInput.push_back(value);
		_dequeInput.push_back(value);
		++i;
	}
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	*this = other;
}

PmergeMe::~PmergeMe(void)
{
}

PmergeMe	&PmergeMe::operator=(const PmergeMe &other)
{
	if (this == &other)
		return (*this);
	_vectorInput = other._vectorInput;
	_dequeInput = other._dequeInput;
	_sortedVector = other._sortedVector;
	_sortedDeque = other._sortedDeque;
	_vectorTimeUs = other._vectorTimeUs;
	_dequeTimeUs = other._dequeTimeUs;
	return (*this);
}

bool	PmergeMe::parsePositiveInt(const char *token, int &value)
{
	std::istringstream	stream(token);
	long				parsed;
	char				extra;

	stream >> parsed;
	if (stream.fail() || stream.get(extra))
		return (false);
	if (parsed <= 0 || parsed > INT_MAX)
		return (false);
	value = static_cast<int>(parsed);
	return (true);
}

std::vector<std::size_t>	PmergeMe::buildInsertionOrder(std::size_t size)
{
	std::vector<std::size_t>	order;
	std::size_t				previousJacob;
	std::size_t				jacobPrev;
	std::size_t				jacobCurr;

	if (size == 0)
		return (order);
	previousJacob = 1;
	jacobPrev = 1;
	jacobCurr = 3;
	while (previousJacob <= size)
	{
		std::size_t	upper;
		std::size_t	index;

		upper = jacobCurr - 1;
		if (upper > size)
			upper = size;
		index = upper;
		while (index >= previousJacob)
		{
			order.push_back(index - 1);
			if (index == previousJacob)
				break ;
			--index;
		}
		previousJacob = jacobCurr;
		jacobCurr = jacobCurr + (2 * jacobPrev);
		jacobPrev = previousJacob;
	}
	return (order);
}

PairData	PmergeMe::findPairByMaxId(
	const std::vector<PairRelation> &relations,
	std::size_t maxId
)
{
	std::size_t	i;

	i = 0;
	while (i < relations.size())
	{
		if (relations[i].maxId == maxId)
			return (relations[i].minPair);
		++i;
	}
	throw std::runtime_error("Error");
}

PairData	PmergeMe::findPairByMaxId(
	const std::deque<PairRelation> &relations,
	std::size_t maxId
)
{
	std::size_t	i;

	i = 0;
	while (i < relations.size())
	{
		if (relations[i].maxId == maxId)
			return (relations[i].minPair);
		++i;
	}
	throw std::runtime_error("Error");
}

void	PmergeMe::insertVectorPendingPairs(
	std::vector<PairData> &chain,
	const std::vector<PendingPair> &pending
) const
{
	std::vector<std::size_t>	order;
	std::size_t				i;

	order = buildInsertionOrder(pending.size());
	i = 0;
	while (i < order.size())
	{
		const PendingPair						&current = pending[order[i]];
		std::vector<PairData>::iterator			partner;
		std::vector<PairData>::iterator			position;

		partner = findVectorPairPositionById(chain, current.maxId);
		position = upperBoundVectorPairs(chain, current.minPair.larger, partner);
		chain.insert(position, current.minPair);
		++i;
	}
}

void	PmergeMe::insertDequePendingPairs(
	std::deque<PairData> &chain,
	const std::deque<PendingPair> &pending
) const
{
	std::vector<std::size_t>	order;
	std::size_t				i;

	order = buildInsertionOrder(pending.size());
	i = 0;
	while (i < order.size())
	{
		const PendingPair						&current = pending[order[i]];
		std::deque<PairData>::iterator			partner;
		std::deque<PairData>::iterator			position;

		partner = findDequePairPositionById(chain, current.maxId);
		position = upperBoundDequePairs(chain, current.minPair.larger, partner);
		chain.insert(position, current.minPair);
		++i;
	}
}

void	PmergeMe::insertVectorPendingValues(
	std::vector<OutputValue> &chain,
	const std::vector<PendingValue> &pending
) const
{
	std::vector<std::size_t>	order;
	std::size_t				i;

	order = buildInsertionOrder(pending.size());
	i = 0;
	while (i < order.size())
	{
		const PendingValue						&current = pending[order[i]];
		OutputValue								node;
		std::vector<OutputValue>::iterator		partner;
		std::vector<OutputValue>::iterator		position;

		node.value = current.value;
		node.pairId = 0;
		node.isMainChain = false;
		partner = findVectorValuePartner(chain, current.maxId);
		position = upperBoundVectorValues(chain, current.value, partner);
		chain.insert(position, node);
		++i;
	}
}

void	PmergeMe::insertDequePendingValues(
	std::deque<OutputValue> &chain,
	const std::deque<PendingValue> &pending
) const
{
	std::vector<std::size_t>	order;
	std::size_t				i;

	order = buildInsertionOrder(pending.size());
	i = 0;
	while (i < order.size())
	{
		const PendingValue						&current = pending[order[i]];
		OutputValue								node;
		std::deque<OutputValue>::iterator		partner;
		std::deque<OutputValue>::iterator		position;

		node.value = current.value;
		node.pairId = 0;
		node.isMainChain = false;
		partner = findDequeValuePartner(chain, current.maxId);
		position = upperBoundDequeValues(chain, current.value, partner);
		chain.insert(position, node);
		++i;
	}
}

void	PmergeMe::sortVectorPairs(std::vector<PairData> &pairs)
{
	std::vector<PairData>	maxima;
	std::vector<PairRelation>	relations;
	std::vector<PairData>	chain;
	std::vector<PendingPair>	pending;
	PairData					straggler;
	bool						hasStraggler;
	std::size_t					i;

	if (pairs.size() <= 1)
		return ;
	hasStraggler = (pairs.size() % 2 != 0);
	i = 0;
	while (i + 1 < pairs.size())
	{
		PairData	high;
		PairData	low;
		PairRelation	relation;

		if (pairs[i].larger >= pairs[i + 1].larger)
		{
			high = pairs[i];
			low = pairs[i + 1];
		}
		else
		{
			high = pairs[i + 1];
			low = pairs[i];
		}
		maxima.push_back(high);
		relation.maxId = high.id;
		relation.minPair = low;
		relations.push_back(relation);
		i += 2;
	}
	if (hasStraggler)
		straggler = pairs.back();
	sortVectorPairs(maxima);
	chain.push_back(findPairByMaxId(relations, maxima[0].id));
	i = 0;
	while (i < maxima.size())
	{
		chain.push_back(maxima[i]);
		if (i > 0)
		{
			PendingPair	entry;

			entry.minPair = findPairByMaxId(relations, maxima[i].id);
			entry.maxId = maxima[i].id;
			pending.push_back(entry);
		}
		++i;
	}
	insertVectorPendingPairs(chain, pending);
	if (hasStraggler)
	{
		std::vector<PairData>::iterator	position;

		position = upperBoundVectorPairs(chain, straggler.larger, chain.end());
		chain.insert(position, straggler);
	}
	pairs = chain;
}

void	PmergeMe::sortDequePairs(std::deque<PairData> &pairs)
{
	std::deque<PairData>		maxima;
	std::deque<PairRelation>	relations;
	std::deque<PairData>		chain;
	std::deque<PendingPair>		pending;
	PairData					straggler;
	bool						hasStraggler;
	std::size_t					i;

	if (pairs.size() <= 1)
		return ;
	hasStraggler = (pairs.size() % 2 != 0);
	i = 0;
	while (i + 1 < pairs.size())
	{
		PairData	high;
		PairData	low;
		PairRelation	relation;

		if (pairs[i].larger >= pairs[i + 1].larger)
		{
			high = pairs[i];
			low = pairs[i + 1];
		}
		else
		{
			high = pairs[i + 1];
			low = pairs[i];
		}
		maxima.push_back(high);
		relation.maxId = high.id;
		relation.minPair = low;
		relations.push_back(relation);
		i += 2;
	}
	if (hasStraggler)
		straggler = pairs.back();
	sortDequePairs(maxima);
	chain.push_back(findPairByMaxId(relations, maxima[0].id));
	i = 0;
	while (i < maxima.size())
	{
		chain.push_back(maxima[i]);
		if (i > 0)
		{
			PendingPair	entry;

			entry.minPair = findPairByMaxId(relations, maxima[i].id);
			entry.maxId = maxima[i].id;
			pending.push_back(entry);
		}
		++i;
	}
	insertDequePendingPairs(chain, pending);
	if (hasStraggler)
	{
		std::deque<PairData>::iterator	position;

		position = upperBoundDequePairs(chain, straggler.larger, chain.end());
		chain.insert(position, straggler);
	}
	pairs = chain;
}

void	PmergeMe::sortVector(void)
{
	std::vector<PairData>	pairs;
	std::vector<OutputValue>	chain;
	std::vector<PendingValue>	pending;
	bool						hasStraggler;
	int							straggler;
	std::size_t					i;
	std::size_t					pairId;

	_sortedVector = _vectorInput;
	if (_sortedVector.size() <= 1)
		return ;
	hasStraggler = (_sortedVector.size() % 2 != 0);
	if (hasStraggler)
		straggler = _sortedVector.back();
	i = 0;
	pairId = 0;
	while (i + 1 < _sortedVector.size())
	{
		PairData	pair;

		if (_sortedVector[i] >= _sortedVector[i + 1])
		{
			pair.larger = _sortedVector[i];
			pair.smaller = _sortedVector[i + 1];
		}
		else
		{
			pair.larger = _sortedVector[i + 1];
			pair.smaller = _sortedVector[i];
		}
		pair.id = pairId++;
		pairs.push_back(pair);
		i += 2;
	}
	sortVectorPairs(pairs);
	chain.push_back(OutputValue());
	chain.back().value = pairs[0].smaller;
	chain.back().pairId = pairs[0].id;
	chain.back().isMainChain = false;
	i = 0;
	while (i < pairs.size())
	{
		OutputValue	node;

		node.value = pairs[i].larger;
		node.pairId = pairs[i].id;
		node.isMainChain = true;
		chain.push_back(node);
		if (i > 0)
		{
			PendingValue	entry;

			entry.value = pairs[i].smaller;
			entry.maxId = pairs[i].id;
			pending.push_back(entry);
		}
		++i;
	}
	insertVectorPendingValues(chain, pending);
	if (hasStraggler)
	{
		OutputValue							node;
		std::vector<OutputValue>::iterator	position;

		node.value = straggler;
		node.pairId = 0;
		node.isMainChain = false;
		position = upperBoundVectorValues(chain, straggler, chain.end());
		chain.insert(position, node);
	}
	_sortedVector.clear();
	i = 0;
	while (i < chain.size())
	{
		_sortedVector.push_back(chain[i].value);
		++i;
	}
}

void	PmergeMe::sortDeque(void)
{
	std::deque<PairData>	pairs;
	std::deque<OutputValue>	chain;
	std::deque<PendingValue>	pending;
	bool					hasStraggler;
	int						straggler;
	std::size_t				i;
	std::size_t				pairId;

	_sortedDeque = _dequeInput;
	if (_sortedDeque.size() <= 1)
		return ;
	hasStraggler = (_sortedDeque.size() % 2 != 0);
	if (hasStraggler)
		straggler = _sortedDeque.back();
	i = 0;
	pairId = 0;
	while (i + 1 < _sortedDeque.size())
	{
		PairData	pair;

		if (_sortedDeque[i] >= _sortedDeque[i + 1])
		{
			pair.larger = _sortedDeque[i];
			pair.smaller = _sortedDeque[i + 1];
		}
		else
		{
			pair.larger = _sortedDeque[i + 1];
			pair.smaller = _sortedDeque[i];
		}
		pair.id = pairId++;
		pairs.push_back(pair);
		i += 2;
	}
	sortDequePairs(pairs);
	chain.push_back(OutputValue());
	chain.back().value = pairs[0].smaller;
	chain.back().pairId = pairs[0].id;
	chain.back().isMainChain = false;
	i = 0;
	while (i < pairs.size())
	{
		OutputValue	node;

		node.value = pairs[i].larger;
		node.pairId = pairs[i].id;
		node.isMainChain = true;
		chain.push_back(node);
		if (i > 0)
		{
			PendingValue	entry;

			entry.value = pairs[i].smaller;
			entry.maxId = pairs[i].id;
			pending.push_back(entry);
		}
		++i;
	}
	insertDequePendingValues(chain, pending);
	if (hasStraggler)
	{
		OutputValue						node;
		std::deque<OutputValue>::iterator	position;

		node.value = straggler;
		node.pairId = 0;
		node.isMainChain = false;
		position = upperBoundDequeValues(chain, straggler, chain.end());
		chain.insert(position, node);
	}
	_sortedDeque.clear();
	i = 0;
	while (i < chain.size())
	{
		_sortedDeque.push_back(chain[i].value);
		++i;
	}
}

void	PmergeMe::printSequence(void) const
{
	std::size_t	i;

	std::cout << "Before:";
	i = 0;
	while (i < _vectorInput.size())
	{
		std::cout << " " << _vectorInput[i];
		++i;
	}
	std::cout << std::endl;
	std::cout << "After:";
	i = 0;
	while (i < _sortedVector.size())
	{
		std::cout << " " << _sortedVector[i];
		++i;
	}
	std::cout << std::endl;
	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << _vectorInput.size()
		<< " elements with std::vector : " << _vectorTimeUs << " us" << std::endl;
	std::cout << "Time to process a range of " << _dequeInput.size()
		<< " elements with std::deque : " << _dequeTimeUs << " us" << std::endl;
}

void	PmergeMe::process(void)
{
	std::clock_t	start;
	std::clock_t	end;

	start = std::clock();
	sortVector();
	end = std::clock();
	_vectorTimeUs = static_cast<double>(end - start) * 1000000.0 / CLOCKS_PER_SEC;
	start = std::clock();
	sortDeque();
	end = std::clock();
	_dequeTimeUs = static_cast<double>(end - start) * 1000000.0 / CLOCKS_PER_SEC;
	printSequence();
}
