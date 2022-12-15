/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:18:25 by mclam             #+#    #+#             */
/*   Updated: 2022/12/14 18:18:25 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include "RBTree.hpp"
# include "iterator.hpp"
# include "pair.hpp"

namespace ft {

template<
	class Key,
	class T,
	class Compare = std::less<Key>,
	class Allocator = std::allocator<ft::pair<const Key, T> >
> class map {
public:
	/* Member types */
	typedef Key													key_type;
	typedef T													mapped_type;
	typedef ft::pair<const Key, T>								value_type;
	typedef typename Allocator::size_type						size_type;
	typedef std::ptrdiff_t										difference_type;
	typedef Compare												key_compare;
	typedef Allocator											allocator_type;
	typedef value_type&											reference;
	typedef const value_type&									const_reference;
	typedef typename Allocator::pointer							pointer;
	typedef typename Allocator::const_pointer					const_pointer;
//	typedef 	iterator;
//	typedef 	const_iterator;
//	typedef 	reverse_iterator;
//	typedef 	const_reverse_iterator;

private:
	/* Member objects */
	class value_compare {
	protected:
		key_compare k_compare;
	public:
		value_compare() {}
		~value_compare() {}
		bool operator()(const_pointer x, const_pointer y) const {
			return k_compare(x->first, y->first); }
	};

	value_compare							v_compare;
	ft::RBTree< pointer, value_compare >	tree( value_compare& v_compare );
	allocator_type							allocator;
	
public:
	/* Constructors & destructors */
	
	map() {}
		
	~map() {}

	/* Modifiers */
	
	void insert(key_type& key, mapped_type t) {
		pointer p = allocator.allocate(1);
		allocator.construct(p, ft::make_pair(key, t));
		tree().insertNode(p);
	}
	
	size_type size() { return tree().size.size ; }
	
	
}; /* class map end */

} /* namespace ft end */

#endif /* MAP_HPP end */
