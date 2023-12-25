#include "vector_2d.h"

vector_2d::vector_2d(int width, int height, int default_value)
	:width(width), height(height)
{
	vector_two_dimensional = {};
	for (int i = 0; i < width * height; ++i)
	{
		vector_two_dimensional.push_back(default_value);
	}
}
int vector_2d::get_value(int row, int column)
{
	return vector_two_dimensional[row*width + column];
}
int & vector_2d::set_value(int row, int column)
{
	return vector_two_dimensional[(row*width) + column];
}