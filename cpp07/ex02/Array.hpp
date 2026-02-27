#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T>
class Array {
	private:
		T *_data;
		unsigned int _size;

	public:
		Array(void);
		explicit Array(unsigned int n);
		Array(Array const &other);
		~Array(void);
		Array &operator=(Array const &other);

		T &operator[](int index);
		T const &operator[](int index) const;

		unsigned int size(void) const;

		class OutOfBoundsException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

#include "Array.tpp"

#endif
