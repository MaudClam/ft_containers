/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:45:58 by mclam             #+#    #+#             */
/*   Updated: 2022/12/14 19:45:58 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

# include <iostream>

namespace ft {

/* Implementation std::conditional_t */

template< bool B, typename T, typename F >
struct conditional { using type = T; };

template< typename T, typename F >
struct conditional< false, T, F > { using type = F; };

template< bool B, class T, class F >
using conditional_t = typename conditional<B,T,F>::type;

/* Implementation std::conditional_t end */

/* Implementation std::is_same */

template< typename U, typename V >
struct is_same {
	static const bool value = false;
};

template< typename U >
struct is_same< U, U > {
	static const bool value = true;
};

template< typename U, typename V >
using is_same_v = typename is_same<U,V>::value;

template <typename T>
struct remove_const {
	using type = T;
};

template <typename T>
struct remove_const <const T> {
	using type = T;
};

template< typename T >
using remove_const_t = typename remove_const<T>::type;

/* Implementation std::is_same  end */

} /* namespace ft end */

#endif /* UTILS_HPP */
