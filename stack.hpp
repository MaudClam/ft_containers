/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 00:07:47 by mclam             #+#    #+#             */
/*   Updated: 2023/01/02 00:07:47 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

# include <iostream>
#include "vector.hpp"

namespace ft {

template<
	class T,
	class Container = ft::vector<T>
> class stack {
public:
	/* Member types */
	typedef Container							container_type;
	typedef typename Container::value_type		value_type;
	typedef typename Container::size_type		size_type;
	typedef typename Container::reference		reference;
	typedef typename Container::const_reference	const_reference;
	
	/* Member functions */
	explicit stack( const Container& cont = Container() ) : c(cont) {}
	~stack() {}
	stack& operator=( const stack& other ) {
		c = other.c;
	}
	
	/* Element access */
	reference top() {
		return (c.back());
	}
	const_reference top() const {
		return (c.back());
	}
	/* Capacity */
	bool empty() const {
		return (c.empty());
	}
	size_type size() const {
		return (c.size());
	}
	/* Modifiers */
	void push( const value_type& value ) {
		c.push_back(value);
	}
	void pop() {
		c.pop_back();
	}
protected:
	/* Member objects */
	Container	c;
};
/* Non-member functions */
template< class T, class Container >
bool operator==( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ) {
	return (lhs == rhs);
}
template< class T, class Container >
bool operator!=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ) {
	return (lhs != rhs);
}
template< class T, class Container >
bool operator<( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ) {
	return (lhs < rhs);
}
template< class T, class Container >
bool operator<=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ) {
	return (lhs <= rhs);
}
template< class T, class Container >
bool operator>( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ) {
	return (lhs > rhs);
}
template< class T, class Container >
bool operator>=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ) {
	return (lhs >= rhs);
}
}

# endif /* stack_hpp end */
