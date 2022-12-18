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
		map.insert(i, 99);
}

int main(int, const char**)
{
	ft::map<int, int>	my_map;
	std::map<int, int>	map;
	
	fill_map(my_map);
	map[1] = 77;
	ft::map<int, int>::iterator it = my_map.begin();
	(void)it;
//	std::map<int, int>::iterator it1 = map.begin();
//	std::cout << *(++it) << std::endl;
//	std::cout << it->first << std::endl;
//	std::cout << it1 << std::endl;
//	it++;
//	std::cout << *it << std::endl;

	
	
	std::cout << my_map.size() << std::endl;
	std::cout << "Hello, World!\n";
	return 0;
}
