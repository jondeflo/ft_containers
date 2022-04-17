#ifndef MAPITERATOR_HPP
#define MAPITERATOR_HPP

#include "Utils.hpp"

namespace ft
{

template <typename K, typename V, typename node>
class MapIterator
{

public:
	
	typedef std::pair<K, V> value_type;
	typedef std::pair<K, V>& reference;
	typedef MapNode<K, V>* node_pointer;
	//typedef std::bidirectional_iterator_tag	iterator_category;

	MapIterator(void) : _ptr(0), _end(0) {}
	~MapIterator(void) {}
	
	MapIterator(node_pointer ptr, node_pointer _end) : _ptr(ptr), _end(_end) {}
	MapIterator(const MapIterator &other) : _ptr(other._ptr), _end(other._end) {}

	MapIterator& operator=(const MapIterator &other)
	{
		this->_ptr = other._ptr;
		this->_end = other._end;
		return (*this);
	}

	value_type &operator*() const { return (_ptr->pair); }
	value_type *operator->() const { return &(_ptr->pair); }

	MapIterator	&operator++()
	{
		if (this->_ptr == this->_end)
			this->_ptr = this->_end->right;
		else
		{
			node_pointer current =  this->_ptr;

			while (this->_ptr != this->_end && this->_ptr->pair.first <= current->pair.first)
			{
				if (this->_ptr->right && (this->_ptr->right == this->_end ||
				this->_ptr->right->pair.first > current->pair.first))
				{
					this->_ptr = this->_ptr->right;
					if (this->_ptr !=this->_end)
						this->_ptr = findMin(this->_ptr);
				}
				else
					this->_ptr =  this->_ptr->parent;
			}
		}
		return (*this);
	}

	MapIterator	&operator--()
	{
		if (this->_ptr == this->_end)
			this->_ptr = findMax(this->_end->right);
		else
		{
			node_pointer current = this->_ptr;

			while (this->_ptr != this->_end && _ptr->pair.first >= current->pair.first)
			{
				if (this->_ptr->left && (this->_ptr->left == this->_end || 
					current->pair.first > this->_ptr->left->pair.first))
				{
					this->_ptr = this->_ptr->left;
					if (this->_ptr != this->_end)
						this->_ptr = findMax(this->_ptr);
				}
				else
					this->_ptr = this->_ptr->parent;
			}
		}
		return (*this);
	}

	MapIterator	operator++(int)	{ MapIterator it(*this); this->operator++(); return (it); }
	MapIterator	operator--(int)	{ MapIterator it(*this); this->operator--(); return (it); }

	bool operator==(MapIterator const &rhs)	{	return(this->_ptr == rhs._ptr);	}
	bool operator!=(MapIterator const &rhs)	{	return(this->_ptr != rhs._ptr);	}

	node_pointer get_node_ptr()	const {	return (_ptr);	}


	operator MapIterator<const K, V, node_pointer> () const {return MapIterator<const K, V, node_pointer>(_end);	}

private:
	node_pointer _ptr;
	node_pointer _end;

	node_pointer findMin(node_pointer root)
	{
		if (root && root != _end && root->left && root->left != _end)
			return (findMin(root->left));
		return root;
	}

	node_pointer findMax(node_pointer root)
	{
		if (root && root != _end && root->right && root->right != _end)
			return (findMax(root->right));
		return root;
	}

};


template <typename K, typename V, typename node>
class MapReverseIterator
{

public:
	
	typedef std::pair<K, V> value_type;
	typedef std::pair<K, V>& reference;
	typedef MapNode<K, V>* node_pointer;
	//typedef std::bidirectional_iterator_tag	iterator_category;

	MapReverseIterator(void) : _ptr(0), _end(0) {}
	~MapReverseIterator(void) {}
	
	MapReverseIterator(node_pointer ptr, node_pointer _end) : _ptr(ptr), _end(_end) {}
	MapReverseIterator(const MapReverseIterator &other) : _ptr(other._ptr), _end(other._end) {}

	MapReverseIterator& operator=(const MapReverseIterator &other)
	{
		this->_ptr = other._ptr;
		this->_end = other._end;
		return (*this);
	}

	value_type &operator*() const { return (_ptr->pair); }
	value_type *operator->() const { return &(_ptr->pair); }

	MapReverseIterator	&operator--()
	{
		if (this->_ptr == this->_end)
			this->_ptr = this->_end->parent;
		else
		{
			node_pointer current =  this->_ptr;

			while (this->_ptr != this->_end && this->_ptr->pair.first <= current->pair.first)
			{
				if (this->_ptr->right && (this->_ptr->right == this->_end ||
				this->_ptr->right->pair.first > current->pair.first))
				{
					this->_ptr = this->_ptr->right;
					if (this->_ptr !=this->_end)
						this->_ptr = findMin(this->_ptr);
				}
				else
					this->_ptr =  this->_ptr->parent;
			}
		}
		return (*this);
	}

	MapReverseIterator	&operator++()
	{
		if (this->_ptr == this->_end)
			this->_ptr = this->_end->left;
		else
		{
			node_pointer current = this->_ptr;

			while (this->_ptr != this->_end && _ptr->pair.first >= current->pair.first)
			{
				if (this->_ptr->left && (this->_ptr->left == this->_end || 
					current->pair.first > this->_ptr->left->pair.first))
				{
					this->_ptr = this->_ptr->left;
					if (this->_ptr != this->_end)
						this->_ptr = findMax(this->_ptr);
				}
				else
					this->_ptr = this->_ptr->parent;
			}
		}
		return (*this);
	}

	MapReverseIterator	operator++(int)	{ MapReverseIterator it(*this); this->operator++(); return (it); }
	MapReverseIterator	operator--(int)	{ MapReverseIterator it(*this); this->operator--(); return (it); }

	bool operator==(MapReverseIterator const &rhs)	{	return(this->_ptr == rhs._ptr);	}
	bool operator!=(MapReverseIterator const &rhs)	{	return(this->_ptr != rhs._ptr);	}

	node_pointer get_node_ptr()	const {	return (_ptr);	}


	operator MapReverseIterator<const K, V, node_pointer> () const {return MapReverseIterator<const K, V, node_pointer>(_end);	}

private:
	node_pointer _ptr;
	node_pointer _end;

	node_pointer findMin(node_pointer root)
	{
		if (root && root != _end && root->left && root->left != _end)
			return (findMin(root->left));
		return root;
	}

	node_pointer findMax(node_pointer root)
	{
		if (root && root != _end && root->right && root->right != _end)
			return (findMax(root->right));
		return root;
	}

};
}; // end of namespace

#endif