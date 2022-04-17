#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "list.hpp"

namespace ft
{
template <class T, class Container = ft::list<T> >
class queue
{

public:
	typedef Container	container_type;
	typedef T			value_type;
	typedef size_t		size_type;
	
	explicit queue (const container_type& ctnr = container_type()) : _ctnr(ctnr) {}

	bool empty() const {	return (this->_ctnr.empty());	};
	size_type size() const {	return (this->_ctnr.size());	};
	value_type& front() {	return (this->_ctnr.front());	};
	const value_type& front() const {	return (this->_ctnr.front());	};
	value_type& back() {	return (this->_ctnr.back());	};
	const value_type& back() const {	return (this->_ctnr.back());	};
	void push (const value_type& val) {	return (this->_ctnr.push_back(val));	};
	void pop() {	return (this->_ctnr.pop_front());	}

	friend bool operator==(const queue<T, Container>&lhs, const queue<T,Container>&rhs)
	{	return lhs._ctnr == rhs._ctnr;	}
	friend bool operator<(const queue<T, Container>&lhs, const queue<T,Container>&rhs)
	{	return lhs._ctnr < rhs._ctnr;	}

private:
	container_type _ctnr;

};

template <class T, class Container>
bool operator== (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
{	return (lhs == rhs);	}

template <class T, class Container>
bool operator!= (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
{	return (!(lhs == rhs));	}

template <class T, class Container>
bool operator<  (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
{	return(lhs < rhs);	}

template <class T, class Container>
bool operator<= (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
{	return (!(rhs < lhs));	}

template <class T, class Container>
bool operator>  (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
{	return (rhs < lhs);	}

template <class T, class Container>
bool operator>= (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
{	return (!(lhs < rhs));	}

}; //end of namespace

#endif