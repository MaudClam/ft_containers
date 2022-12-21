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


ft::pair<iterator, bool>
				insert( const value_type& value ) {
	node_pointer	node = findKey(value.first);
	bool			is_inserted = (node == NULL ? true : false);
	if ( is_inserted )
		try {
			node = insertPairAndNode(value.first, value.second);
		} catch (std::exception &e) {
			node = tree.findMax();
		}
	return (ft::make_pair(iterator(node), is_inserted));
}

iterator 		insert( iterator pos, const value_type& value ) {
	node_pointer node = findKey(value.first);
	if (node != NULL)
		return (iterator(node));
	if ( !compare(value, *pos) && !compare(*pos, value))
		return (pos);
	return ( insert(value).first );
}
