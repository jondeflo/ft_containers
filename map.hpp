#ifndef MAP_HPP
#define MAP_HPP

#include <functional>
#include <utility>
#include "Allocator.hpp"
#include "MapIterator.hpp"

namespace ft
{

template < class Key, class T, class Compare = std::less<Key>, class Alloc = Allocator<std::pair<const Key,T> > >
class map
{

public:

typedef Key												key_type;
typedef T												mapped_type;
typedef std::pair<const key_type, mapped_type>			value_type;
typedef Compare											key_compare;
typedef Alloc	 										allocator_type;
typedef value_type& 									reference;
typedef const value_type&								const_reference;
typedef value_type*										pointer;
typedef const value_type*								const_pointer;
typedef ptrdiff_t										difference_type;
typedef size_t											size_type;
typedef MapNode<key_type, mapped_type>	node;
typedef MapNode<key_type, mapped_type>*	node_pointer;

typedef MapIterator<key_type, mapped_type, node>		iterator;
typedef MapIterator<key_type, mapped_type, node>		const_iterator;
typedef MapReverseIterator<key_type, mapped_type, node>	reverse_iterator;
typedef MapReverseIterator<key_type, mapped_type, node>	const_reverse_iterator;


class value_compare : public std::binary_function<value_type, value_type, bool>
{
	friend class map;
	protected:
		key_compare comp;
		value_compare (key_compare c) : comp(c) {} 
	public:
	typedef bool result_type;
	typedef value_type first_argument_type;
	typedef value_type second_argument_type;
	bool operator() (const value_type& x, const value_type& y) const
	{
		return comp(x.first, y.first);
	}
};

private:

	allocator_type	_allocator;
	size_type 		_size;
	node_pointer	_root;
	node_pointer	_end;
	value_compare	_comp;


	void eraseNode(node_pointer node)
	{
		if (this->_size == 0 || this->lower_bound(node->pair.first) == this->end()) // if key not present
			return;
		else if (node->parent == 0) // node is a root
		{
			if (node->left == this->_end && node->right == this->_end) // root only , no sons
			{
				delete (_root);
				this->_root = _end;
				_end->left = this->_end;
				_end->right = this->_end;
			}
			else if (node->left && node->right == this->_end) // has only left son
			{
				node_pointer max = findMax(_root->left);
				max->right = this->_end;
				this->_end->left = _root;
				node->left->parent = 0;
				delete (_root);
				this->_root = node->left;
			}
			else if (node->right && node->left == this->_end) // has only right son
			{
				node_pointer min = findMin(_root->right);
				min->left = this->_end;
				this->_end->right = _root;
				node->right->parent = 0;
				node_pointer tmp = node->right;
				delete (_root);
				this->_root = tmp;
			}
			else // root has two sons
			{
				node_pointer oldroot = this->_root;
				node_pointer newroot = findMax(this->_root->left);

				oldroot->right->parent = newroot;
				newroot->right = oldroot->right;
				
				if (oldroot->right == _end)
					_end->right = newroot;

				oldroot->left->parent = newroot;
				
				if (newroot->left != _end)
				{
					if (oldroot->left == newroot)
						newroot->left = oldroot->left->left;
					else
						newroot->left = oldroot->left;
				}
				else 
					this->_end->right = newroot;
				
				newroot->parent = 0;
				
				if (newroot->right == _end)
					this->_end->left = newroot;
				
				delete this->_root;
				_root = newroot;
			}
		}
		else // node is not a root
		{
			if (node == findMin(this->_root)) // delete a min node
			{
				if (node->right)
				{	
					node_pointer newnode = findMin(node->right);
					newnode->left = this->_end;
					this->_end->right = _root;
					node->parent->left = node->right;
					node->right->parent = node->parent;
				}
				else
				{
					node->parent->left = this->_end;
					this->_end->right = _root;
				}
			}
			else if (node == findMax(this->_root)) // delete a max node
			{
				node->parent->right = this->_end;
				this->_end->left = _root;			
			}
			else if (node->left == 0 && node->right == 0) // node is a leaf
			{
				if (node->parent->left == node)
					node->parent->left = 0;
				if (node->parent->right == node)
					node->parent->right = 0;
			}
			else if (node->right == 0) // node has only left child
			{
				if (node == node->parent->right)
				{
					node->parent->right = node->left;
					node->left->parent = node->parent;
				}
				else
				{
					node->parent->left = node->left;
					node->left->parent = node->parent;
				}
				
			}
			else // node has right or both childs
			{
				node_pointer newnode = findMin(node->right);

				if (newnode == newnode->parent->right) // get parent for new node
					newnode->parent->right = 0;
				else
					newnode->parent->left = 0;
				
				newnode->parent = node->parent;

				if (node == node->parent->right) // get child for parent
					node->parent->right = newnode;
				else
					node->parent->left = newnode;

				if (node->left)
				{
					node->left->parent = newnode;
					newnode->left = node->left;
				}
				if (node->right)
				{
					node->right->parent = newnode;
					newnode->right = node->right;
				}
			}

			delete (node);
		}
		this->_size--;
	}

	node_pointer insertNode(node_pointer pos, node_pointer node)
	{
		if (_root == _end)
		{
			this->_root = node;
			this->_root->parent = 0;
			this->_root->left = this->_end;
			this->_root->right = this->_end;
			this->_end->left = this->_root;
			this->_end->right = this->_root;
			this->_size++;
			return this->_root;
		}

		if (pos->pair.first > node->pair.first && pos->left && pos->left != this->_end)
			return insertNode(pos->left, node);
		else if (pos->pair.first < node->pair.first && pos->right && pos->right != this->_end)
			return insertNode(pos->right, node);

		if (pos->pair.first > node->pair.first)
		{
			if (!pos->left) // insert as left child
				pos->left = node;
			else // insert min val
			{
				node->left = this->_end;
				this->_end->right = _root; 
				pos->left = node;
			}
		}
		else if (pos->pair.first < node->pair.first)
		{
			if (!pos->right) // insert as right child
				pos->right = node;
			else // insert max value
			{
				node->right = this->_end;
				this->_end->left = _root;
				pos->right = node;
			}
		}
		node->parent = pos;
		this->_size++;
		return (node);
	}

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

	node_pointer findMin(node_pointer root) const
	{
		if (root && root != _end && root->left && root->left != _end)
			return (findMin(root->left));
		return root;
	}

	node_pointer findMax(node_pointer root) const
	{
		if (root && root != _end && root->right && root->right != _end)
			return (findMax(root->right));
		return root;
	}

public:

explicit map (const key_compare& comp = key_compare(), // empty
	const allocator_type& alloc = allocator_type()) : _allocator(alloc), _size(0), _comp(comp)
{
	this->_end = new MapNode<key_type, mapped_type>();
	this->_end->left = this->_end;
	this->_end->right = this->_end;
	this->_end->parent = 0;
	this->_root = this->_end;
}

template <class InputIterator>
map (InputIterator first, InputIterator last, // range
	const key_compare& comp = key_compare(),
	const allocator_type& alloc = allocator_type()) : _allocator(alloc), _size(0), _comp(comp)
{
	this->_end = new MapNode<key_type, mapped_type>();
	this->_end->left = this->_end;
	this->_end->right = this->_end;
	this->_end->parent = 0;
	this->_root = this->_end;

	while (first != last)
	{
		insert(*first);
		first++;
	}
}

map (const map& x) : _allocator(x._allocator), _size(0), _comp(x._comp) // copy
{
	this->_end = new MapNode<key_type, mapped_type>();
	this->_end->left = this->_end;
	this->_end->right = this->_end;
	this->_end->parent = 0;
	this->_root = this->_end;

	
	const_iterator it = x.begin();
	while (it != x.end())
	{
		insert(*it);
		it++;
	}
}

map& operator= (const map& x) // copy
{
	if (this != &x)
	{
		clear();
		this->insert(x.begin(), x.end());
	}
	return (*this);
}

~map()
{
	while (this->_size != 0)
		erase(this->begin());
	delete (this->_end);
}


/* 
** ITERATORS
*/


iterator begin() { return (iterator(findMin(_root), _end)); }
iterator end() { return (iterator(_end, _end)); }
const_iterator begin() const { return (const_iterator(findMin(_root), _end));	}
const_iterator end() const { return (const_iterator(_end, _end));	}

reverse_iterator rbegin() { return (reverse_iterator(findMax(_root), _end));	}
const_reverse_iterator rbegin() const { return (const_reverse_iterator(findMax(_root), _end));	}
reverse_iterator rend() { return (reverse_iterator(findMin(_root)->left, _root));	}
const_reverse_iterator rend() const { return (const_reverse_iterator(findMin(_root)->left, _root));	}


/* 
** CAPACITY     DONE!
*/


bool empty() const {	return (this->_size == 0);	}
size_type size() const {	return (this->_size);	}
size_type max_size() const {	return  (std::numeric_limits<size_type>::max() / sizeof(MapNode<key_type, mapped_type>));	}


/* 
** ELEMENT ACCESS     DONE!
*/


mapped_type& operator[] (const key_type& k)
{
	iterator tmp = find(k);
	if (tmp != end())
		return (tmp->second);
	else
		return (insert(std::make_pair(k, mapped_type())).first->second);
}


/* 
** MODIFIERS     DONE!
*/


std::pair<iterator,bool> insert (const value_type& val) // single pair
{
	iterator it = this->lower_bound(val.first);
	if ((*it).first == val.first)
		return (std::make_pair(it, false));
	node_pointer newNode = new MapNode<key_type, mapped_type>();
	newNode->pair = std::make_pair(val.first, val.second);
	newNode->parent = 0;
	newNode->left = 0;
	newNode->right = 0;

	insertNode(_root, newNode);
	it = this->lower_bound(val.first);
	return (std::make_pair(it, true));
}

iterator insert (iterator position, const value_type& val) // with hint
{
	if (this->size() == 0)
	{
		this->_root = new MapNode<key_type, mapped_type>();
		this->_root->pair = std::make_pair(val.first, val.second);
		this->_root->parent = 0;
		this->_root->left = this->_end;
		this->_root->right = this->_end;
		this->_end->left = this->_root;
		this->_end->right = this->_root;
		this->_size++;
		return (iterator(this->begin()));
	}
	else
	{
		iterator it = this->lower_bound(val.first);
		if ((*it).first == val.first) 
			return (iterator(position));
		else
		{
			node_pointer newNode = new MapNode<key_type, mapped_type>();
			newNode->pair = std::make_pair(val.first, val.second);
			newNode->parent = 0;
			newNode->left = 0;
			newNode->right = 0;

			insertNode(_root, newNode);
			it = this->lower_bound(val.first);
			return (iterator(it));
		}
	}	
}

template <class InputIterator>
void insert (InputIterator first, InputIterator last) // range
{
	while (first != last)
	{
		insert(*first);
		first++;
	}
}

void erase (iterator position)
{
	eraseNode(position.get_node_ptr());	
}

size_type erase (const key_type& k)
{
	iterator it = this->lower_bound(k);
	if (it != this->end() && (*it).first == k)
		erase(it);
	return (0);

}

void erase (iterator first, iterator last)
{
	while (first != last)
		erase(first++);
}

void swap (map& x)
{
	size_type 		tmpsize = this->_size;
	node_pointer	tmproot = this->_root;
	node_pointer	tmpend = this->_end;

	this->_size = x._size;
	this->_root = x._root;
	this->_end = x._end;

	x._size = tmpsize;
	x._root = tmproot;
	x._end = tmpend;
}

void clear()
{
	this->erase(this->begin(), this->end());
}


/* 
** OBSERVERS     DONE!
*/


key_compare key_comp() const
{
	return (this->_comp.comp);
}

value_compare value_comp() const
{
	return (value_compare(this->_comp.comp));
}


/* 
** OPERATIONS
*/


iterator find (const key_type& k)
{
	iterator it = this->begin();
	while (it != this->end())
	{
		if ((*it).first == k)
			return it;
		it++;
	}
	return (iterator(it));
}


const_iterator find (const key_type& k) const
{
	const_iterator it = this->begin();
	while (it != this->end())
	{
		if ((*it).first == k)
			return it;
		it++;
	}
	return (const_iterator(it));
}


size_type count (const key_type& k) const // 1 (if the element is found) or zero
{
	const_iterator it = this->begin();
	while (it != this->end())
	{
		if ((*it).first == k)
			return (1);
		it++;
	}
	return (0);
}


iterator lower_bound (const key_type& k)
{
	iterator it = this->begin();
	while (it != this->end())
	{
		if (!(_comp.comp(it->first, k)))
			break;
		it++;
	}
	return (it);
}


const_iterator lower_bound (const key_type& k) const
{
	const_iterator it = this->begin();
	while (it != this->end())
	{
		if (!(_comp.comp(it->first, k)))
			break;
		it++;
	}
	return (it);
}


iterator upper_bound (const key_type& k)
{
	iterator it = this->begin();
	while (it != this->end())
	{
		if (this->_comp.comp(k, it->first))
			break;
		it++;
	}
	return (it);
}

const_iterator upper_bound (const key_type& k) const
{
	const_iterator it = this->begin();
	while (it != this->end())
	{
		if (this->_comp.comp(k, it->first))
			break;
		it++;
	}
	return (it);
}


std::pair<const_iterator,const_iterator> equal_range (const key_type& k) const
{
	return (std::pair<const_iterator, const_iterator>(this->lower_bound(k), this->upper_bound(k)));
}


std::pair<iterator,iterator> equal_range (const key_type& k)
{
	return (std::pair<iterator, iterator>(this->lower_bound(k), this->upper_bound(k)));
}


}; // end of class map

/* 
** NON-MEMBER FUNCTIONS OVERLOAD     DONE!
*/


template <class Key, class T, class Compare, class Alloc>
bool operator== ( const map<Key,T,Compare,Alloc>& lhs,
	const map<Key,T,Compare,Alloc>& rhs )
{
	if (lhs.size() != rhs.size())
		return (false);
	typename map<Key,T,Compare,Alloc>::const_iterator end1 = rhs.end();
	typename map<Key,T,Compare,Alloc>::const_iterator end2 = lhs.end();

	typename map<Key,T,Compare,Alloc>::const_iterator b1 = rhs.begin();
	typename map<Key,T,Compare,Alloc>::const_iterator b2 = lhs.begin();
	while (b1 != end1 && b2 != end2)
	{
		if (b1->first != b2->first || b1->second != b2->second)
			return false;
		++b1;
		++b2;
	}
	return (b1 == end1 && b2 == end2);
	
}

template <class Key, class T, class Compare, class Alloc>
bool operator!=(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
{
	return (!(lhs == rhs));
}

template <class Key, class T, class Compare, class Alloc>
bool operator<(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
{
	if (lhs.size() < rhs.size())
		return true;
	if (lhs.size() > rhs.size())
		return false;
	typename ft::map<Key,T,Compare,Alloc>::const_iterator l_it = lhs.begin();
	typename ft::map<Key,T,Compare,Alloc>::const_iterator r_it = rhs.begin();

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

template <class Key, class T, class Compare, class Alloc>
bool operator<=(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
{
	return (!(rhs < lhs));
}

template <class Key, class T, class Compare, class Alloc>
bool operator>(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
{
	return (rhs < lhs);
}

template <class Key, class T, class Compare, class Alloc>
bool operator>=(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
{
	return (!(lhs < rhs));
}

template <class Key, class T, class Compare, class Alloc>
void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y)
{
	x.swap(y);
}

}; //end of namespace

#endif