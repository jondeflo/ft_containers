#ifndef ALLOCATOR_HPP
#define ALLOCATOR_HPP

#include <new>
#include <exception>
#include <limits>

namespace ft
{

template<class T>

class Allocator
{

public:
typedef size_t		size_type;
typedef ptrdiff_t	difference_type;
typedef T*			pointer;
typedef const T* 	const_pointer;
typedef T&			reference;
typedef const T&	const_reference;
typedef T			value_type;

template<class U>
struct rebind {	typedef Allocator<U> other;	};

Allocator() throw() {}
Allocator(const Allocator& allocator) throw() {(void)allocator;};
template <class U>
Allocator(const Allocator<U>& allocator) throw() {(void)allocator;};
~Allocator() throw() {}

pointer address(reference r) { return (&r); }
const_pointer address(const_reference r) { return (&r); }

pointer allocate(size_type cnt)
{ 
	if (cnt > this->max_size())
		throw std::bad_alloc();
	return reinterpret_cast<pointer>(::operator new(cnt * sizeof(value_type)));
}
void deallocate(pointer p)
{ 
	::operator delete(p); 
}

size_type max_size() const
{ 
	return (std::numeric_limits<size_type>::max() / sizeof(value_type));
}

void construct(pointer p, const_reference t)
{ ::new(p) value_type(t); }


void destroy(pointer p)
{
	p->~value_type();
}


};  // end of class


template<>
struct Allocator<void>
{

typedef void		value_type;
typedef void*		pointer;
typedef const void*	const_pointer;

template<class U>
struct rebind {	typedef Allocator<U> other;	};

};  // end of void struct

}; // end of namespace

#endif


