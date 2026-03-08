#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cstddef>
#include <deque>
#include <vector>

struct PairData
{
	int			larger;
	int			smaller;
	std::size_t	id;
};

struct PairRelation
{
	std::size_t	maxId;
	PairData	minPair;
};

struct PendingPair
{
	PairData		minPair;
	std::size_t		maxId;
};

struct OutputValue
{
	int			value;
	std::size_t	pairId;
	bool		isMainChain;
};

struct PendingValue
{
	int			value;
	std::size_t	maxId;
};

class PmergeMe
{
	private:
		std::vector<int>	_vectorInput;
		std::deque<int>		_dequeInput;
		std::vector<int>	_sortedVector;
		std::deque<int>		_sortedDeque;
		double				_vectorTimeUs;
		double				_dequeTimeUs;

		static bool					parsePositiveInt(const char *token, int &value);
		static std::vector<std::size_t>	buildInsertionOrder(std::size_t size);
		void						sortVector(void);
		void						sortDeque(void);
		void						sortVectorPairs(std::vector<PairData> &pairs);
		void						sortDequePairs(std::deque<PairData> &pairs);
		void						insertVectorPendingPairs(
										std::vector<PairData> &chain,
										const std::vector<PendingPair> &pending
									) const;
		void						insertDequePendingPairs(
										std::deque<PairData> &chain,
										const std::deque<PendingPair> &pending
									) const;
		void						insertVectorPendingValues(
										std::vector<OutputValue> &chain,
										const std::vector<PendingValue> &pending
									) const;
		void						insertDequePendingValues(
										std::deque<OutputValue> &chain,
										const std::deque<PendingValue> &pending
									) const;
		static PairData				findPairByMaxId(
										const std::vector<PairRelation> &relations,
										std::size_t maxId
									);
		static PairData				findPairByMaxId(
										const std::deque<PairRelation> &relations,
										std::size_t maxId
									);
		void						printSequence(void) const;

	public:
		PmergeMe(void);
		PmergeMe(int argc, char **argv);
		PmergeMe(const PmergeMe &other);
		~PmergeMe(void);
		PmergeMe	&operator=(const PmergeMe &other);

		void	process(void);
};

#endif
