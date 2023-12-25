#include "minesweeper.h"
#include <iostream>
minesweeper::minesweeper(int width, int height,int mine_amount)
	: height(height), width(width), field(width,height,0),mine_amount(mine_amount), area_3x3(3), amount_of_mines_in_neighbours(width,height,0),revealed_area(width,height,0), flags(width,height,0)
{
}
minesweeper::minesweeper()
	: height(0), width(0), field(0,0,0), mine_amount(0), area_3x3(3), amount_of_mines_in_neighbours(0,0,0), revealed_area(0,0,0), flags(0,0,0)
{
}
minesweeper::~minesweeper()
{
}
void minesweeper::show_mines()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; ++j)
		{
			std::cout << " " << field.get_value_at_index(i,j);
		}
		std::cout << "\n";
	}
}
void minesweeper::show_numbers()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; ++j)
		{
			std::cout <<" " << amount_of_mines_in_neighbours.get_value_at_index(i,j);
		}
		std::cout << "\n";
	}
}
void minesweeper::show_all()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; ++j)
		{
			if (revealed_area.get_value_at_index(i,j) == 0)
			{
				std::cout << " /";
			}
			else
			{
				if (amount_of_mines_in_neighbours.get_value_at_index(i,j) > 8)
				{
					if (amount_of_mines_in_neighbours.get_value_at_index(i,j) == 9)
					{
						std::cout << " *";
					}
				}
				else
				{
					std::cout << " " << amount_of_mines_in_neighbours.get_value_at_index(i,j);
				}
							
			}
		}
		std::cout << "\n";
	}
}
void minesweeper::generate_mines(coord2 starting_point)
{
	int count = 0;
	int last_mine_placed = 0;
	while (count != mine_amount)
	{
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; ++j)
			{
				
				if (j < starting_point.x + 2 && j > starting_point.x - 2 && i < starting_point.y + 2 && i > starting_point.y - 2)
				{
					continue;
				}
				if (field.get_value_at_index(i,j) == 1)
				{
					continue;
				}				
				else
				{
					if (last_mine_placed == 0)
					{
						if (rand() % 100 > 80)
						{
							field.modify_value_at_index( i,j,1);
							count += 1;
							last_mine_placed = 10;
						}
					}
					else

					{
						--last_mine_placed;
					}
					
				}

				if (count == mine_amount)
				{
					break;
				}
			}
			if (count == mine_amount)
			{
				break;
			}
		}
	}
	generate_amount_of_mines();
	reveal_point(starting_point);
}
void minesweeper::reveal_point(coord2 reveal_point)
{
	
	if (flags.get_value_at_index(reveal_point.y, reveal_point.x) == 0)
	{
		
		revealed_area.modify_value_at_index(reveal_point.y, reveal_point.x, 1);
		
		if (amount_of_mines_in_neighbours.get_value_at_index(reveal_point.y, reveal_point.x) == 0)
		{
			int count = -1;
			while (0 != count)
			{
				count = 0;
				for (int i = 0; i < height; ++i)
				{
					for (int j = 0; j < width; ++j)
					{
						
						if (amount_of_mines_in_neighbours.get_value_at_index(i, j) == 0 && revealed_area.get_value_at_index(i, j) == 0)
						{

							if (i - 1 >= 0)
							{
								
								if (revealed_area.get_value_at_index(i - 1, j) == 1)
								{									
									revealed_area.modify_value_at_index(i, j, 1);
									count += 1;
									continue;
								}
								if (j - 1 >= 0)
								{
									
									if (revealed_area.get_value_at_index(i - 1, j - 1) == 1)
									{
										revealed_area.modify_value_at_index(i, j, 1);
										count += 1;
										continue;
									}
								}
								if (j + 1 < width)
								{
									if (revealed_area.get_value_at_index(i - 1, j + 1) == 1)
									{
										revealed_area.modify_value_at_index(i, j, 1);
										count += 1;
										continue;
									}
								}
							}
							if (i + 1 < height)
							{
								if (revealed_area.get_value_at_index(i + 1, j) == 1)
								{
									revealed_area.modify_value_at_index(i, j, 1);
									count += 1;
									continue;
								}
								if (j - 1 >= 0)
								{
									if (revealed_area.get_value_at_index(i + 1, j - 1) == 1)
									{
										revealed_area.modify_value_at_index(i, j, 1);
										count += 1;
										continue;
									}
								}
								if (j + 1 < width)
								{
									if (revealed_area.get_value_at_index(i + 1, j + 1) == 1)
									{
										revealed_area.modify_value_at_index(i, j, 1);
										count += 1;
										continue;
									}
								}
							}
							if (j - 1 >= 0)
							{
								if (revealed_area.get_value_at_index(i, j - 1) == 1)
								{
									revealed_area.modify_value_at_index(i, j, 1);
									count += 1;
									continue;
								}
							}
							if (j + 1 < width)
							{
								if (revealed_area.get_value_at_index(i, j + 1) == 1)
								{
									revealed_area.modify_value_at_index(i, j, 1);
									count += 1;
									continue;
								}
							}
						}
					}
				}
			}
			for (int i = 0; i < height; ++i)
			{
				for (int j = 0; j < width; ++j)
				{
					
					if (amount_of_mines_in_neighbours.get_value_at_index(i, j) != 0 && revealed_area.get_value_at_index(i, j) == 0)
					{

						if (i - 1 >= 0)
						{
							
							if (revealed_area.get_value_at_index(i - 1, j) == 1 && amount_of_mines_in_neighbours.get_value_at_index(i - 1, j) == 0)
							{
								revealed_area.modify_value_at_index(i, j, 1);
								continue;
							}
							if (j - 1 >= 0)
							{
								if (revealed_area.get_value_at_index(i - 1, j - 1) == 1 && amount_of_mines_in_neighbours.get_value_at_index(i - 1, j - 1) == 0)
								{
									revealed_area.modify_value_at_index(i, j, 1);
									continue;
								}
							}
							if (j + 1 < width)
							{
								if (revealed_area.get_value_at_index(i - 1, j + 1) == 1 && amount_of_mines_in_neighbours.get_value_at_index(i - 1, j + 1) == 0)
								{
									revealed_area.modify_value_at_index(i, j, 1);
									continue;
								}
							}
						}
						if (i + 1 < height)
						{
							if (revealed_area.get_value_at_index(i + 1, j) == 1 && amount_of_mines_in_neighbours.get_value_at_index(i + 1, j) == 0)
							{
								revealed_area.modify_value_at_index(i, j, 1);
								continue;
							}
							if (j - 1 >= 0)
							{
								if (revealed_area.get_value_at_index(i + 1, j - 1) == 1 && amount_of_mines_in_neighbours.get_value_at_index(i + 1, j - 1) == 0)
								{
									revealed_area.modify_value_at_index(i, j, 1);
									continue;
								}
							}
							if (j + 1 < width)
							{
								if (revealed_area.get_value_at_index(i + 1, j + 1) == 1 && amount_of_mines_in_neighbours.get_value_at_index(i + 1, j + 1) == 0)
								{
									revealed_area.modify_value_at_index(i, j, 1);
									continue;
								}
							}
						}
						if (j - 1 >= 0)
						{
							if (revealed_area.get_value_at_index(i, j - 1) == 1 && amount_of_mines_in_neighbours.get_value_at_index(i, j - 1) == 0)
							{
								revealed_area.modify_value_at_index(i, j, 1);
								continue;
							}
						}
						if (j + 1 < width)
						{
							if (revealed_area.get_value_at_index(i, j + 1) == 1 && amount_of_mines_in_neighbours.get_value_at_index(i, j + 1) == 0)
							{
								revealed_area.modify_value_at_index(i, j, 1);
								continue;
							}
						}
					}
				}
			}
		}
	}		
}
void minesweeper::reveal_area_around_num_with_enough_mine_flag(coord2 reveal_point)
{
	bool doesithaveenoughflags = false;
	int beginning_x = 0;
	int end_x = 2;
	if (reveal_point.x != 0)
	{
		beginning_x = reveal_point.x-1;
		if (reveal_point.x != width - 1)
		{
			end_x = reveal_point.x + 1;
		}
		else
		{
			end_x = width;
		}
	}
	int beginning_y = 0;
	int end_y = 2;
	if (reveal_point.y != 0)
	{
		beginning_y = reveal_point.y - 1;
		if (reveal_point.y != height - 1)
		{
			end_y = reveal_point.y + 1;
		}
		else
		{
			end_y = height;
		}
	}
	int count = 0;
	for (int i = beginning_y; i < end_y; ++i)
	{
		for (int j = beginning_x; j < end_x; ++j)
		{
			
			if (flags.get_value_at_index(i, j) == 1)
			{
				++count;
			}
		}
	}
	
	if (count == amount_of_mines_in_neighbours.get_value_at_index(reveal_point.y, reveal_point.x));
	{
		for (int i = beginning_y; i < end_y; ++i)
		{
			for (int j = beginning_x; j < end_x; ++j)
			{
				
				if (flags.get_value_at_index(i, j) == 0 && revealed_area.get_value_at_index(i, j) == 0)
				{
					revealed_area.modify_value_at_index(i, j, 1);
				}
			}
		}
	}
}
int minesweeper::add_three_by_three_area(int row, int column)
{
	int length_from_center = ((minesweeper::area_3x3.side_length - 1) / 2);
	int beginning_x = column - length_from_center;
	int beginning_y = row - length_from_center;
	int end_x = column + length_from_center;
	int end_y = row + length_from_center;
	int sum = 0;
	for (int i = beginning_y; i < end_y + 1; ++i)
	{
		if (i < 0 || i > height-1)
		{
			continue;
		}
		for (int j = beginning_x; j < end_x + 1; ++j)
		{
			if (j < 0 || j > width-1)
			{
				continue;
			}
			//std::cout << "\n" << row << " " << column << ": " << i <<" " << j <<" "  << sum << "\n";
			
			sum += field.get_value_at_index(i, j);
		}

	}
	return sum;
}

void minesweeper::make_tile_flag(coord2 flag_point)
{
	
	if (revealed_area.get_value_at_index(flag_point.y, flag_point.x) == 0)
	{
		flags.modify_value_at_index(flag_point.y, flag_point.x, 1);
	}
}

void minesweeper::generate_amount_of_mines()
{
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			
			if (field.get_value_at_index(i, j) == 1)
			{
				amount_of_mines_in_neighbours.modify_value_at_index(i, j, 9);
				continue;
			}
			amount_of_mines_in_neighbours.modify_value_at_index(i, j, add_three_by_three_area(i, j));
		}
	}
}