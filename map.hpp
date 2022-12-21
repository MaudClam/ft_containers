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
	typedef Key										key_type;
	typedef T										mapped_type;
	typedef ft::pair<const Key, T>					value_type;
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
	private:
		key_compare k_compare;
	public:
		value_compare() {}
		~value_compare() {}
		bool operator()(pointer x, pointer y)  {
			return ( k_compare(x->first, y->first) ); }
	};
		
	/* Member types */
	typedef ft::RBTree<pointer,self,value_compare>	tree_type;
	typedef typename tree_type::node_type			node_type;
	typedef node_type*								node_pointer;
	typedef node_type&								node_reference;
	typedef ft::iterator<
			ft::bidirectional_iterator_tag,
			node_type >								iterator_type;

private:

	/* Member objects */
	
	tree_type										tree;
	tree_type										clone_tree;
	allocator_type									allocator;
	
public:

	/* Member functions */
	
	map() {}
	
	~map() {}
	
	map& operator=( const map& other ) {
		if ( other.size() >= max_size() / 2 )
			throw std::bad_array_new_length();
		try {
			node_pointer node = other.tree.findMin();
			while (node != NULL) {
				clonePairAndNode(*node->value, clone_tree);
				node = other.tree.findNextNode(node);
			}
			clear();
			this->tree.tree_transplant(this->clone_tree);
			return (*this);
		}
		catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
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
	
	mapped_type&	operator[]( const Key& key ) {
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

	/* Iterators */
		
	class iterator : public iterator_type {
	private:
		node_pointer		ptr;
		node_pointer		max_keeper;
	public:

		iterator(node_pointer node, node_pointer max_keeper = NULL)
		:
			ptr(node),
			max_keeper(max_keeper)
		{}
		
		iterator() : ptr(NULL), max_keeper(NULL) {}

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

		reference operator*() const { return *ptr->value; }
		
		pointer operator->() const { return ptr->value; }

		iterator operator++(void) {
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
				max_keeper = ptr;
				ptr = u_nullptr;
				return (*this);
			}
			return (*this);
		}

		iterator operator++(int) {
			iterator tmp = *this;
			++(*this);
			return ( tmp );
		}
		
		iterator operator--(void) {
			if (ptr == u_nullptr) {
				ptr = max_keeper;
				max_keeper = NULL;
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
				ptr = NULL;
				return (*this);
			}
			return (*this);
		}

		iterator operator--(int) {
			iterator tmp = *this;
			--(*this);
			return ( tmp );
		}
	
		bool	operator==(iterator other) const { return (ptr == other.ptr); }
		bool	operator!=(iterator other) const { return (!(ptr == other.ptr)); }

	}; /* class iterator_node end */

	iterator 		begin() const { return iterator(tree.findMin()); }

	iterator		end() const { return iterator(u_nullptr, tree.findMax()); };

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
	
	void 			clear(void) {
		while (tree.size.size) {
			node_pointer	node = tree.findMin();
			allocator.destroy(node->value);
			allocator.deallocate(node->value, 1);
			node->value = NULL;
			tree.deleteNode(node);
		}
	}
	
	ft::pair<iterator, bool>insert( const value_type& value );//FIXME
	
private:
	
	/* Several internal functions */

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
	
	node_pointer	findKey( const key_type& key ) {
		value_type value( key, mapped_type() );
		return tree.findNode( &value );
	}

	void			clonePairAndNode( const value_type& value, tree_type& clone_tree ) {
		try {
			pointer p = allocator.allocate(1);
			allocator.construct(p, value_type(value));
			clone_tree.insertNode(p);
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
			clone_tree.clear();
		}
	}
	
}; /* class map end */

} /* namespace ft end */

#endif /* MAP_HPP end */
