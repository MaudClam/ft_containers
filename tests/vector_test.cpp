/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:35:38 by mclam             #+#    #+#             */
/*   Updated: 2023/01/18 13:35:38 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
//#include <stdexcept>
//#include <exception>
//#include <new>
#include <vector>
#include <set>
#include "../vector.hpp"
#include "../set.hpp"

#define DBG			false		// Debag mode
#define NOENDL		false		// No end of line
#define OUT_STYLE	"\033[2m"	// Style for output
#define NORM_STYLE	"\033[0m"	// Normal style
typedef  int		T;			// Container value
typedef  char		T1;			// Container value

template<typename Container>
void print_container(Container& c) {
	typename Container::iterator it = c.begin();
	typename Container::iterator End = c.end();
	if (!DBG) std::cout << OUT_STYLE;
	for (; it != End; ++it) std::cout << *it << " ";
	std::cout << "size = " << c.size();
	std::cout << " capacity = " << c.capacity() << std::endl;
	if (!DBG) std::cout << NORM_STYLE;
}

template<class T>
std::ostream&		operator<<(std::ostream& o, ft::vector<T>& v) {
	print_container(v);
	return o;
}

template<class T>
std::ostream&		operator<<(std::ostream& o, std::vector<T>& v) {
	print_container(v);
	return o;
}

template<typename U>
void	print(U& var, bool endl = true) {
	std::cout << std::boolalpha << var;
	if (endl) std::cout << std::endl;
}

int	main(void) {
//	{
//		print("==== VECTOR TESTING CONSTRUCTORS AND operator=() ====\n");
//
//		ft::vector<T> v;
//		print("ft::vector<T> v;");
//		print("v: ", NOENDL); print(v);
//
//		std::allocator<T1> alloc;
//		print("std::allocator<T1> alloc;");
//		ft::vector<T> v1(alloc);
//		print("ft::vector<T> v1(alloc);");
//		print("v1: ", NOENDL); print(v1);
//
//		ft::vector<T> v2(9, 717);
//		print("ft::vector<T> v2(9, 717);");
//		print("v2: ", NOENDL); print(v2);
//
//		ft::set<T> s; s.insert(712); s.insert(812); s.insert(999); s.insert(-212);
//		print("ft::set<T> s; s.insert(712); s.insert(812); s.insert(919); s.insert(-212);");
//		ft::set<T>::iterator sIt(s.begin());
//		print("ft::set<T>::iterator sIt(s.begin());");
//		ft::vector<T> v3(sIt, ++++++sIt);
//		print("ft::vector<T> v3(sIt, ++++++sIt);");
//		print("v3: ", NOENDL); print(v3);
//
//		ft::vector<T> v4(v3);
//		print("ft::vector<T> v4(v3);");
//		print("v4: ", NOENDL); print(v4);
//
//		v2 = v4;
//		print("v2 = v4;");
//		print("v2: ", NOENDL); print(v2, NOENDL);
//		print("v4: ", NOENDL); print(v4);
//
//		v1 = v2;
//		print("v1 = v2;");
//		print("v1: ", NOENDL); print(v1, NOENDL);
//		print("v2: ", NOENDL); print(v2);
//	}
//	{
//		print("==== namespace std, STL lib\n");
//
//		std::vector<T> v;
//		print("std::vector<T> v;");
//		print("v: ", NOENDL); print(v);
//
//		std::allocator<T1> alloc;
//		print("std::allocator<T1> alloc;");
//		std::vector<T> v1(alloc);
//		print("std::vector<T> v1(alloc);");
//		print("v1: ", NOENDL); print(v1);
//
//		std::vector<T> v2(9, 717);
//		print("std::vector<T> v2(9, 717);");
//		print("v2: ", NOENDL); print(v2);
//
//		std::set<T> s; s.insert(712); s.insert(812); s.insert(999); s.insert(-212);
//		print("std::set<T> s; s.insert(712); s.insert(812); s.insert(919); s.insert(-212);");
//		std::set<T>::iterator sIt(s.begin());
//		print("ft::set<T>::iterator sIt(s.begin());");
//		std::vector<T> v3(sIt, ++++++sIt);
//		print("std::vector<T> v3(sIt, ++++++sIt);");
//		print("v3: ", NOENDL); print(v3);
//
//		std::vector<T> v4(v3);
//		print("std::vector<T> v4(v3);");
//		print("v4: ", NOENDL); print(v4);
//
//		v2 = v4;
//		print("v2 = v4;");
//		print("v2: ", NOENDL); print(v2, NOENDL);
//		print("v4: ", NOENDL); print(v4);
//
//		v1 = v2;
//		print("v1 = v2;");
//		print("v1: ", NOENDL); print(v1, NOENDL);
//		print("v2: ", NOENDL); print(v2);
//	}
//	{
//		print("==== VECTOR TESTING FUNCTIONS ====\n");
//
//		ft::vector<T1> v;
//		print("ft::vector<T1> v;");
//		v.assign(9, '*');
//		print("v.assign(9, '*');");
//		print("v: ", NOENDL); print(v);
//
//		ft::vector<T1> v1(9, '#');
//		print("ft::vector<T1> v1(9, '#');");
//		print("v1: ", NOENDL); print(v1, NOENDL);
//		v1.assign(++++v.begin(), ----v.end());
//		print("v1.assign(++++v.begin(), ----v.end());");
//		print("v1: ", NOENDL); print(v1);
//
//		ft::vector<T> v2;
//		print("ft::vector<T> v2;");
//		for (int i = 1; i <= 9; ++i) v2.push_back(i);
//		print("for (int i = 1; i <= 9; ++i) v2.push_back(i);");
//		print("v2: ", NOENDL); print(v2, NOENDL);
//		print("v2.at(6) = ", NOENDL); print(v2.at(6));
//		print("try { v2.at(11); } catch (const std::exception& e) {");
//		print("\tstd::cout << e.what() << std::endl; }");
//		try { v2.at(11); } catch (const std::exception& e) {
//			std::cout << (DBG ? "" : OUT_STYLE) << e.what() << (DBG ? "" : NORM_STYLE) << std::endl; }
//		v2.at(0) = 99;
//		print("v2.at(0) = 99;");
//		print("v2: ", NOENDL); print(v2, NOENDL);
//	}
//	{
//		print("\n==== namespace std, STL lib\n");
//
//		std::vector<T1> v;
//		print("std::vector<T1> v;");
//		v.assign(9, '*');
//		print("v.assign(9, '*');");
//		print("v: ", NOENDL); print(v);
//
//		std::vector<T1> v1(9, '#');
//		print("std::vector<T1> v1(9, '#');");
//		print("v1: ", NOENDL); print(v1, NOENDL);
//		v1.assign(++++v.begin(), ----v.end());
//		print("v1.assign(++++v.begin(), ----v.end());");
//		print("v1: ", NOENDL); print(v1);
//	}

		std::vector<T> v2;
//		print("std::vector<T> v2;");
		for (int i = 1; i <= 9; ++i) v2.push_back(i);
		print("for (int i = 0; i <= 9; ++i) v2.push_back(i);");
		print("v2: ", NOENDL); print(v2, NOENDL);
//		print("v2.at(6) = ", NOENDL); print(v2.at(6));
//		print("try { v2.at(11); } catch (const std::exception& e) {");
//		print("\tstd::cout << e.what() << std::endl; }");
//		v2.at(0) = 1;
//		print("v2: ", NOENDL); print(v2, NOENDL);

		try {
			v2.at(99);
		} catch (const std::exception& e) {
			std::cout << e.what() << '\n'; }

//	}
	return 0;
}

