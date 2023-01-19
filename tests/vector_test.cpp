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
	{
		print("\n==== VECTOR TESTING CONSTRUCTORS AND operator=() ====\n");

		ft::vector<T> v;
		print("ft::vector<T> v;");
		print("v: ", NOENDL); print(v);

		std::allocator<T1> alloc;
		print("std::allocator<T1> alloc;");
		ft::vector<T> v1(alloc);
		print("ft::vector<T> v1(alloc);");
		print("v1: ", NOENDL); print(v1);

		ft::vector<T> v2(9, 717);
		print("ft::vector<T> v2(9, 717);");
		print("v2: ", NOENDL); print(v2);

		ft::set<T> s; s.insert(712); s.insert(812); s.insert(999); s.insert(-212);
		print("ft::set<T> s; s.insert(712); s.insert(812); s.insert(919); s.insert(-212);");
		ft::set<T>::iterator sIt(s.begin());
		print("ft::set<T>::iterator sIt(s.begin());");
		ft::vector<T> v3(sIt, ++++++sIt);
		print("ft::vector<T> v3(sIt, ++++++sIt);");
		print("v3: ", NOENDL); print(v3);

		ft::vector<T> v4(v3);
		print("ft::vector<T> v4(v3);");
		print("v4: ", NOENDL); print(v4);

		v2 = v4;
		print("v2 = v4;");
		print("v2: ", NOENDL); print(v2, NOENDL);
		print("v4: ", NOENDL); print(v4);

		v1 = v2;
		print("v1 = v2;");
		print("v1: ", NOENDL); print(v1, NOENDL);
		print("v2: ", NOENDL); print(v2);
	}
	{
		print("==== namespace std, STL lib\n");

		std::vector<T> v;
		print("std::vector<T> v;");
		print("v: ", NOENDL); print(v);

		std::allocator<T1> alloc;
		print("std::allocator<T1> alloc;");
		std::vector<T> v1(alloc);
		print("std::vector<T> v1(alloc);");
		print("v1: ", NOENDL); print(v1);

		std::vector<T> v2(9, 717);
		print("std::vector<T> v2(9, 717);");
		print("v2: ", NOENDL); print(v2);

		std::set<T> s; s.insert(712); s.insert(812); s.insert(999); s.insert(-212);
		print("std::set<T> s; s.insert(712); s.insert(812); s.insert(919); s.insert(-212);");
		std::set<T>::iterator sIt(s.begin());
		print("ft::set<T>::iterator sIt(s.begin());");
		std::vector<T> v3(sIt, ++++++sIt);
		print("std::vector<T> v3(sIt, ++++++sIt);");
		print("v3: ", NOENDL); print(v3);

		std::vector<T> v4(v3);
		print("std::vector<T> v4(v3);");
		print("v4: ", NOENDL); print(v4);

		v2 = v4;
		print("v2 = v4;");
		print("v2: ", NOENDL); print(v2, NOENDL);
		print("v4: ", NOENDL); print(v4);

		v1 = v2;
		print("v1 = v2;");
		print("v1: ", NOENDL); print(v1, NOENDL);
		print("v2: ", NOENDL); print(v2);
	}
	{
		print("==== VECTOR TESTING FUNCTIONS ====\n");

		ft::vector<T1> v;
		print("ft::vector<T1> v;");
		v.assign(9, '*');
		print("v.assign(9, '*');");
		print("v: ", NOENDL); print(v);

		ft::vector<T1> v1(9, '#');
		print("ft::vector<T1> v1(9, '#');");
		print("v1: ", NOENDL); print(v1, NOENDL);
		v1.assign(++++v.begin(), ----v.end());
		print("v1.assign(++++v.begin(), ----v.end());");
		print("v1: ", NOENDL); print(v1);

		ft::vector<T> v2;
		print("ft::vector<T> v2;");
		for (int i = 0; i <= 9; ++i) v2.push_back(i);
		print("for (int i = 0; i <= 9; ++i) v2.push_back(i);");
		print("v2: ", NOENDL); print(v2);

		v2.pop_back();;
		print("v2.pop_back();");
		print("v2: ", NOENDL); print(v2);
		
		v2[6] = 90009;
		print("v2[6] = 90009;");
		print("v2: ", NOENDL); print(v2);

		v2.at(6) = 10001;
		print("v2.at(6) = 10001;");
		print("v2: ", NOENDL); print(v2);
		
		print("try { v2.at(15) = 10001; } catch (std::out_of_range const& e) {");
		print("\tstd::cerr << e.what() << std::endl; }");
		try { v2.at(15) = 10001; } catch (std::out_of_range const& e) {
			std::cerr	<< (DBG ? "" : OUT_STYLE) << e.what()
						<< (DBG ? "\n" : NORM_STYLE"\n") << std::endl; }
		
		v2.reserve(100);
		print("v2.reserve(100);");
		print("v2: ", NOENDL); print(v2);
		
		print("try { v2.reserve(v2.max_size() + 1); } catch (std::exception& e) {");
		print("\tstd::cerr << e.what() << std::endl; }");
		try { v2.reserve((v2.max_size() + 1)); } catch (std::exception& e) {
			std::cerr	<< (DBG ? "" : OUT_STYLE) << e.what()
						<< (DBG ? "\n" : NORM_STYLE"\n") << std::endl; }

		v2.resize(3);
		print("v2.resize(3);");
		print("v2: ", NOENDL); print(v2);

		v2.resize(10);
		print("v2.resize(10);");
		print("v2: ", NOENDL); print(v2);
		
		v2.clear();
		print("v2.clear();");
		print("v2: ", NOENDL); print(v2);

	}
	{
		print("==== namespace std, STL lib\n");
		
		std::vector<T1> v;
		print("std::vector<T1> v;");
		v.assign(9, '*');
		print("v.assign(9, '*');");
		print("v: ", NOENDL); print(v);

		std::vector<T1> v1(9, '#');
		print("std::vector<T1> v1(9, '#');");
		print("v1: ", NOENDL); print(v1, NOENDL);
		v1.assign(++++v.begin(), ----v.end());
		print("v1.assign(++++v.begin(), ----v.end());");
		print("v1: ", NOENDL); print(v1);

		std::vector<T> v2;
		print("std::vector<T> v2;");
		for (int i = 0; i <= 9; ++i) v2.push_back(i);
		print("for (int i = 0; i <= 9; ++i) v2.push_back(i);");
		print("v2: ", NOENDL); print(v2);

		v2.pop_back();;
		print("v2.pop_back();");
		print("v2: ", NOENDL); print(v2);
		
		v2[6] = 90009;
		print("v2[6] = 90009;");
		print("v2: ", NOENDL); print(v2);

		v2.at(6) = 10001;
		print("v2.at(6) = 10001;");
		print("v2: ", NOENDL); print(v2);
		
		print("try { v2.at(15) = 10001; } catch (std::out_of_range const& e) {");
		print("\tstd::cerr << e.what() << std::endl; }");
		try { v2.at(15) = 10001; } catch (std::out_of_range const& e) {
			std::cerr	<< (DBG ? "" : OUT_STYLE) << e.what()
						<< (DBG ? "\n" : NORM_STYLE"\n") << std::endl; }
		
		v2.reserve(100);
		print("v2.reserve(100);");
		print("v2: ", NOENDL); print(v2);
		
		print("try { v2.reserve(v2.max_size() + 1); } catch (std::exception& e) {");
		print("\tstd::cerr << e.what() << std::endl; }");
		try { v2.reserve((v2.max_size() + 1)); } catch (std::exception& e) {
			std::cerr	<< (DBG ? "" : OUT_STYLE) << e.what()
						<< (DBG ? "\n" : NORM_STYLE"\n") << std::endl; }

		v2.resize(3);
		print("v2.resize(3);");
		print("v2: ", NOENDL); print(v2);

		v2.resize(10);
		print("v2.resize(10);");
		print("v2: ", NOENDL); print(v2);
		
		v2.clear();
		print("v2.clear();");
		print("v2: ", NOENDL); print(v2);

	}
	return 0;
}

