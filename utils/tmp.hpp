//
//  tmp.hpp
//  ft_containers
//
//  Created by uru on 2022-12-21.
//

#ifndef tmp_hpp
#define tmp_hpp

#include <stdio.h>

#endif /* tmp_hpp */


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
