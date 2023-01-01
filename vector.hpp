/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:26:04 by mclam             #+#    #+#             */
/*   Updated: 2022/12/27 15:26:04 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

# include <iostream>
# include "iterator.hpp"
# include "utils.hpp"

namespace ft {

template<
	class T,
	class Allocator = std::allocator<T>
> class vector {
	
public:
	/* 	Member types */
	typedef T										value_type;
	typedef Allocator								allocator_type;
	typedef typename Allocator::size_type			size_type;
	typedef std::ptrdiff_t							difference_type;
	typedef value_type&								reference;
	typedef const value_type&						const_reference;
	typedef typename Allocator::pointer				pointer;
	typedef typename Allocator::const_pointer		const_pointer;
	typedef ft::iterator<
	ft::random_access_iterator_tag,
	value_type
	>												iterator_type;
	
protected:
	/* Member objects */
	size_type				cap;
	size_type				sz;
	allocator_type			alloc;
	value_type*				arr;

public:
	
	/* Member classes */
	template<bool isConst>
	class common_iterator : public iterator_type {
	protected:
		pointer					ptr;
	public:
		common_iterator() : ptr(NULL) {}
		
		common_iterator(pointer ptr) : ptr(ptr) {}
		
		common_iterator(const common_iterator& other) : ptr(other.ptr) {}
		
		~common_iterator() {}
		
		common_iterator&		operator=( const common_iterator& other ) {
			this->ptr = other.ptr;
			return ( *this );
		}
		bool 					operator==(common_iterator other) const { return( ptr == other.ptr ); }
		bool 					operator!=(common_iterator other) const { return( !(*this == other) ); }
		ft::conditional_t<isConst, const_reference, reference>
		operator*() const { return *ptr; }
		ft::conditional_t<isConst, const_pointer, pointer>
		operator->() const { return ptr; }
		common_iterator&		operator++(void) { ++ptr; return (*this); }
		common_iterator			operator++(int) {
			common_iterator tmp = *this;
			++(*this);
			return ( tmp );
		}
		common_iterator&		operator--(void) { --ptr; return (*this); }
		common_iterator			operator--(int) {
			common_iterator tmp = *this;
			--(*this);
			return (tmp);
		}
		common_iterator&		operator+=(const difference_type& n) {
			difference_type m = n;
			if (m >= 0)
				while (m--) ++*this;
			else
				while (m++) --*this;
			return (*this);
		}
		friend common_iterator	operator+(const common_iterator& lhs, const difference_type& n) {
			common_iterator tmp = lhs;
			return(tmp += n);
		}
		friend common_iterator	operator+(const difference_type& n, const common_iterator& rhs) {
			common_iterator tmp = rhs;
			return(tmp += n);
		}
		common_iterator&		operator-=(const difference_type& n) { return (*this += -n); }
		common_iterator			operator-(const difference_type& n) {
			common_iterator tmp = *this;
			return(tmp -= n); }
		friend difference_type	operator-( common_iterator& lhs,  common_iterator& rhs) {
			difference_type n = 0;
			if (lhs == rhs)
				return (0);
			if (lhs < rhs)
				while (lhs != rhs) {++lhs; n++;}
			else
				while (lhs != rhs) {++rhs; n++;}
			return(n);
		}
		ft::conditional_t<isConst, const_reference, reference>
		operator[](size_type n) const { return(*(*this + n)); }
		bool					operator<(common_iterator& other) { return (other.ptr - this->ptr > 0); }
		bool					operator<=(const common_iterator& other) const { return (*this < other || *this == other); }
		bool					operator>(const common_iterator& other) const { return ( !(*this <= other) ); }
		bool					operator>=(const common_iterator& other) const { return ( !(*this < other) ); }
		
	}; /* class common_iterator end */
	
	/* 	Member types */
	typedef common_iterator<false>					iterator;
	typedef common_iterator<true> 					const_iterator;
	typedef ft::pair<iterator, bool>				iterator_bool;
	typedef ft::reverse_iterator<iterator>			reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;
	
	/* Member functions */
	
							vector()
							:
								cap(1),
								sz(0),
								alloc(),
								arr( alloc.allocate(1) )
							{}

	explicit 				vector( const Allocator& alloc )
							:
								cap(1),
								sz(0),
								alloc(alloc),
								arr( alloc.allocate(cap) )
							{}
	
	explicit 				vector(size_type count,
								   const T& value = T(),
								   const Allocator& alloc = Allocator() )
							:
								cap(count),
								sz(count),
								alloc(alloc),
								arr( alloc.allocate(cap) ) {
		size_type	i = 0;
		try {
			for (; i < sz; ++i)
				alloc.construct(arr + i, value);
		} catch (...) {
			for (size_type j = 0; j < i; ++j)
				alloc.destroy(arr + j);
			alloc.deallocate(arr, cap);
			throw;
		}
	}
	
	template<class InputIt>	vector(InputIt first,
								   InputIt last,
								   const Allocator& alloc = Allocator(),
								   typename ft::enable_if<
										!ft::is_integral<InputIt>::value,
										InputIt
										>::type* = 0 )
							:
								cap(1),
								sz(0),
								alloc(alloc),
								arr( alloc.allocate(cap) ) { insert(begin(), first, last); }
	
							vector( const vector& other )
							:
								cap(1),
								sz(0),
								alloc(other.alloc),
								arr( alloc.allocate(cap) ) { *this = other; }
	
							~vector() { killArr(arr, sz, cap); }
	
	vector&					operator=( const vector& other ) {
		size_type	i = 0;
		value_type*	newArr = alloc.allocate(other.cap);
		try {
			for (; i < other.sz; ++i)
				alloc.construct(newArr + i, other.arr[i]);
		} catch (...) {
			for (size_type j = 0; j < i; ++j)
				alloc.destroy(newArr + j);
			alloc.deallocate(newArr, other.cap);
			throw ;
		}
		killArr(arr, sz, cap);
		arr = newArr;
		sz = other.sz;
		cap = other.cap;
		return (*this);
	}
	
	void 					assign( size_type count, const T& value ) {
		value_type*	clone = arrCopying(sz, 0, 0);
		size_type	size = sz;
		size_type	capacity = cap;
		clear();
		try {
			insert(begin(), count, value);
		} catch (...) {
			arr = clone; clone = NULL;
			sz = size;
			cap = capacity;
			throw ;
		}
		killArr(clone, size, capacity); clone = NULL;
	}
	
	template<class InputIt>
	void 					assign( InputIt first, InputIt last ) {
		value_type*	clone = arrCopying(sz, 0, 0);
		size_type	size = sz;
		size_type	capacity = cap;
		clear();
		try {
			insert(begin(), first, last);
		} catch (...) {
			arr = clone; clone = NULL;
			sz = size;
			cap = capacity;
			throw ;
		}
		killArr(clone, size, capacity); clone = NULL;

	}
	
	allocator_type 			get_allocator() const { return(alloc); }
	
	/* Element access */
	
	reference 				at( size_type pos ) {
		if (pos >= sz)
			throw std::out_of_range("ft::vector::at:  out of range");
		return arr[pos];
	}
	
	const_reference 		at( size_type pos ) const {
		if (pos >= sz) throw std::out_of_range("ft::vector::at:  out of range");
		return arr[pos];
	}
	
	reference 				operator[]( size_type pos ) { return (arr[pos]); }
	
	const_reference 		operator[]( size_type pos ) const { return (arr[pos]); }
	
	reference 				front() { return (arr[0]); }
	
	const_reference 		front() const { return (arr[0]); }
	
	reference 				back() { return (arr[sz - 1]); }
	
	const_reference 		back() const { return (arr[sz - 1]); }
	
	value_type* 			data() { return (arr); }
	
	const value_type* 		data() const { return (arr); }
	
	/* Iterators */
	
	iterator 				begin() { return iterator(arr); }
	const_iterator 			cbegin() const { return const_iterator(arr); }
	
	iterator				end() { return iterator(arr + sz); };
	const_iterator			cend() const { return const_iterator(arr + sz); };
	
	reverse_iterator 		rbegin() { return reverse_iterator( end() ); }
	const_reverse_iterator 	crbegin() const { return const_reverse_iterator( cend() ); }
	
	reverse_iterator		rend() { return reverse_iterator( begin() ); };
	const_reverse_iterator	crend() const { return const_reverse_iterator( cbegin() ); };
	
	/* Capacity */
	
	bool 					empty() const { return ( cbegin() == cend() ); }
	
	size_type 				size() const { return (sz); };
	
	size_type 				max_size() const { return (alloc.max_size()); }
	
	void					reserve(size_type capacity) {
		if (capacity <= cap) return ;
		size_type	i = 0;
		value_type*	newarr = alloc.allocate(capacity);
		try {
			for (; i < sz; ++i)
				alloc.construct(newarr + i, arr[i]);
		} catch (...) {
			for (size_type j = 0; j < i; ++j)
				alloc.destroy(newarr + j);
			alloc.deallocate(newarr, capacity);
			throw ;
		}
		killArr(arr, sz, cap);
		arr = newarr;
		cap = capacity;
	}
	
	size_type 				capacity() const { return (cap); }
	
	/* Modifiers */
	
	void 					clear() {
		while (sz)
			alloc.destroy(arr + --sz);
	}
	
	iterator 				insert(iterator pos,
								   const value_type& value ) {
		return ( insert(pos, 1, value) );
	}

	iterator 				insert(iterator pos,
								   size_type count,
								   const value_type& value ) {
		if (count == 0) return (pos);
		if (cap == 0) { arr = alloc.allocate(1); ++cap; pos = begin(); }

		size_type	posNum = posNumber(pos);
		size_type	distance = count;
		size_type	newSize = sz + distance;
		size_type	newCapacity = ( distance > sz ? newSize : ft::upDegree2(newSize) );
		value_type*	newArr = NULL;
		value_type*	clone = NULL;

		if (cap < newSize) {
			newArr = arrCopying( newCapacity, posNum, distance );
			size_type i = 0;
			try {
				for (; i < count; ++i)
					alloc.construct( newArr + posNum + i, value );
			} catch (...) {
				killArr(newArr, i, newCapacity);
				newArr = NULL;
				throw;
			}
			killArr(arr, sz, cap);
			arr = newArr;
			newArr = NULL;
			sz = newSize;
			cap = newCapacity;
		} else {
			clone = arrCopying(cap, 0, 0);
			try {
				shiftArr(posNum, distance);
				for (size_type i = 0; i < count; ++i)
					alloc.construct(arr + posNum + i, value);
			} catch (...) {
				killArr(arr, sz, cap);
				arr = clone;
				clone = NULL;
				throw;
			}
			killArr(clone, sz, cap);
			clone = NULL;
			sz = newSize;
		}
		return ( iterator(arr + posNum) );
	}

	template< class InputIt >
	iterator 				insert(iterator pos,
								   InputIt first,
								   InputIt last,
								   typename ft::enable_if<
										!ft::is_integral<InputIt>::value,
										InputIt
										>::type* = 0 ) {
		difference_type	dst = ft::distance(first, last);
		if (dst <= 0)
			throw std::out_of_range("ft::vector::insert:  out of range\n");
		size_type		posNum = posNumber(pos);

		value_type*		newArr = NULL;
		value_type*		clone = NULL;
		size_type		distance = (size_type)dst;
		size_type		newSize = sz + distance;
		size_type		newCapacity = (distance > sz ? newSize :
									   ft::upDegree2(newSize));

		if (cap < newSize) {
			newArr = arrCopying( newCapacity, posNum, distance );
			size_type i = 0;
			try {
				for (; i < distance; ++i, ++first)
					alloc.construct( newArr + posNum + i, *first );
			} catch (...) {
				killArr(newArr, i, newCapacity);
				newArr = NULL;
				throw;
			}
			killArr(arr, sz, cap);
			arr = newArr;
			newArr = NULL;
			sz = newSize;
			cap = newCapacity;
		} else {
			clone = arrCopying(cap, 0, 0);
			try {
				shiftArr(posNum, distance);
				for (size_type i = 0; i < distance; ++i, ++first)
					alloc.construct(arr + posNum + i, *first);
			} catch (...) {
				killArr(arr, sz, cap);
				arr = clone;
				clone = NULL;
				throw;
			}
			killArr(clone, sz, cap);
			clone = NULL;
			sz = newSize;
		}
		return ( iterator(arr + posNum) );
	}
	
	iterator 				erase( iterator pos ) {
		size_type	posNum = posNumber(pos);
		if (posNum == sz)
			throw std::out_of_range("ft::vector::insert:  out of range\n");
		return ( erase(posNum, 1) );
	}
	
	iterator 				erase( iterator first, iterator last ) {
		size_type	firstNum = posNumber(first);
		size_type	lastNum = posNumber(last);
		if (lastNum < firstNum)
			throw std::out_of_range("ft::vector::insert:  out of range\n");
		return ( erase(firstNum, lastNum - firstNum) );
	}

	void 					push_back( const value_type& value ) {
		if (cap > 0) {
			if (sz == cap) reserve( cap * 2 );
			try {
				alloc.construct(arr + sz, value); ++sz;
			} catch (...) { throw; }
		} else {
			arr = alloc.allocate(1); ++cap;
			try {
				alloc.construct(arr, value); ++sz;
			} catch (...) {
				alloc.deallocate(arr, 1); --cap;
				throw;
			}
		}
	}
	
	void 					pop_back() {
		if (sz > 0)
			alloc.destroy(arr + sz - 1); --sz;
	}
	
	void 					resize(size_type count,
								   value_type value = value_type() ) {
		if (sz == count)
			return ;
		if (sz > count) {
			for (size_type i = count; i < sz; ++i)
				alloc.destroy(arr + i);
			sz = count;
		} else {
			if ( cap < count ) {
				size_type	i = 0;
				size_type	newCapacity = ft::upDegree2(count);
				value_type*	newArr = alloc.allocate( newCapacity );
				try {
					for (; i < sz; ++i)
						alloc.construct( newArr + i, arr[i] );
					for (; i < count; ++i)
						alloc.construct( newArr + i, value );
				} catch (...) {
					for (size_type j = 0; j < i; ++j)
						alloc.destroy( newArr + j );
					alloc.deallocate( newArr, newCapacity );
					throw ;
				}
				killArr(arr, sz, cap);
				arr = newArr; newArr = NULL;
				cap = newCapacity;
				sz = count;
			} else {
				size_type	i = sz;
				value_type*	clone = arrCopying(cap, 0, 0);
				try {
					for (; i < count; ++i)
						alloc.construct( arr + i, value );
				} catch (...) {
					for (size_type j = 0; j < i; ++j)
						alloc.destroy( arr + j );
					alloc.deallocate( arr, cap );
					arr = clone; clone = NULL;
					throw ;
				}
				killArr(clone, sz, cap); clone = NULL;
				sz = count;
			}
		}
	}
	
	void 					swap( vector& other ) {
		value_type* arrTmp	= this->arr;
		size_type	szTmp	= this->sz;
		size_type	capTmp	= this->cap;
		this->arr	= other.arr;
		this->sz	= other.sz;
		this->cap	= other.cap;
		other.arr	= arrTmp;
		other.sz	= szTmp;
		other.cap	= capTmp;
	}
	
protected:
	
	/* Several internal functions */
	
	value_type*				arrCopying(size_type capacity,
									   size_type position,
									   size_type distance) {
		size_type	i = 0;
		value_type*	arrCopy = alloc.allocate(capacity);
		if (capacity >= sz + distance) {
			try {
				for (; i < position; ++i) {
					alloc.construct(arrCopy + i, arr[i]);
				}
				i += distance;
				for (; i < sz + distance; ++i) {
					alloc.construct(arrCopy + i, arr[i - distance]);
				}
			} catch (...) {
				for(size_type j = 0; j < i; ++j) {
					alloc.destroy(arrCopy + j);
				}
				alloc.deallocate(arrCopy, capacity);
				arrCopy = NULL;
				throw;
			}
		}
		return (arrCopy);
	}
	
	void					shiftArr(size_type position,
									 size_type distance) {
		for (size_type i = sz; i > position; i--) {
			alloc.construct(arr + i + distance - 1, arr[i - 1]);
			alloc.destroy(arr + i - 1);
		}
	}
	
	void					killArr(value_type* array,
									size_type size,
									size_type capacity) {
		if (capacity > 0) {
			for (size_type i = 0; i < size; ++i) {
				alloc.destroy(array + i);
			}
			alloc.deallocate(array, capacity);
		}
	}
	
	size_type				posNumber(iterator& pos) {
		size_type	count = 0;
		iterator 	it = begin();
		iterator 	End = end();
		for (; it != End; ++count, ++it) {
			if (it == pos)
				return (count);
		}
		if (it == pos)
			return (count);
		throw std::out_of_range("ft::vector::insert:  out of range\n");
	}
	
	iterator				erase( size_type pos, size_type distance ) {
		value_type*	clone = arrCopying(cap, 0, 0);
		try {
			for (size_type i = pos; i < sz - distance; ++i) {
				alloc.destroy(arr + i);
				alloc.construct(arr + i, arr[i + distance]);
			}
		} catch (...) {
			killArr(arr, sz, cap);
			arr = clone; clone = NULL;
			throw;
		}
		killArr(clone, sz, cap);
		for (size_type i = sz - distance; i < sz + distance; ++i) {
			alloc.destroy(arr + i); --sz;
		}
		return ( iterator(arr + pos) );
	}
	
}; /* class vector end */

/* Non-member functions */

template< class T, class Alloc >
bool					operator==(const std::vector<T,Alloc>& lhs,
								   const std::vector<T,Alloc>& rhs ) {
	return (lhs.size() == rhs.size() &&
			ft::equal( lhs.cbegin(), lhs.cend(), rhs.cbegin() ) );
}
template< class T, class Alloc >
bool					operator!=(const ft::vector<T,Alloc>& lhs,
								   const ft::vector<T,Alloc>& rhs ) {
	return (!(lhs == rhs));
}

template< class T, class Alloc >
bool					operator<(const ft::vector<T,Alloc>& lhs,
								  const ft::vector<T,Alloc>& rhs ) {
	return (ft::lexicographical_compare(lhs.cbegin(), lhs.cend(), rhs.cbegin(), rhs.cend()));
}
template< class T, class Alloc >
bool					operator<=(const ft::vector<T,Alloc>& lhs,
								   const ft::vector<T,Alloc>& rhs ) {
	return (!(rhs < lhs));
}
template< class T, class Alloc >
bool					operator>(const ft::vector<T,Alloc>& lhs,
								  const ft::vector<T,Alloc>& rhs ) {
	return (rhs < lhs);
}
template< class T, class Alloc >
bool					operator>=(const ft::vector<T,Alloc>& lhs,
								   const ft::vector<T,Alloc>& rhs ) {
	return (!(lhs < rhs));
}
template< class T, class Alloc >
void 								swap(ft::vector<T,Alloc>& lhs,
										 ft::vector<T,Alloc>& rhs ) {
	lhs.swap(rhs);
}


} /* namespace ft end */

#endif /* VECTOR_HPP end */