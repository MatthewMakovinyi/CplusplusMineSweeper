#include <vector>
#ifndef VECTORTWOD_H
#define VECTORTWOD_H
class vector_2d
{
	public:
		std::vector<int> vector_two_dimensional;
		int width;
		int height;
		vector_2d(int width, int height, int defaul_value);
		int get_value_at_index(int row, int column);
		void modify_value_at_index(int row, int column, int value);
};
#endif

