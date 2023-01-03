/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messy_vector_test.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 12:02:48 by mclam             #+#    #+#             */
/*   Updated: 2022/12/04 12:02:48 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "vector.hpp"

# define START			0			/* Start key to be stored */
# define END			7			/* End key to be stored */
# define Y				3
# define X				2

template< typename Container >
void fill_container(Container& c) {
	for (int i = START; i <= END; ++i) {
		c.push_back(10 * i + 100 * i + i);
	}
}

template< typename Container >
void print_container(Container& c) {
	typename Container::const_iterator it;
	std::cout << "arr: ";
	for (it = c.cbegin(); it != c.cend(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << "\nsize = " << c.size() << ", capacity = " << c.capacity() << std::endl;
}

typedef int								T;
typedef std::vector<T>::iterator		iterator_std;
typedef std::vector<T>::const_iterator	const_iterator_std;
typedef ft::vector<T>::iterator			iterator_ft;
typedef ft::vector<T>::const_iterator	const_iterator_ft;
typedef ft::vector<T>::size_type		size_type;

int	main()
{
	{
		std::vector<T> v;
		ft::vector<T> vv;
		//	fill_container(v);
		//	fill_container(vv);
		//
		//	print_container(v);
		//	print_container(vv);
		//	std::cout << std::endl;
		//
		//	std::cout << "at(3) = " << v.at(3) << std::endl;
		//	std::cout << "at(3) = " << vv.at(3) << std::endl;
		//	std::cout << std::endl;
		//
		//	std::cout << "[4] = " << v[4] << std::endl;
		//	std::cout << "[4] = " << vv[4] << std::endl;
		//	std::cout << std::endl;
		//
		//	std::cout << "front() = " << v.front() << std::endl;
		//	std::cout << "front() = " << vv.front() << std::endl;
		//	std::cout << std::endl;
		//
		//	std::cout << "back() = " << v.back() << std::endl;
		//	std::cout << "back() = " << vv.back() << std::endl;
		//	std::cout << std::endl;
		//
		//	std::cout << "*data() = " << *v.data() << std::endl;
		//	std::cout << "*data() = " << *vv.data() << std::endl;
		//	std::cout << std::endl;
		//
		//	std::cout << std::boolalpha << "empty() = " << v.empty() << std::endl;
		//	std::cout << std::boolalpha << "empty() = " << vv.empty() << std::endl;
		//	v.clear(); vv.clear();
		//	std::cout << std::boolalpha << "after clear() empty() = " << v.empty() << std::endl;
		//	std::cout << std::boolalpha << "after clear() empty() = " << vv.empty() << std::endl;
		//	print_container(v);
		//	print_container(vv);
		//	std::cout << std::endl;
		//
		//	std::cout << "after push_back(11011)" << std::endl;
		//	v.push_back(11011);
		//	vv.push_back(11011);
		//	print_container(v);
		//	print_container(vv);
		//	std::cout << std::endl;
	}
	{
		std::vector<T> v1;
		ft::vector<T> vv1;
		fill_container(v1);
		fill_container(vv1);

		
		
//		std::vector<T>	v(v1.begin(), v1.end());
//		ft::vector<T>	vv(vv1.begin(), vv1.end());
//
		std::vector<T>	v;
		ft::vector<T>	vv;
		
//		v.resize(5);
//		vv.resize(5);
		
		v.swap(v1);
		vv.swap(vv1);

		print_container(v);
		print_container(vv);
		std::cout << std::endl;

		print_container(v1);
		print_container(vv1);
		std::cout << std::endl;


		
//		fill_container(v);
//		fill_container(vv);
//		print_container(v);
//		print_container(vv);
//		std::cout << std::endl;
//
//		size_type x = X;
//		size_type y = Y;
//		iterator_std	it_std = v.begin() += x;
//		it_std = v.insert(it_std, y, 10000001);
//		print_container(v);
//		iterator_ft		it_ft = vv.begin() += x;
//		it_ft = vv.insert(it_ft, y, 10000001);
//		print_container(vv);
//		std::cout << std::endl;
//
//		std::vector<T> v1;
//		ft::vector<T> vv1;
//		fill_container(v1);
//		fill_container(vv1);
//
//		iterator_std	it_std1 = v1.begin(); it_std1 += y;
//		iterator_std	it_std2 = it_std1; it_std2 += y;
//		it_std	= v.insert(it_std, it_std1, it_std2);
//		print_container(v);
//
//		iterator_ft	it_ft1 = vv1.begin(); it_ft1 += y;
//		iterator_ft	it_ft2 = it_ft1; it_ft2 += y;
//		it_ft = vv.insert(it_ft, it_ft1, it_ft2);
//		print_container(vv);
//		std::cout << std::endl;
//
//		it_std1 = v.begin(); it_std1 += y;
//		it_std	= v.erase(it_std1);
//		print_container(v);
//
//		it_ft1 = vv.begin(); it_ft1 += y;
//		it_ft	= vv.erase(it_ft1);
//		print_container(vv);
//		std::cout << std::endl;
	}
	{
//		std::vector<T> v;
//		ft::vector<T> vv;
//		fill_container(v);
//		fill_container(vv);
//		print_container(v);
//		print_container(vv);
//		std::cout << std::endl;
//
//		iterator_std it_std1 = v.begin(); it_std1 += 3;
//		iterator_std it_std2 = v.end(); it_std2 -= 3;
//		std:: cout << *v.erase(it_std2) << std::endl;
//		print_container(v);
//
//		iterator_ft it_ft1 = vv.begin(); it_ft1 += 3;
//		iterator_ft it_ft2 = vv.end(); it_ft2 -= 3;
//		std::cout << *vv.erase(it_ft2) << std::endl;
//		print_container(vv);
//		std::cout << std::endl;
//
//		v.resize( 4 );
//		print_container(v);
//
//		vv.resize( 4 );
//		print_container(vv);
//		std::cout << std::endl;
//
//		ft::vector<T>	vvv;
//		fill_container(vvv);
//		vvv.swap(vv);
//		print_container(vvv);
//		std::cout << std::endl;
//
//		vvv = vv;
//		print_container(vvv);
//		vv.assign(31, 11);
//		print_container(vv);
//		std::cout << std::endl;
	}

	std::cout << "Hello, World!\n";
	return 0;
}
