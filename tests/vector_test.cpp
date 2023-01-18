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

#define START		1		// Container filling
#define END			9		// range
#define NOENDL		false	// No end of line
typedef  int		T;		// Container value
typedef  int		T1;		// Container value

template<typename Container>
void fill_container(Container& c) {
	for (int i = START; i <= END; ++i) {
		c.push_back( 10 * i + 100 * i + i );
	}
}

template<typename Container>
void print_container(Container& c) {
	typename Container::iterator it = c.begin();
	typename Container::iterator End = c.end();
//	std::cout << "\\033[2m";
	for (; it != End; ++it) std::cout << *it << " ";
	std::cout << "size = " << c.size();
	std::cout << " capacity = " << c.capacity() << std::endl;
//	std::cout << " \\033[0m";
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
		print("====TESTING CONSTRUCTORS AND operator=() ====\n");
		
		ft::vector<T> v;
		print("ft::vector<T> v;");
		print("v: ", NOENDL); print(v);
		
		std::allocator<T1> alloc;
		print("std::allocator<T1> alloc;");
		ft::vector<T> v1(alloc);
		print("ft::vector<T> v1(ft::vector<T> v1(alloc);");
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
	}
	{
		print("====namespace std\n");
		
		std::vector<T> v;
		print("std::vector<T> v;");
		print("v: ", NOENDL); print(v);
		
		std::allocator<T1> alloc;
		print("std::allocator<T1> alloc;");
		std::vector<T> v1(alloc);
		print("std::vector<T> v1(std::vector<T> v1(alloc);");
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
	}
	return 0;
}

