/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   @filename.c@                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 23:36:41 by mclam             #+#    #+#             */
/*   Updated: 2023/01/04 23:36:41 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include "map.hpp"

#define START	1
#define END		9
#define NS		ft
#define ss		std::cout

typedef int		Key;
typedef int		T;

template< typename Container >
void fill_container(Container& c) {
	for (int i = START; i <= END; ++i) {
		c.insert(NS::make_pair( i, 10 * i + 100 * i + i) );
	}
}

template< typename Container >
void print_container(Container& c) {
	typename Container::const_iterator xIt;
	typename Container::const_iterator Begin( c.cbegin() );
	typename Container::iterator End( c.cend() );
	xIt = Begin;
//	xIt->second = 777;
	std::cout << "map: ";
	for (; xIt != End; ++xIt) {
		std::cout << xIt->first << "-" << xIt->second << " ";
	}
	std::cout << "\nsize = " << c.size() << std::endl;
}

template< typename Container >
void print_container_It(Container& c) {
	typename Container::iterator It = c.begin();
	typename Container::iterator End( c.cend() );
	std::cout << "map: ";
	for (; It != End; ++It) {
		std::cout << It->first << "-" << It->second << " ";
	}
	std::cout << "\nsize = " << c.size() << std::endl;
}

template< typename Container >
void erase_container_It(Container& c) {
	typename Container::iterator It = c.begin();
	typename Container::iterator End( c.end() );
		c.erase(c.cbegin(), --c.cend());
}

int	main(){
	
	{
		NS::map<int, int>	A;
		A.insert(NS::make_pair(0, 0));
		A.insert(NS::make_pair(-2, -2));
		A.insert(NS::make_pair(2, 2));
		A.insert(NS::make_pair(-1, -1));
		A.insert(NS::make_pair(1, 1));
		A.insert(NS::make_pair(-3, -3));
		A.insert(NS::make_pair(3, 3));
		A.insert(NS::make_pair(-4, -4));
		A.insert(NS::make_pair(4, 4));
		ss << " " << A.size() << " ";
		for (NS::map<int, int>::iterator first = A.begin(); first != A.end(); ++first)
			ss << " " << first->second;
		NS::map<int, int>::iterator	it1;
		NS::map<int, int>::iterator	it2;
		it1 = A.find(-1);
		it2 = A.find(1);
		A.erase(it1, it2);
		for (NS::map<int, int>::iterator first = A.begin(); first != A.end(); ++first)
			ss << " " << first->second;
		ss << " " << A.size() << " ";
		A.erase(A.find(-2));
		A.erase(A.find(2));
		for (NS::map<int, int>::iterator first = A.begin(); first != A.end(); ++first)
			ss << " " << first->second;
		ss << " " << A.size() << " ";
		A.erase(A.find(-3));
		A.erase(A.find(4));
		for (NS::map<int, int>::iterator first = A.begin(); first != A.end(); ++first)
			ss << " " << first->second;
		ss << " " << A.size();
		A.clear();
		ss << " " << A.size();
	}
	
	NS::map<Key,T> m;
	fill_container(m);
	print_container(m);
	print_container_It(m);
//	erase_container_It(m);
	print_container_It(m);
	std::cout << std::endl;
		
	std::cout << "Hellow, World!\n";
	return 0;
}
