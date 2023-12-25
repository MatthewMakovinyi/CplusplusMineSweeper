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
int vector_2d::get_value_at_index(int row, int column)
{
	return vector_two_dimensional[row*width + column];
}
void vector_2d::modify_value_at_index(int row, int column, int value)
{
	vector_two_dimensional[row * width + column] = value;
}