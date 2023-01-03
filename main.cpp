#include "vector.hpp"
#include <vector>
#include <ctime>

int	main() {
	{
		std::vector<int>		vct;
		ft::vector<int> 	vct_two;
		
		
		for (int i = 1; i < 12; ++i) {
			vct.assign(i, 1);
			vct_two.assign(i, 1);
			std::cout << " " << vct.size();
			std::cout << " " << vct.capacity();
			std::cout << " " << vct_two.size();
			std::cout << " " << vct_two.capacity() << std::endl;
		}
		for (int i = 1; i < 20; ++i) {
			vct.assign(i, 1);
			vct_two.assign(i, 1);
			std::cout << " " << vct.size();
			std::cout << " " << vct.capacity();
			std::cout << " " << vct_two.size();
			std::cout << " " << vct_two.capacity() << std::endl;
		}
	}
	return 0;
}
