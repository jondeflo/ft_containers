#ifndef VECTORITERATOR_HPP
#define VECTORITERATOR_HPP

namespace ft
{

template <class T>
class VectorIterator
{

public:

	typedef T								value_type;
	typedef T*								pointer;
	typedef T&								reference;
	typedef ptrdiff_t						difference_type;
	//typedef std::random_access_iterator_tag	iterator_category;


	VectorIterator(void) : _ptr() {}
	~VectorIterator(void) {}
	
	VectorIterator(pointer ptr) : _ptr(ptr) {}
	VectorIterator(const VectorIterator &other) : _ptr(other._ptr) {}

	VectorIterator& operator=(const VectorIterator& other)
	{
		_ptr = other._ptr;
		return (*this);
	}

	reference		operator*() const { return (*_ptr); }
	pointer			operator->() const { return (_ptr); };
	reference		operator[](difference_type n) const { return (_ptr[n]); }
	
	VectorIterator	&operator++()	{ ++_ptr; return (*this); }
	VectorIterator	&operator--()	{ --_ptr; return (*this); }
	VectorIterator	operator++(int)	{ VectorIterator it(*this); ++_ptr; return (it); }
	VectorIterator	operator--(int)	{ VectorIterator it(*this); --_ptr; return (it); }

	VectorIterator	&operator+=(int offset)	{ _ptr += offset; return (*this); }
	VectorIterator	&operator-=(int offset)	{ _ptr -= offset; return (*this); }

	VectorIterator	operator+(int offset) const	{ VectorIterator it(*this); return (it += offset); }
	VectorIterator	operator-(int offset) const	{ VectorIterator it(*this); return (it -= offset); }

	difference_type	operator-(const VectorIterator &other) const	{ return (_ptr - other._ptr); }

	operator VectorIterator<const value_type> () const { return VectorIterator<const value_type>(_ptr) ; }


private:

	pointer _ptr;

public:

	friend bool operator<(const VectorIterator &a, const VectorIterator &b)
	{ return a._ptr < b._ptr; };
	friend bool operator<=(const VectorIterator &a, const VectorIterator &b)
	{ return a._ptr <= b._ptr; };
	friend bool operator>(const VectorIterator &a, const VectorIterator &b)
	{ return a._ptr > b._ptr; };
	friend bool operator>=(const VectorIterator &a, const VectorIterator &b)
	{ return a._ptr >= b._ptr; };
	friend bool operator==(const VectorIterator &a, const VectorIterator &b)
	{ return a._ptr == b._ptr; };
	friend bool operator!=(const VectorIterator &a, const VectorIterator &b)
	{ return a._ptr != b._ptr; };

}; // end of class

template <class T>
class VectorReverseIterator
{

public:

	typedef T								value_type;
	typedef T*								pointer;
	typedef T&								reference;
	typedef ptrdiff_t						difference_type;
	typedef std::random_access_iterator_tag	iterator_category;


	VectorReverseIterator() : _ptr() {}
	~VectorReverseIterator() {}
	VectorReverseIterator(pointer ptr) : _ptr(ptr) {}

	VectorReverseIterator(const VectorReverseIterator &other) : _ptr(other._ptr) {}

	VectorReverseIterator& operator=(const VectorReverseIterator& other)
	{
		_ptr = other._ptr;
		return (*this);
	}

	reference		operator*() const { return (*_ptr); }
	pointer			operator->() const { return (_ptr); };
	reference		operator[](difference_type n) const { return (_ptr[n]); }
	
	VectorReverseIterator	&operator++()      { --_ptr; return (*this); }
	VectorReverseIterator	&operator--()      { ++_ptr; return (*this); }
	VectorReverseIterator	operator++(int)    { VectorReverseIterator it(*this); --_ptr; return (it); }
	VectorReverseIterator	operator--(int)    { VectorReverseIterator it(*this); ++_ptr; return (it); }

	VectorReverseIterator	&operator+=(int offset) { _ptr -= offset; return (*this); }
	VectorReverseIterator	&operator-=(int offset) { _ptr += offset; return (*this); }

	VectorReverseIterator	operator+(int offset) const { VectorReverseIterator it(*this); return (it -= offset); }
	VectorReverseIterator	operator-(int offset) const { VectorReverseIterator it(*this); return (it += offset); }

	difference_type	operator-(const VectorReverseIterator &other) const { return (other._ptr - _ptr); }

	operator VectorReverseIterator<const value_type> () const { return VectorReverseIterator<const value_type>(_ptr) ; }

private:
	pointer _ptr;

public:

	friend bool operator<(const VectorReverseIterator &a, const VectorReverseIterator &b)
	{ return a._ptr < b._ptr; };
	friend bool operator<=(const VectorReverseIterator &a, const VectorReverseIterator &b)
	{ return a._ptr <= b._ptr; };
	friend bool operator>(const VectorReverseIterator &a, const VectorReverseIterator &b)
	{ return a._ptr > b._ptr; };
	friend bool operator>=(const VectorReverseIterator &a, const VectorReverseIterator &b)
	{ return a._ptr >= b._ptr; };
	friend bool operator==(const VectorReverseIterator &a, const VectorReverseIterator &b)
	{ return a._ptr == b._ptr; };
	friend bool operator!=(const VectorReverseIterator &a, const VectorReverseIterator &b)
	{ return a._ptr != b._ptr; };

}; // end of class


}; // end of namespace


#endif