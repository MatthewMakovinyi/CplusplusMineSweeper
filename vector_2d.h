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
		int get_value(int row, int column);
		int& set_value(int row, int column);
};
#endif

