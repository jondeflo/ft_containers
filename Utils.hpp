#ifndef UTILS_HPP
#define UTILS_HPP

namespace ft
{

template<bool B, class P = void>
struct enable_if {};

template<class P>
struct enable_if<true, P> { typedef P type; };


typedef std::true_type ret_true;
typedef std::false_type ret_false;

template <class T>
struct is_integral : public ret_false{};

 template <>
struct is_integral<bool> : public ret_true{};

template <>
struct is_integral<char> : public ret_true{};

template <>
struct is_integral<signed char> : public ret_true{};

template <>
struct is_integral<unsigned char> : public ret_true{};

template <>
struct is_integral<wchar_t> : public ret_true{};

template <>
struct is_integral<short> : public ret_true{};

template <>
struct is_integral<int> : public ret_true{};

template <>
struct is_integral<long> : public ret_true{};

template <>
struct is_integral<long long> : public ret_true{};

template <>
struct is_integral<unsigned short> : public ret_true{};

template <>
struct is_integral<unsigned int> : public ret_true{};

template <>
struct is_integral<unsigned long> : public ret_true{};

template <>
struct is_integral<unsigned long long> : public ret_true{};

template <typename K, typename V>
struct MapNode
{
	std::pair<K, V> pair;
	MapNode	*parent;
	MapNode	*left;
	MapNode	*right;
};

template <typename T>
class ListNode
{

public:

	ListNode	*prev;
	T			data;
	ListNode	*next;

	ListNode(const T& data = T()) : prev(0), data(data), next(0) {}
	ListNode(const ListNode& other) : prev(other.prev), data(other.data), next(other.next) {}
	~ListNode(void) {}

	ListNode& operator=(const ListNode& other)
	{
		if (this != &other)
		{
			this->data = other.data;
			this->prev = other.prev;
			this->next = other.next;
		}
		return (*this);
	}

	bool operator==(const ListNode& other) const
	{
		if (this->data == other.data && this->prev == other.prev && this->next == other.next)
			return true;
		return false;
	}

};

};

#endif