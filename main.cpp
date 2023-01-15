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
#include <vector>
#include <map>
#include <set>
#include <list>
#include "vector.hpp"
#include "map.hpp"
#include "set.hpp"

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
void fill_container_set(Container& c) {
	for (int i = START; i <= END; ++i) {
		c.insert(i);
	}
}

template< typename Container >
void print_container(Container& c) {
	
	typename Container::const_iterator xIt = c.begin();
	typename Container::iterator Begin( c.begin() );
	typename Container::iterator End( c.end() );
	xIt = Begin;
	std::cout << std::boolalpha << "xIt == Begin | " << (xIt == Begin) << std::endl;
	std::cout << std::boolalpha << "Begin == xIt | " << (Begin == xIt) << std::endl;
	std::cout << std::boolalpha << "xIt != Begin | " << (xIt != Begin) << std::endl;
	std::cout << std::boolalpha << "Begin != xIt | " << (Begin != xIt) << std::endl;
//	xIt->second = 777;
	std::cout << "cntnr: ";
	for (; xIt != End; ++xIt) {
		std::cout << *xIt << " ";
	}
	std::cout << "\nsize = " << c.size() << std::endl;
}

template< typename Container >
void print_container_It(Container& c) {
	typename Container::reverse_iterator rIt = c.rbegin();
	typename Container::reverse_iterator rEnd( c.rend() );
	std::cout << "cntnr: ";
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

int	main() {
	

		NS::set<Key> s;
		fill_container_set(s);
		print_container(s);
		print_container_It(s);
		s.erase(++++++s.begin(), ------s.end());
		print_container_It(s);
		erase_container_It(s);
		print_container_It(s);
		std::cout << std::endl;
		
	std::cout << "Hellow, World!\n";
	return 0;
}
