#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <stdexcept>

template <typename T>
class Array{
	private:
		T *array;
		unsigned int a_size;
	public:
		Array(): array(new T[0]), a_size(0) // allocates an empty array (non zero amount of space ! will be deleted with [])
		{};

		Array(unsigned int n): array(new T[n]()), a_size(n) // new T[n]() : synthax for default initialization: every element in the array will be "default initialized": for classes, means that default constructor will be called; for non classes (int, floats...) zero initialization is done
		{};
		
		Array(const Array &copy): a_size(copy.a_size)
		{
			this->array = new T[copy.a_size];
			for (unsigned int i = 0; i < copy.a_size; i++)
				this->array[i] = copy.array[i];
		}

		Array &operator=(const Array &rhs)
		{
			delete [] this->array;
			this->array = new T[rhs.a_size];
			for (unsigned int i = 0; i < rhs.a_size; i++)
				this->array[i] = rhs.array[i];
			this->a_size = rhs.a_size;
			return *this;
		}

		~Array()
		{
			delete [] this->array;
		}

		T &operator[](unsigned int n) // we return a reference, so we can do "obj[i] =" (it "can be used as an lvalue") 
		{
			if (n >= this->a_size)
				throw std::out_of_range("out of range exception thrown");
			return this->array[n];
		}

		unsigned int size() const
		{
			return this->a_size;
		}
};


#endif