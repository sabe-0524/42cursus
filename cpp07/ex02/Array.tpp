template <typename T>
Array<T>::Array(void) : _data(NULL), _size(0) {
}

template <typename T>
Array<T>::Array(unsigned int n) : _data(new T[n]()), _size(n) {
}

template <typename T>
Array<T>::Array(Array const &other) : _data(NULL), _size(0) {
	*this = other;
}

template <typename T>
Array<T>::~Array(void) {
	delete[] _data;
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &other) {
	T *newData = NULL;

	if (this == &other) {
		return (*this);
	}
	if (other._size != 0) {
		newData = new T[other._size];
		for (unsigned int i = 0; i < other._size; ++i) {
			newData[i] = other._data[i];
		}
	}
	delete[] _data;
	_data = newData;
	_size = other._size;
	return (*this);
}

template <typename T>
T &Array<T>::operator[](int index) {
	if (index < 0 || static_cast<unsigned int>(index) >= _size) {
		throw OutOfBoundsException();
	}
	return (_data[index]);
}

template <typename T>
T const &Array<T>::operator[](int index) const {
	if (index < 0 || static_cast<unsigned int>(index) >= _size) {
		throw OutOfBoundsException();
	}
	return (_data[index]);
}

template <typename T>
unsigned int Array<T>::size(void) const {
	return (_size);
}

template <typename T>
const char *Array<T>::OutOfBoundsException::what() const throw() {
	return ("Array index is out of bounds");
}
