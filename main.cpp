/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 12:02:48 by mclam             #+#    #+#             */
/*   Updated: 2022/12/04 12:02:48 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include "map.hpp"

# define START			1			/* Start key to be stored */
# define END			9			/* End key to be stored */

template< typename T1, typename T2 >
void fill_map(ft::map<T1,T2>& map) {
	for (int i = END; i >= START; --i)
		map[i] = 99 * i + i;
}

template< typename T1, typename T2 >
void fill_map(ft::map<const T1,T2>& map) {
	for (int i = END; i >= START; --i)
		map[i] = 99 * i + i;
}

typedef const int		Key;
typedef int		T;

int main(int, const char**)
{
	ft::map<Key,T>	map, mapp;

	fill_map(map);
	
	ft::pair<ft::map<Key,T>::iterator, bool> p;
	p = map.insert( ft::make_pair<Key,T>(5,1) );
	
	ft::map<Key,T>::iterator pos = map.begin();
	++pos; ++pos; ++pos; ++pos; ++pos; ++pos;
	ft::map<Key,T>::iterator it = map.insert( pos, ft::make_pair<Key,T>(5,1) );
	
	std::cout << *p.first << " " << p.second << std::endl;
	std::cout << *it << " " << std::endl;


	mapp[1] = 2;
	mapp[3] = 4;

	std::cout << map.size() << std::endl;
	std::cout << mapp.size() << std::endl;

	try {
		mapp = map;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << map.size() << std::endl;
	std::cout << mapp.size() << std::endl;

	std::cout << "Hello, World!\n";
	return 0;
}
