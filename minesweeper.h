#include "equalsidedsquarearea.h"
#ifndef MINESWEEPER_H
#define MINESWEEPER_H
class minesweeper
{
	public:
		minesweeper(int width, int height, int mineamount);
		minesweeper();
		~minesweeper();
		void showmines();
		void shownumbers();
		void showall();
		void revealpoint(coord2 revealPoint);
		void generateMines(coord2 startingPoint);
		void revealareaaroundnumwithenoughmineflag(coord2 revealpoint);
		void generateAmountOfMines();
		int* field;
		int* amountofminesinneighbours;
		int* revealedarea;
		int* flags;
		int width;
		int height;
		int mineamount;
		int addThreeByThreeArea(int row, int column);
		equalsidedsquarearea area3x3;
		
};
#endif

