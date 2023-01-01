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
	typedef std::random_access_iterator_tag		iterator_category;
};

template< class T >
struct iterator_traits<const T*> {
	typedef	typename std::ptrdiff_t				difference_type;
	typedef	const T								value_type;
	typedef	const T*							pointer;
	typedef	const T&							reference;
	typedef std::random_access_iterator_tag		iterator_category;
};

template< class Iter >
class reverse_iterator {

	/* Member objects */

protected:
	Iter current = Iter();

public:

	/* Member types */

	typedef Iter													iterator_type;
	typedef typename ft::iterator_traits<Iter>::iterator_category	iterator_category;
	typedef typename ft::iterator_traits<Iter>::value_type			value_type;
	typedef typename ft::iterator_traits<Iter>::difference_type		difference_type;
	typedef typename ft::iterator_traits<Iter>::pointer				pointer;
	typedef typename ft::iterator_traits<Iter>::reference			reference;

	/* Member functions */
	
	reverse_iterator() {}
	
	explicit reverse_iterator( iterator_type x ) : current(x) {}
	
	template< class U >
	reverse_iterator( const reverse_iterator<U>& other ) : current(other.base()) {}
	
	template< class U >
	reverse_iterator& operator=( const reverse_iterator<U>& other ) {
		current = other.base();
	}
	reference operator*() const { Iter tmp = current; return *(--tmp); }
	
	pointer operator->() const { Iter tmp = current; return &(*(--tmp)); }
	
	reference operator[]( difference_type n ) const {//random_access
		return(base()[-n-1]);
	}

	reverse_iterator& operator++(void) {
		--current;
		return (*this);
	}

	reverse_iterator& operator--(void) {
		++current;
		return (*this);
	}

	reverse_iterator& operator++(int) {
		current--;
		return (*this);
	}

	reverse_iterator& operator--(int) {
		current++;
		return (*this);
	}
	
	reverse_iterator operator+( difference_type n ) const {
		return (reverse_iterator(base()-n));
	}
	
	reverse_iterator operator-( difference_type n ) const {
		return (reverse_iterator(base()+n));
	}
	
	reverse_iterator& operator+=( difference_type n ) {
		current -= n;
		return (*this);
	}

	reverse_iterator& operator-=( difference_type n ) {
		current += n;
		return (*this);
	}

	Iter base() const { return current; }
	
};

/* Non-member functions */

template< class Iterator1, class Iterator2 >
bool operator==( const ft::reverse_iterator<Iterator1>& lhs,
				const ft::reverse_iterator<Iterator2>& rhs ) {
	return ( lhs.base() == rhs.base() ); }

template< class Iterator1, class Iterator2 >
bool operator!=( const ft::reverse_iterator<Iterator1>& lhs,
				const ft::reverse_iterator<Iterator2>& rhs ) {
	return ( lhs.base() != rhs.base() );
}

template< class Iterator1, class Iterator2 >
bool operator<( const ft::reverse_iterator<Iterator1>& lhs,
				const ft::reverse_iterator<Iterator2>& rhs ) {
	return ( lhs.base() > rhs.base() );
}

template< class Iterator1, class Iterator2 >
bool operator<=( const ft::reverse_iterator<Iterator1>& lhs,
				const ft::reverse_iterator<Iterator2>& rhs ) {
	return ( lhs.base() >= rhs.base() );
}

template< class Iterator1, class Iterator2 >
bool operator>( const ft::reverse_iterator<Iterator1>& lhs,
				const ft::reverse_iterator<Iterator2>& rhs ) {
	return ( lhs.base() < rhs.base() );
}

template< class Iterator1, class Iterator2 >
bool operator>=( const ft::reverse_iterator<Iterator1>& lhs,
				const ft::reverse_iterator<Iterator2>& rhs ) {
	return ( lhs.base() <= rhs.base() );
}

template< class Iter >
reverse_iterator<Iter>
	operator+( typename reverse_iterator<Iter>::difference_type n,
			  const reverse_iterator<Iter>& it ) {
		return ( reverse_iterator<Iter>(it.base() - n) );
	}

template< class Iterator1, class Iterator2 >
typename reverse_iterator<Iterator1>::difference_type
	operator-( const reverse_iterator<Iterator1>& lhs,
			  const reverse_iterator<Iterator2>& rhs ) {
		return( rhs.base() - lhs.base() );
	}

/* Implementation distance */

template<class It>
typename ft::iterator_traits<It>::difference_type
	do_distance(It first, It last, ft::input_iterator_tag)
{
	typename ft::iterator_traits<It>::difference_type result = 0;
	while (first != last) {
		++first;
		++result;
	}
	return result;
}
 
template<class It>
typename ft::iterator_traits<It>::difference_type
	do_distance(It first, It last, ft::random_access_iterator_tag)
{
	return last - first;
}
  
template<class It>
typename ft::iterator_traits<It>::difference_type
	distance(It first, It last)
{
	return ft::do_distance(first, last,
						typename ft::iterator_traits<It>::iterator_category());
}

/* Implementation distance end */


} /* namespace ft end */

#endif /* ITERATOR_HPP */
