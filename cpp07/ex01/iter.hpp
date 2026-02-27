#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <typename T>
void iter(T *array, const std::size_t length, void (*function)(T &)) {
	if (array == NULL || function == NULL) {
		return;
	}
	for (std::size_t i = 0; i < length; ++i) {
		function(array[i]);
	}
}

template <typename T>
void iter(T const *array, const std::size_t length, void (*function)(T const &)) {
	if (array == NULL || function == NULL) {
		return;
	}
	for (std::size_t i = 0; i < length; ++i) {
		function(array[i]);
	}
}

#endif
