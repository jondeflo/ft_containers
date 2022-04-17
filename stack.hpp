#ifndef STACK_HPP
#define STACK_HPP

#include "list.hpp"

namespace ft
{
template <class T, class Container = ft::list<T> >
class stack
{

public:
	typedef Container	container_type;
	typedef T			value_type;
	typedef size_t		size_type;
	
	explicit stack (const container_type& ctnr = container_type()) : _ctnr(ctnr) {}

	bool empty() const {	return (this->_ctnr.empty());	};
	size_type size() const {	return (this->_ctnr.size());	};
	value_type& top() {	return (this->_ctnr.front());	};
	const value_type& top() const {	return (this->_ctnr.front());	};
	void push (const value_type& val) {	return (this->_ctnr.push_front(val));	};
	void pop() {	return (this->_ctnr.pop_front());	}

	friend bool operator==(const stack<T, Container>&lhs, const stack<T,Container>&rhs)
	{	return lhs._ctnr == rhs._ctnr;	}
	friend bool operator<(const stack<T, Container>&lhs, const stack<T,Container>&rhs)
	{	return lhs._ctnr < rhs._ctnr;	}
	
private:
	container_type _ctnr;

};

template <class T, class Container>
bool operator== (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
{	return (lhs == rhs);	}

template <class T, class Container>
bool operator!= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
{	return (!(lhs == rhs));	}

template <class T, class Container>
bool operator<  (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
{	return(lhs < rhs);	}

template <class T, class Container>
bool operator<= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
{	return (!(rhs < lhs));	}

template <class T, class Container>
bool operator>  (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
{	return (rhs < lhs);	}

template <class T, class Container>
bool operator>= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
{	return (!(lhs < rhs));	}

}; //end of namespace

#endif