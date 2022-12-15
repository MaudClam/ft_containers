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
#include "map.hpp"


int main(int, const char**)
{
	ft::map<const int, int> my_map;
	
	my_map.insert(1, '*');
	
//	std::cout << my_map.size() << std::endl;
	

	std::cout << "Hello, World!\n";
	return 0;
}
