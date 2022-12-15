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



} /* namespace ft end */

#endif /* UTILS_HPP */
