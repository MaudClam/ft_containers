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
	for (int i = END; i >= START; --i) {
		map[i] = 10 * i + 100 * i + i;
//		map.insert( map.begin(), ft::pair<T1,T2>(i, 10 * i + 100 * i + i) );
	}
}

template< typename T1, typename T2 >
void fill_map(ft::map<const T1,T2>& map) {
	for (int i = END; i >= START; --i) {
		map[i] = 10 * i + 100 * i + i;
//		map.insert( map.begin(), ft::pair<T1,T2>(i, 10 * i + 100 * i + i) );
	}
}

typedef int		Key;
typedef int		T;

int main(int, const char**)
{
	ft::map<Key,T>	map, mapp;
	fill_map(map);

	ft::pair<ft::map<Key,T>::iterator, bool> it_bool;
	it_bool = map.insert( ft::make_pair<Key,T>(5,1) );
	std::cout << "insert(5-1) return " << *it_bool.first << (it_bool.second ? " true\n" : " false\n");
	it_bool = map.insert( ft::make_pair<Key,T>(10,10) );
	std::cout << "insert(10-10) return "  << *it_bool.first << (it_bool.second ? " true\n" : " false\n");
	std::cout << std::endl;

	ft::map<Key,T>::iterator pos = map.begin();
	++pos; ++pos; ++pos;
	ft::map<Key,T>::iterator it = map.insert( pos, ft::make_pair<Key,T>(5,1) );
	std::cout << "insert(5-1) return " << *it << " \n";
	it = map.insert( pos, ft::make_pair<Key,T>(-1,1) );
	std::cout << "insert(-1-1) return "   << *it << " \n";
	std::cout << std::endl;

	map.printIteratively();
	std::cout << std::endl;

	std::cout << "erase(" << *pos << ") return ";
	pos = map.erase(pos);
	std::cout << *pos << "\n";
	std::cout << std::endl;
	
	map.printIteratively();
	std::cout << std::endl;

	ft::map<Key,T>::iterator first = map.begin();
	++first; ++first; ++first;
	ft::map<Key,T>::iterator last = first;
	++last; ++last;
	std::cout << "erase(" << *first << ", ";
	if ( last == map.end() ) std::cout << "end()"; else std::cout << *last;
	std::cout << ") return ";
	pos = map.erase(first, last);
	if ( pos == map.end() ) std::cout << "end()\n"; else std::cout << *pos << "\n";
	std::cout << std::endl;

	map.printIteratively();
	std::cout << std::endl;

	mapp[1] = 2;
	mapp[3] = 4;
	mapp[3] = 7;
	
	map.swap(mapp);

	try {
		map = mapp;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	map.printRecursively();
	std::cout << std::endl;
	
	Key x = 2;
	ft::map<Key,T>::iterator l_bound( map.lower_bound(&x) );
	std::cout << "map.lower_bound(" << x << ") = ";
	if ( l_bound == map.end() ) std::cout << "end()\n"; else std::cout << *l_bound << "\n";
	x = 3;
	ft::map<Key,T>::const_iterator cl_bound( map.lower_bound(x) );
	std::cout << "map.lower_bound(" << x << ") = ";
	if ( cl_bound == map.cend() ) std::cout << "end()\n"; else std::cout << *cl_bound << "\n";

	return 0;
}
