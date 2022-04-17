#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <stack>
#include <queue>
#include "vector.hpp"
#include "list.hpp"
#include "map.hpp"
#include "stack.hpp"
#include "queue.hpp"

template <typename T, typename U>
void print_vector(T& native, U& my)
{
	size_t i = 0;

	typename T::iterator it;
	std::cout << "\033[91m";
	std::cout << "std::vector: size " << native.size() << ", capacity " 
	<< native.capacity() << std::endl;
	for (it = native.begin(); it != native.end(); it++)
		std::cout << *it << ", ";
	std::cout << std::endl;

	i = 0;
	typename U::iterator my_it;
	std::cout << "\033[93m";
	
	for (my_it = my.begin(); my_it != my.end(); my_it++)
		std::cout << *my_it << ", ";
	std::cout << "\n ft::vector: size " << my.size() << ", capacity " 
	<< my.capacity() << std::endl;

	std::cout << "\033[0m";
}

template <typename T, typename U>
void print_list(T& native, U& my)
{
	size_t i = 0;

	typename T::iterator it;
	std::cout << "\033[91m";
	std::cout << "std::list, size " << native.size() << std::endl;
	for (it = native.begin(); it != native.end(); it++)
		std::cout << *it << ", ";
	std::cout << std::endl;

	i = 0;
	typename U::iterator my_it;
	std::cout << "\033[93m";
	for (my_it = my.begin(); my_it != my.end(); my_it++)
		std::cout << *my_it << ", ";
	std::cout << "\n ft::list, size " << my.size() << std::endl;
	std::cout << "\033[0m";
}

template <typename T, typename U>
void print_map(T& native, U& my)
{
	typename T::iterator it;
	std::cout << "\033[91m";
	for (it = native.begin(); it != native.end(); it++)
		std::cout << "std::map (key " << it->first << ") : " << it->second << std::endl;
	std::cout << "--> size " << native.size() << std::endl;


	typename U::iterator my_it = my.begin();
	std::cout << "\033[93m";
	for (my_it = my.begin(); my_it != my.end(); my_it++)
		std::cout << " ft::map (key " << my_it->first << ") : " << my_it->second << std::endl;
	std::cout << "--> size " << my.size() << std::endl;
	std::cout << "\033[0m" << std::endl;
}

bool pred_int (const int& value)
{ 
	if (value == 31)
		return true; 
	return false;
}

bool bin_pred_int (const int& a, const int& b) 
{ 
	return (a == b);
}

bool pred_str (const std::string& value)
{ 
	if (value == "charlie")
		return true; 
	return false;
}

bool bin_pred_str (const std::string& a, const std::string& b)
{ 
	return (a == b);
}

bool compare_less_int (const int& a, const int& b)
{
	if (a < b)
		return true;
	return false;
}

bool compare_less_str (const std::string& a, const std::string& b)
{
	if (a < b)
		return true;
return false;
}

void test_vector_int(void)
{
	std::vector<int> test_insert;
	std::vector<int>::iterator it_test;

	test_insert.push_back(30);
	test_insert.push_back(31);
	test_insert.push_back(32);
	test_insert.push_back(33);

	int arr[] = {41,42,43,44,45,46,47,48,49};

	std::vector<int> native;
	std::vector<int>::iterator native_it;

	ft::vector<int> my;
	ft::VectorIterator<int> my_it;


	std::cout << "\033[35m>>>>>   P A R T   1 :   V E C T O R < i n t >   <<<<<\033[0m" <<std::endl;
	
	std::cout << "\n\033[97m==========  CAPACITY ========== \033[0m" << std::endl; 

	std::cout << "\nMax size: native "<< native.max_size() << ", my " << my.max_size() << std::endl;
	
	std::cout << "\nIs empty? (1 - empty, 0 - not): native "<< native.empty() << ", my " << my.empty() << std::endl;
	
	std::cout << "\nResize to 5" << std::endl;
	native.resize(5);
	my.resize(5);
	print_vector(native, my);

	std::cout << "\nResize to 8 with value to fill \'77\'" << std::endl;
	native.resize(8, 77);
	my.resize(8, 77);
	print_vector(native, my);

	std::cout << "\nIs empty now? (1 - empty, 0 - not): native "<< native.empty() << ", my " << my.empty() << std::endl;

	std::cout << "\nReserve 3, nothing should happens" << std::endl;
	native.reserve(3);
	my.reserve(3);
	print_vector(native, my);

	std::cout << "\nReserve 18" << std::endl;
	native.reserve(18);
	my.reserve(18);
	print_vector(native, my);

	
	std::cout << "\n\033[97m==========  ELEMENT ACCESS ========== \033[0m" << std::endl; // [], at, front. back

	std::cout << "\nValue [5]: native "<< native[5] << ", my " << my[5] << std::endl;
	native.push_back(21);
	my.push_back(21);
	std::cout << "New \'pushed to back\' value [8]: native "<< native[8] << ", my " << my[8] << std::endl;
	std::cout << "Non-existing value [99]: native "<< native[99] << ", my " << my[99] << std::endl;

	std::cout << "\nValue at 5: native "<< native.at(5) << ", my " << my.at(5) << std::endl;
	std::cout << "Value at 8: native "<< native.at(8) << ", my " << my.at(8) << std::endl;
	
	try { std::cout << "Non-existing value at -1: native " << native.at(-1) << std::endl;}
	catch(const std::exception& e) { std::cout << "catch an exeption at non-existing value at -1" << std::endl;}
	try { std::cout << "Non-existing value at -1: my " << my.at(-1) << std::endl;}
	catch(const std::exception& e) { std::cout << "catch an exeption at non-existing value at -1" << std::endl;}

	std::cout << "\nFront: native "<< native.front() << ", my " << my.front() << std::endl;
	std::cout << "Back: native "<< native.back() << ", my " << my.back() << std::endl;
	native.push_back(23);
	my.push_back(23);
	std::cout << "Back after pushing \'23\': native "<< native.back() << ", my " << my.back() << std::endl;


	
	std::cout << "\n\033[97m==========  MODIFIERS ========== \033[0m" << std::endl; 
	// assign range, assign fill, push_back, pop_back, insert one, insert fill, insert range, erase one, erase range, swap, clear

	std::cout << "\nAssign (fill) to size 5 with \'19\'" << std::endl; 
	native.assign(5, 19);
	my.assign(5, 19);
	print_vector(native, my);

	std::cout << "\nAssign (range) 7 elements from {41,42,43,44,45,46,47,48,49} array" << std::endl; 
	native.assign(arr, arr+7);
	my.assign(arr, arr+7);
	print_vector(native, my);

	std::cout << "\nPush back \'51\'" << std::endl;
	native.push_back(51);
	my.push_back(51);
	print_vector(native, my);

	std::cout << "\nPop back twice" << std::endl;
	native.pop_back();
	native.pop_back();
	my.pop_back();
	my.pop_back();
	print_vector(native, my);

	native_it = native.begin();
	std::cout << "\nInsert single value to begin and near by (using iterators)" << std::endl;
	native.insert(native_it, 933);
	native_it = native.begin();
	native_it++;
	native.insert(native_it, 822);
	
	my_it = my.begin();
	my.insert(my_it, 933);
	my_it = my.begin();
	my_it++;
	my.insert(my_it, 822);
	print_vector(native, my);

	std::cout << "\nInsert (fill) value \'222\' to positions from 2 to 5" << std::endl;
	native.insert(native.begin() + 2, 4, 222);
	my.insert(my.begin() + 2, 4, 222);
	print_vector(native, my);

	std::cout << "\nInsert (range) values from different vector to positions from 5 to 8" << std::endl;
	native.insert(native.begin() + 5, test_insert.begin(), test_insert.end());
	my.insert(my.begin() + 5, test_insert.begin(), test_insert.end());
	print_vector(native, my);
	
	std::cout << "\nErase one \'222\' at position 9" << std::endl;
	native.erase(native.begin() + 9);
	my.erase(my.begin() + 9);
	print_vector(native, my);

	std::cout << "\nErase range from begin to position 9" << std::endl;
	native.erase(native.begin(), native.begin() + 9);
	my.erase(my.begin(), my.begin() + 9);
	print_vector(native, my);

	std::cout << "\nCopy vector" << std::endl;
	ft::vector<int> my_copy(my);
	my.assign(5, 19);
	my_copy.assign(3, 77);
	print_vector(my, my_copy);

	std::cout << "\nThen swap it" << std::endl;
	my.swap(my_copy);
	print_vector(my, my_copy);
	my.swap(my_copy);

	std::cout << "\nThen clear" << std::endl;
	native.clear();
	my.clear();
	print_vector(native, my);



	std::cout << "\n\033[97m==========  NON-MEMBER FUNCTIONS OVERLOAD ========== \033[0m" << std::endl;
	// == != < <= > >=

	my.assign(5, 82);
	my_copy.assign(5, 82);

	std::cout << "\nTwo equal vectors, comparator \'==\' (1 - true, 0 - false): " << (my == my_copy) <<std::endl;
	std::cout << "Two equal vectors, comparator \'!=\' (1 - true, 0 - false): " << (my != my_copy) <<std::endl;
	std::cout << "Two equal vectors, comparator \'<\' (1 - true, 0 - false): " << (my < my_copy) <<std::endl;
	std::cout << "Two equal vectors, comparator \'<=\' (1 - true, 0 - false): " << (my <= my_copy) <<std::endl;
	std::cout << "Two equal vectors, comparator \'>\' (1 - true, 0 - false): " << (my > my_copy) <<std::endl;
	std::cout << "Two equal vectors, comparator \'>=\' (1 - true, 0 - false): " << (my >= my_copy) <<std::endl;

	my_copy.push_back(69);

	std::cout << "\nTwo non-equal vectors, comparator \'==\' (1 - true, 0 - false): " << (my == my_copy) <<std::endl;
	std::cout << "Two non-equal vectors, comparator \'!=\' (1 - true, 0 - false): " << (my != my_copy) <<std::endl;
	std::cout << "Two non-equal vectors, comparator \'<\' (1 - true, 0 - false): " << (my < my_copy) <<std::endl;
	std::cout << "Two non-equal vectors, comparator \'<=\' (1 - true, 0 - false): " << (my <= my_copy) <<std::endl;
	std::cout << "Two non-equal vectors, comparator \'>\' (1 - true, 0 - false): " << (my > my_copy) <<std::endl;
	std::cout << "Two non-equal vectors, comparator \'>=\' (1 - true, 0 - false): " << (my >= my_copy) <<std::endl;

	std::cout << "\n\033[97m==========  ITERATOR ========== \033[0m" << std::endl;
	
	std::cout << "\nAssign (range) 7 elements from {41,42,43,44,45,46,47,48,49} array" << std::endl; 
	my.assign(arr, arr+7);
	ft::vector<int>::reverse_iterator rev_it = my.rbegin();
	my_it = my.begin();
	std::cout << "Forward iterator" << std::endl;
	while (my_it != my.end())
		std::cout << *my_it++ << ", ";
	std::cout << std::endl;
	std::cout << "Reverse iterator" << std::endl;
	while (rev_it != my.rend())
		std::cout << *rev_it++ << ", ";
	std::cout << std::endl;

	ft::vector<int>::const_iterator c_it = my.begin();
	ft::vector<int>::const_reverse_iterator cr_it = my.rbegin();
	std::cout << "Const Forward iterator" << std::endl;
	while (c_it != my.end())
		std::cout << *c_it++ << ", ";
	std::cout << std::endl;
	std::cout << "Const Reverse iterator" << std::endl;
	while (cr_it != my.rend())
		std::cout << *cr_it++ << ", ";
	std::cout << std::endl;


	std::cout << "Copy constructor, assign constructor (native and my is a copies here)" << std::endl;
	ft::vector<int>	copy1(my);
	ft::vector<int> copy2 = my;
	print_vector(copy1, copy2);

	//test_insert.clear(); native.clear();my.clear();my_copy.clear();


	std::cout <<std::endl <<std::endl << "\033[35m>>>>>   E N D   O F   V E C T O R < i n t >   <<<<<\033[0m" <<std::endl <<std::endl;

}

void test_vector_string(void)
{
	std::vector<std::string> test_insert;
	std::vector<std::string>::iterator it_test;

	test_insert.push_back("alpha");
	test_insert.push_back("bravo");
	test_insert.push_back("charlie");
	test_insert.push_back("delta");

	std::string arr[] = {"kilo","lima","november","oscar","papa","quebec","romeo","sierra"};


	std::vector<std::string> native;
	std::vector<std::string>::iterator native_it;

	ft::vector<std::string> my;
	ft::VectorIterator<std::string> my_it;



	std::cout << "\033[35m>>>>>   P A R T   2 :   V E C T O R < s t r i n g >   <<<<<\033[0m" <<std::endl;
	
	std::cout << "\n\033[97m==========  CAPACITY ========== \033[0m" << std::endl; 

	std::cout << "\nMax size: native "<< native.max_size() << ", my " << my.max_size() << std::endl;
	
	std::cout << "\nIs empty? (1 - empty, 0 - not): native \'" << native.empty() << "\', my \'" << my.empty() << "\'"<< std::endl;
	
	std::cout << "\nResize to 5" << std::endl;
	native.resize(5);
	my.resize(5);
	print_vector(native, my);



	std::cout << "\nResize to 8 with value to fill \'india\'" << std::endl;
	native.resize(8, "india");
	my.resize(8, "india");
	print_vector(native, my);

	std::cout << "\nIs empty now? (1 - empty, 0 - not): native \'" << native.empty() << "\', my \'" << my.empty() << "\'"<< std::endl;

	std::cout << "\nReserve 3, nothing should happens" << std::endl;
	native.reserve(3);
	my.reserve(3);
	print_vector(native, my);

	std::cout << "\nReserve 18" << std::endl;
	native.reserve(18);
	my.reserve(18);
	print_vector(native, my);


	
	std::cout << "\n\033[97m==========  ELEMENT ACCESS ========== \033[0m" << std::endl; // [], at, front. back

	std::cout << "\nValue [5]: native \'"<< native[5] << "\', my \'" << my[5] << "\'"<< std::endl;
	native.push_back("victor");
	my.push_back("victor");
	std::cout << "New \'pushed to back\' value [8]: native \'"<< native[8] << "\', my \'" << my[8] << "\'"<< std::endl;
	
	
	
	std::cout << "Non-existing value [99]: native \'"<< native[99] << "\', my \'" << my[99] << "\'" << std::endl;

	std::cout << "\nValue at 5: native \'"<< native.at(5) << "\', my \'" << my.at(5) << "\'"<< std::endl;
	std::cout << "Value at 8: native \'"<< native.at(8) << "\', my \'" << my.at(8) << "\'"<< std::endl;
	
	try { std::cout << "Non-existing value at -1: native \'" << native.at(-1) << std::endl;}
	catch(const std::exception& e) { std::cout << "catch an exeption at non-existing value at -1\'" << std::endl;}
	try { std::cout << "Non-existing value at -1: my \'" << my.at(-1) << std::endl;}
	catch(const std::exception& e) { std::cout << "catch an exeption at non-existing value at -1\'" << std::endl;}

	std::cout << "\nFront: native \'"<< native.front() << "\', my \'" << my.front() << "\'"<< std::endl;
	std::cout << "Back: native \'"<< native.back() << "\', my \'" << my.back() << "\'"<< std::endl;
	native.push_back("tango");
	my.push_back("tango");
	std::cout << "Back after pushing \'tango\': native \'"<< native.back() << "\', my \'" << my.back() << "\'"<< std::endl;


	
	std::cout << "\n\033[97m==========  MODIFIERS ========== \033[0m" << std::endl; 
	// assign range, assign fill, push_back, pop_back, insert one, insert fill, insert range, erase one, erase range, swap, clear

	std::cout << "\nAssign (fill) to size 5 with \'juliett\'" << std::endl; 
	native.assign(5, "juliett");
	my.assign(5, "juliett");
	print_vector(native, my);

	std::cout << "\nAssign (range) 7 elements from string array" << std::endl; 
	native.assign(arr, arr + 7);
	my.assign(arr, arr + 7);
	print_vector(native, my);

	std::cout << "\nPush back \'x-ray\'" << std::endl;
	native.push_back("x-ray");
	my.push_back("x-ray");
	print_vector(native, my);

	std::cout << "\nPop back twice" << std::endl;
	native.pop_back();
	native.pop_back();
	my.pop_back();
	my.pop_back();
	print_vector(native, my);



	native_it = native.begin();
	std::cout << "\nInsert single value to begin and near by (using iterators)" << std::endl;
	native.insert(native_it, "yankee");
	native_it = native.begin();
	native_it++;
	native.insert(native_it, "zulu");
	
	my_it = my.begin();
	my.insert(my_it, "yankee");
	my_it = my.begin();
	my_it++;
	my.insert(my_it, "zulu");
	print_vector(native, my);

	std::cout << "\nInsert (fill) value \'golf\' to positions from 2 to 5" << std::endl;
	native.insert(native.begin() + 2, 4, "golf");
	my.insert(my.begin() + 2, 4, "golf");
	print_vector(native, my);

	std::cout << "\nInsert (range) values from different vector to positions from 5 to 8" << std::endl;
	native.insert(native.begin() + 5, test_insert.begin(), test_insert.end());
	my.insert(my.begin() + 5, test_insert.begin(), test_insert.end());
	print_vector(native, my);
	
	std::cout << "\nErase one \'golf\' at position 9" << std::endl;
	native.erase(native.begin() + 9);
	my.erase(my.begin() + 9);
	print_vector(native, my);

	std::cout << "\nErase range from begin to position 9" << std::endl;
	native.erase(native.begin(), native.begin() + 9);
	my.erase(my.begin(), my.begin() + 9);
	print_vector(native, my);

	std::cout << "\nCopy vector" << std::endl;
	ft::vector<std::string> my_copy(my);
	my.assign(5, "echo");
	my_copy.assign(3, "delta");
	print_vector(my, my_copy);

	std::cout << "\nThen swap it" << std::endl;
	my.swap(my_copy);
	print_vector(my, my_copy);
	my.swap(my_copy);

	std::cout << "\nThen clear" << std::endl;
	native.clear();
	my.clear();
	print_vector(native, my);



	std::cout << "\n\033[97m==========  NON-MEMBER FUNCTIONS OVERLOAD ========== \033[0m" << std::endl;
	// == != < <= > >=

	my.assign(5, "hotel");
	my_copy.assign(5, "hotel");

	std::cout << "\nTwo equal vectors, comparator \'==\' (1 - true, 0 - false): " << (my == my_copy) <<std::endl;
	std::cout << "Two equal vectors, comparator \'!=\' (1 - true, 0 - false): " << (my != my_copy) <<std::endl;
	std::cout << "Two equal vectors, comparator \'<\' (1 - true, 0 - false): " << (my < my_copy) <<std::endl;
	std::cout << "Two equal vectors, comparator \'<=\' (1 - true, 0 - false): " << (my <= my_copy) <<std::endl;
	std::cout << "Two equal vectors, comparator \'>\' (1 - true, 0 - false): " << (my > my_copy) <<std::endl;
	std::cout << "Two equal vectors, comparator \'>=\' (1 - true, 0 - false): " << (my >= my_copy) <<std::endl;

	std::cout << "\nPush back to copy to create difference" << std::endl;
	my_copy.push_back("foxtrot");

	std::cout << "\nTwo non-equal vectors, comparator \'==\' (1 - true, 0 - false): " << (my == my_copy) <<std::endl;
	std::cout << "Two non-equal vectors, comparator \'!=\' (1 - true, 0 - false): " << (my != my_copy) <<std::endl;
	std::cout << "Two non-equal vectors, comparator \'<\' (1 - true, 0 - false): " << (my < my_copy) <<std::endl;
	std::cout << "Two non-equal vectors, comparator \'<=\' (1 - true, 0 - false): " << (my <= my_copy) <<std::endl;
	std::cout << "Two non-equal vectors, comparator \'>\' (1 - true, 0 - false): " << (my > my_copy) <<std::endl;
	std::cout << "Two non-equal vectors, comparator \'>=\' (1 - true, 0 - false): " << (my >= my_copy) <<std::endl;

	std::cout << "\n\033[97m==========  ITERATOR ========== \033[0m" << std::endl;
	
	std::cout << "\nAssign (range) 7 elements from string array" << std::endl; 
	my.assign(arr, arr+7);
	ft::vector<std::string>::reverse_iterator rev_it = my.rbegin();
	my_it = my.begin();
	std::cout << "Normal iterator" << std::endl;
	while (my_it != my.end())
		std::cout << *my_it++ << ", ";
	std::cout << std::endl;
	std::cout << "Reverse iterator" << std::endl;
	while (rev_it != my.rend())
		std::cout << *rev_it++ << ", ";
	std::cout << std::endl;

	ft::vector<std::string>::const_iterator c_it = my.begin();
	ft::vector<std::string>::const_reverse_iterator cr_it = my.rbegin();
	std::cout << "Const Forward iterator" << std::endl;
	while (c_it != my.end())
		std::cout << *c_it++ << ", ";
	std::cout << std::endl;
	std::cout << "Const Reverse iterator" << std::endl;
	while (cr_it != my.rend())
		std::cout << *cr_it++ << ", ";
	std::cout << std::endl;


	std::cout << "Copy constructor, assign constructor (native and my is a copies here)" << std::endl;
	ft::vector<std::string>	copy1(my);
	ft::vector<std::string> copy2 = my;
	print_vector(copy1, copy2);


	std::cout <<std::endl <<std::endl << "\033[35m>>>>>   E N D   O F   V E C T O R < s t r i n g >   <<<<<\033[0m" <<std::endl <<std::endl;

}

void test_list_int(void)
{
	std::list<int> st;
	ft::list<int> my;

	std::list<int> test_insert;

	test_insert.push_back(30);
	test_insert.push_back(31);
	test_insert.push_back(32);
	test_insert.push_back(33);

	int arr[] = {41,42,43,44,45,46,47,48,49};

	std::cout << "\033[35m>>>>>   P A R T   3 :   L I S T < i n t >   <<<<<\033[0m" <<std::endl;
	
	std::cout << "\n\033[97m==========  CAPACITY ========== \033[0m" << std::endl; 
	std::cout << "\nMax size: native "<< st.max_size() << ", my " << my.max_size() << std::endl;
	std::cout << "\nIs empty? (1 - empty, 0 - not): native "<< st.empty() << ", my " << my.empty() << std::endl;

	
	std::cout << "\n\033[97m==========  ELEMENT ACCESS ========== \033[0m" << std::endl; 
	std::cout << "Native front: " << st.front() << ", my front: " << my.front() << std::endl;
	std::cout << "Native back: " << st.back() << ", my back: " << my.back() << std::endl;
	print_list(st, my);

	std::cout << "\n\033[97m==========  MODIFIERS ========== \033[0m" << std::endl;
	std::cout << "\nPush front \'19\'" << std::endl;
	st.push_front(19);
	my.push_front(19);
	print_list(st, my);

	std::cout << "\nPush front \'29\'" << std::endl;
	st.push_front(29);
	my.push_front(29);
	print_list(st, my);

	std::cout << "\nPush front \'39\'" << std::endl;
	st.push_front(39);
	my.push_front(39);
	print_list(st, my);

	std::cout << "\nPop front" << std::endl;
	st.pop_front();
	my.pop_front();
	print_list(st, my);

	std::cout << "\nPush back \'49\'" << std::endl;
	st.push_back(49);
	my.push_back(49);
	print_list(st, my);

	std::cout << "\nPop back" << std::endl;
	st.pop_back();
	my.pop_back();
	print_list(st, my);

	std::list<int>::iterator st_it = st.begin(); st_it++;
	ft::list<int>::iterator my_it = my.begin(); my_it++;
	std::cout << "\nInsert \'59\' at position begin + 1" << std::endl;
	st.insert(st_it, 59);
	my.insert(my_it, 59);
	print_list(st, my);

	std::cout << "\nInsert \'69\' 3 times at position begin + 2" << std::endl;
	st_it = st.begin(); st_it++; st_it++;
	my_it = my.begin(); my_it++; my_it++;
	st.insert(st_it, 3, 69);
	my.insert(my_it, 3, 69);
	print_list(st, my);

	std::cout << "\nInsert \'41-44\' at position begin + 1 from int array" << std::endl;
	st_it = st.begin(); st_it++;
	my_it = my.begin(); my_it++;
	st.insert(st_it, arr, arr + 4);
	my.insert(my_it, arr, arr + 4);
	print_list(st, my);

	std::cout << "\nInsert \'30-33\' at position begin + 1 from another list" << std::endl;
	st_it = st.begin(); st_it++;
	my_it = my.begin(); my_it++;
	st.insert(st_it, test_insert.begin(), test_insert.end());
	my.insert(my_it, test_insert.begin(), test_insert.end());
	print_list(st, my);

	std::cout << "\nAssign \'79\' 5 times" << std::endl;
	st.assign(5, 79);
	my.assign(5, 79);
	print_list(st, my);

	std::cout << "\nAssign \'30-33\' from another list" << std::endl;
	st.assign(test_insert.begin(), test_insert.end());
	my.assign(test_insert.begin(), test_insert.end());
	print_list(st, my);

	std::cout << "\nErase one at position begin + 1" << std::endl;
	st_it = st.begin(); st_it++;
	my_it = my.begin(); my_it++;
	st.erase(st_it);
	my.erase(my_it);
	print_list(st, my);
	
	std::cout << "\nPush to front values \'99 & 89\' " << std::endl;
	st.push_front(99);st.push_front(89);
	my.push_front(99);my.push_front(89);
	print_list(st, my);
	
	std::cout << "\nThen erase from position 2 to last (excluding last)" << std::endl;
	st.erase(++st.begin(), --st.end());
	my.erase(++my.begin(), --my.end());
	print_list(st, my);

	std::cout << "\nResize to 10 with value \'19\'" << std::endl;
	st.resize(10, 19);
	my.resize(10, 19);
	print_list(st, my);

	std::cout << "\nResize to 3 with value \'29\'" << std::endl;
	st.resize(3, 29);
	my.resize(3, 29);
	print_list(st, my);

	std::cout << "\nResize to 5 without value" << std::endl;
	st.resize(5);
	my.resize(5);
	print_list(st, my);

	std::cout << "\nCreate copy of list" << std::endl;
	ft::list<int> my_copy(my);
	print_list(my, my_copy);

	std::cout << "\nCreate a difference in lists" << std::endl;
	my.push_back(11);
	my_copy.pop_front();
	print_list(my, my_copy);

	std::cout << "\nThen swap it" << std::endl;
	my.swap(my_copy);
	print_list(my, my_copy);

	

	std::cout << "\n\033[97m==========  OPERATIONS ========== \033[0m" << std::endl;

	std::cout << "\nAssign values to lists" << std::endl;
	my.assign(test_insert.begin(), test_insert.end());
	my_copy.assign(arr, arr+4);
	print_list(my, my_copy);

	my_it = my.begin(); ++my_it; 
	std::cout << "\nThen splice single element to position 2" << std::endl;
	my.splice(my_it, my_copy, my_copy.begin());
	print_list(my, my_copy);

	std::cout << "\nThen splice entire list to position 3" << std::endl;
	++my_it; 
	my.splice(my_it, my_copy);
	print_list(my, my_copy);

	std::cout << "\nThen splice backward from 3rd to end-1" << std::endl;
	my_it = my.begin(); my_it++;my_it++;my_it++;
	my_copy.splice(my_copy.begin(), my, my_it, my.end());
	print_list(my, my_copy);

	std::cout << "\nAssign \'30-33\' from another list" << std::endl;
	st.assign(test_insert.begin(), test_insert.end());
	my.assign(test_insert.begin(), test_insert.end());
	print_list(st, my);

	std::cout << "\nThen remove value\'32\'" << std::endl;
	st.assign(test_insert.begin(), test_insert.end());
	my.assign(test_insert.begin(), test_insert.end());
	st.remove(32);
	my.remove(32);
	print_list(st, my);

	std::cout << "\nRemove if value == \'31\'" << std::endl;
	st.remove_if(pred_int);
	my.remove_if(pred_int);
	print_list(st, my);

	std::cout << "\nPrepare lists for unique() test" << std::endl;
	st.assign(test_insert.begin(), test_insert.end());
	st.push_back(33); st.push_back(33); st.push_back(44);
	my.assign(test_insert.begin(), test_insert.end());
	my.push_back(33); my.push_back(33); my.push_back(44);
	print_list(st, my);
	std::cout << "\nCall unique()" << std::endl;
	st.unique();
	my.unique();
	print_list(st, my);

	std::cout << "\nPrepare lists for unique() test with binary predicate" << std::endl;
	st.assign(test_insert.begin(), test_insert.end());
	st.push_back(33); st.push_back(33); st.push_back(44);
	my.assign(test_insert.begin(), test_insert.end());
	my.push_back(33); my.push_back(33); my.push_back(44);
	print_list(st, my);
	std::cout << "\nCall unique() with binary predicate (prev == next)" << std::endl;
	st.unique(bin_pred_int);
	my.unique(bin_pred_int);
	print_list(st, my);



	std::cout << "\nCreate unsorted lists" << std::endl;
	st.clear();
	st.push_front(5); st.push_front(25); st.push_front(4); st.push_front(25); st.push_front(35); st.push_front(1);
	my.clear();
	my.push_front(5); my.push_front(25); my.push_front(4); my.push_front(25); my.push_front(35); my.push_front(1);
	print_list(st, my);
	
	std::cout << "\nThen sort it" << std::endl;
	st.sort();
	my.sort();
	print_list(st, my);


	std::cout << "\nCreate unsorted lists again" << std::endl;
	st.clear();
	st.push_front(5); st.push_front(25); st.push_front(4); st.push_front(25); st.push_front(35); st.push_front(1);
	my.clear();
	my.push_front(5); my.push_front(25); my.push_front(4); my.push_front(25); my.push_front(35); my.push_front(1);
	print_list(st, my);
	
	std::cout << "\nThen sort it with \'comp\'" << std::endl;
	st.sort(compare_less_int);
	my.sort(compare_less_int);
	print_list(st, my);

	std::cout << "\nCreate damned unsorted lists again" << std::endl;
	st.clear();
	st.push_front(5); st.push_front(25); st.push_front(4); st.push_front(25); st.push_front(35); st.push_front(1);
	my.clear();
	my.push_front(5); my.push_front(25); my.push_front(4); my.push_front(25); my.push_front(35); my.push_front(1);
	print_list(st, my);

	std::cout << "\nCreate two lists for merging" << std::endl;
	std::list<int> st_m;
	ft::list<int> my_m;
	st_m.push_back(1);st_m.push_back(2);st_m.push_back(3);st_m.push_back(40);
	my_m.push_back(1);my_m.push_back(2);my_m.push_back(3);my_m.push_back(40);
	st_m.sort();
	my_m.sort();
	print_list(st_m, my_m);
	
	std::cout << "\nThen merge it" << std::endl;
	st.merge(st_m);
	my.merge(my_m);
	print_list(st, my);

	std::cout << "\nCreate damned unsorted lists last time" << std::endl;
	st.clear();
	st.push_front(5); st.push_front(25); st.push_front(4); st.push_front(25); st.push_front(35); st.push_front(1);
	my.clear();
	my.push_front(5); my.push_front(25); my.push_front(4); my.push_front(25); my.push_front(35); my.push_front(1);
	print_list(st, my);

	std::cout << "\nCreate two lists for merging" << std::endl;
	std::list<int> st_m1;
	ft::list<int> my_m1;
	st_m1.push_back(1);st_m1.push_back(2);st_m1.push_back(3);st_m1.push_back(40);
	my_m1.push_back(1);my_m1.push_back(2);my_m1.push_back(3);my_m1.push_back(40);
	st_m1.sort();
	my_m1.sort();
	print_list(st_m1, my_m1);
	
	std::cout << "\nThen merge it with \'comp\'" << std::endl;
	st.merge(st_m1, compare_less_int);
	my.merge(my_m1, compare_less_int);
	print_list(st, my);

	std::cout << "\nReverse list" << std::endl;
	st.reverse();
	my.reverse();
	print_list(st, my);



	std::cout << "\n\033[97m==========  NON-MEMBER FUNCTIONS OVERLOAD ========== \033[0m" << std::endl;

	my_copy.assign(my.begin(), my.end());
	print_list(my, my_copy);

	std::cout << "\nTwo equal lists, comparator \'==\' (1 - true, 0 - false): " << (my == my_copy) <<std::endl;
	std::cout << "Two equal lists, comparator \'!=\' (1 - true, 0 - false): " << (my != my_copy) <<std::endl;
	std::cout << "Two equal lists, comparator \'<\' (1 - true, 0 - false): " << (my < my_copy) <<std::endl;
	std::cout << "Two equal lists, comparator \'<=\' (1 - true, 0 - false): " << (my <= my_copy) <<std::endl;
	std::cout << "Two equal lists, comparator \'>\' (1 - true, 0 - false): " << (my > my_copy) <<std::endl;
	std::cout << "Two equal lists, comparator \'>=\' (1 - true, 0 - false): " << (my >= my_copy) <<std::endl;

	std::cout << "\nPushback \'29\'to one of them and compare" << std::endl;
	my_copy.push_back(29);
	print_list(my, my_copy);

	std::cout << "\nTwo non-equal lists, comparator \'==\' (1 - true, 0 - false): " << (my == my_copy) <<std::endl;
	std::cout << "Two non-equal lists, comparator \'!=\' (1 - true, 0 - false): " << (my != my_copy) <<std::endl;
	std::cout << "Two non-equal lists, comparator \'<\' (1 - true, 0 - false): " << (my < my_copy) <<std::endl;
	std::cout << "Two non-equal lists, comparator \'<=\' (1 - true, 0 - false): " << (my <= my_copy) <<std::endl;
	std::cout << "Two non-equal lists, comparator \'>\' (1 - true, 0 - false): " << (my > my_copy) <<std::endl;
	std::cout << "Two non-equal lists, comparator \'>=\' (1 - true, 0 - false): " << (my >= my_copy) <<std::endl;



	std::cout << "\n\033[97m==========  ITERATOR ========== \033[0m" << std::endl;
	
	ft::list<int>::reverse_iterator rev_it = my.rbegin();
	my_it = my.begin();
	std::cout << "\nForward iterator" << std::endl;
	while (my_it != my.end())
		std::cout << *my_it++ << ", ";
	std::cout << std::endl;
	std::cout << "\nReverse iterator" << std::endl;
	while (rev_it != my.rend())
		std::cout << *rev_it++ << ", ";
	std::cout << std::endl;

	ft::list<int>::const_iterator cit = my.begin();
	std::cout << "\nConst Forward iterator" << std::endl;
	while (cit != my.end())
		std::cout << *cit++ << ", ";
	std::cout << std::endl;
	ft::list<int>::const_reverse_iterator crit = my.rbegin();
	std::cout << "\nConst Reverse iterator" << std::endl;
	while (crit != my.rend())
		std::cout << *crit++ << ", ";
	std::cout << std::endl;

	std::cout << "\nAssignation" << std::endl;
	ft::list<int> copy1;
	copy1 = my;
	print_list(my, copy1);

	std::cout <<std::endl <<std::endl << "\033[35m>>>>>   E N D   O F   L I S T < i n t >   <<<<<\033[0m" <<std::endl <<std::endl;
	


}

void test_list_string(void)
{
	std::list<std::string> st;
	ft::list<std::string> my;

	std::list<std::string> test_insert;

	test_insert.push_back("alpha");
	test_insert.push_back("bravo");
	test_insert.push_back("charlie");
	test_insert.push_back("delta");

	std::string arr[] = {"kilo","lima","mike","november","oscar","papa","quebec","romeo","sierra"};


	std::cout << "\033[35m>>>>>   P A R T   4 :   L I S T < s t r i n g >   <<<<<\033[0m" <<std::endl;
	
	std::cout << "\n\033[97m==========  CAPACITY ========== \033[0m" << std::endl; 
	std::cout << "\nMax size: native \'"<< st.max_size() << "\', my \'" << my.max_size() << "\'" << std::endl;
	std::cout << "\nIs empty? (1 - empty, 0 - not): native \'"<< st.empty() << "\', my \'" << my.empty() << "\'" << std::endl;

	
	std::cout << "\n\033[97m==========  ELEMENT ACCESS ========== \033[0m" << std::endl; 
	std::cout << "Native front: \'" << st.front() << "\', my front: \'" << my.front() << "\'" << std::endl;
	std::cout << "Native back: \'" << st.back() << "\', my back: \'" << my.back() << "\'" << std::endl;
	print_list(st, my);

	std::cout << "\n\033[97m==========  MODIFIERS ========== \033[0m" << std::endl;
	std::cout << "Push front \'tango\'" << std::endl;
	st.push_front("tango");
	my.push_front("tango");
	print_list(st, my);

	std::cout << "Push front \'uniform\'" << std::endl;
	st.push_front("uniform");
	my.push_front("uniform");
	print_list(st, my);

	std::cout << "Push front \'whiskey\'" << std::endl;
	st.push_front("whiskey");
	my.push_front("whiskey");
	print_list(st, my);

	std::cout << "Pop front" << std::endl;
	st.pop_front();
	my.pop_front();
	print_list(st, my);

	std::cout << "Push back \'echo\'" << std::endl;
	st.push_back("echo");
	my.push_back("echo");
	print_list(st, my);

	std::cout << "Pop back" << std::endl;
	st.pop_back();
	my.pop_back();
	print_list(st, my);

	std::list<std::string>::iterator st_it = st.begin(); st_it++;
	ft::list<std::string>::iterator my_it = my.begin(); my_it++;
	std::cout << "Insert \'foxtrot\' at position begin + 1" << std::endl;
	st.insert(st_it, "foxtrot");
	my.insert(my_it, "foxtrot");
	print_list(st, my);

	std::cout << "Insert \'golf\' 3 times at position begin + 2" << std::endl;
	st_it = st.begin(); st_it++; st_it++;
	my_it = my.begin(); my_it++; my_it++;
	st.insert(st_it, 3, "golf");
	my.insert(my_it, 3, "golf");
	print_list(st, my);

	std::cout << "Insert \'kilo-november\' at position begin + 1 from string array" << std::endl;
	st_it = st.begin(); st_it++;
	my_it = my.begin(); my_it++;
	st.insert(st_it, arr, arr + 4);
	my.insert(my_it, arr, arr + 4);
	print_list(st, my);

	std::cout << "Insert \'alpha-delta\' at position begin + 1 from another list" << std::endl;
	st_it = st.begin(); st_it++;
	my_it = my.begin(); my_it++;
	st.insert(st_it, test_insert.begin(), test_insert.end());
	my.insert(my_it, test_insert.begin(), test_insert.end());
	print_list(st, my);

	std::cout << "Assign \'juliett\' 5 times" << std::endl;
	st.assign(5, "juliett");
	my.assign(5, "juliett");
	print_list(st, my);

	std::cout << "Assign \'alpha-delta\' from another list" << std::endl;
	st.assign(test_insert.begin(), test_insert.end());
	my.assign(test_insert.begin(), test_insert.end());
	print_list(st, my);

	std::cout << "Erase one at position begin + 1" << std::endl;
	st_it = st.begin(); st_it++;
	my_it = my.begin(); my_it++;
	st.erase(st_it);
	my.erase(my_it);
	print_list(st, my);
	
	std::cout << "Push to front values \'hotel & india\' " << std::endl;
	st.push_front("hotel");st.push_front("india");
	my.push_front("hotel");my.push_front("india");
	print_list(st, my);
	
	std::cout << "Then erase from position 2 to last (excluding last)" << std::endl;
	st.erase(++st.begin(), --st.end());
	my.erase(++my.begin(), --my.end());
	print_list(st, my);

	std::cout << "Resize to 10 with value \'papa\'" << std::endl;
	st.resize(10, "papa");
	my.resize(10, "papa");
	print_list(st, my);

	std::cout << "Resize to 3 with value \'oscar\'" << std::endl;
	st.resize(3, "oscar");
	my.resize(3, "oscar");
	print_list(st, my);

	std::cout << "Resize to 5 without value" << std::endl;
	st.resize(5);
	my.resize(5);
	print_list(st, my);

	std::cout << "Create copy of list" << std::endl;
	ft::list<std::string> my_copy(my);
	print_list(my, my_copy);

	std::cout << "Create a difference in lists" << std::endl;
	my.push_back("quebec");
	my_copy.pop_front();
	print_list(my, my_copy);

	std::cout << "Then swap it" << std::endl;
	my.swap(my_copy);
	print_list(my, my_copy);

	

	std::cout << "\n\033[97m==========  OPERATIONS ========== \033[0m" << std::endl;

	std::cout << "Assign values to lists" << std::endl;
	my.assign(test_insert.begin(), test_insert.end());
	my_copy.assign(arr, arr+4);
	print_list(my, my_copy);

	my_it = my.begin(); ++my_it; 
	std::cout << "Then splice single element to position 2" << std::endl;
	my.splice(my_it, my_copy, my_copy.begin());
	print_list(my, my_copy);

	std::cout << "Then splice entire list to position 3" << std::endl;
	++my_it; 
	my.splice(my_it, my_copy);
	print_list(my, my_copy);

	std::cout << "Then splice backward from 3rd to end-1" << std::endl;
	my_it = my.begin(); my_it++;my_it++;my_it++;
	my_copy.splice(my_copy.begin(), my, my_it, my.end());
	print_list(my, my_copy);

	std::cout << "Assign \'30-33\' from another list" << std::endl;
	st.assign(test_insert.begin(), test_insert.end());
	my.assign(test_insert.begin(), test_insert.end());
	print_list(st, my);

	std::cout << "Then remove value \'bravo\'" << std::endl;
	st.assign(test_insert.begin(), test_insert.end());
	my.assign(test_insert.begin(), test_insert.end());
	st.remove("bravo");
	my.remove("bravo");
	print_list(st, my);

	std::cout << "Remove if value == \'charlie\'" << std::endl;
	st.remove_if(pred_str);
	my.remove_if(pred_str);
	print_list(st, my);

	std::cout << "Prepare lists for unique() test" << std::endl;
	st.assign(test_insert.begin(), test_insert.end());
	st.push_back("alpha"); st.push_back("alpha"); st.push_back("bravo");
	my.assign(test_insert.begin(), test_insert.end());
	my.push_back("alpha"); my.push_back("alpha"); my.push_back("bravo");
	print_list(st, my);
	std::cout << "Call unique()" << std::endl;
	st.unique();
	my.unique();
	print_list(st, my);

	std::cout << "Prepare lists for unique() test with binary predicate" << std::endl;
	st.assign(test_insert.begin(), test_insert.end());
	st.push_back("alpha"); st.push_back("alpha"); st.push_back("bravo");
	my.assign(test_insert.begin(), test_insert.end());
	my.push_back("alpha"); my.push_back("alpha"); my.push_back("bravo");
	print_list(st, my);
	std::cout << "Call unique() with binary predicate (prev == next)" << std::endl;
	st.unique(bin_pred_str);
	my.unique(bin_pred_str);
	print_list(st, my);



	std::cout << "Create unsorted lists" << std::endl;
	st.clear();
	st.push_front("foxtrot"); st.push_front("oscar"); st.push_front("Echo"); st.push_front("oscar"); st.push_front("x-ray"); st.push_front("alpha");
	my.clear();
	my.push_front("foxtrot"); my.push_front("oscar"); my.push_front("Echo"); my.push_front("oscar"); my.push_front("x-ray"); my.push_front("alpha");
	print_list(st, my);
	
	std::cout << "Then sort it" << std::endl;
	st.sort();
	my.sort();
	print_list(st, my);


	std::cout << "Create unsorted lists again" << std::endl;
	st.clear();
	st.push_front("foxtrot"); st.push_front("oscar"); st.push_front("Echo"); st.push_front("oscar"); st.push_front("x-ray"); st.push_front("alpha");
	my.clear();
	my.push_front("foxtrot"); my.push_front("oscar"); my.push_front("Echo"); my.push_front("oscar"); my.push_front("x-ray"); my.push_front("alpha");
	print_list(st, my);
	
	std::cout << "Then sort it with \'comp\'" << std::endl;
	st.sort(compare_less_str);
	my.sort(compare_less_str);
	print_list(st, my);

	std::cout << "Create damned unsorted lists again" << std::endl;
	st.clear();
	st.push_front("foxtrot"); st.push_front("oscar"); st.push_front("Echo"); st.push_front("oscar"); st.push_front("x-ray"); st.push_front("alpha");
	my.clear();
	my.push_front("foxtrot"); my.push_front("oscar"); my.push_front("Echo"); my.push_front("oscar"); my.push_front("x-ray"); my.push_front("alpha");
	print_list(st, my);

	std::cout << "Create two lists for merging" << std::endl;
	std::list<std::string> st_m;
	ft::list<std::string> my_m;
	st_m.push_back("alpha");st_m.push_back("oscar");st_m.push_back("kilo");st_m.push_back("charlie");
	my_m.push_back("alpha");my_m.push_back("oscar");my_m.push_back("kilo");my_m.push_back("charlie");
	st_m.sort();
	my_m.sort();
	print_list(st_m, my_m);
	
	std::cout << "Then merge it" << std::endl;
	st.merge(st_m);
	my.merge(my_m);
	print_list(st, my);

	std::cout << "Create damned unsorted lists last time" << std::endl;
	st.clear();
	st.push_front("foxtrot"); st.push_front("oscar"); st.push_front("Echo"); st.push_front("oscar"); st.push_front("x-ray"); st.push_front("alpha");
	my.clear();
	my.push_front("foxtrot"); my.push_front("oscar"); my.push_front("Echo"); my.push_front("oscar"); my.push_front("x-ray"); my.push_front("alpha");
	print_list(st, my);

	std::cout << "Create two lists for merging" << std::endl;
	std::list<std::string> st_m1;
	ft::list<std::string> my_m1;
	st_m1.push_back("alpha");st_m1.push_back("oscar");st_m1.push_back("kilo");st_m1.push_back("charlie");
	my_m1.push_back("alpha");my_m1.push_back("oscar");my_m1.push_back("kilo");my_m1.push_back("charlie");
	st_m1.sort();
	my_m1.sort();
	print_list(st_m1, my_m1);
	
	std::cout << "Then merge it with \'comp\'" << std::endl;
	st.merge(st_m1, compare_less_str);
	my.merge(my_m1, compare_less_str);
	print_list(st, my);

	std::cout << "Reverse list" << std::endl;
	st.reverse();
	my.reverse();
	print_list(st, my);



	std::cout << "\n\033[97m==========  NON-MEMBER FUNCTIONS OVERLOAD ========== \033[0m" << std::endl;

	my_copy.assign(my.begin(), my.end());
	print_list(my, my_copy);

	std::cout << "\nTwo equal lists, comparator \'==\' (1 - true, 0 - false): " << (my == my_copy) <<std::endl;
	std::cout << "Two equal lists, comparator \'!=\' (1 - true, 0 - false): " << (my != my_copy) <<std::endl;
	std::cout << "Two equal lists, comparator \'<\' (1 - true, 0 - false): " << (my < my_copy) <<std::endl;
	std::cout << "Two equal lists, comparator \'<=\' (1 - true, 0 - false): " << (my <= my_copy) <<std::endl;
	std::cout << "Two equal lists, comparator \'>\' (1 - true, 0 - false): " << (my > my_copy) <<std::endl;
	std::cout << "Two equal lists, comparator \'>=\' (1 - true, 0 - false): " << (my >= my_copy) <<std::endl;

	std::cout << "\nPushback \'zulu\' to one of them and compare" << std::endl;
	my_copy.push_back("zulu");
	print_list(my, my_copy);

	std::cout << "\nTwo non-equal lists, comparator \'==\' (1 - true, 0 - false): " << (my == my_copy) <<std::endl;
	std::cout << "Two non-equal lists, comparator \'!=\' (1 - true, 0 - false): " << (my != my_copy) <<std::endl;
	std::cout << "Two non-equal lists, comparator \'<\' (1 - true, 0 - false): " << (my < my_copy) <<std::endl;
	std::cout << "Two non-equal lists, comparator \'<=\' (1 - true, 0 - false): " << (my <= my_copy) <<std::endl;
	std::cout << "Two non-equal lists, comparator \'>\' (1 - true, 0 - false): " << (my > my_copy) <<std::endl;
	std::cout << "Two non-equal lists, comparator \'>=\' (1 - true, 0 - false): " << (my >= my_copy) <<std::endl;



	std::cout << "\n\033[97m==========  ITERATOR & ASSIGN========== \033[0m" << std::endl;
	
	ft::list<std::string>::reverse_iterator rev_it = my.rbegin();
	my_it = my.begin();
	std::cout << "Normal iterator" << std::endl;
	while (my_it != my.end())
		std::cout << *my_it++ << ", ";
	std::cout << std::endl;
	std::cout << "Reverse iterator" << std::endl;
	while (rev_it != my.rend())
		std::cout << *rev_it++ << ", ";
	std::cout << std::endl;

	ft::list<std::string>::const_iterator cit = my.begin();
	std::cout << "Const Forward iterator" << std::endl;
	while (cit != my.end())
		std::cout << *cit++ << ", ";
	std::cout << std::endl;
	ft::list<std::string>::const_reverse_iterator crit = my.rbegin();
	std::cout << "Const Reverse iterator" << std::endl;
	while (crit != my.rend())
		std::cout << *crit++ << ", ";
	std::cout << std::endl;

	std::cout << "\nAssignation" << std::endl;
	ft::list<std::string> copy1;
	copy1 = my;
	print_list(my, copy1);

	std::cout <<std::endl <<std::endl << "\033[35m>>>>>   E N D   O F   L I S T < s t r i n g >   <<<<<\033[0m" <<std::endl <<std::endl;
	


}

void test_map(void)
{
	
	
	std::map<int, std::string> st;
	ft::map<int, std::string> my;

	std::map<int, std::string> test_insert;
	test_insert.insert(std::make_pair(23, "whiskey"));
	test_insert.insert(std::make_pair(24, "xray"));
	test_insert.insert(std::make_pair(25, "yankee"));
	test_insert.insert(std::make_pair(26, "zulu"));
	test_insert.insert(std::make_pair(6, "fake"));

	std::cout << "\033[35m>>>>>   P A R T   5 :   M A P < i n t ,   s t r i n g >   <<<<<\033[0m" <<std::endl;
	
	std::cout << "\n\033[97m==========  CAPACITY & INSERT ========== \033[0m" << std::endl; 
	
	std::cout << "\nMax size: native \'"<< st.max_size() << "\', my \'" << my.max_size() << "\'" << std::endl;
	std::cout << "\nIs empty? (1 - empty, 0 - not): native \'"<< st.empty() << "\', my \'" << my.empty() << "\'" << std::endl;
	

	std::cout << "Insert pair" << std::endl;
	st.insert(std::make_pair(1, "alpha"));
	st.insert(std::make_pair(6, "foxtrot"));
	st.insert(std::make_pair(2, "bravo"));
	st.insert(std::make_pair(6, "foxtrot-double"));
	st.insert(std::make_pair(-5, "sub_zero"));
	st.insert(std::make_pair(5, "echo"));
	st.insert(std::make_pair(0, "zero"));	

	my.insert(std::make_pair(1, "alpha"));
	my.insert(std::make_pair(6, "foxtrot"));
	my.insert(std::make_pair(2, "bravo"));
	my.insert(std::make_pair(6, "foxtrot-double"));
	my.insert(std::make_pair(-5, "sub_zero"));
	my.insert(std::make_pair(5, "echo"));
	my.insert(std::make_pair(0, "zero"));	
	
	print_map(st, my);
	
	std::cout << "\nIs empty now? (1 - empty, 0 - not): native \'"<< st.empty() << "\', my \'" << my.empty() << "\'" << std::endl;

	
	std::cout << "\n\033[97m==========  ELEMENT ACCESS ========== \033[0m" << std::endl;

	std::cout << "\nCall operator[]: [8] = \'hotel\'" << std::endl;
	st[8] = "hotel";
	my[8] = "hotel";
	print_map(st, my);

	std::cout << "Call non-existing [4]" << std::endl;
	std::cout << "Native [4] = " << st[4] << ", my [4] = " << my[4] << std::endl;
	print_map(st, my);

	
	std::cout << "\n\033[97m==========  MODIFIERS ========== \033[0m" << std::endl;

	std::cout << "\nInsert with hint (it = 3, pair: 3, \'charlie\')" << std::endl;
	std::map<int, std::string>::iterator it = st.begin();
	ft::map<int, std::string>::iterator my_it = my.begin();
	it++;it++;it++;
	my_it++;my_it++;my_it++;

	st.insert(it, std::make_pair(3, "charlie"));
	my.insert(my_it, std::make_pair(3, "charlie"));
	print_map(st, my);

	
	std::cout << "\nInsert with wrong hint (it = 4, pair: \'-1, minus_one\')" << std::endl;
	st.insert(it, std::make_pair(-1, "minus_one"));
	my.insert(my_it, std::make_pair(-1, "minus_one"));
	print_map(st, my);

	std::cout << "\nInsert with wrong hint again (it = 4, pair: -1, \'minus_one\')" << std::endl;
	st.insert(it, std::make_pair(-1, "minus_one"));
	my.insert(my_it, std::make_pair(-1, "minus_one"));
	print_map(st, my);
	
	std::cout << "\nInsert range from another map" << std::endl;
	st.insert(test_insert.begin(), test_insert.end());
	my.insert(test_insert.begin(), test_insert.end());
	print_map(st, my);

	
	
	std::cout << "\nErase one at position 2 (-1, \'minus_one\' will disappears)" << std::endl;
	it = st.begin(); it++;
	my_it = my.begin(); my_it++;
	st.erase(it);
	my.erase(my_it);
	print_map(st, my);

	std::cout << "\nPrepare new map for some more erasing" << std::endl;
	
	std::map<int, std::string> st1;
	ft::map<int, std::string> my1;

	st1.insert(std::make_pair(1, "alpha"));
	st1.insert(std::make_pair(6, "foxtrot"));
	st1.insert(std::make_pair(-6, "-foxtrot"));
	
	my1.insert(std::make_pair(1, "alpha"));
	my1.insert(std::make_pair(6, "foxtrot"));
	my1.insert(std::make_pair(-6, "-foxtrot"));

	print_map(st1, my1);

	std::map<int, std::string>::iterator it1 = st1.begin();
	it1++;
	ft::map<int, std::string>::iterator my_it1 = my1.begin();
	my_it1++;
	
	std::cout << "Erase iterator 1 (1)" << std::endl;
	st1.erase(it1);
	my1.erase(my_it1);
	print_map(st1, my1);
	
	std::cout << "Insert 1" << std::endl;
	st1.insert(std::make_pair(1, "alpha"));
	my1.insert(std::make_pair(1, "alpha"));
	print_map(st1, my1);
	
	it1 = st1.begin();
	my_it1 = my1.begin();
	std::cout << "Erase begin (-6)" << std::endl;
	st1.erase(it1);
	my1.erase(my_it1);
	print_map(st1, my1);

	std::cout << "Insert -6, -10, -2, 7" << std::endl;
	st1.insert(std::make_pair(-6, "-six"));
	my1.insert(std::make_pair(-6, "-six"));
	st1.insert(std::make_pair(-10, "-ten"));
	my1.insert(std::make_pair(-10, "-ten"));
	st1.insert(std::make_pair(-2, "-two"));
	my1.insert(std::make_pair(-2, "-two"));
	st1.insert(std::make_pair(7, "gold"));
	my1.insert(std::make_pair(7, "gold"));

	print_map(st1, my1);


	it1 = st1.begin();
	my_it1 = my1.begin();
	it1++;it1++;it1++;it1++;
	my_it1++;my_it1++;my_it1++;my_it1++;

	std::cout << "Erase root at position 5 (key 6)" << std::endl;
	st1.erase(it1);
	my1.erase(my_it1);
	print_map(st1, my1);

	

	it1 = st1.begin();
	my_it1 = my1.begin();
	it1++;
	my_it1++;
	std::cout << "Erase iterator 1 (-6) "<< std::endl;
	st1.erase(it1);
	my1.erase(my_it1);
	print_map(st1, my1);
	
	std::cout << "\nErase non-existing key 90" << std::endl;
	st.erase(90);
	my.erase(90);
	print_map(st, my);

	std::cout << "\nErase one with key \'-5\'" << std::endl;
	st.erase(-5);
	my.erase(-5);
	print_map(st, my);

	std::cout << "\nErase range (last 3)" << std::endl;
	it = st.end();
	my_it = my.end();
	
	it--;my_it--;
	it--;my_it--;
	it--;my_it--;
	
	st.erase(it, st.end());
	my.erase(my_it, my.end());
	print_map(st, my);	


	std::cout << "\nPrepare new map for swap" << std::endl;
	ft::map<int, std::string> my_copy;
	my_copy.insert(std::make_pair(-1, "minus_one"));
	my_copy.insert(std::make_pair(-2, "minus_two"));
	my_copy.insert(std::make_pair(-3, "minus_three"));
	print_map(my, my_copy);

	std::cout << "\nThen swap maps" << std::endl;
	my.swap(my_copy);
	print_map(my, my_copy);

	std::cout << "\nClear maps" << std::endl;
	st.clear();
	my.clear();
	print_map(st, my);


	std::cout << "\n\033[97m==========  OBSERVERS ========== \033[0m" << std::endl;

	std::cout << "\nPrepare maps for key_comp" << std::endl;
	st.insert(std::make_pair(1, "alpha"));
	st.insert(std::make_pair(2, "bravo"));
	st.insert(std::make_pair(3, "charlie"));
	st.insert(std::make_pair(4, "delta"));
	my.insert(std::make_pair(1, "alpha"));
	my.insert(std::make_pair(2, "bravo"));
	my.insert(std::make_pair(3, "charlie"));
	my.insert(std::make_pair(4, "delta"));
	print_map(st, my);

	std::cout << "\nCreating key comparator, then print it until next key == 3" << std::endl;

	std::map<int, std::string>::key_compare stcomp = st.key_comp();
	ft::map<int, std::string>::key_compare mycomp = my.key_comp();
	it = st.begin();
	my_it = my.begin();
	while ((stcomp((*it).first, 3)))
	{
		std::cout << "native map: first = \'" << it->first << "\', second = \'" << it->second << "\'" << std::endl;
		it++;
	}	
	while ((mycomp((*my_it).first, 3)))
	{
		std::cout << "my map: first  = \'" << my_it->first << "\', second = \'" << my_it->second << "\'" << std::endl;
		my_it++;
	}

	std::cout << "\nCreating value comparator, then print it until next pair == \'4, delta\'" << std::endl;

	std::map<int, std::string>::value_compare stvcomp = st.value_comp();
	ft::map<int, std::string>::value_compare myvcomp = my.value_comp();
	it = st.begin();
	my_it = my.begin();
	std::pair<int, std::string> test_pair = std::make_pair(4, "delta");
	while (stvcomp(*it, test_pair))
	{
		std::cout << "native map: first = \'" << it->first << "\', second = \'" << it->second << "\'" << std::endl;
		it++;
	}	
	while (myvcomp(*my_it, test_pair))
	{
		std::cout << "my map: first  = \'" << my_it->first << "\', second = \'" << my_it->second << "\'" << std::endl;
		my_it++;
	}

	std::cout << "\n\033[97m==========  OPERATIONS ========== \033[0m" << std::endl;

	std::cout << "\nEnlarging maps" << std::endl;
	st.insert(std::make_pair(5, "echo"));
	st.insert(std::make_pair(6, "foxtrot"));
	st.insert(std::make_pair(7, "golf"));
	st.insert(std::make_pair(8, "hotel"));
	my.insert(std::make_pair(5, "echo"));
	my.insert(std::make_pair(6, "foxtrot"));
	my.insert(std::make_pair(7, "golf"));
	my.insert(std::make_pair(8, "hotel"));
	print_map(st, my);

	std::cout << "\nFind key value \'5\' and return an iterator for it" << std::endl;

	std::cout << "native map: \'" << st.find(5)->second << "\'\n   my map = \'" << my.find(5)->second << "\'" << std::endl;

	std::cout << "\nSame but with const_iterator" << std::endl;

	std::map<int, std::string>::const_iterator cit = st.find(5);
	ft::map<int, std::string>::const_iterator my_cit = my.find(5);
	std::cout << "native map: \'" << cit->second << "\'\n   my map = \'" << my_cit->second << "\'" << std::endl;

	std::cout << "\nCount elems with key = \'4\' (1 if elem found, 0 if not)" << std::endl;
	std::cout << "native map: \'" << st.count(4) << "\'\n   my map = \'" << my.count(4) << "\'" << std::endl;
	std::cout << "\nCount elems with non-existing key = \'20\' (1 if elem found, 0 if not)" << std::endl;
	std::cout << "native map: \'" << st.count(20) << "\'\n   my map = \'" << my.count(20) << "\'" << std::endl;
	
	std::cout << "\nExisting lower bound 5" << std::endl;
	std::cout << "native map value: \'" << st.lower_bound(3)->second <<
	"\'\n         my map = \'" << my.lower_bound(3)->second << "\'" << std::endl;

	std::cout << "\nNon-existing lower bound 11 (must points to the end)" << std::endl;
	std::cout << "native map value: \'" << st.lower_bound(11)->second <<
	"\'\n         my map = \'" << my.lower_bound(11)->second << "\'" << std::endl;

	std::cout << "\nExisting upper bound 6" << std::endl;
	std::cout << "native map value: \'" << st.upper_bound(6)->second <<
	"\'\n         my map = \'" << my.upper_bound(6)->second << "\'" << std::endl;

	std::cout << "\nNon-existing upper bound 11 (must points to the end)" << std::endl;
	std::cout << "native map value: \'" << st.upper_bound(11)->second <<
	"\'\n         my map = \'" << my.upper_bound(11)->second << "\'" << std::endl;

	std::cout << "\nEqual range" << std::endl;
	std::pair<std::map<int, std::string>::iterator,
	std::map<int, std::string>::iterator> st_ret;
	st_ret = st.equal_range(3);
	std::pair<ft::map<int, std::string>::iterator,
	ft::map<int, std::string>::iterator> my_ret;
	my_ret = my.equal_range(3);
	std::cout << "native lower bound points to: ";
	std::cout << st_ret.first->first << " => " << st_ret.first->second;
	std::cout << ", upper bound points to: ";
	std::cout << st_ret.second->first << " => " << st_ret.second->second << std::endl;
	std::cout << "    my lower bound points to: ";
	std::cout << my_ret.first->first << " => " << my_ret.first->second;
	std::cout << ", upper bound points to: ";
	std::cout << my_ret.second->first << " => " << my_ret.second->second << std::endl;

	std::cout << "\n\033[97m==========  REVERSE ITERATOR, COPY & ASSIGN ========== \033[0m" << std::endl; 


	std::cout << "\nCopy: create copy then make a difference in 1st one" << std::endl;
	ft::map<int, std::string> my_copy1(my);
	my.insert(std::make_pair(11, "kilo"));
	print_map(my, my_copy1);

	std::cout << "\nAssignation: assign, then make a difference in 1st one, then print both" << std::endl;
	ft::map<int, std::string> my_copy2 = my;
	my.insert(std::make_pair(12, "lima"));
	print_map(my, my_copy2);

	std::cout << "\nForward iteration" << std::endl;
	my_it = my.begin();
	while (my_it != my.end())
	{
		std::cout << "Key = \'" << my_it->first << "\', Value = \'" << my_it->second << "\'" << std::endl;
		my_it++;
	}

	std::cout << "\n\nReverse iteration" << std::endl;
	ft::map<int, std::string>::reverse_iterator rev_it = my.rbegin();
	while (rev_it != my.rend())
	{
		std::cout << "Key = \'" << rev_it->first << "\', Value = \'" << rev_it->second << "\'" << std::endl;
		rev_it++;
	}

	ft::map<int, std::string>::const_iterator my_cit1 = my.begin();
	std::cout << "\nConst Forward iteration" << std::endl;
	while (my_cit1 != my.end())
	{
		std::cout << "Key = \'" << my_cit1->first << "\', Value = \'" << my_cit1->second << "\'" << std::endl;
		my_cit1++;
	}

	ft::map<int, std::string>::const_reverse_iterator my_crit1 = my.rbegin();
	std::cout << "\n\nConst Reverse iteration" << std::endl;
	while (my_crit1 != my.rend())
	{
		std::cout << "Key = \'" << my_crit1->first << "\', Value = \'" << my_crit1->second << "\'" << std::endl;
		my_crit1++;
	}
	
	std::cout << "\n\033[97m==========  NON-MEMBER FUNCTIONS OVERLOAD ========== \033[0m" << std::endl;
	my.clear();
	my_copy.clear();

	std::cout << "\n\nPreparing two maps for comparation" << std::endl;
	
	my.insert(std::make_pair(1, "alpha"));
	my.insert(std::make_pair(2, "bravo"));
	my.insert(std::make_pair(3, "charlie"));
	my.insert(std::make_pair(4, "delta"));

	my_copy.insert(std::make_pair(1, "alpha"));
	my_copy.insert(std::make_pair(2, "bravo"));
	my_copy.insert(std::make_pair(3, "charlie"));
	my_copy.insert(std::make_pair(4, "delta"));

	print_map(my, my_copy);

	std::cout << "\nTwo equal maps, comparator \'==\' (1 - true, 0 - false): " << (my == my_copy) <<std::endl;
	std::cout << "Two equal maps, comparator \'!=\' (1 - true, 0 - false): " << (my != my_copy) <<std::endl;
	std::cout << "Two equal maps, comparator \'<\' (1 - true, 0 - false): " << (my < my_copy) <<std::endl;
	std::cout << "Two equal maps, comparator \'<=\' (1 - true, 0 - false): " << (my <= my_copy) <<std::endl;
	std::cout << "Two equal maps, comparator \'>\' (1 - true, 0 - false): " << (my > my_copy) <<std::endl;
	std::cout << "Two equal maps, comparator \'>=\' (1 - true, 0 - false): " << (my >= my_copy) <<std::endl;


	std::cout << "\nCreate a difference in map" << std::endl;
	my.insert(std::make_pair(5, "echo"));
	print_map(my, my_copy);

	std::cout << "\nTwo non-equal maps, comparator \'==\' (1 - true, 0 - false): " << (my == my_copy) <<std::endl;
	std::cout << "Two non-equal maps, comparator \'!=\' (1 - true, 0 - false): " << (my != my_copy) <<std::endl;
	std::cout << "Two non-equal maps, comparator \'<\' (1 - true, 0 - false): " << (my < my_copy) <<std::endl;
	std::cout << "Two non-equal maps, comparator \'<=\' (1 - true, 0 - false): " << (my <= my_copy) <<std::endl;
	std::cout << "Two non-equal maps, comparator \'>\' (1 - true, 0 - false): " << (my > my_copy) <<std::endl;
	std::cout << "Two non-equal maps, comparator \'>=\' (1 - true, 0 - false): " << (my >= my_copy) <<std::endl;

	std::cout <<std::endl <<std::endl << "\033[35m>>>>>   E N D   O F   M A P < i n t ,   s t r i n g >   <<<<<\033[0m" <<std::endl <<std::endl;
}

void test_stack()
{
	std::cout << "\033[35m>>>>>   P A R T   6 :   S T A C K < i n t >   <<<<<\033[0m" <<std::endl;
	
	std::cout << "\n\033[97m==========  MEMBER FUNCTIONS ========== \033[0m" << std::endl; 
	std::stack<int> st;
	ft::stack<int> my;

	std::cout << "\nIs empty? (1 - empty, 0 - not): native \'"<< st.empty() << "\', my \'" << my.empty() << "\'" << std::endl;
	
	std::cout << "\nPush \'77\' and check empty()" << std::endl;
	st.push(77);
	my.push(77);
	std::cout << "Is empty now? (1 - empty, 0 - not): native \'"<< st.empty() << "\', my \'" << my.empty() << "\'" << std::endl;
	

	std::cout << "\nPush \'99' and check size()" << std::endl;
	st.push(99);
	my.push(99);

	std::cout << "Native size is \'"<< st.size() << "\', my size is \'" << my.size() << "\'" << std::endl;

	std::cout << "\nWhat is on top? native \'"<< st.top() << "\', my \'" << my.top() << "\'" << std::endl;

	std::cout << "\nPush \'177'" << std::endl;
	st.push(177);
	my.push(177);
	std::cout << "What is on top now? native \'"<< st.top() << "\', my \'" << my.top() << "\'" << std::endl;

	std::cout << "\nPop twice" << std::endl;
	st.pop();st.pop();
	my.pop();my.pop();
	std::cout << "What is on top now? native \'"<< st.top() << "\', my \'" << my.top() << "\'" << std::endl;

	std::cout << "\n\033[97m==========  NON-MEMBER FUNCTIONS OVERLOAD ========== \033[0m" << std::endl; 
	std::cout << "\nPrepare two equal stacks for comparsion" << std::endl;
	ft::stack<int> my_copy;
	my.push(197);
	my.push(199);
	my_copy.push(77);
	my_copy.push(197);
	my_copy.push(199);


	std::cout << "\nTwo equal stacks, comparator \'==\' (1 - true, 0 - false): " << (my == my_copy) <<std::endl;
	std::cout << "Two equal stacks, comparator \'!=\' (1 - true, 0 - false): " << (my != my_copy) <<std::endl;
	std::cout << "Two equal stacks, comparator \'<\' (1 - true, 0 - false): " << (my < my_copy) <<std::endl;
	std::cout << "Two equal stacks, comparator \'<=\' (1 - true, 0 - false): " << (my <= my_copy) <<std::endl;
	std::cout << "Two equal stacks, comparator \'>\' (1 - true, 0 - false): " << (my > my_copy) <<std::endl;
	std::cout << "Two equal stacks, comparator \'>=\' (1 - true, 0 - false): " << (my >= my_copy) <<std::endl;

	std::cout << "\nCreate a difference in first one" << std::endl;
	my.push(799);
	std::cout << "#1 top = \'" << my.top() << "\', #2 top = \'" << my_copy.top() << "\'" << std::endl;
	
	std::cout << "\nTwo non-equal stacks, comparator \'==\' (1 - true, 0 - false): " << (my == my_copy) <<std::endl;
	std::cout << "Two non-equal stacks, comparator \'!=\' (1 - true, 0 - false): " << (my != my_copy) <<std::endl;
	std::cout << "Two non-equal stacks, comparator \'<\' (1 - true, 0 - false): " << (my < my_copy) <<std::endl;
	std::cout << "Two non-equal stacks, comparator \'<=\' (1 - true, 0 - false): " << (my <= my_copy) <<std::endl;
	std::cout << "Two non-equal stacks, comparator \'>\' (1 - true, 0 - false): " << (my > my_copy) <<std::endl;
	std::cout << "Two non-equal stacks, comparator \'>=\' (1 - true, 0 - false): " << (my >= my_copy) <<std::endl;

	std::cout <<std::endl <<std::endl << "\033[35m>>>>>   E N D   O F   S T A C K < i n t >   <<<<<\033[0m" <<std::endl <<std::endl;
}

void test_queue()
{
	std::cout << "\033[35m>>>>>   P A R T   7 :   Q U E U E < i n t >   <<<<<\033[0m" <<std::endl;
	
	
	std::cout << "\n\033[97m==========  MEMBER FUNCTIONS ========== \033[0m" << std::endl; 

	std::queue<int> st;
	ft::queue<int> my;

	std::cout << "\nIs empty? (1 - empty, 0 - not): native \'"<< st.empty() << "\', my \'" << my.empty() << "\'" << std::endl;
	
	std::cout << "\nPush \'1\' and check empty()" << std::endl;
	st.push(1);
	my.push(1);
	std::cout << "Is empty now? (1 - empty, 0 - not): native \'"<< st.empty() << "\', my \'" << my.empty() << "\'" << std::endl;
	

	std::cout << "\nPush \'2' and check size()" << std::endl;
	st.push(2);
	my.push(2);
	std::cout << "Native size is \'"<< st.size() << "\', my size is \'" << my.size() << "\'" << std::endl;

	std::cout << "\nPush \'3-5' and check size()" << std::endl;
	st.push(3);st.push(4);st.push(5);
	my.push(3);my.push(4);my.push(5);

	std::cout << "Native size is \'"<< st.size() << "\', my size is \'" << my.size() << "\'" << std::endl;

	std::cout << "\nWhat is on front? native \'"<< st.front() << "\', my \'" << my.front() << "\'" << std::endl;
	std::cout << "What is on back? native \'"<< st.back() << "\', my \'" << my.back() << "\'" << std::endl;
	
	std::cout << "\nPush \'6'" << std::endl;
	st.push(6);
	my.push(6);
	std::cout << "What is on back now? native \'"<< st.back() << "\', my \'" << my.back() << "\'" << std::endl;

	std::cout << "\nPop twice" << std::endl;
	st.pop();st.pop();
	my.pop();my.pop();
	std::cout << "\nWhat is on front? native \'"<< st.front() << "\', my \'" << my.front() << "\'" << std::endl;
	std::cout << "What is on back? native \'"<< st.back() << "\', my \'" << my.back() << "\'" << std::endl;
	std::cout << "Native size is \'"<< st.size() << "\', my size is \'" << my.size() << "\'" << std::endl;
	

	std::cout << "\n\033[97m==========  NON-MEMBER FUNCTIONS OVERLOAD ========== \033[0m" << std::endl; 
	std::cout << "\nPrepare two equal queues for comparsion" << std::endl;
	ft::queue<int> my_copy;
	my_copy.push(3);
	my_copy.push(4);
	my_copy.push(5);
	my_copy.push(6);
	std::cout << "#1 front = \'" << my.front() << "\', #1 back = \'" << my.back() << "\'" << ", size "<< my.size() << std::endl;
	std::cout << "#2 front = \'" << my_copy.front() << "\', #2 back = \'" << my_copy.back() << "\'" << ", size " << my_copy.size() << std::endl;


	std::cout << "\nTwo equal queues, comparator \'==\' (1 - true, 0 - false): " << (my == my_copy) <<std::endl;
	std::cout << "Two equal queues, comparator \'!=\' (1 - true, 0 - false): " << (my != my_copy) <<std::endl;
	std::cout << "Two equal queues, comparator \'<\' (1 - true, 0 - false): " << (my < my_copy) <<std::endl;
	std::cout << "Two equal queues, comparator \'<=\' (1 - true, 0 - false): " << (my <= my_copy) <<std::endl;
	std::cout << "Two equal queues, comparator \'>\' (1 - true, 0 - false): " << (my > my_copy) <<std::endl;
	std::cout << "Two equal queues, comparator \'>=\' (1 - true, 0 - false): " << (my >= my_copy) <<std::endl;

	std::cout << "\nCreate a difference in first one" << std::endl;
	my.push(7);
	std::cout << "#1 front = \'" << my.front() << "\', #1 back = \'" << my.back() << "\'" << ", size " << my.size() << std::endl;
	std::cout << "#2 front = \'" << my_copy.front() << "\', #2 back = \'" << my_copy.back() << "\'" << ", size " << my_copy.size() << std::endl;
	
	std::cout << "\nTwo non-equal queues, comparator \'==\' (1 - true, 0 - false): " << (my == my_copy) <<std::endl;
	std::cout << "Two non-equal queues, comparator \'!=\' (1 - true, 0 - false): " << (my != my_copy) <<std::endl;
	std::cout << "Two non-equal queues, comparator \'<\' (1 - true, 0 - false): " << (my < my_copy) <<std::endl;
	std::cout << "Two non-equal queuess, comparator \'<=\' (1 - true, 0 - false): " << (my <= my_copy) <<std::endl;
	std::cout << "Two non-equal queues, comparator \'>\' (1 - true, 0 - false): " << (my > my_copy) <<std::endl;
	std::cout << "Two non-equal queues, comparator \'>=\' (1 - true, 0 - false): " << (my >= my_copy) <<std::endl;

	std::cout <<std::endl <<std::endl << "\033[35m>>>>>   E N D   O F   Q U E U E < i n t >   <<<<<\033[0m" <<std::endl <<std::endl;

}


int main()
{

	//test_vector_int();
	//test_vector_string();
	test_list_int();
	test_list_string();
	//test_map();
	//test_stack();
	//test_queue();

	return 0;
}