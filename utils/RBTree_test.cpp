/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:47:32 by mclam             #+#    #+#             */
/*   Updated: 2022/12/12 11:47:32 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <unistd.h>//	sleep(3);
#include "RBTree.hpp"
#include "pair.hpp"

# define START			1			/* Start key to be stored */
# define END			2500			/* End key to be stored */

template< typename T >
void fill_tree(ft::RBTree<T>& tree) {
	for (int i = END; i >= START; --i)
		tree.insertNode(i);
}

template< typename T >
void fill_tree_rand(ft::RBTree<T>& tree) {
	struct timespec ts;
	
	timespec_get(&ts, TIME_UTC);
	srand((unsigned int)ts.tv_nsec);
	for (int i = START; i <= END; ++i)
		tree.insertNode( START + rand() % (END - START + 1) );
}

template< typename T1, typename T2 >
void fill_tree_pair_rand(ft::RBTree<ft::pair<T1,T2> >& tree) {
	struct timespec ts;
	
	timespec_get(&ts, TIME_UTC);
	srand((unsigned int)ts.tv_nsec);
	for (int i = START; i <= END; ++i) {
		ft::pair<T1,T2> p(START + rand() % (END - START + 1), '*');
		tree.insertNode( p );
	}
}

template< typename T >
void	delete_tree_rand(ft::RBTree<T>& tree) {
	struct timespec ts;
	
	timespec_get(&ts, TIME_UTC);
	srand((unsigned int)ts.tv_nsec);
	for (int i = START; i <= END; ++i)
		tree.deleteNode( START + rand() % (END - START + 1) );
}

template< typename T1, typename T2 >
void	delete_tree_pair_rand(ft::RBTree<ft::pair<T1,T2> >& tree) {
	struct timespec ts;
	
	timespec_get(&ts, TIME_UTC);
	srand((unsigned int)ts.tv_nsec);
	for (int i = START; i <= END * 10; ++i) {
		ft::pair<T1,T2> p(START + rand() % (END / 10 - START + 1), '*');
		tree.deleteNode( p );
	}
}

int main(int, const char**)
{
	ft::RBTree<int> tree;
//	ft::RBTree<ft::pair<int, char> > tree;

	
//	ft::pair<int, char> p = ft::make_pair(1, '*');
//	tree.insertNode(p);
//	p = ft::make_pair(2, '|');
//	tree.insertNode(p);
//	p = ft::make_pair(3, '=');
//	tree.insertNode(p);

//	fill_tree(tree);
//	fill_tree_rand(tree);
//	fill_tree_pair_rand(tree);
//	delete_tree_rand(tree);
//	delete_tree_pair_rand(tree);

//	tree.deleteNode(p);
	tree.printTreeRecursively();
	tree.printTreeIteratively();

//	sleep(5);
	return 0;
}
