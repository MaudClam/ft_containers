/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_test.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:48:13 by mclam             #+#    #+#             */
/*   Updated: 2022/12/14 19:48:13 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

int main(void)
{
	typedef ft::conditional<true, int, double>::type Type1;
	typedef ft::conditional<false, int, double>::type Type2;
	typedef ft::conditional<sizeof(int) >= sizeof(double), int, double>::type Type3;
 
	std::cout << typeid(Type1).name() << '\n';
	std::cout << typeid(Type2).name() << '\n';
	std::cout << typeid(Type3).name() << '\n';
	
	return 0;
}
