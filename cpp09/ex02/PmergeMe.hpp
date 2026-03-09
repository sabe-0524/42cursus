#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cstddef>
#include <deque>
#include <string>
#include <vector>

class PmergeMe
{
	private:
		struct VectorItem
		{
			int	value;
			int	id;
		};

		struct VectorPair
		{
			VectorItem	smaller;
			VectorItem	larger;
		};

		struct DequeItem
		{
			int	value;
			int	id;
		};

		struct DequePair
		{
			DequeItem	smaller;
			DequeItem	larger;
		};

		static std::vector<int>	parseInput(int argc, char **argv);
		static void				printSequence(
								const std::string &label,
								const std::vector<int> &values);
		static void				validateSameResult(
								const std::vector<int> &vectorValues,
								const std::deque<int> &dequeValues);

		static double			sortVector(std::vector<int> &values);
		static double			sortDeque(std::deque<int> &values);

		static void				fordJohnsonSortVector(
								std::vector<VectorItem> &items);
		static void				fordJohnsonSortDeque(
								std::deque<DequeItem> &items);

		static std::vector<size_t>	buildVectorInsertionOrder(size_t pairCount);
		static std::deque<size_t>	buildDequeInsertionOrder(size_t pairCount);

		static size_t			findVectorMatchIndex(
								const std::vector<VectorPair> &pairs,
								const std::vector<bool> &used,
								int largerId);
		static size_t			findDequeMatchIndex(
								const std::deque<DequePair> &pairs,
								const std::deque<bool> &used,
								int largerId);

		static size_t			findVectorItemIndex(
								const std::vector<VectorItem> &items,
								int itemId);
		static size_t			findDequeItemIndex(
								const std::deque<DequeItem> &items,
								int itemId);

		static size_t			findVectorInsertionIndex(
								const std::vector<VectorItem> &items,
								int value,
								size_t upperBound);
		static size_t			findDequeInsertionIndex(
								const std::deque<DequeItem> &items,
								int value,
								size_t upperBound);

		static std::vector<int>	extractVectorValues(
								const std::vector<VectorItem> &items);
		static std::deque<int>	extractDequeValues(
								const std::deque<DequeItem> &items);

	public:
		PmergeMe(void);
		PmergeMe(const PmergeMe &other);
		~PmergeMe(void);
		PmergeMe	&operator=(const PmergeMe &other);

		void	run(int argc, char **argv) const;
};

#endif
