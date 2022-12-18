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
	typedef Key										key_type;
	typedef T										mapped_type;
	typedef ft::pair<const Key, T>					value_type;
	typedef std::ptrdiff_t							difference_type;
	typedef Compare									key_compare;
	typedef value_type&								reference;
	typedef const value_type&						const_reference;
	typedef Allocator								allocator_type;
	typedef std::size_t								size_type;

private:
	/* Member objects */
	
	typedef ft::RBTree< key_type, mapped_type >		tree_type;
	tree_type										tree;
	
public:

	/* Constructors & destructors */
	
	map() {}
	
	~map() {}

	/* Iterators */
	typedef typename tree_type::iterator			iterator;

	iterator begin() {
		return iterator(tree.begin());
	}

//	iterator_type begin() {
//		iterator_type it;
//	return tree.begin();
//	}
	
	/* Modifiers */
	
	void insert( const key_type& key, const mapped_type& t ) {
		tree.insertNode(key, t);
	}

	/* Element access */
	
	size_type size() { return tree.get_size() ; }
	
	
}; /* class map end */

} /* namespace ft end */

#endif /* MAP_HPP end */
