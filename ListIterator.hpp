#ifndef LISTITERATOR_HPP
#define LISTITERATOR_HPP


namespace ft
{

template <typename T>
class ListNode;

template <typename T, typename node_pointer>
class ListIterator
{

public:
	typedef T								value_type;
	typedef T*								pointer;
	typedef T&								reference;
	typedef ptrdiff_t						difference_type;
	//typedef std::bidirectional_iterator_tag	iterator_category;

	ListIterator(void) : _ptr(0) {}
	~ListIterator(void) {}
	
	ListIterator(node_pointer ptr) : _ptr(ptr) {}
	ListIterator(const ListIterator &other) : _ptr(other._ptr) {}

	ListIterator& operator=(const ListIterator &other)
	{
		this->_ptr = other._ptr;
		return (*this);
	}

	reference		operator*() const { return (_ptr->data); }
	pointer			operator->() const { return &(_ptr->data); }

	ListIterator	&operator++()	{ _ptr = _ptr->next; return (*this); }
	ListIterator	&operator--()	{ _ptr = _ptr->prev; return (*this); }
	ListIterator	operator++(int)	{ ListIterator it(*this); _ptr = _ptr->next; return (it); }
	ListIterator	operator--(int)	{ ListIterator it(*this); _ptr = _ptr->prev; return (it); }

	bool operator==(ListIterator const &rhs)	{	return(this->_ptr == rhs._ptr);	}
	bool operator!=(ListIterator const &rhs)	{	return(this->_ptr != rhs._ptr);	}

	node_pointer get_node_ptr()	const {	return (_ptr);	}

	void set_next(node_pointer ptr) {this->next = ptr;}
	void set_prev(node_pointer ptr) {this->prev = ptr;}

	operator ListIterator<const value_type, node_pointer> () const {return ListIterator<const value_type, node_pointer>(_ptr);	}

private:
	node_pointer _ptr;

};

template <typename T, typename node_pointer>
class ListReverseIterator
{

public:
	typedef T								value_type;
	typedef T*								pointer;
	typedef T&								reference;
	typedef ptrdiff_t						difference_type;
	//typedef std::bidirectional_iterator_tag	iterator_category;

	ListReverseIterator(void) : _ptr(0) {}
	~ListReverseIterator(void) {}
	
	ListReverseIterator(node_pointer ptr) : _ptr(ptr) {}
	ListReverseIterator(const ListReverseIterator &other) : _ptr(other._ptr) {}

	ListReverseIterator& operator=(const ListReverseIterator &other)
	{
		this->_ptr = other._ptr;
		return (*this);
	}

	reference		operator*() const { return (_ptr->data); }
	pointer			operator->() const { return &(_ptr->data); }

	ListReverseIterator	&operator++()	{ _ptr = _ptr->prev; return (*this); }
	ListReverseIterator	&operator--()	{ _ptr = _ptr->next; return (*this); }
	ListReverseIterator	operator++(int)	{ ListReverseIterator it(*this); _ptr = _ptr->prev; return (it); }
	ListReverseIterator	operator--(int)	{ ListReverseIterator it(*this); _ptr = _ptr->next; return (it); }

	bool operator==(ListReverseIterator const &rhs)	{	return(this->_ptr == rhs._ptr);	}
	bool operator!=(ListReverseIterator const &rhs)	{	return(this->_ptr != rhs._ptr);	}

	node_pointer get_node_ptr()	const {	return (_ptr);	}

	void set_next(node_pointer ptr) {this->next = ptr;}
	void set_prev(node_pointer ptr) {this->prev = ptr;}

	operator ListReverseIterator<const value_type, node_pointer> () const {return ListReverseIterator<const value_type, node_pointer>(_ptr);	}

private:
	node_pointer _ptr;

};


}; // end of namespace


#endif