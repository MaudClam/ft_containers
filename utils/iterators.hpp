/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 20:18:18 by mclam             #+#    #+#             */
/*   Updated: 2023/01/08 18:21:50 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

# include <iostream>
# include "util.hpp"

namespace ft {

/* Class iterator */

template<
	class Category,
	class T,
	bool  isConst = false,
	class Distance = std::ptrdiff_t,
	class Pointer = typename ft::conditional<isConst,const T,T >::type*,
	class Reference = typename ft::conditional<isConst,const T, T >::type&
> struct iterator {
	/* Member types */
	typedef typename ft::conditional<
		isConst, const T, T >::type				value_type;
	typedef Category							iterator_category;
	typedef Distance							difference_type;
	typedef Pointer								pointer;
	typedef Reference							reference;
}; /* Class iterator end */

/* Implementation iterator_traits */

struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : public input_iterator_tag {};
struct bidirectional_iterator_tag : public forward_iterator_tag {};
struct random_access_iterator_tag : public bidirectional_iterator_tag {};

template< class Iter >
struct iterator_traits {
	/* Member types */
	typedef typename Iter::difference_type		difference_type;
	typedef	typename Iter::value_type			value_type;
	typedef	typename Iter::pointer				pointer;
	typedef	typename Iter::reference			reference;
	typedef	typename Iter::iterator_category	iterator_category;
};

template< class T >
struct iterator_traits<T*> {
	typedef	typename std::ptrdiff_t				difference_type;
	typedef	T									value_type;
	typedef	T*									pointer;
	typedef	T&									reference;
	typedef ft::random_access_iterator_tag		iterator_category;
};

template< class T >
struct iterator_traits<const T*> {
	typedef	typename std::ptrdiff_t				difference_type;
	typedef	const T								value_type;
	typedef	const T*							pointer;
	typedef	const T&							reference;
	typedef ft::random_access_iterator_tag		iterator_category;
};

/* Implementation iterator_traits end */

/* Implementation reverse_iterator */
template< class Iter, bool isConst = false >
class reverse_iterator {

	/* Member objects */
protected:
	Iter current;
public:
	/* Member types */
	typedef Iter													iterator_type;
	typedef typename ft::iterator_traits<Iter>::iterator_category	iterator_category;
	typedef typename ft::iterator_traits<Iter>::value_type			value_type;
	typedef typename ft::iterator_traits<Iter>::difference_type		difference_type;
	typedef typename ft::iterator_traits<Iter>::pointer				pointer;
	typedef typename ft::iterator_traits<Iter>::reference			reference;

	/* Member functions */
						reverse_iterator() : current() {}
	explicit			reverse_iterator( iterator_type x ) : current(x) {}
	template< class U >	reverse_iterator(const reverse_iterator<U>& other ) : current(other.base()) {}
	template< class U >
	reverse_iterator&	operator=( const reverse_iterator<U>& other ) {
		current = other.base();
		return (*this);
	}
	typename ft::conditional<isConst, const reference, reference>::type
						operator*() const {
		Iter tmp = current;
		return ( (typename ft::conditional<isConst, const reference, reference>::type)*(--tmp) );
	}
	typename ft::conditional<isConst, const pointer, pointer>::type
						operator->() const {
		Iter tmp = current;
		return (typename ft::conditional<isConst, const pointer, pointer>::type)&(*(--tmp));
	}
	
	reference			operator[]( difference_type n ) const {//random_access
		return(base()[-n-1]);
	}
	reverse_iterator& 	operator++(void) {
		--current;
		return (*this);
	}
	reverse_iterator& 	operator--(void) {
		++current;
		return (*this);
	}
	reverse_iterator 	operator++(int) {
		reverse_iterator	tmp = *this;
		++(*this);
		return (tmp);
	}
	reverse_iterator	operator--(int) {
		reverse_iterator	tmp = *this;
		--(*this);
		return (tmp);
	}
	reverse_iterator	operator+( difference_type n ) const {
		return (reverse_iterator(base()-n));
	}
	reverse_iterator	operator-( difference_type n ) const {
		return (reverse_iterator(base()+n));
	}
	reverse_iterator&	operator+=( difference_type n ) {
		current -= n;
		return (*this);
	}
	reverse_iterator&	operator-=( difference_type n ) {
		current += n;
		return (*this);
	}
	Iter				base() const { return current; }
};
/* Non-member functions for reverse_iterator */
template< class Iterator1, class Iterator2 >
bool	operator==(const ft::reverse_iterator<Iterator1>& lhs,
				   const ft::reverse_iterator<Iterator2>& rhs ) {
	return ( lhs.base() == rhs.base() );
}
template< class Iterator1, class Iterator2 >
bool	operator!=(const ft::reverse_iterator<Iterator1>& lhs,
				   const ft::reverse_iterator<Iterator2>& rhs ) {
		return ( lhs.base() != rhs.base() );
}
template< class Iterator1, class Iterator2 >
bool	operator<(const ft::reverse_iterator<Iterator1>& lhs,
				  const ft::reverse_iterator<Iterator2>& rhs ) {
	return ( lhs.base() > rhs.base() );
}
template< class Iterator1, class Iterator2 >
bool	operator<=(const ft::reverse_iterator<Iterator1>& lhs,
				   const ft::reverse_iterator<Iterator2>& rhs ) {
	return ( lhs.base() >= rhs.base() );
}
template< class Iterator1, class Iterator2 >
bool	operator>(const ft::reverse_iterator<Iterator1>& lhs,
				  const ft::reverse_iterator<Iterator2>& rhs ) {
	return ( lhs.base() < rhs.base() );
}
template< class Iterator1, class Iterator2 >
bool	operator>=(const ft::reverse_iterator<Iterator1>& lhs,
				   const ft::reverse_iterator<Iterator2>& rhs ) {
	return ( lhs.base() <= rhs.base() );
}
template< class Iter >
reverse_iterator<Iter>
		operator+(typename reverse_iterator<Iter>::difference_type n,
				  const reverse_iterator<Iter>& it ) {
		return ( reverse_iterator<Iter>(it.base() - n) );
	}
template< class Iter >
reverse_iterator<Iter>
		operator-(const reverse_iterator<Iter>& it,
				  typename reverse_iterator<Iter>::difference_type n) {
		return ( reverse_iterator<Iter>(it.base() + n) );
	}
template< class Iterator1, class Iterator2 >
typename reverse_iterator<Iterator1>::difference_type
		operator-(const reverse_iterator<Iterator1>& lhs,
				  const reverse_iterator<Iterator2>& rhs ) {
		return( rhs.base() - lhs.base() );
	}
/* Implementation reverse_iterator end */

/* Class rbtree_iterator */
template<
typename node_type,
typename value_type,
bool isConst = false >
class rbtree_iterator : public ft::iterator<ft::bidirectional_iterator_tag, value_type> {
public:
	typedef node_type*																				node_pointer;
	typedef rbtree_iterator<node_type, typename ft::remove_const<value_type>::type, false>			non_const_iterator;
	typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::pointer				pointer;
	typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::reference			reference;
	typedef const typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::value_type*	const_pointer;
	typedef const typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::value_type&	const_reference;
protected:
	node_pointer			ptr;
	node_pointer			max;
public:
							rbtree_iterator() : ptr(NULL), max(NULL) {}
							rbtree_iterator(node_pointer node, node_pointer maxNode = NULL) : ptr(node), max(maxNode) {
								if (max == NULL) max = findMax(ptr);
							}
							rbtree_iterator(const rbtree_iterator& other) : ptr(other.ptr), max(other.max) {}
							rbtree_iterator(non_const_iterator other) : ptr(other.get_ptr()), max(other.get_max()) {}
							~rbtree_iterator() {}
	node_pointer			get_ptr() const { return (this->ptr); }
	node_pointer			get_max() const { return (this->max); }
	node_pointer			findMax(node_pointer node) const {
		while (node && node->parent)
			node = node->parent;
		while (node && node->right)
			node = node->right;
		return (node);
	}
	rbtree_iterator&		operator=(const rbtree_iterator& other) {
		this->ptr = other.ptr;
		this->max = other.max;
		return ( *this );
	}
	typename ft::conditional<isConst, const_reference, reference>::type
							operator*() const {
								return (typename ft::conditional<isConst, const reference, reference>::type)*ptr->value;
							}
	typename ft::conditional<isConst, const_pointer, pointer>::type
							operator->() const {
								return (typename ft::conditional<isConst, const pointer, pointer>::type)ptr->value;
							}
	rbtree_iterator&		operator++(void) {
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
	rbtree_iterator			operator++(int) {
		rbtree_iterator tmp = *this;
		++(*this);
		return ( tmp );
	}
	rbtree_iterator&		operator--(void) {
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
	rbtree_iterator			operator--(int) {
		rbtree_iterator tmp = *this;
		--(*this);
		return ( tmp );
	}
	friend bool				operator==(const rbtree_iterator& lhs, const rbtree_iterator& rhs) {
		return( lhs.ptr == rhs.ptr );
	}
	friend bool				operator!=(const rbtree_iterator& lhs, const rbtree_iterator& rhs)  {
		return( !(lhs == rhs) );
	}
}; /* class rbtree_iterator end */

/* Implementation distance */

namespace detail {
template<class It>
typename ft::iterator_traits<It>::difference_type
		do_distance(It first, It last, ft::input_iterator_tag) {
	typename ft::iterator_traits<It>::difference_type result = 0;
	while (first != last) {
		++first;
		++result;
	}
	return result;
}
template<class It>
typename ft::iterator_traits<It>::difference_type
		do_distance(It first, It last, ft::forward_iterator_tag) {
	typename ft::iterator_traits<It>::difference_type result = 0;
	while (first != last) {
		++first;
		++result;
	}
	return result;
}
template<class It>
typename ft::iterator_traits<It>::difference_type
		do_distance(It first, It last, ft::random_access_iterator_tag) {
	return last - first;
}
 } /* namespace detail end */

template<class It>
typename ft::iterator_traits<It>::difference_type
		distance(It first, It last) {
	return detail::do_distance(first, last,
						typename ft::iterator_traits<It>::iterator_category());
}

/* Implementation distance end */

} /* namespace ft end */

#endif /* ITERATOR_HPP */
