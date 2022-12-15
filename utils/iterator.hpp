/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 20:18:18 by mclam             #+#    #+#             */
/*   Updated: 2022/12/14 20:18:18 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

# include <iostream>
# include "utils.hpp"

namespace ft {

template<
	class Category,
	class T,
	bool  isConst = false,
	class Distance = std::ptrdiff_t,
	class Pointer = ft::conditional_t< isConst, const T, T >*,
	class Reference = ft::conditional_t< isConst, const T, T >&
> struct iterator {
	/* Member types */
	typedef Category									iterator_category;
	typedef ft::conditional_t< isConst, const T, T >	value_type;
	typedef Distance									difference_type;
	typedef Pointer										pointer;
	typedef Reference									reference;
};

struct input_iterator_tag { };
struct output_iterator_tag { };
struct forward_iterator_tag : public input_iterator_tag { };
struct bidirectional_iterator_tag : public forward_iterator_tag { };
struct random_access_iterator_tag : public bidirectional_iterator_tag { };

} /* namespace ft end */

#endif /* ITERATOR_HPP */
