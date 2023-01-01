/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:45:58 by mclam             #+#    #+#             */
/*   Updated: 2022/12/14 19:45:58 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

# include <iostream>

namespace ft {

/* Implementation std::conditional_t */

template< bool B, typename T, typename F >
struct conditional { using type = T; };

template< typename T, typename F >
struct conditional< false, T, F > { using type = F; };

template< bool B, class T, class F >
using conditional_t = typename conditional<B,T,F>::type;

/* Implementation std::conditional_t end */

/* Implementation std::is_same */

template< typename U, typename V >
struct is_same {
	static const bool value = false;
};

template< typename U >
struct is_same< U, U > {
	static const bool value = true;
};

template< typename U, typename V >
using is_same_v = typename is_same<U,V>::value;

/* Implementation std::is_same  end */

/* Implementation remove_const */

template <typename T>
struct remove_const {
	using type = T;
};

template <typename T>
struct remove_const <const T> {
	using type = T;
};

template< typename T >
using remove_const_t = typename remove_const<T>::type;

/* Implementation remove_const end */

/* Implementation nullptr end */

static class nullptr_t {
public:
	template<class T>
	operator T*() const { return (0); }
	
	template<class C, class T>
	operator T C::*() const { return (0); }

	template<class T>
	T operator->() const { return (0); }

private:
		void operator&() const;
		
} u_nullptr = {};

/* Implementation nullptr  end */

/* Implementation enable_if */

template<bool B, class T = void>
	struct enable_if {};
	
template<class T>
	struct enable_if<true, T>{ using type = T; };

template<bool B, class T = void>
using	enable_if_t = typename enable_if<B, T>::type;

/* Implementation enable_if end */

/* Implementation lexicographical_compare */

template< class InputIt1, class InputIt2 >
bool lexicographical_compare( InputIt1 first1, InputIt1 last1,
							 InputIt2 first2, InputIt2 last2 ) {
	for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2)
	{
		if (*first1 < *first2)
			return true;
		if (*first2 < *first1)
			return false;
	}
	return (first1 == last1) && (first2 != last2);
}

template< class InputIt1, class InputIt2, class Compare >
bool lexicographical_compare( InputIt1 first1, InputIt1 last1,
							 InputIt2 first2, InputIt2 last2, Compare comp ) {
	for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2)
	{
		if (comp(*first1, *first2))
			return true;
		if (comp(*first2, *first1))
			return false;
	}
	return (first1 == last1) && (first2 != last2);
}

/* Implementation lexicographical_compare end */

/* Implementation equal */

template< class InputIt1, class InputIt2 >
bool equal( InputIt1 first1, InputIt1 last1,
		   InputIt2 first2 ) {
	for (; first1 != last1; ++first1, ++first2) {
		if (!(*first1 == *first2)) {
			return false;
		}
	}
	return true;
}

template< class InputIt1,
		  class InputIt2,
		  class BinaryPredicate >
bool equal( InputIt1 first1,
			InputIt1 last1,
			InputIt2 first2,
			BinaryPredicate p ) {
	for (; first1 != last1; ++first1, ++first2) {
		if (!p(*first1, *first2)) {
			return false;
		}
	}
	return true;
}

/* Implementation equal end */

/* Implementation is_integral */

template <typename>
struct is_integral_base {

	static const bool	value = false;
};

template <>
struct is_integral_base<bool> {

	static const bool	value = true;
};

template <>
struct is_integral_base<char> {

	static const bool	value = true;
};

template <>
struct is_integral_base<char16_t> {

	static const bool	value = true;
};

template <>
struct is_integral_base<char32_t> {

	static const bool	value = true;
};

template <>
struct is_integral_base<wchar_t> {

	static const bool	value = true;
};

template <>
struct is_integral_base<signed char> {

	static const bool	value = true;
};

template <>
struct is_integral_base<short int> {

	static const bool	value = true;
};

template <>
struct is_integral_base<int> {

	static const bool	value = true;
};

template <>
struct is_integral_base<long int> {

	static const bool	value = true;
};

template <>
struct is_integral_base<long long int> {

	static const bool	value = true;
};

template <>
struct is_integral_base<unsigned char> {

	static const bool	value = true;
};

template <>
struct is_integral_base<unsigned short int> {

	static const bool	value = true;
};

template <>
struct is_integral_base<unsigned int> {

	static const bool	value = true;
};

template <>
struct is_integral_base<unsigned long int> {

	static const bool	value = true;
};

template <>
struct is_integral_base<unsigned long long int> {

	static const bool	value = true;
};

template < typename T>
struct is_integral : public is_integral_base<typename remove_const<T>::type> {};


/* Implementation is_integral end */

size_t	upDegree2(size_t num) {
	size_t i = 2;
	while (i < num)
		i *= 2;
	return (i);
}

} /* namespace ft end */

#endif /* UTILS_HPP */
