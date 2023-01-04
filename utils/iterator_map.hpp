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
	typedef node_type*										node_pointer;
	typedef map_iterator<node_type, value_type, isConst>	iterator;
	typedef map_iterator<node_type, value_type, !isConst>	opposite_iterator;
protected:
	node_pointer			ptr;
	node_pointer			max;
	friend class map_iterator<node_type, value_type, !isConst>;
public:
	typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::pointer				pointer;
	typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::reference			reference;
	typedef const typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::value_type*	const_pointer;
	typedef const typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::value_type&	const_reference;
	
							map_iterator() : ptr(NULL), max(NULL) {}
							map_iterator(node_pointer node, node_pointer max = NULL) : ptr(node), max(max) {}
							map_iterator(const map_iterator& other) : ptr(other.ptr), max(other.max) {}
							map_iterator(const opposite_iterator& other) : ptr(other.ptr), max(other.max) {}
							~map_iterator() {}
	
	map_iterator&		operator=( const map_iterator& other ) {
		this->ptr = other.ptr;
		this->max = other.max;
		return ( *this );
	}
	map_iterator&		operator=( const opposite_iterator& other ) {
		this->ptr = other.ptr;
		this->max = other.max;
		return ( *this );
	}
	typename ft::conditional<isConst, const_reference, reference>::type
							operator*() const { return *ptr->value; }
	typename ft::conditional<isConst, const_pointer, pointer>::type
							operator->() const { return ptr->value; }
	map_iterator&			operator++(void) {
		if (ptr != NULL) {
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
	bool					operator==(map_iterator other) const { return( ptr == other.ptr ); }
	bool					operator!=(map_iterator other) const { return( !(*this == other) ); }

}; /* class map_iterator end */

} /* namespace ft end */

#endif /* iterator_map_hpp */

