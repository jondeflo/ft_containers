#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "VectorIterator.hpp"
#include "Allocator.hpp"
#include "Utils.hpp"

namespace ft
{

template<class T, class Allocator = Allocator<T> >
class vector
{

public:
	typedef T										value_type;
	typedef Allocator								allocator_type;
	typedef T*										pointer;
	typedef const T* 								const_pointer;
	typedef T&										reference;
	typedef const T&								const_reference;
	typedef size_t									size_type;
	typedef ptrdiff_t								difference_type;
	
	typedef VectorIterator<value_type>				iterator;
	typedef VectorIterator<const value_type>		const_iterator;
	typedef VectorReverseIterator<value_type>		reverse_iterator;
	typedef VectorReverseIterator<const value_type>	const_reverse_iterator;

private:

	allocator_type	_allocator;
	size_type		_size;
	size_type		_capacity;
	pointer			_data;

public:

/* 
** MEMBER FUNCTIONS    DONE!!!!!!!!
*/

explicit vector (const allocator_type& alloc = allocator_type()) :
	 _allocator(alloc), _size(0), _capacity(0) // default
{
	_data = _allocator.allocate(0);
} 

explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) :
	 _allocator(alloc), _size(0), _capacity(0) // fill
{
	_data = _allocator.allocate(0);
	insert(begin(), n, val);
}

template <class InputIterator>
vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0) :
	 _allocator(alloc), _size(0), _capacity(0) // range
{
	_data = _allocator.allocate(0);
	insert(begin(), first, last);
}

vector (const vector& x) :  _size(0), _capacity(0), _data(0) // copy
{
	_data = _allocator.allocate(0);
	
	size_type i = 0;
	while (i < x._size)
	{
		push_back(x.at(i));
		i++;
	}
}

~vector()
{
	while (this->_size > 0)
		pop_back();
	this->_allocator.deallocate(this->_data);
}

vector& operator= (const vector& x) // copy
{
	if (this->_data != 0)
		clear();
	size_type i = 0;
	while (i < x._size )
	{
		push_back(x.at(i));
		i++;
	}	
	return (*this);
}

/* 
** ITERATORS	   DONE!!!!!!!!
*/

iterator begin() {	return (iterator(this->_data));	};
const_iterator begin() const {	return (const_iterator(this->_data));	};
iterator end() {	return (iterator(this->_data + this->_size));	};
const_iterator end() const {	return (const_iterator(this->_data + this->_size));	};
reverse_iterator rbegin() {	return (reverse_iterator(this->_data + this->_size - 1));	};
const_reverse_iterator rbegin() const {	return (const_reverse_iterator(this->_data + this->_size - 1));	};
reverse_iterator rend() {	return (reverse_iterator(this->_data - 1));	};
const_reverse_iterator rend() const {	return (const_reverse_iterator(this->_data - 1));	};;

/* 
** CAPACITY	   DONE!!!!!!!!
*/

size_type size() const {	return (this->_size);	};
size_type max_size() const {	return  (std::numeric_limits<size_type>::max() / sizeof(value_type));	};

void resize (size_type n, value_type val = value_type())
{
	while (this->_size > n)
		pop_back();
	while (this->_size < n)
		push_back(val);
}

size_type capacity() const {	return (this->_capacity);	};
bool empty() const {	return this->_size == 0 ? true : false;	};

void reserve (size_type n)
{
	if (n > this->max_size())
		throw std::length_error("allocator<T>::allocate(size_t n) \'n\' exceeds maximum supported size");
	if (n > this->_capacity)
	{
		pointer temp = this->_allocator.allocate(n);
		size_type i = 0;
		while (i < this->_size)
		{
			this->_allocator.construct(&temp[i], this->_data[i]);
			this->_allocator.destroy(&this->_data[i]);
			i++;
		}
		this->_allocator.deallocate(this->_data);
		this->_capacity = n;
		_data = temp;
	}
}

/* 
** ELEMENT ACCESS	   DONE!!!!!!!!
*/

reference operator[] (size_type n) {	return (this->_data[n]);	};
const_reference operator[] (size_type n) const {	return (this->_data[n]);	};

reference at (size_type n)
{
	if (n >= this->_size)
		throw std::out_of_range("vector");
	return (this->_data[n]);
}

const_reference at (size_type n) const
{
	if (n >= this->_size)
		throw std::out_of_range("vector");
	return (this->_data[n]);
}

reference front() {	return (this->_data[0]);	};
const_reference front() const {	return (this->_data[0]);	};
reference back() {	return (this->_data[this->_size - 1]);	};
const_reference back() const {	return (this->_data[this->_size - 1]);	};

/* 
** MODIFIERS	   DONE!!!!!!!!
*/

template <class InputIterator>
void assign (InputIterator first, InputIterator last) // range
{
	clear();
	insert(begin(), first, last);
}

void assign (size_type n, const value_type& val) // fill
{
	clear();
	insert(begin(), n, val);
}

void push_back (const value_type& val)
{
	if (this->_capacity == 0)
		reserve(1);
	else if (this->_size + 1 > this->_capacity)
		reserve(this->_capacity * 2);
	this->_allocator.construct(&this->_data[this->_size], val);
	this->_size++;
}

void pop_back()
{
	if (this->_size == 0)
		return;
	this->_allocator.destroy((&this->_data[this->_size - 1]));
	this->_size -= 1;
}

iterator insert (iterator position, const value_type& val) // single element
{
	insert(position, 1, val);
	return (position);
}

void insert (iterator position, size_type n, const value_type& val) // fill
{
	pointer temp;
	size_type new_capacity;
	size_type add = n;

	if (this->_size + n > this->_capacity)
	{
		if (this->_capacity == 0)
			this->_capacity++;
		size_type m_cap = this->_capacity;
		while (this->_size + n > m_cap)
			m_cap *=2;
		temp = this->_allocator.allocate(m_cap);
		new_capacity = m_cap;
	}
	else 
	{
		temp = this->_allocator.allocate(this->_capacity);
		new_capacity = this->_capacity;
	}

	iterator it = begin();
	size_type i = 0;
	size_type j = 0;

	while (it != position && i < this->_size)
	{
		this->_allocator.construct(&temp[i], this->_data[j]);
		this->_allocator.destroy(&this->_data[j]);
		i++;
		j++;
		it++;
	}
	while (n-- > 0)
	{	
		this->_allocator.construct(&temp[i], val);
		i++;
	}
	while (it != end() && i < this->_size + add)
	{
		this->_allocator.construct(&temp[i], this->_data[j]);
		this->_allocator.destroy(&this->_data[j]);
		i++;
		j++;
		it++;
	}

	this->_allocator.deallocate(this->_data);
	this->_data = temp;
	this->_capacity = new_capacity;
	this->_size = this->_size + add;
} 

template <class InputIterator>
void insert (iterator position, InputIterator first, InputIterator last,
typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0) // range
{
	pointer temp;
	size_type new_capacity;
	size_type add = last - first;

	if (add <= 0)
		return;

	if (this->_size + add > this->_capacity)
	{
		if (this->_capacity == 0)
			this->_capacity++;
		size_type m_cap = this->_capacity;
		while (this->_size + add > m_cap)
			m_cap *=2;
		temp = this->_allocator.allocate(m_cap);
		new_capacity = m_cap;
	}
	else 
	{
		temp = this->_allocator.allocate(this->_capacity);
		new_capacity = this->_capacity;
	}

	iterator it = begin();
	size_type i = 0;
	size_type j = 0;

	while (it != position && i < this->_size)
	{
		this->_allocator.construct(&temp[i], this->_data[j]);
		this->_allocator.destroy(&this->_data[j]);
		i++;
		j++;
		it++;
	}	
	size_type diff = add;
	while (diff-- > 0)
	{	
		this->_allocator.construct(&temp[i], *first);
		i++;
		first++;
	}
	while (it != end() && i < this->_size + add)
	{
		temp[i++] = this->_data[j++];
		this->_allocator.construct(&temp[i], this->_data[j]);
		this->_allocator.destroy(&this->_data[j]);
		i++;
		j++;
		it++;
	}

	this->_allocator.deallocate(this->_data);
	this->_data = temp;
	this->_capacity = new_capacity;
	this->_size = this->_size + add;
} 

iterator erase (iterator position)
{
	if (this->_size == 0)
		return (begin());
	
	pointer temp;
	temp = this->_allocator.allocate(this->_capacity);

	iterator it = begin();
	size_type i = 0;
	size_type j = 0;

	while (it != position && i < this->_size)
	{
		this->_allocator.construct(&temp[i], this->_data[j]);
		this->_allocator.destroy(&this->_data[j]);
		i++;
		j++;
		it++;
	}
	j++;
	
	iterator res;
	if (this->_size < 1)
		res = end();
	else
		res = it + 1;
	while (it != end() && i < this->_size)
	{
		this->_allocator.construct(&temp[i], this->_data[j]);
		this->_allocator.destroy(&this->_data[j]);
		i++;
		j++;
		it++;
	}

	this->_allocator.deallocate(this->_data);
	this->_data = temp;
	this->_size = this->_size - 1;
	return (res);
}

iterator erase (iterator first, iterator last)
{
	if (this->_size == 0 || last - first <= 0)
		return (iterator(first));
	
	pointer temp;
	temp = this->_allocator.allocate(this->_capacity);

	size_type diff = last - first;

	iterator it = begin();
	size_type i = 0;
	size_type j = 0;

	while (it != first && i < this->_size)
	{
		this->_allocator.construct(&temp[i], this->_data[j]);
		this->_allocator.destroy(&this->_data[j]);
		i++;
		j++;
		it++;
	}
	while (first != last)
	{
		j++;
		first++;
	}
	
	iterator res = it;
	
	while (it != end() && i < this->_size && j < this->_size)
	{
		this->_allocator.construct(&temp[i], this->_data[j]);
		this->_allocator.destroy(&this->_data[j]);
		i++;
		j++;
		it++;
	}
	
	this->_allocator.deallocate(this->_data);
	this->_data = temp;
	this->_size = this->_size - diff;
	
	if (this->_size < 1)
		res = end();
	else
		res = it + 1;

	return (res);
}

void swap (vector& x)
{
	size_type tmp_size = this->_size;
	size_type tmp_capacity = this->_capacity;
	pointer tmp_data = this->_data;

	this->_size = x._size;
	this->_capacity = x._capacity;
	this->_data = x._data;

	x._size = tmp_size;
	x._capacity = tmp_capacity;
	x._data = tmp_data;
}

void clear()
{
	while (this->_size > 0)
		pop_back();
}


}; // end of vector class

/* 
** NON-MEMBER FUNCTIONS OVERLOAD 
*/

template <class T, class Allocator>
bool operator== (const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs)
{
	if (lhs.size() != rhs.size())
			return (false);
	for (size_t i = 0; i < lhs.size(); i++)
		if (lhs[i] != rhs[i])
			return (false);
	return (true);
}

template <class T, class Allocator>
bool operator!= (const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs)
{
	return (!(lhs == rhs));
}

template <class T, class Allocator>
bool operator<  (const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs)
{
	size_t i;
	size_t j;	

	j = lhs.size() >= rhs.size() ? rhs.size() : lhs.size();

	for (i = 0; i < j; i++)
	{
		if (lhs.at(i) != rhs.at(i))
			return (lhs.at(i) != rhs.at(i));
	}
	return (lhs.size() < rhs.size());
}

template <class T, class Allocator>
bool operator<= (const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs)
{
	return (!(rhs < lhs));
}

template <class T, class Allocator>
bool operator>  (const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs)
{
	return (rhs < lhs);
}

template <class T, class Allocator>
bool operator>= (const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs)
{
	return (!(lhs < rhs));
}

template <class T, class Allocator>
void swap (vector<T,Allocator>& x, vector<T,Allocator>& y)
{
	x.swap(y);
}

};// end of namespase

#endif