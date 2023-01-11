/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:36:30 by mclam             #+#    #+#             */
/*   Updated: 2023/01/11 16:36:30 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include "map.hpp"

# include <iostream>
# include <exception>
# include <new>

# include <string>
# include <memory>
# include <limits>
# include <cstddef>
# include <sstream>

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
	
	typename Container::iterator xIt;
	typename Container::const_iterator Begin( c.begin() );
	typename Container::const_iterator End( c.end() );
	xIt = Begin;
	std::cout << std::boolalpha << "xIt == Begin | " << (xIt == Begin) << std::endl;
	std::cout << std::boolalpha << "Begin == xIt | " << (Begin == xIt) << std::endl;
	std::cout << std::boolalpha << "xIt != Begin | " << (xIt != Begin) << std::endl;
	std::cout << std::boolalpha << "Begin != xIt | " << (Begin != xIt) << std::endl;
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
	typename Container::const_iterator End( c.end() );
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
	c.erase(It, End);
}

int	main(){
	
	NS::map<Key,T> m;
	fill_container(m);
	print_container(m);
	print_container_It(m);
	erase_container_It(m);
	print_container_It(m);
	std::cout << std::endl;
		
	std::cout << "Hellow, World!\n";
	return 0;
}