/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 12:06:28 by mclam             #+#    #+#             */
/*   Updated: 2022/12/04 12:06:28 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_MAP_HPP
# define ITERATOR_MAP_HPP

# include "iterator.hpp"
# include "util.hpp"

namespace ft {

template<
typename node_type,
typename value_type,
bool isConst = false >
class map_iterator : public ft::iterator<ft::bidirectional_iterator_tag, value_type> {
public:
	typedef node_type*																				node_pointer;
	typedef map_iterator<node_type, value_type, !isConst>											opposite_iterator;
	typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::pointer				pointer;
	typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::reference			reference;
	typedef const typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::value_type*	const_pointer;
	typedef const typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::value_type&	const_reference;
	typedef typename ft::conditional<isConst, opposite_iterator, map_iterator>::type				const_conditional1;
	typedef typename ft::conditional<!isConst, opposite_iterator, map_iterator>::type				const_conditional2;
protected:
	node_pointer			ptr;
	node_pointer			max;
public:
	
							map_iterator() : ptr(NULL), max(NULL) {}
							map_iterator(node_pointer node, node_pointer maxNode = NULL) : ptr(node), max(maxNode) {
								if (max == NULL) max = findMax(ptr);
							}
							map_iterator(const const_conditional1& other) : ptr(other.get_ptr()), max(other.get_max()) {}
							map_iterator(const const_conditional2& other) : ptr(other.get_ptr()), max(other.get_max()) {}
							~map_iterator() {}
	node_pointer			get_ptr() const { return (this->ptr); }
	node_pointer			get_max() const { return (this->max); }
	node_pointer			findMax(node_pointer node) const {
		while (node && node->parent)
			node = node->parent;
		while (node && node->right)
			node = node->right;
		return (node);
	}

	map_iterator&			operator=( const const_conditional1& other ) {
		this->ptr = other.get_ptr();
		this->max = other.get_max();
		return ( *this );
	}
	map_iterator&			operator=( const const_conditional2& other ) {
		this->ptr = other.get_ptr();
		this->max = other.get_max();
			return ( *this );
	}
	typename ft::conditional<isConst, const_reference, reference>::type
							operator*() const { return *ptr->value; }
	typename ft::conditional<isConst, const_pointer, pointer>::type
							operator->() const { return ptr->value; }
	map_iterator&			operator++(void) {
		if (ptr != NULL) {
			max = findMax(ptr);
			if (ptr->right != NULL) {
				ptr = ptr->right;
				while (ptr->left != NULL)
					ptr = ptr->left;
				return (*this);
			}
			while (ptr->parent != NULL) {
				if (ptr == ptr->parent->left) {
					ptr = ptr->parent;
					return (*this);
				}
				ptr = ptr->parent;
			}
			ptr = u_nullptr;
		}
		return (*this);
	}
	map_iterator			operator++(int) {
		map_iterator tmp = *this;
		++(*this);
		return ( tmp );
	}
	map_iterator&			operator--(void) {
		if (ptr == u_nullptr) {
			ptr = max;
			return (*this);
		}
		if (ptr != NULL) {
			max = findMax(ptr);
			if (ptr->left != NULL) {
				ptr = ptr->left;
				while (ptr->right != NULL)
					ptr = ptr->right;
				return (*this);
			}
			while (ptr->parent != NULL) {
				if (ptr == ptr->parent->right) {
					ptr = ptr->parent;
					return (*this);
				}
				ptr = ptr->parent;
			}
			ptr = u_nullptr;
		}
		return (*this);
	}
	map_iterator			operator--(int) {
		map_iterator tmp = *this;
		--(*this);
		return ( tmp );
	}
	friend bool				operator==(const map_iterator& lhs, const map_iterator& rhs)  { return( lhs.ptr == rhs.ptr ); }
	friend bool				operator==(const map_iterator& lhs, const opposite_iterator& rhs)  { return( lhs.ptr == rhs.get_ptr() ); }
	friend bool				operator!=(const map_iterator& lhs, const map_iterator& rhs)  { return( !(lhs == rhs) ); }
	friend bool				operator!=(const map_iterator& lhs, const opposite_iterator& rhs)  { return( !(lhs == rhs) ); }

}; /* class map_iterator end */

} /* namespace ft end */

#endif /* iterator_map_hpp */

