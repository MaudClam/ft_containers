/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair_test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:00:19 by mclam             #+#    #+#             */
/*   Updated: 2022/12/09 14:00:19 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include "pair.hpp"

template<class T1, class T2>
void print( std::string rem, const ft::pair<T1,T2>& p ) {
	std::cout << rem << "(" << p.first << ", " << p.second << ")\n";
}

template<class T1, class T2>
void print( std::string rem, const std::pair<T1,T2>& p ) {
	std::cout << rem << "(" << p.first << ", " << p.second << ")\n";
}

int main(void)
{
	ft::pair<int, float> p1;
	print("(1) Value-initialized: ", p1);

	ft::pair<int, double> p2(42, 3.1415);
	print("(2) Initialized with two values: ", p2);

	ft::pair<int, double> p4(p2);
	print("(5) Initialized with pair: ", p4);
	
	ft::pair<char, int> p5(p2);
	print("(5) Implicitly converted: ", p5);

	double	x = 77.1;
	char	y = 'N';
	ft::pair<char, int> p6 = ft::make_pair(x, y);
	print("ft::make_pair visibly converted: ", p6);

	std::pair<char, int> p7 = std::make_pair(x, y);
	print("std::make_pair implicitly converted: ", p7);

//	Not fo c++98, test for operator==,!=,<,<=,>,>=,<=>(std::pair)
/*	std::vector<ft::pair< int, std::string> > v = { {2, "baz"},
													  {2, "bar"},
													  {1, "foo"} };
	std::sort(v.begin(), v.end());
	for(auto p: v) {
		std::cout << "{" << p.first << ", " << std::quoted(p.second) << "}\n";
	}
*/
}
