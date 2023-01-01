/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_map_test.cpp                                           :+:      :+:    :+:   */
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
std::ostream& operator<<(std::ostream& o, ft::pair<T1, T2>& pair) {
	o << pair.first << "-" << pair.second;
	return o;
}

template< typename T1, typename T2 >
std::ostream& operator<<(std::ostream& o, std::pair<T1, T2>& pair) {
	o << pair.first << "-" << pair.second;
	return o;
}

template< typename Container >
void fill_container(Container& c) {
	for (int i = END; i >= START; --i) {
		c[i] = 10 * i + 100 * i + i;
	}
}

template< typename Container >
void print_container(Container& c) {
	typename Container::iterator it;
	for (it = c.begin(); it != c.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

template< typename Container >
void print_rev_container(Container& c) {
	typename Container::reverse_iterator it;
	for (it = c.rbegin(); it != c.rend(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

template< typename Container >
void print_container_decrement(Container& c) {
	typename Container::iterator it;
	it = c.end();
	while (it != c.begin())
		std::cout << *(--it) << " ";
	std::cout << std::endl;
}

template< typename Container >
void print_rev_container_decrement(Container& c) {
	typename Container::reverse_iterator it;
	it = c.rend();
	while (it != c.rbegin())
		std::cout << *(--it) << " ";
	std::cout << std::endl;
}

typedef int			Key;
typedef int			T;

int main(int, const char**)
{
	std::map<Key,T>	map;
	ft::map<Key,T>	my_map;
	fill_container(map);
	fill_container(my_map);

	
	print_container(map);
	print_container(my_map);
	std::cout << std::endl;

	print_rev_container(map);
	print_rev_container(my_map);
	std::cout << std::endl;

	print_container_decrement(map);
	print_container_decrement(my_map);
	std::cout << std::endl;

	print_rev_container_decrement(map);
	print_rev_container_decrement(my_map);
	std::cout << std::endl;

	std::map<Key,T>	map1;
	fill_container(map1);
	ft::map<Key,T>	my_map1;
	fill_container(my_map1);
	
	std::cout 	<< std::boolalpha << "map == map1: "
				<<	(map == map1) << std::endl;
	std::cout 	<< std::boolalpha << "my_map == my_map1: "
				<<	(my_map == my_map1) << std::endl;
	std::cout << std::endl;

	my_map[3] = 3;
	map[3] = 3;
	std::cout 	<< std::boolalpha << "map == map1: "
				<<	(map == map1) << std::endl;
	std::cout 	<< std::boolalpha << "my_map == my_map1: "
				<<	(my_map == my_map1) << std::endl;
	std::cout << std::endl;


	std::cout 	<< std::boolalpha << "map < map1: "
				<<	(map < map1) << std::endl;
	std::cout 	<< std::boolalpha << "my_map < my_map1: "
				<<	(my_map < my_map1) << std::endl;
	std::cout << std::endl;

	map1 = map;
	my_map1 = my_map;

	print_rev_container_decrement(map);
	print_rev_container_decrement(my_map1);
	std::cout << std::endl;

	return 0;
}
