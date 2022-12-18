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
# include "utils.hpp"
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
	typedef std::ptrdiff_t										difference_type;
	typedef Compare												key_compare;
	typedef value_type&											reference;
	typedef const value_type&									const_reference;
	typedef Allocator											allocator_type;
	typedef typename allocator_type::size_type					size_type;
	typedef typename allocator_type::pointer					pointer;
	typedef typename allocator_type::const_pointer				const_pointer;
//	typedef 	iterator;
//	typedef 	const_iterator;
//	typedef 	reverse_iterator;
//	typedef 	const_reverse_iterator;

private:
	/* Member objects */
	
	class value_compare {
	private:
		key_compare k_compare;
	public:
		value_compare() {}
		~value_compare() {}
		bool operator()(pointer x, pointer y) const {
			return ( k_compare(x->first, y->first) ); }
	};
	
	typedef ft::RBTree< pointer, value_compare >		tree_type;
	tree_type											tree;
	allocator_type										allocator;
	typedef typename tree_type::node_pointer			node_pointer;
	
public:

	/* Constructors & destructors */
	map() {}
	~map() {}

	/* Iterators */
	
	typedef typename tree_type::iterator_type	iterator_type;

	iterator_type begin() {
		iterator_type it;
	return tree.begin();
	}
	


	/* Modifiers */
	
	void insert( const key_type& key, const mapped_type& t ) {
		pointer value = allocator.allocate(1);
		allocator.construct( value, ft::make_pair(key, t) );
		tree.insertNode(value);
	}

	/* Element access */
	
	size_type size() { return tree.get_size() ; }
	
	
}; /* class map end */

} /* namespace ft end */

#endif /* MAP_HPP end */
