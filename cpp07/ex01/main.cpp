#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void printValue(T const &value) {
	std::cout << value << std::endl;
}

template <typename T>
void increment(T &value) {
	++value;
}

void appendExclamation(std::string &value) {
	value += "!";
}

int main(void) {
	int numbers[] = {0, 1, 2, 3};
	const std::size_t numberCount = sizeof(numbers) / sizeof(numbers[0]);

	std::cout << "numbers (before increment):" << std::endl;
	::iter(numbers, numberCount, printValue<int>);

	::iter(numbers, numberCount, increment<int>);

	std::cout << "numbers (after increment):" << std::endl;
	::iter(numbers, numberCount, printValue<int>);

	std::string words[] = {"hello", "templates", "world"};
	const std::size_t wordCount = sizeof(words) / sizeof(words[0]);

	::iter(words, wordCount, appendExclamation);

	std::cout << "words (after append):" << std::endl;
	::iter(words, wordCount, printValue<std::string>);

	const std::string constWords[] = {"const", "array", "test"};

	std::cout << "const words:" << std::endl;
	::iter(constWords, 3, printValue<std::string>);

	return (0);
}
