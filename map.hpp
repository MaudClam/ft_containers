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

//private:
	/* Member objects */
	
	/* Iterators */
	
	class value_compare;
	
	class iterator : public ft::iterator<ft::bidirectional_iterator_tag, value_type> {
	private:
		pointer									ptr;
		ft::RBTree< iterator, value_compare >*	tree;
	public:
		typedef pointer		iterator_type;
		friend ft::map< Key, T, Compare, Allocator >;
		
		iterator() : tree(NULL) {}
		iterator(pointer ptr) : ptr(ptr) {}
		iterator(pointer ptr, ft::RBTree< iterator, value_compare >* tree)
		:
			ptr(ptr),
			tree(tree)
		{}
		iterator(const iterator& other) : ptr(other.ptr), tree(other.tree) {}
		iterator& operator=(const iterator& other) {
//			if ( *this != other )
			this->ptr = other.ptr;
			this->tree = other.tree;
			return ( *this ) ;
		}
		~iterator() {}

		reference operator++(void) const {
			return tree->findNextNode(tree->root)->value;
		}
		reference operator++(int) const {
			return tree->findNextNode(tree->root)->value;
		}
		reference operator*() const { return *ptr; }
		pointer operator->() const { return ptr; }
		
	};

	class value_compare {
	private:
		key_compare k_compare;
	public:
		value_compare() {}
		~value_compare() {}
		bool operator()(iterator x, iterator y)  {
			return ( k_compare(x->first, y->first) ); }
	};


public:
	ft::RBTree< iterator, value_compare >	tree;
	allocator_type							allocator;
	
//public:
	/* Constructors & destructors */
	
	iterator begin() {
		return tree.findMin()->value;
	}
	
	map() {}
		
	~map() {}
	
	 

	/* Modifiers */
	
	/* Element access */

//	mapped_type& operator[](const key_type& key) {
//		mapped_type v;
//		value_type p1(ft::make_pair(key, v));
//		value_type p2(tree.findNode(&p1)->value);
//		return p2.second;
//	}
	
	void insert(const key_type& key, mapped_type t) {
//		pointer p = allocator.allocate(1);
//		allocator.construct(p, ft::make_pair(key, t));
//		iterator it(p);
//		tree.insertNode(it);
		
		iterator it(allocator.allocate(1));
		allocator.construct(it.ptr, ft::make_pair(key, t));
		tree.insertNode(it);
	}
	
	size_type size() { return tree.get_size() ; }
	
	
}; /* class map end */

template<typename T1, typename T2>
std::ostream& operator<<(std::ostream& o, typename ft::map<T1,T2>::iterator& it) {
	o << it->first << std::endl;//(it-> == RED ? "r" : "B");
	return o;
}



} /* namespace ft end */

#endif /* MAP_HPP end */
