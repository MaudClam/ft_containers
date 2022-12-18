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

#ifndef RBTREE_HPP
# define RBTREE_HPP

# define RED	false
# define BLACK	true
# define LEFT	false
# define RIGHT	true
# define INDENT	":   "

# include <iostream>
# include "pair.hpp"
# include "iterator.hpp"

namespace ft {

template<typename T>
struct RBSize {
	typedef T		size_type;
	size_type		size, nodes, reds, blacks;
	bool			is_unsorted;
	
	RBSize()
	:
		size(0),
		nodes(0),
		reds(0),
		blacks(0),
		is_unsorted(false)
	{}
	
	~RBSize() {}
	
}; /* struct Size end */

template<typename T>
std::ostream& operator<<(std::ostream& o, ft::RBSize<T>& size) {
	o 	<<	"Size: " << size.size << ". "
		<< size.nodes << " nodes, "
		<< size.reds << " REDs, "
		<< size.blacks << " BLACKs. "
		<< (size.is_unsorted ? "Tree is unsorted" : "Tree is sorted. ");
	return o;
}

template< typename Key, typename T >
struct RBNode : public ft::pair<Key,T> {
	
	/* Member types */
	
	typedef Key				key_type;
	typedef T				mapped_type;
	typedef RBNode*			node_pointer;

	/* Member objects */
	
	key_type				first;
	mapped_type				second;
	bool					color;
	node_pointer			parent;
	node_pointer			left;
	node_pointer			right;

	/* Member functions */

	RBNode()
	:
		color(RED),
		parent(NULL),
		left(NULL),
		right(NULL)
	{}

	~RBNode() {};

	RBNode(
		key_type		key,
		mapped_type		t,
		bool			color = RED,
		RBNode*			parent = NULL,
		RBNode*			left = NULL,
		RBNode*			right = NULL
		)
	:
		first(key),
		second(t),
		color(color),
		parent(parent),
		left(left),
		right(right)
	{}

	RBNode (const RBNode& node)
	:
		first(node.first),
		second(node.second),
		color(node.color),
		parent(node.parent),
		left(node.left),
		right(node.right)
	{}

	RBNode& operator=(const RBNode& other)
	{
		if (other != *this) {
			this->first = other.first;
			this->second = other.second;
			this->value = other.value;
			this->color = other.color;
			this->parent = other.parent;
			this->left = other.left;
			this->right = other.right;
		}
		return (*this);
	}

	bool operator==(const RBNode& other)
	{
		if (
			this->first == other.first &&
			this->second == other.secont &&
			this->color == other.color &&
			this->parent == other.parent &&
			this->left == other.left &&
			this->right == other.right
			)
			return (true);
		return (false);
	}

	bool operator!=(const RBNode& other) {
		return ( !(other == *this) );
	}

}; /* struct RBNode end */

template< typename Key, typename T >
std::ostream& operator<<(std::ostream& o, ft::RBNode<Key,T>& node) {
	o << node.first << "-";
	o << node.second << (node.color == RED ? "r" : "B");
	return o;
}

template<
	class Key,
	class T,
	class Compare = std::less<Key>,
	typename Allocator = std::allocator<RBNode<const Key,T> >
> class RBTree {
public:
	
	/* Member types */
	
	typedef Key									key_type;
	typedef T									mapped_type;
	typedef Compare								compare_type;
	typedef RBNode<const Key, T>				node_type;
	typedef node_type*							node_pointer;
	typedef node_type&							node_reference;
	typedef Allocator							allocator_type;
	typedef typename Allocator::size_type		size_type;
	typedef RBSize< size_type >					Size_type;
	typedef ft::iterator<
			ft::bidirectional_iterator_tag,
			node_type >							iterator_type;
	
private:
	
	/* Member objects */
	
	node_pointer								root;
	compare_type								compare;
	Size_type									size;
	allocator_type								allocator;
	
public:

	/* Constructor & destructor */
	
	RBTree() : root(NULL) {}
	
	~RBTree() {
		while (size.size)
			deleteNode(findMinNode(root)->first);
	}
	
	class iterator : public iterator_type {
	private:
		node_pointer		ptr;
	public:

		iterator(node_pointer node) : ptr(node) {}
		
		iterator() : ptr(NULL) {}

		iterator(const iterator_type& other) {
			if (*this != other)
				this->ptr = other.ptr;
			return ( *this );
		}
		
		iterator_type& operator=( const iterator_type& other ) {
			if (*this != other)
				ptr = other.ptr;
			return ( *this );
		}
				
		~iterator() {}

		node_reference operator*() const { return *ptr; }
		
		node_pointer operator->() const { return ptr; }

		node_pointer operator++(void) const {
			ptr = ft::RBTree< key_type, mapped_type >::findNextNode(*ptr);
			return ( *this );
		}
		
		node_pointer operator++(int) const {
			iterator_type tmp = ptr;
			++(*this);
			return ( tmp );
		}
		
		node_pointer operator--(void) const {
			ptr = findPreviousNode(ptr);
			return ( *this );
		}
		
		node_pointer operator--(int) const {
			iterator_type tmp = ptr;
			--(*this);
			return ( tmp );
		}
		
	}; /* class iterator_node end */

	
	node_pointer begin() {
//		iterator it(findMin());
		return findMin();
	}

	/* Other member functions */

	size_type		get_size() {
		return ( size.size );
	}
	
	void			insertNode(node_pointer nodeToInsert) {
		if (root != NULL) {
			bool child = RIGHT;
			node_pointer node = root, parent = NULL;
			while (node != NULL) {
				if (!compare(nodeToInsert->value, node->value) &&
					!compare(node->value, nodeToInsert->value)) {
					allocator.destroy(nodeToInsert);
					allocator.deallocate(nodeToInsert, 1);
					return ;
				}
				parent = node;
				child = (compare(nodeToInsert->value, node->value) ? LEFT : RIGHT);
				node = (child == LEFT ? node->left : node->right);
			}
			child == LEFT ? parent->left = nodeToInsert : parent->right = nodeToInsert;
			nodeToInsert->parent = parent;
			size.size++;
			insertCase1(nodeToInsert);
		} else {
			root = nodeToInsert;
			nodeToInsert->color = BLACK;
			size.size++;
		}
	}
		
	void			insertNode(const key_type& key, const mapped_type& t) {
		if (root != NULL) {
			bool child = RIGHT;
			node_pointer node = root, parent = NULL;
			while (node != NULL) {
				if ( !compare(key, node->first) && !compare(node->first, key) )
					return ;
				parent = node;
				child = (compare(key, node->first) ? LEFT : RIGHT);
				node = (child == LEFT ? node->left : node->right);
			}
			node = allocator.allocate(1);
			allocator.construct(node, node_type(key, t, RED, parent));
			child == LEFT ? parent->left = node : parent->right = node;
			size.size++;
			insertCase1(node);
		} else {
			root = allocator.allocate(1);
			allocator.construct(root, node_type(key, t, BLACK));
			size.size++;
		}
	}
		
	void			deleteNode(const key_type& key) {
		node_pointer node = findNode(key), tmp = NULL;
		if (node != NULL) {
			if (node->left != NULL) {
				tmp = findMaxNode(node->left);
				swapNodes(node, tmp);
				deleteOneChild(node);
			} else if (node->right != NULL) {
				tmp = findMinNode(node->right);
				swapNodes(node, tmp);
				deleteOneChild(node);
			} else
				deleteOneChild(node);
		}
	}
	
	node_pointer	findNode(const key_type& key) {
		node_pointer node = root;
		while (node != NULL) {
			if ( !compare(key, node->first) && !compare(node->first, key) )
				break ;
			else if ( compare(key, node->first) )
				node = node->left;
			else
				node = node->right;
		}
		return (node);
	}
	
	node_pointer	findMin() { return findMinNode(root); }
	
	node_pointer	findMax() { return findMaxNode(root); }
	
	node_pointer	findNextNode(node_pointer node) {
		if (node != NULL) {
			if (node->right != NULL)
				return (findMinNode(node->right));
			while (node->parent != NULL) {
				if (node == node->parent->left)
					return (node->parent);
				node = node->parent;
			}
		}
		return (NULL);
	}

	node_pointer	findPreviousNode(node_pointer node) {
		if (node != NULL) {
			if (node->left != NULL)
				return (findMaxNode(node->left));
			while (node->parent != NULL) {
				if (node == node->parent->right)
					return (node->parent);
				node = node->parent;
			}
		}
		return (NULL);
	}

private:
	
	void			swapNodes(node_pointer n1, node_pointer n2) {
		node_pointer p1 = n1->parent;
		bool bp1 = (n1 == n1->parent->left ? LEFT : RIGHT);
		node_pointer p2 = n2->parent;
		bool bp2 = (n2 == n2->parent->left ? LEFT : RIGHT);
		if (bp1 == LEFT) p1->left = n2; else p1->right = n2;
		if (bp2 == LEFT) p2->left = n1; else p2->right = n1;
		n1->parent = p2; n2->parent = p1;
		p1 = n1->left; p2 = n1->right;
		n1->left = n2->left; n1->right = n2->right;
		n2->left = p1; n2->right = p2;
	}
	
	void			deleteOneChild(node_pointer node) {
		/* Condition: node has at most one non-zero child. */
		if (node->left == NULL && node->right == NULL) {
			if (node->parent == NULL)		/* Tree is empty after deletion */
				root = NULL;
			else {
				if (node == node->parent->left) {
					node->parent->left = NULL;
				} else {
					node->parent->right = NULL;
				}
				deleteCase1(node->parent);
			}
		}
		else {
			node_pointer child = ( node->right == NULL ?
								  node->left : node->right );
			replaceNode(node, child);
			if (node->color == BLACK) {
				if (child->color == RED)
					child->color = BLACK;
				else
					deleteCase1(child);
			}
		}
		allocator.destroy(node);
		allocator.deallocate(node, 1);
		size.size--;
	}
	
	void			replaceNode(node_pointer node,
								node_pointer child) {
		child->parent = node->parent;
		if (node == node->parent->left) {
			node->parent->left = child;
		} else {
			node->parent->right = child;
		}
	}
	
	node_pointer	grandparent(node_pointer node) {
		if (node != NULL && node->parent != NULL)
			return (node->parent->parent);
		return (NULL);
	}
	
	node_pointer	uncle(node_pointer node) {
		node_pointer grandpa = grandparent(node);
		if (grandpa == NULL) /* No grandparent means no uncle */
			return (NULL);
		if (node->parent == grandpa->left)
			return (grandpa->right);
		else
			return (grandpa->left);
	}
	
	node_pointer	sibling(node_pointer node) {
		if (node != NULL && node->parent != NULL) { /* No parent - no brother (root) */
			if (node == node->parent->left)
				return node->parent->right;
			else
				return node->parent->left;
		}
		return (NULL);
	}
	
	node_pointer	findMaxNode(node_pointer node) {
		while (node != NULL && node->right != NULL)
			node = node->right;
		return (node);
	}
	
	node_pointer	findMinNode(node_pointer node) {
		while (node != NULL && node->left != NULL)
			node = node->left;
		return (node);
	}
	
	void			rotateLeft(node_pointer node) {
		node_pointer	pivot = node->right;
		
		pivot->parent = node->parent; /* perhaps the pivot becomes the root of the tree */
		if (node->parent != NULL) {
			if (node->parent->left == node)
				node->parent->left = pivot;
			else
				node->parent->right = pivot;
		} else
			root = pivot;
		node->right = pivot->left;
		if (pivot->left != NULL)
			pivot->left->parent = node;
		node->parent = pivot;
		pivot->left = node;
	}
	
	void			rotateRight(node_pointer node) {
		node_pointer	pivot = node->left;
		
		pivot->parent = node->parent; /* perhaps the pivot becomes the root of the tree */
		if (node->parent != NULL) {
			if (node->parent->left == node)
				node->parent->left = pivot;
			else
				node->parent->right = pivot;
		} else
			root = pivot;
		node->left = pivot->right;
		if (pivot->right != NULL)
			pivot->right->parent = node;
		node->parent = pivot;
		pivot->right = node;
	}

	void			insertCase1(node_pointer node) {
		if (node->parent == NULL)
			node->color = BLACK;
		else
			insertCase2(node);
	}
	
	void			insertCase2(node_pointer node) {
		if (node->parent->color == BLACK)
			return;
		else
			insertCase3(node);
	}

	void			insertCase3(node_pointer node) {
		node_pointer	uncl = uncle(node);
		node_pointer	grandpa = grandparent(node);

		if ((uncl != NULL) && (uncl->color == RED)) {
			node->parent->color = BLACK;
			uncl->color = BLACK;
			grandpa->color = RED;
			insertCase1(grandpa);
		} else {
			insertCase4(node);
		}
	}

	void			insertCase4(node_pointer node) {
		node_pointer	grandpa = grandparent(node);

		if ((node == node->parent->right) && (node->parent == grandpa->left)) {
			rotateLeft(node->parent);
			node = node->left;
		} else if ((node == node->parent->left) && (node->parent == grandpa->right)) {
			rotateRight(node->parent);
			node = node->right;
		}
		insertCase5(node);
	}

	void			insertCase5(node_pointer node) {
		node_pointer	grandpa = grandparent(node);

		node->parent->color = BLACK;
		grandpa->color = RED;
		if ((node == node->parent->left) && (node->parent == grandpa->left)) {
			rotateRight(grandpa);
		} else {
			rotateLeft(grandpa);
		}
	}
	
	void			deleteCase1(node_pointer node) {
		if (node->parent != NULL)
			deleteCase2(node);
	}

	void			deleteCase2(node_pointer node) {
		node_pointer	siblng = sibling(node);

		if (siblng != NULL && siblng->color == RED) {
			node->parent->color = RED;
			siblng->color = BLACK;
			if (node == node->parent->left)
				rotateLeft(node->parent);
			else
				rotateRight(node->parent);
		}
		deleteCase3(node);
	}

	void			deleteCase3(node_pointer node) {
		node_pointer	siblng = sibling(node);

		if ( siblng != NULL &&
			(node->parent->color == BLACK) &&
			(siblng->color == BLACK) &&
			(siblng->left == NULL || siblng->left->color == BLACK) &&
			(siblng->right == NULL || siblng->right->color == BLACK)
			)
		{
			siblng->color = RED;
			deleteCase1(node->parent);
		} else
			deleteCase4(node);
	}

	void			deleteCase4(node_pointer node) {
		node_pointer	siblng = sibling(node);

		if ( siblng != NULL &&
			(node->parent->color == RED) &&
			(siblng->color == BLACK) &&
			(siblng->left == NULL || siblng->left->color == BLACK) &&
			(siblng->right == NULL || siblng->right->color == BLACK)
			)
		{
			siblng->color = RED;
			node->parent->color = BLACK;
		} else
			deleteCase5(node);
	}

	void			deleteCase5(node_pointer node) {
		node_pointer	siblng = sibling(node);

		if (siblng != NULL && siblng->color == BLACK) {
			if (
				(node == node->parent->left) &&
				(siblng->right == NULL || siblng->right->color == BLACK) &&
				(siblng->left != NULL && siblng->left->color == RED)
			   )
			{
				siblng->color = RED;
				siblng->left->color = BLACK;
				rotateRight(siblng);
			} else if (
					(node == node->parent->right) &&
					(siblng->left == NULL || siblng->left->color == BLACK) &&
					(siblng->right != NULL && siblng->right->color == RED)
				)
			{
				siblng->color = RED;
				siblng->right->color = BLACK;
				rotateLeft(siblng);
			}
		}
		deleteCase6(node);
	}

	void			deleteCase6(node_pointer node) {
		node_pointer	siblng = sibling(node);

		if (siblng != NULL)
		{
			siblng->color = node->parent->color;
			node->parent->color = BLACK;
			
			if (node == node->parent->left) {
				if (siblng->right != NULL)
					siblng->right->color = BLACK;
				rotateLeft(node->parent);
			} else {
				if (siblng->left != NULL)
					siblng->left->color = BLACK;
				rotateRight(node->parent);
			}
		}
	}
	
	void			treeBalanceCounter(node_pointer node) {
		if (node != NULL) {
			if (node->left != NULL && compare(node->value, node->left->value))
				size.is_unsorted = true;
			if (node->right != NULL && compare(node->right->value, node->value))
				size.is_unsorted = true;
			size.nodes++;
			if (node->color == RED)
				size.reds++;
			else
				size.blacks++;
			if (node->right == NULL)
				size.blacks++;
			if (node->left == NULL)
				size.blacks++;
		}
	}
		
	void			treeBalanceCounter_reset(void) {
		size.nodes = 0;
		size.reds = 0;
		size.blacks = 0;
		size.is_unsorted = false;
	}
		
	void			printRecursively(node_pointer node, int indents) {
		if (node != NULL)
		{
			printRecursively(node->right, indents + 1);
			for (int i = 0; i < indents; ++i) std::cout << INDENT;
			std::cout << *node << std::endl;
			treeBalanceCounter(node);
			printRecursively(node->left, indents + 1);
		}
	}

	void			printIteratively(node_pointer node) {
		if (node != NULL) {
			node->parent = NULL;
			node_pointer tmp = findMinNode(node);
			while (tmp != NULL) {
				//			std::cout << *tmp;
				treeBalanceCounter(tmp);
				tmp = findNextNode(tmp);
				//			std::cout << (tmp != NULL ? " " : "\n");
			}
			std::cout << size << std::endl;
			node->parent = root;
		}
	}
	
public:
	
	void			printTreeRecursively(void) {
		printRecursively(root, 0);
		std::cout << size << std::endl;
	}
	
	void			printTreeIteratively(void) {
		if (root != NULL) {
			treeBalanceCounter_reset();
			printIteratively(root->left);
			treeBalanceCounter_reset();
			printIteratively(root->right);
		}
	}

	
}; /* class RBTree end */

} /* namespace ft end */

#endif /* RBTREE_HPP end */
