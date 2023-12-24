#include "equalsidedsquarearea.h"
#ifndef MINESWEEPER_H
#define MINESWEEPER_H
class minesweeper
{
	public:
		minesweeper(int width, int height, int mineamount);
		minesweeper();
		~minesweeper();
		void show_mines();
		void show_numbers();
		void show_all();
		void reveal_point(coord2 reveal_point);
		void generate_mines(coord2 starting_point);
		void reveal_area_around_num_with_enough_mine_flag(coord2 reveal_point);
		void generate_amount_of_mines();
		void make_tile_flag(coord2 flag_point);
		int* field;
		int* amount_of_mines_in_neighbours;
		int* revealed_area;
		int* flags;
		int width;
		int height;
		int mine_amount;
		int add_three_by_three_area(int row, int column);
		equal_sided_square_area area_3x3;
		
};
#endif

