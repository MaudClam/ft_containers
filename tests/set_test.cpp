/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 19:56:01 by mclam             #+#    #+#             */
/*   Updated: 2023/01/22 19:56:01 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include "../vector.hpp"
#include "../map.hpp"
#include "../stack.hpp"
#include "../set.hpp"

#define DBG			false		// Debag mode
#define NOENDL		false		// No end of line
#define OUT_STYLE	"\033[2m"	// Style for output
#define NORM_STYLE	"\033[0m"	// Normal style

template<typename Container>
void print_container(Container& c) {
	typename Container::iterator it = c.begin();
	typename Container::iterator End = c.end();
	if (!DBG) std::cout << OUT_STYLE;
	for (; it != End; ++it) std::cout << *it << " ";
	if (!DBG) std::cout << NORM_STYLE;
	std::cout << "size = " << c.size() << std::endl;
}

template<class T>
std::ostream&		operator<<(std::ostream& o, std::set<T>& v) {
	print_container(v);
	return o;
}

template<class T>
std::ostream&		operator<<(std::ostream& o, ft::set<T>& v) {
	print_container(v);
	return o;
}

template<typename U>
void	print(U& var, bool endl = true) {
	std::cout << std::boolalpha << var;
	if (endl) std::cout << std::endl;
}

template<typename Container>
void	rand_fill(Container& c, int start, int end) {
	srand( static_cast<unsigned int>(clock()) );
	for (int i = start; i <= end; ++i) {
		c.insert(c.begin(), typename Container::value_type(start + rand() % (end - start + 1)) );
	}
}

int	main(void) {

	print("\n================ SET TESTING ================");
	print("SET IS RED-BLACK TREE OF SORTED UNIQUE KEYS");

	print("\nSET BEHAVIOR AND METHODS ARE THE SAME AS MAP\n");
	
	ft::set<int> s;
	print("ft::set<int> s;");
	rand_fill(s, 1, 24);
	print("rand_fill(s, 1, 24);");
	print("s: ",NOENDL); print(s,NOENDL);
	s.printRecursively();

	print("\nSET IMPLEMENTS THE BIDIRECTIONAL ITERATOR");
	print("THE SAME ITERATORS AS MAP");
	print("A REVERSE ITERATOR ALSO IMPLEMENTED\n");

	ft::set<int>::reverse_iterator rit = s.rbegin();
	print("ft::set<int>::reverse_iterator rit = s.rbegin();");
	ft::set<int>::reverse_iterator rEnd = s.rend();
	print("for (; rit != rEnd; ++rit) {");
	print("    :std::cout << *rit << \" \"; }:");
	print("s: ",NOENDL);
	for (; rit != rEnd; ++rit) {
		std::cout << OUT_STYLE << *rit << NORM_STYLE << " "; }
	size_t x = s.size();
	print("size = ",NOENDL); print(x);
	return 0;
}
