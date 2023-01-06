#include <vector>
#include <iterator>
#include <list>
#include <map>
#include <stack>
#include <iostream>
#include <fstream>
#include <exception>
#include <ctime>
#include <utility>
#include <iomanip>


#include "map.hpp"
#include "stack.hpp"
#include "vector.hpp"

#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define GREEN "\033[1;32m"
#define DFLT "\033[0m"

template <typename T>
void ft_out_vector(std::ostream &stream, ft::vector<T> &vctr)
{
	stream << "size = " << vctr.size() << std::endl;
	stream << "capacity = " << vctr.capacity() << std::endl;
//	stream << "max_size = " << vctr.max_size() << std::endl;
	typename ft::vector<T>::iterator it = vctr.begin();
	stream << "vector: ";
	while (it != vctr.end())
	{
		stream << *it << " ";
		++it;
	}
	stream << std::endl;
	stream << "-----\n" << std::endl;
	
}

template <typename T>
void std_out_vector(std::ostream &stream, std::vector<T> &vctr)
{
	stream << "size = " << vctr.size() << std::endl;
	stream << "capacity = " << vctr.capacity() << std::endl;
//	stream << "max_size = " << vctr.max_size() << std::endl;
	typename std::vector<T>::iterator it = vctr.begin();
	stream << "vector: ";
	while (it != vctr.end())
	{
		stream << *it << " ";
		++it;
	}
	stream << std::endl;
	stream << "-----\n" << std::endl;
	
}

void ft_stl_vector_out(std::ostream &stream)
{
	
	stream << "----------vector_tests----------" << std::endl;
	std::vector<int> tmp_1;
	std::vector<int> tmp_2(4, 8);
	std::vector<int> tmp_3(tmp_2);
	std::vector<int> tmp_4(tmp_2.begin(), tmp_2.end());
	stream << "--------------" << std::endl;
	stream << "CONSTRUCTORS: " << std::endl;
	stream << "--------------\n" << std::endl;
	stream << "tmp_1(empty): " << std::endl;
	std_out_vector(stream, tmp_1);
	stream << "tmp_2(4, 8): " << std::endl;;
	std_out_vector(stream, tmp_2);
	stream << "tmp_3(tmp_2): " << std::endl;;
	std_out_vector(stream, tmp_3);
	stream << "tmp_4(tmp_2.begin(), tmp_2.end()): " << std::endl;;
	std_out_vector(stream, tmp_4);
	stream << "--------------" << std::endl;
	stream << "OPERATOR = " << std::endl;
	stream << "--------------\n" << std::endl;
	std::vector<int> tmp_5(9, 1);
	std::vector<int> tmp_6(2, 88);
	stream << "tmp_5(9, 1):" << std::endl;
	std_out_vector(stream, tmp_5);
	stream << "tmp_6(2, 88):" << std::endl;
	std_out_vector(stream, tmp_6);
	tmp_6 = tmp_5;
	stream << "tmp_6 = tmp_5;" << std::endl;
	stream << "tmp_6: " << std::endl;
	std_out_vector(stream, tmp_6);
	tmp_5 = tmp_4;
	stream << "tmp_5 = tmp_4;" << std::endl;
	stream << "tmp_5: " << std::endl;
	std_out_vector(stream, tmp_5);
	stream << "--------------" << std::endl;
	stream << "POP_BACK AND PUSH_BACK: " << std::endl;
	stream << "--------------\n" << std::endl;
	stream << "tmp_2: " << std::endl;
	std_out_vector(stream, tmp_2);
	tmp_2.push_back(15);
	stream << "tmp_2.push_back(15)" << std::endl;
	std_out_vector(stream, tmp_2);
	tmp_2.push_back(16);
	tmp_2.push_back(23);
	tmp_2.push_back(42);
	tmp_2.push_back(69);
	tmp_2.push_back(-70);
	tmp_2.push_back(-45);
	stream << "tmp_2.push_back 16 23 42 69 -70 -45" << std::endl;
	std_out_vector(stream, tmp_2);
	stream << "--\n" << std::endl;
	stream << "tmp_6: " << std::endl;
	std_out_vector(stream, tmp_6);
	tmp_6.pop_back();
	tmp_6.pop_back();
	stream << "tmp_6.pop_back 2 times:" << std::endl;
	std_out_vector(stream, tmp_6);
	stream << "--------------" << std::endl;
	stream << "CAPACITY: " << std::endl;
	stream << "--------------\n" << std::endl;
	stream << "tmp_4: " << std::endl;
	std_out_vector(stream, tmp_4);
	tmp_4.resize(10,44);
	stream << "tmp_4 [after tmp_4.resize(10, 44)] : " << std::endl;
	std_out_vector(stream, tmp_4);
	stream << "tmp_2: " << std::endl;
	std_out_vector(stream, tmp_2);
	tmp_2.resize(1);
	stream << "tmp_2 [after tmp_2.resize(1)] : " << std::endl;
	std_out_vector(stream, tmp_2);
	stream << "tmp_1.empty()= " << tmp_1.empty() << std::endl;
	stream << "tmp_2.empty()= " << tmp_2.empty() << std::endl;
	stream << "tmp_6.empty()= " << tmp_6.empty() << std::endl;
	stream << std::endl;
	stream << "tmp_1: " << std::endl;
	std_out_vector(stream, tmp_1);
	tmp_1.reserve(10);
	stream << "tmp_1.reserve(10) " << std::endl;
	std_out_vector(stream, tmp_1);
	stream << "tmp_5: " << std::endl;
	std_out_vector(stream, tmp_5);
	tmp_5.reserve(1);
	stream << "tmp_5.reserve(1) " << std::endl;
	std_out_vector(stream, tmp_5);
	stream << "--------------" << std::endl;
	stream << "ITERATORS: " << std::endl;
	stream << "--------------\n" << std::endl;
	tmp_4.push_back(9);
	stream << "tmp_4: " << std::endl;
	std_out_vector(stream, tmp_4);
	stream << "tmp_4.begin(): " << (*(tmp_4.begin())) << std::endl;
	std::vector<int>::difference_type nbr = 1;
	stream << "tmp_4.end() - 1: " << (*(tmp_4.end() - nbr)) << std::endl;
	stream << "tmp_4.rbegin(): " << (*(tmp_4.rbegin())) << std::endl;
	stream << "tmp_4.rend() - 1: " << (*(tmp_4.rend() - nbr)) << std::endl;
	stream << "--------------" << std::endl;
	stream << "ELEMENT ACCESS: " << std::endl;
	stream << "--------------\n" << std::endl;
	stream << "tmp_4: " << std::endl;
	stream << "tmp_4[5]: " << (tmp_4[5]) << std::endl;
	stream << "tmp_4.at(3): " << tmp_4.at(3) << std::endl;
	stream << "tmp_4.front(): " << tmp_4.front() << std::endl;
	stream << "tmp_4.back(): " << tmp_4.back() << std::endl;
	stream << "--------------" << std::endl;
	stream << "MODIFIERS: " << std::endl;
	stream << "--------------\n" << std::endl;
	stream << "tmp_1: " << std::endl;
	std_out_vector(stream, tmp_1);
	tmp_1.assign(17, 5);
	stream << "tmp_1.assign(17, 5) " << std::endl;
	std_out_vector(stream, tmp_1);
	stream << "tmp_2: " << std::endl;
	std_out_vector(stream, tmp_2);
	tmp_2.assign(tmp_4.begin(), tmp_4.end());
	stream << "tmp_2.assign(tmp_4.begin(), tmp_4.end()) " << std::endl;
	std_out_vector(stream, tmp_2);
	stream << "tmp_2.clear()" << std::endl;
	tmp_2.clear();
	std_out_vector(stream, tmp_2);
	stream << "tmp_2.insert(tmp_2.begin(), 2)" << std::endl;
	tmp_2.insert(tmp_2.begin(), 2);
	std_out_vector(stream, tmp_2);
	stream << "tmp_2.insert((tmp_2.begin() + nbr), 5, 7)" << std::endl;
	tmp_2.insert((tmp_2.begin() + nbr), 5, 7);
	std_out_vector(stream, tmp_2);
	tmp_1.push_back(99);
	stream << "tmp_2.insert((tmp_2.begin() + (nbr*2)), tmp_1.begin(), tmp_1.end())" << std::endl;
	tmp_2.insert((tmp_2.begin() + nbr + nbr), tmp_1.begin(), tmp_1.end());
	std_out_vector(stream, tmp_2);
	stream << "tmp_2.erase(tmp_2.begin() + 6 , (tmp_2.begin() + nbr(12))))" << std::endl;
	nbr += 5;
	tmp_2.erase((tmp_2.begin() + nbr), (tmp_2.begin() + nbr + nbr));
	std_out_vector(stream, tmp_2);
	stream << "tmp_2.erase(tmp_2.end() - 1)" << std::endl;
	nbr = 1;
	tmp_2.erase(tmp_2.end() - nbr);
	std_out_vector(stream, tmp_2);
	stream << "tmp_2.erase(tmp_2.begin()) two times" << std::endl;
	tmp_2.erase(tmp_2.begin());
	tmp_2.erase(tmp_2.begin());
	std_out_vector(stream, tmp_2);
	stream << "tmp_4:" << std::endl;
	std_out_vector(stream, tmp_4);
	stream << "tmp_2:" << std::endl;
	std_out_vector(stream, tmp_2);
	tmp_2.swap(tmp_4);
	stream << "tmp_4:" << std::endl;
	std_out_vector(stream, tmp_4);
	stream << "tmp_2:" << std::endl;
	std_out_vector(stream, tmp_2);
	tmp_1.clear();
	tmp_1.assign(5, 22);
	tmp_1.push_back(1);
	tmp_2.assign(5, 22);
	tmp_3.assign(5, 22);
	stream << (tmp_1 < tmp_2) << std::endl;
	stream << (tmp_1 > tmp_2) << std::endl;
	stream << (tmp_1 >= tmp_2) << std::endl;
	stream << (tmp_3 >= tmp_2) << std::endl;
	stream << (tmp_3 == tmp_2) << std::endl;
	stream << (tmp_1 == tmp_2) << std::endl;
	stream << (tmp_3 != tmp_2) << std::endl;
	return;
	
}

void ft_my_vector_out(std::ostream &stream)
{
	
	stream << "----------vector_tests----------" << std::endl;
	ft::vector<int> tmp_1;
	ft::vector<int> tmp_2(4, 8);
	ft::vector<int> tmp_3(tmp_2);
	ft::vector<int> tmp_4(tmp_2.begin(), tmp_2.end());
	stream << "--------------" << std::endl;
	stream << "CONSTRUCTORS: " << std::endl;
	stream << "--------------\n" << std::endl;
	stream << "tmp_1(empty): " << std::endl;
	ft_out_vector(stream, tmp_1);
	stream << "tmp_2(4, 8): " << std::endl;;
	ft_out_vector(stream, tmp_2);
	stream << "tmp_3(tmp_2): " << std::endl;;
	ft_out_vector(stream, tmp_3);
	stream << "tmp_4(tmp_2.begin(), tmp_2.end()): " << std::endl;;
	ft_out_vector(stream, tmp_4);
	stream << "--------------" << std::endl;
	stream << "OPERATOR = " << std::endl;
	stream << "--------------\n" << std::endl;
	ft::vector<int> tmp_5(9, 1);
	ft::vector<int> tmp_6(2, 88);
	stream << "tmp_5(9, 1):" << std::endl;
	ft_out_vector(stream, tmp_5);
	stream << "tmp_6(2, 88):" << std::endl;
	ft_out_vector(stream, tmp_6);
	tmp_6 = tmp_5;
	stream << "tmp_6 = tmp_5;" << std::endl;
	stream << "tmp_6: " << std::endl;
	ft_out_vector(stream, tmp_6);
	tmp_5 = tmp_4;
	stream << "tmp_5 = tmp_4;" << std::endl;
	stream << "tmp_5: " << std::endl;
	ft_out_vector(stream, tmp_5);
	stream << "--------------" << std::endl;
	stream << "POP_BACK AND PUSH_BACK: " << std::endl;
	stream << "--------------\n" << std::endl;
	stream << "tmp_2: " << std::endl;
	ft_out_vector(stream, tmp_2);
	tmp_2.push_back(15);
	stream << "tmp_2.push_back(15)" << std::endl;
	ft_out_vector(stream, tmp_2);
	tmp_2.push_back(16);
	tmp_2.push_back(23);
	tmp_2.push_back(42);
	tmp_2.push_back(69);
	tmp_2.push_back(-70);
	tmp_2.push_back(-45);
	stream << "tmp_2.push_back 16 23 42 69 -70 -45" << std::endl;
	ft_out_vector(stream, tmp_2);
	stream << "--\n" << std::endl;
	stream << "tmp_6: " << std::endl;
	ft_out_vector(stream, tmp_6);
	tmp_6.pop_back();
	tmp_6.pop_back();
	stream << "tmp_6.pop_back 2 times:" << std::endl;
	ft_out_vector(stream, tmp_6);
	stream << "--------------" << std::endl;
	stream << "CAPACITY: " << std::endl;
	stream << "--------------\n" << std::endl;
	stream << "tmp_4: " << std::endl;
	ft_out_vector(stream, tmp_4);
	tmp_4.resize(10,44);
	stream << "tmp_4 [after tmp_4.resize(10, 44)] : " << std::endl;
	ft_out_vector(stream, tmp_4);
	stream << "tmp_2: " << std::endl;
	ft_out_vector(stream, tmp_2);
	tmp_2.resize(1);
	stream << "tmp_2 [after tmp_2.resize(1)] : " << std::endl;
	ft_out_vector(stream, tmp_2);
	stream << "tmp_1.empty()= " << tmp_1.empty() << std::endl;
	stream << "tmp_2.empty()= " << tmp_2.empty() << std::endl;
	stream << "tmp_6.empty()= " << tmp_6.empty() << std::endl;
	stream << std::endl;
	stream << "tmp_1: " << std::endl;
	ft_out_vector(stream, tmp_1);
	tmp_1.reserve(10);
	stream << "tmp_1.reserve(10) " << std::endl;
	ft_out_vector(stream, tmp_1);
	stream << "tmp_5: " << std::endl;
	ft_out_vector(stream, tmp_5);
	tmp_5.reserve(1);
	stream << "tmp_5.reserve(1) " << std::endl;
	ft_out_vector(stream, tmp_5);
	stream << "--------------" << std::endl;
	stream << "ITERATORS: " << std::endl;
	stream << "--------------\n" << std::endl;
	tmp_4.push_back(9);
	stream << "tmp_4: " << std::endl;
	ft_out_vector(stream, tmp_4);
	stream << "tmp_4.begin(): " << (*(tmp_4.begin())) << std::endl;
	ft::vector<int>::difference_type nbr = 1;
	stream << "tmp_4.end() - 1: " << (*(tmp_4.end() - nbr)) << std::endl;
	stream << "tmp_4.rbegin(): " << (*(tmp_4.rbegin())) << std::endl;
	stream << "tmp_4.rend() - 1: " << (*(tmp_4.rend() - nbr)) << std::endl;
	stream << "--------------" << std::endl;
	stream << "ELEMENT ACCESS: " << std::endl;
	stream << "--------------\n" << std::endl;
	stream << "tmp_4: " << std::endl;
	stream << "tmp_4[5]: " << (tmp_4[5]) << std::endl;
	stream << "tmp_4.at(3): " << tmp_4.at(3) << std::endl;
	stream << "tmp_4.front(): " << tmp_4.front() << std::endl;
	stream << "tmp_4.back(): " << tmp_4.back() << std::endl;
	stream << "--------------" << std::endl;
	stream << "MODIFIERS: " << std::endl;
	stream << "--------------\n" << std::endl;
	stream << "tmp_1: " << std::endl;
	ft_out_vector(stream, tmp_1);
	tmp_1.assign(17, 5);
	stream << "tmp_1.assign(17, 5) " << std::endl;
	ft_out_vector(stream, tmp_1);
	stream << "tmp_2: " << std::endl;
	ft_out_vector(stream, tmp_2);
	tmp_2.assign(tmp_4.begin(), tmp_4.end());
	stream << "tmp_2.assign(tmp_4.begin(), tmp_4.end()) " << std::endl;
	ft_out_vector(stream, tmp_2);
	stream << "tmp_2.clear()" << std::endl;
	tmp_2.clear();
	ft_out_vector(stream, tmp_2);
	stream << "tmp_2.insert(tmp_2.begin(), 2)" << std::endl;
	tmp_2.insert(tmp_2.begin(), 2);
	ft_out_vector(stream, tmp_2);
	stream << "tmp_2.insert((tmp_2.begin() + nbr), 5, 7)" << std::endl;
	tmp_2.insert((tmp_2.begin() + nbr), 5, 7);
	ft_out_vector(stream, tmp_2);
	tmp_1.push_back(99);
	stream << "tmp_2.insert((tmp_2.begin() + (nbr*2)), tmp_1.begin(), tmp_1.end())" << std::endl;
	tmp_2.insert((tmp_2.begin() + nbr + nbr), tmp_1.begin(), tmp_1.end());
	ft_out_vector(stream, tmp_2);
	stream << "tmp_2.erase(tmp_2.begin() + 6 , (tmp_2.begin() + nbr(12))))" << std::endl;
	nbr += 5;
	tmp_2.erase((tmp_2.begin() + nbr), (tmp_2.begin() + nbr + nbr));
	ft_out_vector(stream, tmp_2);
	stream << "tmp_2.erase(tmp_2.end() - 1)" << std::endl;
	nbr = 1;
	tmp_2.erase(tmp_2.end() - nbr);
	ft_out_vector(stream, tmp_2);
	stream << "tmp_2.erase(tmp_2.begin()) two times" << std::endl;
	tmp_2.erase(tmp_2.begin());
	tmp_2.erase(tmp_2.begin());
	ft_out_vector(stream, tmp_2);
	stream << "tmp_4:" << std::endl;
	ft_out_vector(stream, tmp_4);
	stream << "tmp_2:" << std::endl;
	ft_out_vector(stream, tmp_2);
	tmp_2.swap(tmp_4);
	stream << "tmp_4:" << std::endl;
	ft_out_vector(stream, tmp_4);
	stream << "tmp_2:" << std::endl;
	ft_out_vector(stream, tmp_2);
	tmp_1.clear();
	tmp_1.assign(5, 22);
	tmp_1.push_back(1);
	tmp_2.assign(5, 22);
	tmp_3.assign(5, 22);
	stream << (tmp_1 < tmp_2) << std::endl;
	stream << (tmp_1 > tmp_2) << std::endl;
	stream << (tmp_1 >= tmp_2) << std::endl;
	stream << (tmp_3 >= tmp_2) << std::endl;
	stream << (tmp_3 == tmp_2) << std::endl;
	stream << (tmp_1 == tmp_2) << std::endl;
	stream << (tmp_3 != tmp_2) << std::endl;
	return;
	
	
}

void ft_check_my_vector()
{
	unsigned long 	start_time = clock();
	std::ofstream outPutFile_1;
	outPutFile_1.open("ft_vector.txt");
	if (!outPutFile_1.is_open())
		throw std::exception();
	ft_my_vector_out(outPutFile_1);
	outPutFile_1.close();
	unsigned long 	finish_time = clock();
	std::cout << YELLOW << "ft_vector time = " << finish_time - start_time << std::setprecision(7) << " msec" << DFLT << std::endl;
		
	unsigned long 	start_time_2 = clock();
	std::ofstream outPutFile_2;
	outPutFile_2.open("std_vector.txt");
	if (!outPutFile_2.is_open())
		throw std::exception();
	ft_stl_vector_out(outPutFile_2);
	outPutFile_2.close();
	unsigned long 	finish_time_2 = clock();
	std::cout << YELLOW << "std_vector time = " << finish_time_2 - start_time_2 << std::setprecision(7) << " msec" << DFLT << std::endl;

	std::cout << BLUE << "* VECTOR check files have been created *" << DFLT << std::endl << std::endl;;
	return ;
}

void ft_my_stack_out(std::ostream &stream)
{
	stream << "----------stack_tests----------" << std::endl;
	stream << "constructors: " << std::endl;
	ft::vector<int> test_vctr(5, 88);
	ft::stack<char> tmp_1;
	ft::stack<int, ft::vector<int> >tmp_2(test_vctr);
	stream << "stack #1: tmp_1 (empty) size = " << tmp_1.size() << std::endl;
	stream << "stack #2: tmp_2 (5, 88) size = " << tmp_2.size() << std::endl;
	stream <<  "----------------------------\n"  << std::endl;

	stream  << "member functions: " << std::endl;
	
	stream <<  "empty: " <<  std::endl;
	stream << "tmp_1 empty: " << tmp_1.empty() << std::endl;
	stream << "tmp_2 empty: " << tmp_1.empty() << std::endl;
	stream  << "----------------------------\n" << std::endl;

	stream << "push: " <<  std::endl;
	stream << "tmp_1: size before push = " << tmp_1.size() << std::endl;
	tmp_1.push('l');
	tmp_1.push('o');
	tmp_1.push('l');
	stream << "tmp_1: size after push ('l', 'o' and 'l' were added)= " << tmp_1.size() << std::endl;
	tmp_2.push(77);
	stream << "tmp_2: size after push (77 was added)= " << tmp_2.size() << std::endl;
	stream <<  "----------------------------\n" << std::endl;

	stream << "top and pop: " << std::endl;
	stream << "tmp_1 top element: " << tmp_1.top() << std::endl;
	stream << "tmp_2 top element: " << tmp_2.top() << std::endl;
	tmp_1.pop();
	tmp_2.pop();
	stream << "tmp_1 top element after tmp_1.pop(): " << tmp_1.top() << "and size = " << tmp_1.size() << std::endl;
	stream << "tmp_2 top element after tmp_2.pop(): " << tmp_2.top() << "and size = " << tmp_1.size() << std::endl;
	stream << "----------------------------\n" << std::endl;
	return ;
}

void ft_stl_stack_out(std::ostream &stream)
{
	stream << "----------stack_tests----------" << std::endl;
	stream << "constructors: " << std::endl;
	std::vector<int> test_vctr(5, 88);
	std::stack<char> tmp_1;
	std::stack<int, std::vector<int> >tmp_2(test_vctr);
	stream << "stack #1: tmp_1 (empty) size = " << tmp_1.size() << std::endl;
	stream << "stack #2: tmp_2 (5, 88) size = " << tmp_2.size() << std::endl;
	stream <<  "----------------------------\n"  << std::endl;

	stream  << "member functions: " << std::endl;
	
	stream <<  "empty: " <<  std::endl;
	stream << "tmp_1 empty: " << tmp_1.empty() << std::endl;
	stream << "tmp_2 empty: " << tmp_1.empty() << std::endl;
	stream  << "----------------------------\n" << std::endl;

	stream << "push: " <<  std::endl;
	stream << "tmp_1: size before push = " << tmp_1.size() << std::endl;
	tmp_1.push('l');
	tmp_1.push('o');
	tmp_1.push('l');
	stream << "tmp_1: size after push ('l', 'o' and 'l' were added)= " << tmp_1.size() << std::endl;
	tmp_2.push(77);
	stream << "tmp_2: size after push (77 was added)= " << tmp_2.size() << std::endl;
	stream <<  "----------------------------\n" << std::endl;

	stream << "top and pop: " << std::endl;
	stream << "tmp_1 top element: " << tmp_1.top() << std::endl;
	stream << "tmp_2 top element: " << tmp_2.top() << std::endl;
	tmp_1.pop();
	tmp_2.pop();
	stream << "tmp_1 top element after tmp_1.pop(): " << tmp_1.top() << "and size = " << tmp_1.size() << std::endl;
	stream << "tmp_2 top element after tmp_2.pop(): " << tmp_2.top() << "and size = " << tmp_1.size() << std::endl;
	stream << "----------------------------\n" << std::endl;
	return ;
}

void ft_check_my_stack()
{
	unsigned long 	start_time = clock();
	std::ofstream outPutFile_3;
	outPutFile_3.open("ft_stack.txt");
	if (!outPutFile_3.is_open())
		throw std::exception();
	ft_my_stack_out(outPutFile_3);
	outPutFile_3.close();
	unsigned long 	finish_time = clock();
	std::cout << YELLOW << "ft_stack time = " << finish_time - start_time << std::setprecision(7) << " msec" << DFLT << std::endl;
		
	unsigned long 	start_time_2 = clock();
	std::ofstream outPutFile_4;
	outPutFile_4.open("std_stack.txt");
	if (!outPutFile_4.is_open())
		throw std::exception();
	ft_stl_stack_out(outPutFile_4);
	outPutFile_4.close();
	unsigned long 	finish_time_2 = clock();
	std::cout << YELLOW << "std_stack time = " << finish_time_2 - start_time_2 << std::setprecision(7) << " msec" << DFLT << std::endl;
	
	std::cout << BLUE << "* STACK check files have been created *" << DFLT << std::endl << std::endl;
	return ;
}

template <typename T_MAP>
void	ft_print_map(T_MAP const &mp, std::ostream &stream)
{
	stream << "size: " << mp.size() << std::endl;
		typename T_MAP::const_iterator it = mp.begin(), ite = mp.end();
		stream << std::endl << "Content is:" << std::endl;
		while (it != ite)
		{
			stream << "- " << "key: " << it->first << " | value: " << it->second << std::endl;
			++it;
		}
	stream << "-----------------------------------------" << std::endl;
}

void ft_stl_map_out(std::ostream &stream)
{
	std::list<std::pair<int, std::string > > lst;
	unsigned int lst_size = 10;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(std::make_pair(i, std::string((lst_size - i), i + 65)));

		
	stream << "----------map_tests----------" << std::endl;

	std::map<int, std::string > map1;
	std::map<int, std::string > map2(lst.begin(), lst.end());
	std::map<int, std::string >::value_type tmp(42, "lol");
	std::map<int, std::string >::value_type tmp2(21, "lplplplplplp");
	std::map<int, std::string >::iterator it;
	std::map<int, std::string >::iterator it2;
	std::map<int, std::string >::reverse_iterator itr;

	
	stream << "is empty map1: " << map1.empty() << std::endl;
	stream << "is empty map2: " << map2.empty() << std::endl;
	map1 = map2;
	stream << "map1 after map1 = map2: " << std::endl;
	ft_print_map(map1, stream);
	stream << "map2: " << map1.empty() << std::endl;
	ft_print_map(map2, stream);
	stream << "map1 after insert key 42 and then 21: " << std::endl;
	map1.insert(tmp);
	map1.insert(tmp2);
	ft_print_map(map1, stream);
	stream << "map2 after erase key 8 and then key 0: " << std::endl;
	map2.erase(8);
	map2.erase(0);
	ft_print_map(map2, stream);
	stream << "map1 after erase from begin to ++ ++ begin " << std::endl;
	map1.erase(map1.begin(), (++(++map1.begin())));
	ft_print_map(map1, stream);
	stream << "map1 after erase another erase with iterators:" << std::endl;
	map1.erase((++(++map1.begin())), --map1.end());
	ft_print_map(map1, stream);
	map1[10] = "privet 10";
	map1[9] = "poka";
	map1[333] = "tr tr tr";
	map1[42] = "yyyyyyy";
	stream << "map1 after [10], [9], [333], [42] :" << std::endl;
	ft_print_map(map1, stream);
	
	it = map1.end(); --it;
	stream << "map1 begin() key:" << map1.begin()->first << std::endl;
	stream << "map1 --end() key:" << it->first << std::endl;
	
	stream << "map1 rbegin() key:" << map1.rbegin()->first << std::endl;
	itr = map1.rend(); --itr;
	stream << "map1 rend() key:" << itr->first << std::endl;

	stream << "map1 lower_bound(10)->second: ";
	stream << map1.lower_bound(10)->second << std::endl;
	stream << "map1 lower_bound(8)->second: ";
	stream << map1.lower_bound(8)->second << std::endl;

	stream << "map1 upper_bound(42)->second: ";
	stream << map1.upper_bound(42)->second << std::endl;
	stream << "map1 upper_bound(43)->second: ";
	stream << map1.upper_bound(43)->second << std::endl;


	stream << "map1:" << std::endl; ft_print_map(map1, stream);
	stream << "map2:" << std::endl; ft_print_map(map2, stream);
	map1.swap(map2);
	stream << "swap map1 and map2:\n ";
	stream << "map1:" << std::endl; ft_print_map(map1, stream);
	stream << "map2:" << std::endl; ft_print_map(map2, stream);

	it = map1.find(7);
	stream << "map1.find(7) second elem->: " << it->second << std::endl;
	
	it = map1.begin(); ++it;
	it2 = map1.end(); -- it2; --it2;
	bool res1 = map1.key_comp()(map1.begin()->first, it->first);
	bool res2 = map1.value_comp()(*it2, *it);
	stream << "key_comp: " << res1 << std::endl;
	stream << "value_comp: " << res2 << std::endl;

	map1.clear();
	map2.clear();
	stream << "\n\nmaps after clear: \n";
	ft_print_map(map1, stream);
	ft_print_map(map2, stream);
	return ;
	
}

void ft_my_map_out(std::ostream &stream)
{
	std::list<ft::pair<int, std::string > > lst;
	unsigned int lst_size = 10;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(ft::make_pair(i, std::string((lst_size - i), i + 65)));

	stream << "----------map_tests----------" << std::endl;

	ft::map<int, std::string > map1;

	ft::map<int, std::string > map2(lst.begin(), lst.end());
	
	ft::map<int, std::string >::value_type tmp(42, "lol");
	ft::map<int, std::string >::value_type tmp2(21, "lplplplplplp");
	ft::map<int, std::string >::iterator it;
	ft::map<int, std::string >::iterator it2;
	ft::map<int, std::string >::reverse_iterator itr;

	
	stream << "is empty map1: " << map1.empty() << std::endl;
	stream << "is empty map2: " << map2.empty() << std::endl;
	
	map1 = map2;
	stream << "map1 after map1 = map2: " << std::endl;
	
	ft_print_map(map1, stream);
	stream << "map2: " << map1.empty() << std::endl;
	ft_print_map(map2, stream);

	stream << "map1 after insert key 42 and then 21: " << std::endl;
	map1.insert(tmp);
	map1.insert(tmp2);
	ft_print_map(map1, stream);
	
	stream << "map2 after erase key 8 and then key 0: " << std::endl;
	map2.erase(8);
	map2.erase(0);
	ft_print_map(map2, stream);
	
	stream << "map1 after erase from begin to ++ ++ begin " << std::endl;
	map1.erase(map1.begin(), (++(++map1.begin())));
	ft_print_map(map1, stream);
	
	stream << "map1 after erase another erase with iterators:" << std::endl;
	map1.erase((++(++map1.begin())), --map1.end());
	ft_print_map(map1, stream);
	
	map1[10] = "privet 10";
	map1[9] = "poka";
	map1[333] = "tr tr tr";
	map1[42] = "yyyyyyy";
	stream << "map1 after [10], [9], [333], [42] :" << std::endl;
	ft_print_map(map1, stream);
	
	it = map1.end(); --it;
	stream << "map1 begin() key:" << map1.begin()->first << std::endl;
	stream << "map1 --end() key:" << it->first << std::endl;
	
	stream << "map1 rbegin() key:" << map1.rbegin()->first << std::endl;
	itr = map1.rend(); --itr;
	stream << "map1 rend() key:" << itr->first << std::endl;

	stream << "map1 lower_bound(10)->second: ";
	stream << map1.lower_bound(10)->second << std::endl;
	stream << "map1 lower_bound(8)->second: ";
	stream << map1.lower_bound(8)->second << std::endl;

	stream << "map1 upper_bound(42)->second: ";
	stream << map1.upper_bound(42)->second << std::endl;
	stream << "map1 upper_bound(43)->second: ";
	stream << map1.upper_bound(43)->second << std::endl;


	stream << "map1:" << std::endl; ft_print_map(map1, stream);
	stream << "map2:" << std::endl; ft_print_map(map2, stream);
	map1.swap(map2);
	stream << "swap map1 and map2:\n ";
	stream << "map1:" << std::endl; ft_print_map(map1, stream);
	stream << "map2:" << std::endl; ft_print_map(map2, stream);

	it = map1.find(7);
	stream << "map1.find(7) second elem->: " << it->second << std::endl;
	
	it = map1.begin(); ++it;
	it2 = map1.end(); -- it2; --it2;
	bool res1 = map1.key_comp()(map1.begin()->first, it->first);
	bool res2 = map1.value_comp()(*it2, *it);
	stream << "key_comp: " << res1 << std::endl;
	stream << "value_comp: " << res2 << std::endl;

	map1.clear();
	map2.clear();
	stream << "\n\nmaps after clear: \n";
	ft_print_map(map1, stream);
	ft_print_map(map2, stream);

	return ;

}

void ft_check_my_map()
{
	unsigned long 	start_time = clock();
	std::ofstream outPutFile_5;
	outPutFile_5.open("ft_map.txt");
	if (!outPutFile_5.is_open())
		throw std::exception();
	ft_my_map_out(outPutFile_5);
	outPutFile_5.close();
	unsigned long 	finish_time = clock();
	std::cout << YELLOW << "ft_map time = " << finish_time - start_time << std::setprecision(7) << " msec" << DFLT << std::endl;
		
	unsigned long 	start_time_2 = clock();
	std::ofstream outPutFile_6;
	outPutFile_6.open("std_map.txt");
	if (!outPutFile_6.is_open())
		throw std::exception();
	ft_stl_map_out(outPutFile_6);
	outPutFile_6.close();
	unsigned long 	finish_time_2 = clock();
	std::cout << YELLOW << "std_map time = " << finish_time_2 - start_time_2 << std::setprecision(7) << " msec" << DFLT << std::endl;
	
	std::cout << BLUE << "* MAP check files have been created *" << DFLT << std::endl << std::endl;
	return ;
}
