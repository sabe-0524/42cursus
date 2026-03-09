#include "PmergeMe.hpp"

#include <climits>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>

PmergeMe::PmergeMe(void)
{
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	(void)other;
}

PmergeMe::~PmergeMe(void)
{
}

PmergeMe	&PmergeMe::operator=(const PmergeMe &other)
{
	(void)other;
	return (*this);
}

std::vector<int>	PmergeMe::parseInput(int argc, char **argv)
{
	std::vector<int>	values;

	if (argc < 2)
		throw std::runtime_error("Error");
	values.reserve(argc - 1);
	for (int i = 1; i < argc; ++i)
	{
		char	*end;
		long	value;

		value = std::strtol(argv[i], &end, 10);
		if (argv[i][0] == '\0' || *end != '\0'
			|| value <= 0 || value > INT_MAX)
			throw std::runtime_error("Error");
		values.push_back(static_cast<int>(value));
	}
	return (values);
}

void	PmergeMe::printSequence(
	const std::string &label,
	const std::vector<int> &values)
{
	std::cout << label;
	for (size_t i = 0; i < values.size(); ++i)
		std::cout << " " << values[i];
	std::cout << std::endl;
}

void	PmergeMe::validateSameResult(
	const std::vector<int> &vectorValues,
	const std::deque<int> &dequeValues)
{
	if (vectorValues.size() != dequeValues.size())
		throw std::runtime_error("Error");
	for (size_t i = 0; i < vectorValues.size(); ++i)
	{
		if (vectorValues[i] != dequeValues[i])
			throw std::runtime_error("Error");
	}
}

std::vector<size_t>	PmergeMe::buildVectorInsertionOrder(size_t pairCount)
{
	std::vector<size_t>	order;
	size_t				previous;
	size_t				current;
	size_t				jacobsthalPrev;
	size_t				jacobsthalCurr;

	if (pairCount <= 1)
		return (order);
	previous = 1;
	jacobsthalPrev = 1;
	jacobsthalCurr = 3;
	while (previous < pairCount)
	{
		current = jacobsthalCurr;
		if (current > pairCount)
			current = pairCount;
		for (size_t index = current; index > previous; --index)
			order.push_back(index);
		previous = current;
		current = jacobsthalCurr + (2 * jacobsthalPrev);
		jacobsthalPrev = jacobsthalCurr;
		jacobsthalCurr = current;
	}
	return (order);
}

std::deque<size_t>	PmergeMe::buildDequeInsertionOrder(size_t pairCount)
{
	std::deque<size_t>	order;
	size_t				previous;
	size_t				current;
	size_t				jacobsthalPrev;
	size_t				jacobsthalCurr;

	if (pairCount <= 1)
		return (order);
	previous = 1;
	jacobsthalPrev = 1;
	jacobsthalCurr = 3;
	while (previous < pairCount)
	{
		current = jacobsthalCurr;
		if (current > pairCount)
			current = pairCount;
		for (size_t index = current; index > previous; --index)
			order.push_back(index);
		previous = current;
		current = jacobsthalCurr + (2 * jacobsthalPrev);
		jacobsthalPrev = jacobsthalCurr;
		jacobsthalCurr = current;
	}
	return (order);
}

size_t	PmergeMe::findVectorMatchIndex(
	const std::vector<VectorPair> &pairs,
	const std::vector<bool> &used,
	int largerId)
{
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		if (!used[i] && pairs[i].larger.id == largerId)
			return (i);
	}
	throw std::runtime_error("Error");
}

size_t	PmergeMe::findDequeMatchIndex(
	const std::deque<DequePair> &pairs,
	const std::deque<bool> &used,
	int largerId)
{
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		if (!used[i] && pairs[i].larger.id == largerId)
			return (i);
	}
	throw std::runtime_error("Error");
}

size_t	PmergeMe::findVectorItemIndex(
	const std::vector<VectorItem> &items,
	int itemId)
{
	for (size_t i = 0; i < items.size(); ++i)
	{
		if (items[i].id == itemId)
			return (i);
	}
	throw std::runtime_error("Error");
}

size_t	PmergeMe::findDequeItemIndex(
	const std::deque<DequeItem> &items,
	int itemId)
{
	for (size_t i = 0; i < items.size(); ++i)
	{
		if (items[i].id == itemId)
			return (i);
	}
	throw std::runtime_error("Error");
}

size_t	PmergeMe::findVectorInsertionIndex(
	const std::vector<VectorItem> &items,
	int value,
	size_t upperBound)
{
	size_t	low;
	size_t	high;
	size_t	middle;

	low = 0;
	high = upperBound;
	while (low < high)
	{
		middle = low + ((high - low) / 2);
		if (items[middle].value <= value)
			low = middle + 1;
		else
			high = middle;
	}
	return (low);
}

size_t	PmergeMe::findDequeInsertionIndex(
	const std::deque<DequeItem> &items,
	int value,
	size_t upperBound)
{
	size_t	low;
	size_t	high;
	size_t	middle;

	low = 0;
	high = upperBound;
	while (low < high)
	{
		middle = low + ((high - low) / 2);
		if (items[middle].value <= value)
			low = middle + 1;
		else
			high = middle;
	}
	return (low);
}

void	PmergeMe::fordJohnsonSortVector(std::vector<VectorItem> &items)
{
	std::vector<VectorPair>	pairs;
	VectorItem				straggler;
	bool					hasStraggler;
	std::vector<VectorItem>	largers;
	std::vector<VectorPair>	sortedPairs;
	std::vector<bool>		used;
	std::vector<VectorItem>	mainChain;
	std::vector<size_t>		order;

	if (items.size() <= 1)
		return ;
	hasStraggler = false;
	for (size_t i = 0; i + 1 < items.size(); i += 2)
	{
		VectorPair	pair;

		if (items[i].value <= items[i + 1].value)
		{
			pair.smaller = items[i];
			pair.larger = items[i + 1];
		}
		else
		{
			pair.smaller = items[i + 1];
			pair.larger = items[i];
		}
		pairs.push_back(pair);
	}
	if (items.size() % 2 != 0)
	{
		straggler = items[items.size() - 1];
		hasStraggler = true;
	}
	largers.reserve(pairs.size());
	for (size_t i = 0; i < pairs.size(); ++i)
		largers.push_back(pairs[i].larger);
	fordJohnsonSortVector(largers);
	used.assign(pairs.size(), false);
	sortedPairs.reserve(pairs.size());
	for (size_t i = 0; i < largers.size(); ++i)
	{
		size_t	matchIndex;

		matchIndex = findVectorMatchIndex(pairs, used, largers[i].id);
		used[matchIndex] = true;
		sortedPairs.push_back(pairs[matchIndex]);
	}
	mainChain.reserve(items.size());
	mainChain.push_back(sortedPairs[0].smaller);
	mainChain.push_back(sortedPairs[0].larger);
	for (size_t i = 1; i < sortedPairs.size(); ++i)
		mainChain.push_back(sortedPairs[i].larger);
	order = buildVectorInsertionOrder(sortedPairs.size());
	for (size_t i = 0; i < order.size(); ++i)
	{
		const VectorPair	&pair = sortedPairs[order[i] - 1];
		size_t				boundIndex;
		size_t				insertIndex;

		boundIndex = findVectorItemIndex(mainChain, pair.larger.id);
		insertIndex = findVectorInsertionIndex(
				mainChain,
				pair.smaller.value,
				boundIndex);
		mainChain.insert(mainChain.begin() + insertIndex, pair.smaller);
	}
	if (hasStraggler)
	{
		size_t	insertIndex;

		insertIndex = findVectorInsertionIndex(
				mainChain,
				straggler.value,
				mainChain.size());
		mainChain.insert(mainChain.begin() + insertIndex, straggler);
	}
	items.swap(mainChain);
}

void	PmergeMe::fordJohnsonSortDeque(std::deque<DequeItem> &items)
{
	std::deque<DequePair>	pairs;
	DequeItem				straggler;
	bool					hasStraggler;
	std::deque<DequeItem>	largers;
	std::deque<DequePair>	sortedPairs;
	std::deque<bool>		used;
	std::deque<DequeItem>	mainChain;
	std::deque<size_t>		order;

	if (items.size() <= 1)
		return ;
	hasStraggler = false;
	for (size_t i = 0; i + 1 < items.size(); i += 2)
	{
		DequePair	pair;

		if (items[i].value <= items[i + 1].value)
		{
			pair.smaller = items[i];
			pair.larger = items[i + 1];
		}
		else
		{
			pair.smaller = items[i + 1];
			pair.larger = items[i];
		}
		pairs.push_back(pair);
	}
	if (items.size() % 2 != 0)
	{
		straggler = items[items.size() - 1];
		hasStraggler = true;
	}
	for (size_t i = 0; i < pairs.size(); ++i)
		largers.push_back(pairs[i].larger);
	fordJohnsonSortDeque(largers);
	used.assign(pairs.size(), false);
	for (size_t i = 0; i < largers.size(); ++i)
	{
		size_t	matchIndex;

		matchIndex = findDequeMatchIndex(pairs, used, largers[i].id);
		used[matchIndex] = true;
		sortedPairs.push_back(pairs[matchIndex]);
	}
	mainChain.push_back(sortedPairs[0].smaller);
	mainChain.push_back(sortedPairs[0].larger);
	for (size_t i = 1; i < sortedPairs.size(); ++i)
		mainChain.push_back(sortedPairs[i].larger);
	order = buildDequeInsertionOrder(sortedPairs.size());
	for (size_t i = 0; i < order.size(); ++i)
	{
		const DequePair	&pair = sortedPairs[order[i] - 1];
		size_t			boundIndex;
		size_t			insertIndex;

		boundIndex = findDequeItemIndex(mainChain, pair.larger.id);
		insertIndex = findDequeInsertionIndex(
				mainChain,
				pair.smaller.value,
				boundIndex);
		mainChain.insert(mainChain.begin() + insertIndex, pair.smaller);
	}
	if (hasStraggler)
	{
		size_t	insertIndex;

		insertIndex = findDequeInsertionIndex(
				mainChain,
				straggler.value,
				mainChain.size());
		mainChain.insert(mainChain.begin() + insertIndex, straggler);
	}
	items.swap(mainChain);
}

std::vector<int>	PmergeMe::extractVectorValues(
	const std::vector<VectorItem> &items)
{
	std::vector<int>	values;

	values.reserve(items.size());
	for (size_t i = 0; i < items.size(); ++i)
		values.push_back(items[i].value);
	return (values);
}

std::deque<int>	PmergeMe::extractDequeValues(const std::deque<DequeItem> &items)
{
	std::deque<int>	values;

	for (size_t i = 0; i < items.size(); ++i)
		values.push_back(items[i].value);
	return (values);
}

double	PmergeMe::sortVector(std::vector<int> &values)
{
	std::vector<VectorItem>	items;
	clock_t					start;
	clock_t					finish;

	start = std::clock();
	items.reserve(values.size());
	for (size_t i = 0; i < values.size(); ++i)
	{
		VectorItem	item;

		item.value = values[i];
		item.id = static_cast<int>(i);
		items.push_back(item);
	}
	fordJohnsonSortVector(items);
	values = extractVectorValues(items);
	finish = std::clock();
	return (static_cast<double>(finish - start) * 1000000.0 / CLOCKS_PER_SEC);
}

double	PmergeMe::sortDeque(std::deque<int> &values)
{
	std::deque<DequeItem>	items;
	clock_t					start;
	clock_t					finish;

	start = std::clock();
	for (size_t i = 0; i < values.size(); ++i)
	{
		DequeItem	item;

		item.value = values[i];
		item.id = static_cast<int>(i);
		items.push_back(item);
	}
	fordJohnsonSortDeque(items);
	values = extractDequeValues(items);
	finish = std::clock();
	return (static_cast<double>(finish - start) * 1000000.0 / CLOCKS_PER_SEC);
}

void	PmergeMe::run(int argc, char **argv) const
{
	std::vector<int>	before;
	std::vector<int>	vectorValues;
	std::deque<int>	dequeValues;
	double				vectorTime;
	double				dequeTime;

	before = parseInput(argc, argv);
	vectorValues = before;
	dequeValues.assign(before.begin(), before.end());
	printSequence("Before:", before);
	vectorTime = sortVector(vectorValues);
	dequeTime = sortDeque(dequeValues);
	validateSameResult(vectorValues, dequeValues);
	printSequence("After:", vectorValues);
	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << before.size()
		<< " elements with std::vector : " << vectorTime << " us" << std::endl;
	std::cout << "Time to process a range of " << before.size()
		<< " elements with std::deque : " << dequeTime << " us" << std::endl;
}
