/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:16:15 by mclam             #+#    #+#             */
/*   Updated: 2022/12/09 13:16:15 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

# include <iostream>

namespace ft {

/* Implementation std::pair */

template<
class T1,
class T2
> struct pair {
	
	/* Member types */
	typedef T1	first_type;
	typedef T2	second_type;
	
	/* Member objects */
	first_type	first;
	second_type	second;
	
	/* Member functions */
		
				pair() : first(), second() {}
				pair( const T1& x, const T2& y ) : first(x), second(y) {}
	template< class U1, class U2 >
				pair( const pair<U1,U2>& p ) : first(p.first), second(p.second) {}
	template< class U1, class U2 >
				pair& operator=( const pair<U1, U2>& other )  {
			this->first = other.first;
			this->second = other.second;
		return (*this);
	}
}; /* struct pair end */

/* Non-member functions */
template <class T1, class T2>
pair<T1,T2>		make_pair(T1 x, T2 y) {
	return (pair<T1,T2>(x, y));
}
template< class T1, class T2 >
bool			operator==( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs ) {
	return ( lhs.first == rhs.first && lhs.second == rhs.second );
}
template< class T1, class T2 >
bool 			operator!=( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs ) {
	return ( !(rhs == lhs) );
}
template< class T1, class T2 >
bool			operator<( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs ) {
	return ( (lhs.first < rhs.first) || ((lhs.first == rhs.first) && (lhs.second < rhs.second)) );
}
template< class T1, class T2 >
bool			operator<=( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs ) {
	return (!(rhs < lhs));
}
template< class T1, class T2 >
bool			operator>( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs ) {
	return ( rhs < lhs );
}
template< class T1, class T2 >
bool			operator>=( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs ) {
	return ( !(lhs < rhs) );
}

} /* namespace ft end */

#endif /* PAIR_HPP end */
