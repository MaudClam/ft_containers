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
# include "iterator.hpp"

namespace ft {

template<typename T>
struct RBSize {
	typedef T		size_type;
	size_type		size, nodes, reds, blacks;
	bool			is_unsorted;
	RBSize() : size(0), nodes(0), reds(0), blacks(0), is_unsorted(false) {}
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

template< typename T >
struct RBNode {
	/* Member types */
	typedef T				value_type;
	/* Member objects */
	value_type				value;
	bool					color;
	RBNode*					parent;
	RBNode*					left;
	RBNode*					right;

	/* Member functions */

	RBNode()
	:
		value(),
		color(RED),
		parent(NULL),
		left(NULL),
		right(NULL)
	{}

	~RBNode() {};

	RBNode(const value_type& value, bool color = RED,
		   RBNode* parent = NULL, RBNode* left = NULL, RBNode* right = NULL)
	:
		value(value),
		color(color),
		parent(parent),
		left(left),
		right(right)
	{}

	RBNode (const RBNode& node)
	:
		value(node.value),
		color(node.color),
		parent(node.parent),
		left(node.left),
		right(node.right)
	{}

	RBNode& operator=(const RBNode& other)
	{
		if (other != *this) {
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
			value == other.value &&
			color == other.color &&
			parent == other.parent &&
			left == other.left &&
			right == other.right
			)
			return (true);
		return (false);
	}

	bool operator!=(const RBNode& other) {
		return ( !(other == *this) );
	}

}; /* struct RBNode end */

template<typename T>
std::ostream& operator<<(std::ostream& o, ft::RBNode<T>& node) {
	o << node.value << (node.color == RED ? "r" : "B");
	return o;
}

template<
	typename T,
	typename Compare = std::less<T>,
	typename Allocator = std::allocator<RBNode<T> >
> class RBTree {
public:
	/* Member types */
	typedef T									value_type;
	typedef Compare								compare_type;
	typedef RBNode< value_type >				node_type;
	typedef node_type*							node_pointer;
	typedef node_type&							node_reference;
	typedef Allocator							allocator_type;
	typedef typename Allocator::size_type		size_type;
	typedef RBSize< size_type >					Size_type;
	typedef ft::iterator<
			ft::bidirectional_iterator_tag,
			value_type >						iterator_type;
private:
	/* Member objects */
	node_pointer								root;
	compare_type								compare;
	Size_type									size;
public:
	allocator_type								allocator;

	/* Constructor & destructor */
	
	RBTree() : root(NULL) {}
	
	~RBTree() {
		while (size.size)
			deleteNode(findMinNode(root)->value);
	}
	
	class iterator : public iterator_type {
	private:
		iterator_type							value;
		node_pointer							node;

	public:

		iterator() : value(NULL), node(NULL) {}
		
		iterator( const value_type& value, const node_pointer& node )
		:
			value(value),
			node(node)
		{}

		iterator(const iterator_type& other)
		:
			value(other.value),
			node(other.node)
		{}
		
		iterator_type& operator=( const iterator_type& other ) {
			if (*this != other) {
				value = other.value;
				node = findNode(value);
			}
			return ( *this );
		}
				
		~iterator() {}

		iterator_type& operator*() const { return *value; }
		
		iterator_type& operator->() const { return value; }

		iterator_type& operator++(void) const {
			node = findNextNode(node);
			value = node->value;
			return ( *this );
		}
		
		iterator_type& operator++(int) const {
			iterator_type tmp = value;
			++(*this);
			return ( tmp );
		}
		
		iterator_type& operator--(void) const {
			node = findPreviousNode(node);
			value = node->value;
			return ( *this );
		}
		
		iterator_type& operator--(int) const {
			iterator_type tmp = value;
			--(*this);
			return ( tmp );
		}
		
		
	}; /* class iterator_node end */

	iterator_type& begin() {
		node_pointer node = findMinNode(root);
		value_type value = node->value;
		return iterator(value, node);
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
		
	void			insertNode(const value_type& value) {
		if (root != NULL) {
			bool child = RIGHT;
			node_pointer node = root, parent = NULL;
			while (node != NULL) {
				if ( !compare(value, node->value) && !compare(node->value, value) )
					return ;
				parent = node;
				child = (compare(value, node->value) ? LEFT : RIGHT);
				node = (child == LEFT ? node->left : node->right);
			}
			node = allocator.allocate(1);
			allocator.construct(node, node_type(value, RED, parent));
			child == LEFT ? parent->left = node : parent->right = node;
			size.size++;
			insertCase1(node);
		} else {
			root = allocator.allocate(1);
			allocator.construct(root, node_type(value, BLACK));
			size.size++;
		}
	}
		
	void			deleteNode(const value_type& value) {
		node_pointer node;
		node_pointer rm_node;
		if ( (node = findNode(value) ) != NULL) {
			if (node->left != NULL) {
				rm_node = findMaxNode(node->left);
				node->value = rm_node->value;
				deleteOneChild(rm_node);
			} else if (node->right != NULL) {
				rm_node = findMinNode(node->right);
				node->value = rm_node->value;
				deleteOneChild(rm_node);
			} else
				deleteOneChild(node);
		}
	}
	
	node_pointer	findNode(const value_type value) {
		node_pointer node = root;
		while (node != NULL) {
			if ( !compare(value, node->value) && !compare(node->value, value) )
				break ;
			else if ( compare(value, node->value) )
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
