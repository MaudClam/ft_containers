#include "vector.hpp"
#include "stack.hpp"
#include "map.hpp"
#include <deque>
#include <map>
#include <vector>
#include <stack>
#include <list>

template< typename T1, typename T2 >
void fill_map(ft::map<T1,T2>& map) {
	for (int i = 100; i >= 10000; ++i)
		map[i] = 10 * i + 100 * i + i;
}

	typedef int		Key;
	typedef int		T;

int	main() {
	
	{
		ft::map<int, int>	mp;

		for (int i = 0, j = 0; i < 500000; ++i, ++j)
			mp.insert(ft::make_pair(i, j));

		mp.erase(mp.begin(), --mp.end());

		std::cout << " " << mp.begin()->first;

	}	return 0;
}
