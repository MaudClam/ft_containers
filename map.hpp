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
# include "utils.hpp"//ghj
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
	typedef ft::RBTree< key_type, mapped_type >		tree_type;
	typedef typename tree_type::node_type			node_type;
	typedef node_type*								node_pointer;
	typedef node_type&								node_reference;
	typedef ft::iterator<
			ft::bidirectional_iterator_tag,
			node_type >								iterator_type;

private:
	/* Member objects */
	tree_type										tree;
	
public:

	/* Constructors & destructors */
	
	map() {}
	
	~map() {}

	/* Iterators */
		
	class iterator : public iterator_type {
	private:
		node_pointer		ptr;
	public:

		iterator(node_pointer node) : ptr(node) {}
		
		iterator() : ptr(NULL) {}

		iterator(const iterator& other) {
			if (ptr != other.ptr)
				this->ptr = other.ptr;
		}
		
		iterator& operator=( const iterator& other ) {
			if (ptr != other.ptr)
				this->ptr = other.ptr;
			return ( *this );
		}
				
		~iterator() {}

		node_reference operator*() const { return *ptr; }
		
		node_pointer operator->() const { return ptr; }

		node_pointer operator++(void) {
			if (ptr != NULL) {
				if (ptr->right != NULL) {
					ptr = ptr->right;
					while (ptr->left != NULL)
						ptr = ptr->left;
					return (ptr);
				}
				while (ptr->parent != NULL) {
					if (ptr == ptr->parent->left)
						return (ptr = ptr->parent);
					ptr = ptr->parent;
				}
			}
			return (NULL);
		}

		node_pointer operator++(int) {
			node_pointer tmp = ptr;
			++(*this);
			return ( tmp );
		}
		
		node_pointer operator--(void) {
			if (ptr != NULL) {
				if (ptr->left != NULL) {
					ptr = ptr->left;
					while (ptr->right != NULL)
						ptr = ptr->right;
					return (ptr);
				}
				while (ptr->parent != NULL) {
					if (ptr == ptr->parent->right)
						return (ptr->parent);
					ptr = ptr->parent;
				}
			}
			return (NULL);
		}

		node_pointer operator--(int) {
			node_pointer tmp = ptr;
			--(*this);
			return ( tmp );
		}
		
	}; /* class iterator_node end */

	iterator begin() {
		return tree.findMin();
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
