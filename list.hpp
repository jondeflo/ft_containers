#ifndef LIST_HPP
#define LIST_HPP

#include "ListIterator.hpp"
#include "Allocator.hpp"
#include "Utils.hpp"

namespace ft
{

template<class T, class Allocator = Allocator<T> >
class list
{

public:
	typedef T			value_type;
	typedef Allocator	allocator_type;
	typedef value_type*			pointer;
	typedef const value_type* 	const_pointer;
	typedef value_type&			reference;
	typedef const value_type&	const_reference;
	typedef size_t		size_type;
	typedef ptrdiff_t	difference_type;

	typedef ListNode<value_type>*						node_pointer;

	typedef ListIterator<value_type, node_pointer>					iterator;
	typedef ListIterator<const value_type, node_pointer>			const_iterator;

	typedef ListReverseIterator<value_type, node_pointer>			reverse_iterator;
	typedef ListReverseIterator<const value_type, node_pointer>		const_reverse_iterator;

private:

	allocator_type	_allocator;
	size_type 		_size;
	node_pointer	_begin;
	node_pointer	_end;	


public:

/* 
** MEMBER FUNCTIONS     DONE!
*/

explicit list (const allocator_type& alloc = allocator_type()) : _allocator(alloc), _size(0) //default
{
	this->_begin = new ListNode<value_type>();
	this->_end = new ListNode<value_type>();
	this->_begin->next = this->_end;
	this->_end->prev = this->_begin;
}

explicit list (size_type n, const value_type& val = value_type(), // fill
	const allocator_type& alloc = allocator_type()) : _allocator(alloc), _size(0)
{
	this->_begin = new ListNode<value_type>();
	this->_end = new ListNode<value_type>();
	this->_begin->next = this->_end;
	this->_end->prev = this->_begin;
	this->assign(n, val);
}

template <class InputIterator>
list (InputIterator first, InputIterator last, // range
	const allocator_type& alloc = allocator_type(),
	typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0)  : _allocator(alloc), _size(0)
{
	this->_begin = new ListNode<value_type>();
	this->_end = new ListNode<value_type>();
	this->_begin->next = this->_end;
	this->_end->prev = this->_begin;
	this->assign(first, last);
}

list (const list& x) : _allocator(x._allocator), _size(0)// copy
{
	this->_begin = new ListNode<value_type>();
	this->_end = new ListNode<value_type>();
	this->_begin->next = this->_end;
	this->_end->prev = this->_begin;
	*this = x;
}

list& operator=(const list& x) // copy
{
	if (this != &x)
		this->insert(begin(), x.begin(), x.end());
	return (*this);
}

~list()
{
	clear();
	delete this->_begin;
	delete this->_end;
}


/* 
** ITERATORS      DONE!
*/

iterator begin() { return (iterator(this->_begin->next));	}
const_iterator begin() const { return (const_iterator(this->_begin->next));	}
iterator end() { return (iterator(this->_end));	}
const_iterator end() const { return (const_iterator(this->_end));	}

reverse_iterator rbegin() { return (reverse_iterator(this->_end->prev));	}
const_reverse_iterator rbegin() const { return (const_reverse_iterator(this->_end->prev));	}
reverse_iterator rend() { return (reverse_iterator(this->_begin));	}
const_reverse_iterator rend() const { return (const_reverse_iterator(this->_begin));	}


/* 
** CAPACITY     DONE!
*/

bool empty() const {	return (this->_size == 0);	}
size_type size() const {	return (this->_size);	}
size_type max_size() const {	return  (std::numeric_limits<size_type>::max() / sizeof(ListNode<value_type>));	}


/* 
** ELEMENT ACCESS     DONE!
*/

reference front() {	return (this->_begin->next->data); }
const_reference front() const {	return (this->_begin->next->data); }
reference back() {	return (this->_end->prev->data); }
const_reference back() const {	return (this->_end->prev->data); }


/* 
** MODIFIERS     DONE!
*/

template <class InputIterator>
void assign (InputIterator first, InputIterator last,
typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0) // range
{
	clear();
	insert(this->begin(), first, last);
}

void assign (size_type n, const value_type& val) // fill
{
	clear();
	insert(this->begin(), n, val);
}

void push_front (const value_type& val)
{
	node_pointer newNode = new ListNode<value_type>();
	newNode->data = val;
	newNode->prev = this->_begin;
	newNode->next = this->_begin->next;
	this->_begin->next->prev = newNode;
	this->_begin->next = newNode;	
	this->_size++;
}

void pop_front()
{
	if (this->_size > 0)
	{
		node_pointer tmp = this->_begin->next->next;
		delete this->_begin->next;
		this->_begin->next = tmp;
		tmp->prev = this->_begin;
		this->_size--;
	}
}

void push_back (const value_type& val)
{
	node_pointer newNode = new ListNode<value_type>();
	newNode->data = val;
	newNode->prev = this->_end->prev;
	newNode->next = this->_end;
	this->_end->prev->next = newNode;
	this->_end->prev = newNode;	
	this->_size++;
}

void pop_back()
{
	if (this->_size > 0)
	{
		node_pointer tmp = this->_end->prev->prev;
		delete this->_end->prev;
		this->_end->prev = tmp;
		tmp->next = this->_end;
		//this->_begin->next->next->prev = this->_begin;
		
		this->_size--;
	}
}

iterator insert (iterator position, const value_type& val)// single element
{
	node_pointer tmp_next = position.get_node_ptr();
	node_pointer tmp_prev = tmp_next->prev;
	node_pointer newNode = new ListNode<value_type>();
	newNode->data = val;
	newNode->prev = tmp_prev;
	newNode->next = tmp_next;
	tmp_prev->next = newNode;
	tmp_next->prev = newNode;
	this->_size++;
	return (iterator(newNode));
}

void insert (iterator position, size_type n, const value_type& val) // fill
{
	while (n > 0)
	{
		position = insert(position, val);
		n--;
	}
}

template <class InputIterator>
void insert (iterator position, InputIterator first, InputIterator last,
typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0) // range
{
	while (first != last)
	{
		insert(position, *first);
		first++;
	}
}

iterator erase (iterator position)
{
	node_pointer tmp_next = position.get_node_ptr()->next;
	node_pointer tmp_prev = position.get_node_ptr()->prev;
	delete position.get_node_ptr();
	tmp_prev->next = tmp_next;
	tmp_next->prev = tmp_prev;
	this->_size--;
	return (iterator(tmp_next));
}

iterator erase (iterator first, iterator last)
{
	while (first != last)
	{
		erase(first);
		first++;
	}
	return (first);
}

void swap (list& x)
{
	size_type tmp_size = this->_size;
	node_pointer tmp_begin = this->_begin;
	node_pointer tmp_end = this->_end;

	this->_size = x._size;
	this->_begin = x._begin;
	this->_end = x._end;

	x._size = tmp_size;
	x._begin = tmp_begin;
	x._end = tmp_end;
}

void resize (size_type n, value_type val = value_type())
{
	while (n < this->_size)
		pop_back();
	while (n > this->_size)
		push_back(val);
}

void clear()
{
	while (!(this->empty()))
		pop_front();
}


/* 
** OPERATIONS     DONE!
*/

void splice (iterator position, list& x) // move entire list
{
	this->insert(position, x.begin(), x.end());
	x.clear();
}

void splice (iterator position, list& x, iterator i) // move single element
{
	this->insert(position, *i);
	x.erase(i);
}

void splice (iterator position, list& x, iterator first, iterator last) // move range
{
	this->insert(position, first, last);
	x.erase(first, last);
}

void remove (const value_type& val) // Remove elements with specific value
{
	iterator it = this->begin();
	while (it != this->end())
	{
		if (*it == val)
			it = erase(it);
		else
			it++;
	}
}

template <class Predicate>
void remove_if (Predicate pred) // Remove elements fulfilling condition (pred returns true)
{
	iterator it = this->begin();
	while (it != this->end())
	{
		if (pred(*it))
			it = erase(it);
		else
			it++;
	}
}

void unique() // Remove duplicate values
{
	if (this->_size > 1)
	{
		iterator it = begin();
		++it;
		while (it != end()) 
		{
			if (*it == it.get_node_ptr()->prev->data)
				it = erase(it);
			else
				++it;
		}
	}
}

template <class BinaryPredicate>
void unique (BinaryPredicate binary_pred) // remove if _pred returns true
{
	if (this->_size > 1)
	{
		iterator it = begin();
		++it;
		while (it != end()) 
		{
			if (binary_pred(*it, (it.get_node_ptr()->prev->data)))
				it = erase(it);
			else
				++it;
		}
	}
}

void merge (list& x)
{
	if (&x == this)
		return;
	iterator it = this->begin();
	iterator x_it = x.begin();

	while (it != this->end() && x_it != x.end())
	{
		if (*x_it < *it)
		{
			iterator tmp = x_it;
			++x_it;
			splice(it, x, tmp);
		}
		else
			++it;
	}

	if (x_it != x.end())
		splice(this->end(), x);
}

template <class Compare>
void merge (list& x, Compare comp)
{
	if (&x == this)
		return;
	iterator it = this->begin();
	iterator x_it = x.begin();

	while (it != this->end() && x_it != x.end())
	{
		if (comp(*x_it, *it))
		{
			iterator tmp = x_it;
			++x_it;
			splice(it, x, tmp);
		}
		else
			++it;
	}

	if (x_it != x.end())
		splice(this->end(), x);
}

void sort()
{
	if (this->_size > 1)
	{
		iterator it = begin();
		++it;
		while (it != end())
		{
			if (*it < (it.get_node_ptr()->prev->data))
			{
				node_pointer left = it.get_node_ptr()->prev;
				node_pointer right = it.get_node_ptr();
				
				left->prev->next = right;
				right->prev = left->prev;

				left->next = right->next;
				right->next->prev = left;

				right->next = left;
				left->prev = right;

				/*
				// it works, but through swapping data
				value_type tmp = it.get_node_ptr()->data;
				it--;
				value_type tmp1 = it.get_node_ptr()->data;
				it.get_node_ptr()->data = tmp;
				it++;
				it.get_node_ptr()->data = tmp1;
				*/

				it = begin();
			}
			++it;
		}
	}
}

template <class Compare>
void sort (Compare comp)
{
	if (this->_size > 1)
	{
		iterator it = begin();
		++it;
		while (it != end())
		{
			if (comp(*it, (it.get_node_ptr()->prev->data)))
			{
				node_pointer left = it.get_node_ptr()->prev;
				node_pointer right = it.get_node_ptr();

				left->prev->next = right;
				right->prev = left->prev;

				left->next = right->next;
				right->next->prev = left;

				right->next = left;
				left->prev = right;
				
				it = begin();
			}
			++it;
		}
	}
}

void reverse()
{
	list<value_type> tmp;
	iterator it = this->begin();
	while (it != this->end())
	{
		tmp.push_front(*(it));
		it++;
	}
	this->clear();
	*this = tmp;
}


}; // end of list class

/* 
** NON-MEMBER FUNCTIONS OVERLOAD     DONE!
*/

template <class T, class Alloc>
bool operator== (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
{
	typename list<T,Alloc>::const_iterator end1 = rhs.end();
	typename list<T,Alloc>::const_iterator end2 = lhs.end();

	typename list<T,Alloc>::const_iterator b1 = rhs.begin();
	typename list<T,Alloc>::const_iterator b2 = lhs.begin();
	while (b1 != end1 && b2 != end2 && *b1 == *b2)
	{
		++b1;
		++b2;
	}
	return (b1 == end1 && b2 == end2);
}

template <class T, class Alloc>
bool operator!= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
{
	return (!(lhs == rhs));
}

template <class T, class Alloc>
bool operator<  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
{
	if (lhs.size() < rhs.size())
		return true;
	if (lhs.size() > rhs.size())
		return false;
	typename ft::list<T, Alloc>::const_iterator l_it = lhs.begin();
	typename ft::list<T, Alloc>::const_iterator r_it = rhs.begin();

	while ((l_it != lhs.end()) && (r_it != rhs.end()))
	{
		if (*l_it < *r_it)
			return true;
		if (*r_it < *l_it)
			return false;
		++l_it;
		++r_it;
	}
	
	return ((l_it == lhs.end()) && (r_it != rhs.end()));
}

template <class T, class Alloc>
bool operator<= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
{
	return (!(rhs < lhs));
}

template <class T, class Alloc>
bool operator>  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
{
	return (rhs < lhs);
}

template <class T, class Alloc>
bool operator>= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
{
	return (!(lhs < rhs));
}

template <class T, class Alloc>
void swap (list<T,Alloc>& x, list<T,Alloc>& y)
{
	x.swap(y);
}

};// end of namespase

#endif