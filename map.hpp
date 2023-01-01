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
# include "pair.hpp"
# include "utils.hpp"

namespace ft {

template<
	class Key,
	class T,
	class Compare = std::less<Key>,
	class Allocator = std::allocator<ft::pair<const Key, T> >
> class map {
	
public:
	
	/* Member types */
	typedef ft::map<Key,T,Compare,Allocator>		self;
	typedef ft::remove_const_t<Key>					key_type;
	typedef T										mapped_type;
	typedef ft::pair<const key_type, mapped_type>	value_type;
	typedef std::ptrdiff_t							difference_type;
	typedef Compare									key_compare;
	typedef Allocator								allocator_type;
	typedef value_type&								reference;
	typedef typename Allocator::size_type			size_type;
	typedef const value_type&						const_reference;
	typedef typename Allocator::pointer				pointer;
	typedef typename Allocator::const_pointer		const_pointer;

	/* Member classes */
	class value_compare {
	protected:
		key_compare	comp;
	public:
		value_compare() {}
		~value_compare() {}
		bool operator()(pointer x, pointer y) const {
			return ( comp(x->first, y->first) ); }
		bool operator()(const value_type& x, const value_type& y) const {
			return ( comp(x.first, y.first) ); }
		bool operator()(const value_type& x, pointer y) const {
			return ( comp(x.first, y->first) ); }
		bool operator()(pointer x, const value_type& y) const {
			return ( comp(x->first, y.first) ); }
	};
		
	/* Member types */
	typedef ft::RBTree<pointer,self,value_compare>	tree_type;
	typedef typename tree_type::node_type			node_type;
	typedef node_type*								node_pointer;
	typedef node_type&								node_reference;
	typedef ft::iterator<
			ft::bidirectional_iterator_tag,
			value_type >								iterator_type;

private:
	/* Member objects */
	tree_type										tree;
	key_compare										k_comp;
	value_compare									compare;
	allocator_type									allocator;
	
public:

	/* Member functions */
	
	map() {}
	
	~map() { clear(); }
	
	map& operator=( const map& other ) {
		if ( other.size() >= max_size() / 2 )
			throw std::bad_array_new_length();
		tree_type	clone_tree;
		try {
			node_pointer node = other.tree.findMin();
			while (node != NULL) {
				clonePairAndNode(*node->value, clone_tree);
				node = other.tree.findNextNode(node);
			}
			clear(tree);
			this->tree.transplant(clone_tree);
			return (*this);
		}
		catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
			clear(clone_tree);
		}
		return (*this);
	}
	
	allocator_type 	get_allocator() const { return (this->allocator); }

	/* Element access */
	
	mapped_type& 	at( const key_type& key ) {
		node_pointer node = findKey(key);
		if ( node == NULL )
			throw std::out_of_range("ft::map::at:  key not found");
		return ( node->value->second );
	}
	
	const mapped_type& 	at( const key_type& key ) const {
		node_pointer node = findKey(key);
		if ( node == NULL )
			throw std::out_of_range("ft::map::at:  key not found");
		return ( node->value->second );
	}
	
	mapped_type&	operator[]( const key_type& key ) {
		node_pointer node = findKey(key);
		if (node == NULL) {
			try {
				node = insertPairAndNode(key, mapped_type());
				return (node->value->second);
			}
			catch (std::exception &e) {
				std::cerr << e.what() << std::endl;
				return ( tree.findMax()->value->second );
			}
		}
		return (node->value->second);
	}
	
	/* Member classes */
	template<bool isConst>
	class common_iterator : public iterator_type {
	private:
		node_pointer				ptr;
		node_pointer				max;
	public:
		common_iterator()
		:
			ptr(NULL),
			max(NULL)
		{}

		common_iterator(node_pointer node, node_pointer max = NULL)
		:
			ptr(node),
			max(max)
		{}
		
		common_iterator(const common_iterator& other)
		:
			ptr(other.ptr),
			max(other.max)
		{}
		
		common_iterator&	operator=( const common_iterator& other ) {
				this->ptr = other.ptr;
				this->max = other.max;
			return ( *this );
		}
				
		~common_iterator() {}

		ft::conditional_t<isConst, const_reference, reference>	operator*() const { return *ptr->value; }
		
		ft::conditional_t<isConst, const_pointer, pointer>		operator->() const { return ptr->value; }

		common_iterator&	operator++(void) {
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

		common_iterator		operator++(int) {
			common_iterator tmp = *this;
			++(*this);
			return ( tmp );
		}
		
		common_iterator&	operator--(void) {
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

		common_iterator		operator--(int) {
			common_iterator tmp = *this;
			--(*this);
			return ( tmp );
		}
	
		bool	operator==(common_iterator other) const { return( ptr == other.ptr ); }
		bool	operator!=(common_iterator other) const { return( !(this == other) ); }

	}; /* class common_iterator end */

	/* Member types */
	typedef common_iterator<false>						iterator;
	typedef common_iterator<true> 						const_iterator;
	typedef ft::pair<iterator, bool>					iterator_bool;
	typedef ft::reverse_iterator<iterator>				reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;
	
	/* Iterators */
	
	iterator 				begin() { return iterator(tree.findMin(), tree.findMax()); }
	const_iterator 			cbegin() const { return const_iterator(tree.findMin(), tree.findMax()); }

	iterator				end() { return iterator(u_nullptr, tree.findMax()); };
	const_iterator			cend() const { return const_iterator(u_nullptr, tree.findMax()); };

	reverse_iterator 		rbegin() { return reverse_iterator(end()); }
	const_reverse_iterator 	crbegin() const { return const_reverse_iterator(cend()); }

	reverse_iterator		rend() { return reverse_iterator(begin()); };
	const_reverse_iterator	crend() const { return const_reverse_iterator(cbegin()); };

	/* Capacity */

	bool			empty(void) const { return ( begin() == end() ); }
	
	size_type 		size(void) const { return tree.get_size() ; }
	
	size_type 		max_size(void) const {
		size_type pair_max_size = allocator.max_size();
		size_type tree_max_size = tree.max_size();
		if (pair_max_size < tree_max_size)
			return (pair_max_size);
		else
			return (tree_max_size);
	}

	/* Modifiers */
	
	void 			clear(void) { clear(tree); }
	
	iterator_bool	insert( const value_type& value ) {
		node_pointer	node = findKey(value.first);
		bool			is_inserted = (node == NULL ? true : false);
		if ( is_inserted )
			try {
				node = insertPairAndNode(value.first, value.second);
			} catch (std::exception &e) {
				node = tree.findMax();
			}
		return (iterator_bool(iterator(node), is_inserted));
	}
	
	iterator 		insert( iterator pos, const value_type& value ) {
		if ( !compare(value, *pos) && !compare(*pos, value))
			return (pos);
		return ( insert(value).first );
	}
	
	iterator 		erase( iterator pos ) {
		if ( pos != end() ) {
			node_pointer node = findKey(pos->first);
			++pos;
			if (node != NULL) {
				allocator.destroy(node->value);
				allocator.deallocate(node->value, 1);
				node->value = NULL;
				tree.deleteNode(node);
			}
		}
		return (pos);
	}
	
	iterator 		erase( iterator first, iterator last ) {
		while ( first != last )
			erase(first++);
		return (first);
	}
	
	size_type		erase( const key_type& key ) {
		size_type s = size();
		tree.deleteNode(findKey(key));
		return (size() - s);
	}
	
	void 			swap( map& other ) {
		node_pointer	tmp = tree.get_root();
		tree.set_root(other.tree.get_root());
		other.tree.set_root(tmp);
		size_type	s = tree.get_size();
		tree.set_size(other.tree.get_size());
		other.tree.set_size(s);
	}
	
	/* Lookup */
	
	size_type count( const key_type& key ) const { return (findKey(key) == NULL); }
	
	iterator 		find( const key_type& key ) {
		node_pointer node = findKey(*key);
		if (node == NULL)
			return (end());
		return ( inerator(node) );
	}
	
	const_iterator 	find( const key_type& key ) const {
		node_pointer node = findKey(key);
		if (node == NULL)
			return (end());
		return ( const_iterator(node) );
	}
	
	ft::pair<iterator,iterator>
					equal_range( const key_type& key ) {
		return ft::pair<iterator,iterator>( lower_bound(key),upper_bound(key) );
	}

	ft::pair<const_iterator, const_iterator>
					equal_range( const Key& key ) const {
		return ft::pair<const_iterator,const_iterator>( lower_bound(key),upper_bound(key) );
	}
	
	iterator		lower_bound( const key_type& key) {
		node_pointer node = tree.findMin();
		while (node != NULL && k_comp(node->value->first, *key)) {
			node = tree.findNextNode(node);
		}
		if (node == NULL)
			return ( end() );
		return ( iterator(node) );
	}

	const_iterator	lower_bound( const key_type& key ) const {
		node_pointer node = tree.findMin();
		while (node != NULL && k_comp(node->value->first, key)) {
			node = tree.findNextNode(node);
		}
		if (node == NULL)
			return ( cend() );
		return ( const_iterator(node) );
	}
	
	iterator		upper_bound( const key_type& key ) {
		node_pointer node = tree.findMin();
		while (node != NULL && !k_comp(*key, node->value->first)) {
			node = tree.findNextNode(node);
		}
		if (node == NULL)
			return ( end() );
		return ( iterator(node) );
	}

	const_iterator	upper_bound( const key_type& key ) const {
		node_pointer node = tree.findMin();
		while (node != NULL && !k_comp(*key, node->value->first)) {
			node = tree.findNextNode(node);
		}
		if (node == NULL)
			return ( end() );
		return ( const_iterator(node) );
	}
	
	/* Observers */

	key_compare 	key_comp() const { return (k_comp); }
	
	self::value_compare value_comp() const { return (compare); };

	/* Several internal functions */
	
	void			printIteratively(void) { tree.printTreeIteratively(false); }
	
	void			printRecursively(void) { tree.printTreeRecursively(); }

private:
	
	node_pointer	insertPairAndNode( const key_type& key, const mapped_type& t ) {
		if ( size() >= max_size() )
			throw std::bad_array_new_length();
		try {
			pointer p = allocator.allocate(1);
			allocator.construct(p, value_type(key, t));
			return ( tree.insertNode(p) );
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
			return (NULL);
		}
	}
	
	node_pointer	findKey( const key_type& key ) const {
		value_type value( key, mapped_type() );
		return tree.findNode( &value );
	}

	void			clonePairAndNode( const value_type& value, tree_type& clone_tree ) {
		pointer p = allocator.allocate(1);
		allocator.construct(p, value_type(value));
		clone_tree.insertNode(p);
	}
	
	void 			clear(tree_type& tree_to_clear) {
		while (tree_to_clear.size.size) {
			node_pointer	node = tree_to_clear.findMin();
			allocator.destroy(node->value);
			allocator.deallocate(node->value, 1);
			node->value = NULL;
			tree_to_clear.deleteNode(node);
		}
	}
		
}; /* class map end */

/* Map non-member functions */

template< class Key, class T, class Compare, class Alloc >
bool operator==( const ft::map<Key,T,Compare,Alloc>& lhs,
				const ft::map<Key,T,Compare,Alloc>& rhs ) {
	if (lhs.size() == rhs.size())
		return ( ft::equal(lhs.cbegin(), lhs.cend(), rhs.cbegin()) );
	return (false);
}

template< class Key, class T, class Compare, class Alloc >
bool operator!=( const ft::map<Key,T,Compare,Alloc>& lhs,
				const ft::map<Key,T,Compare,Alloc>& rhs ) {
		return ( !(lhs == rhs) );
}

template< class Key, class T, class Compare, class Alloc >
bool operator<( const ft::map<Key,T,Compare,Alloc>& lhs,
				const ft::map<Key,T,Compare,Alloc>& rhs ) {
	
		return ( ft::lexicographical_compare(lhs.cbegin(), lhs.cend(), rhs.cbegin(), rhs.cend()) );
}

template< class Key, class T, class Compare, class Alloc >
bool operator<=( const ft::map<Key,T,Compare,Alloc>& lhs,
				const ft::map<Key,T,Compare,Alloc>& rhs ) {
	
		return ( !(rhs < lhs) );
}

template< class Key, class T, class Compare, class Alloc >
bool operator>( const ft::map<Key,T,Compare,Alloc>& lhs,
				const ft::map<Key,T,Compare,Alloc>& rhs ) {
	
		return ( rhs < lhs );
}

template< class Key, class T, class Compare, class Alloc >
bool operator>=( const ft::map<Key,T,Compare,Alloc>& lhs,
				const ft::map<Key,T,Compare,Alloc>& rhs ) {
	
		return ( !(lhs < rhs) );
}

template< class Key, class T, class Compare, class Alloc >
void swap( std::map<Key,T,Compare,Alloc>& lhs,
		  std::map<Key,T,Compare,Alloc>& rhs ) {
	lhs.swap(rhs);
}

} /* namespace ft end */

#endif /* MAP_HPP end */
