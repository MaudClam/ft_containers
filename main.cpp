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
#include <list>
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

typedef  int		Key;
typedef  int		T;

template<class T1, class T2>
std::ostream&		operator<<(std::ostream& o, ft::pair<T1,T2>& pair) {
	o << pair.first << "=" << pair.second;
	return o;
}

template< typename Container >
void fill_container(Container& c) {
	for (int i = START; i <= END; ++i) {
		c.insert(NS::make_pair( i, 10 * i + 100 * i + i) );
	}
}

template< typename Container >
void print_container(Container& c) {
	
	typename Container::iterator xIt;
	typename Container::iterator Begin( c.begin() );
	typename Container::iterator End( c.end() );
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
	typename Container::reverse_iterator rIt = c.rbegin();
	typename Container::reverse_iterator rEnd( c.rend() );
	std::cout << "map: ";
	for (; rIt != rEnd; ++rIt) {
		std::cout << *rIt << " ";
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
	m[3] = 2;
	m[77] = 1000001;
	try {
		std::cout << m.at(77) << std::endl;
		std::cout << m.at(99) << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	print_container_It(m);
	m.erase(++++++m.begin(), ------m.end());
	print_container_It(m);
	erase_container_It(m);
	print_container_It(m);
	std::cout << std::endl;
		
	std::cout << "Hellow, World!\n";
	return 0;
}
