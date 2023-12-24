#include "minesweeper.h"
#include <iostream>
minesweeper::minesweeper(int width, int height,int mineamount)
	: height(height), width(width), field(new int[height * width]),mineamount(mineamount), area3x3(3), amountofminesinneighbours(new int[height * width]),revealedarea(new int[height * width]), flags(new int[height*width])
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; ++j)
		{
			field[(i * width) + j] = 0;
			amountofminesinneighbours[(i * width) + j] = 0;
			revealedarea[(i * width) + j] = 0;
			flags[(i * width) + j] = 0;
		}
	}
}
minesweeper::minesweeper()
	: height(0), width(0), field(new int[0]), mineamount(0), area3x3(3), amountofminesinneighbours(new int[0]), revealedarea(new int[0]), flags(new int[0])
{
}
minesweeper::~minesweeper()
{
	delete[] field;
	delete[] amountofminesinneighbours;
	delete[] revealedarea;
}
void minesweeper::showmines()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; ++j)
		{
			std::cout << " " << field[(i*width) + j];
		}
		std::cout << std::endl;
	}
}
void minesweeper::shownumbers()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; ++j)
		{
			std::cout <<" " << amountofminesinneighbours[(i * width) + j];
		}
		std::cout << std::endl;
	}
}
void minesweeper::showall()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; ++j)
		{
			if (*(revealedarea+(i*width)+j) == 0)
			{
				std::cout << " /";
			}
			else
			{
				if (amountofminesinneighbours[(i * width) + j] > 8)
				{
					if (amountofminesinneighbours[(i * width) + j] == 9)
					{
						std::cout << " *";
					}
				}
				else
				{
					std::cout << " " << amountofminesinneighbours[(i * width) + j];
				}
							
			}
		}
		std::cout << std::endl;
	}
}
void minesweeper::generateMines(coord2 startingPoint)
{
	int count = 0;
	int lastMinePlaced = 0;
	while (count != mineamount)
	{
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; ++j)
			{
				
				if (j < startingPoint.x + 2 && j > startingPoint.x - 2 && i < startingPoint.y + 2 && i > startingPoint.y - 2)
				{
					continue;
				}
				if (field[(i * width) + j] == 1)
				{
					continue;
				}				
				else
				{
					if (lastMinePlaced == 0)
					{
						if (rand() % 100 > 80)
						{
							field[(i * width) + j] = 1;
							count += 1;
							lastMinePlaced = 10;
						}
					}
					else

					{
						--lastMinePlaced;
					}
					
				}

				if (count == mineamount)
				{
					break;
				}
			}
			if (count == mineamount)
			{
				break;
			}
		}
	}
	generateAmountOfMines();
	revealpoint(startingPoint);
}
void minesweeper::revealpoint(coord2 revealPoint)
{
	*(revealedarea + (revealPoint.y * width) + revealPoint.x) = 1;	
	if (*(amountofminesinneighbours + (revealPoint.y * width) + revealPoint.x) == 0)
	{
		int count = -1;
		while (0 != count)
		{
			count = 0;
			for (int i = 0; i < height; ++i)
			{
				for (int j = 0; j < width; ++j)
				{
					if (*(amountofminesinneighbours+(i * width + j)) == 0 && *(revealedarea + (width * i) + j) == 0)
					{
						
						if (i - 1 >= 0)
						{
							if (*(revealedarea + (width * (i-1)) + j) == 1)
							{
								*(revealedarea + (width * i) + j) = 1;
								count += 1;
								continue;
							}	
							if (j - 1 >= 0)
							{
								if (*(revealedarea + (width * (i - 1)) + j - 1) == 1)
								{
									*(revealedarea + (width * i) + j) = 1;
									count += 1;
									continue;
								}
							}
							if (j + 1 < width)
							{
								if (*(revealedarea + (width * (i - 1)) + j + 1) == 1)
								{
									*(revealedarea + (width * i) + j) = 1;
									count += 1;
									continue;
								}
							}
						}
						if (i + 1 < height)
						{
							if (*(revealedarea + (width * (i + 1)) + j) == 1)
							{
								*(revealedarea + (width * i) + j) = 1;
								count += 1;
								continue;
							}
							if (j - 1 >= 0)
							{
								if (*(revealedarea + (width * (i + 1)) + j - 1) == 1)
								{
									*(revealedarea + (width * i) + j) = 1;
									count += 1;
									continue;
								}
							}
							if (j + 1 < width)
							{
								if (*(revealedarea + (width * (i + 1)) + j + 1) == 1)
								{
									*(revealedarea + (width * i) + j) = 1;
									count += 1;
									continue;
								}
							}
						}
						if (j - 1 >= 0)
						{
							if (*(revealedarea + (width * i) + j - 1) == 1)
							{
								*(revealedarea + (width * i) + j) = 1;
								count += 1;
								continue;
							}
						}
						if (j + 1 < width)
						{
							if (*(revealedarea + (width * i) + j + 1) == 1)
							{
								*(revealedarea + (width * i) + j) = 1;
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
				if (*(amountofminesinneighbours + (i * width + j)) != 0 && *(revealedarea + (width * i) + j) == 0)
				{

					if (i - 1 >= 0)
					{
						if (*(revealedarea + (width * (i - 1)) + j) == 1 && *(amountofminesinneighbours + (width * (i - 1)) + j) == 0)
						{
							*(revealedarea + (width * i) + j) = 1;
							continue;
						}
						if (j - 1 >= 0)
						{
							if (*(revealedarea + (width * (i - 1)) + j - 1) == 1 && *(amountofminesinneighbours + (width * (i - 1)) + j - 1) == 0)
							{
								*(revealedarea + (width * i) + j) = 1;
								continue;
							}
						}
						if (j + 1 < width)
						{
							if (*(revealedarea + (width * (i - 1)) + j + 1) == 1 && *(amountofminesinneighbours + (width * (i - 1)) + j + 1) == 0)
							{
								*(revealedarea + (width * i) + j) = 1;
								continue;
							}
						}
					}
					if (i + 1 < height)
					{
						if (*(revealedarea + (width * (i + 1)) + j) == 1 && *(amountofminesinneighbours + (width * (i + 1)) + j) == 0)
						{
							*(revealedarea + (width * i) + j) = 1;
							continue;
						}
						if (j - 1 >= 0)
						{
							if (*(revealedarea + (width * (i + 1)) + j - 1) == 1 && *(amountofminesinneighbours + (width * (i + 1)) + j - 1) == 0)
							{
								*(revealedarea + (width * i) + j) = 1;
								continue;
							}
						}
						if (j + 1 < width)
						{
							if (*(revealedarea + (width * (i + 1)) + j + 1) == 1 && *(amountofminesinneighbours + (width * (i + 1)) + j + 1) == 0)
							{
								*(revealedarea + (width * i) + j) = 1;
								continue;
							}
						}
					}
					if (j - 1 >= 0)
					{
						if (*(revealedarea + (width * i) + j - 1) == 1 && *(amountofminesinneighbours + (width * i) + j - 1) == 0)
						{
							*(revealedarea + (width * i) + j) = 1;
							continue;
						}
					}
					if (j + 1 < width)
					{
						if (*(revealedarea + (width * i) + j + 1) == 1 && *(amountofminesinneighbours + (width * i) + j + 1) == 0)
						{
							*(revealedarea + (width * i) + j) = 1;
							continue;
						}
					}
				}
			}
		}
	}
	
}
void minesweeper::revealareaaroundnumwithenoughmineflag(coord2 revealpoint)
{
	bool doesithaveenoughflags = false;
	int beginningX = 0;
	int endX = 2;
	if (revealpoint.x != 0)
	{
		beginningX = revealpoint.x-1;
		if (revealpoint.x != width - 1)
		{
			endX = revealpoint.x + 1;
		}
		else
		{
			endX = width;
		}
	}
	int beginningY = 0;
	int endY = 2;
	if (revealpoint.y != 0)
	{
		beginningY = revealpoint.y - 1;
		if (revealpoint.y != height - 1)
		{
			endY = revealpoint.y + 1;
		}
		else
		{
			endY = height;
		}
	}
	int count = 0;
	for (int i = beginningY; i < endY; ++i)
	{
		for (int j = beginningX; j < endX; ++j)
		{
			if (*(flags + (i * width) + j) == 1)
			{
				++count;
			}
		}
	}
	if (count == *(amountofminesinneighbours + (revealpoint.y) + revealpoint.x))
}
int minesweeper::addThreeByThreeArea(int row, int column)
{
	int lengthFromCenter = ((minesweeper::area3x3.sideLength - 1) / 2);
	int beginningX = column - lengthFromCenter;
	int beginningY = row - lengthFromCenter;
	int endX = column + lengthFromCenter;
	int endY = row + lengthFromCenter;
	int sum = 0;
	for (int i = beginningY; i < endY + 1; ++i)
	{
		if (i < 0 || i > height-1)
		{
			continue;
		}
		for (int j = beginningX; j < endX + 1; ++j)
		{
			if (j < 0 || j > width-1)
			{
				continue;
			}
			//std::cout << std::endl << row << " " << column << ": " << i <<" " << j <<" "  << sum << std::endl;
			sum += *(minesweeper::field + (i * width) + j);
		}

	}
	return sum;
}

void minesweeper::generateAmountOfMines()
{
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			if (*(minesweeper::field + (i * width) + j) == 1)
			{
				*(minesweeper::amountofminesinneighbours + (i * width) + j) = 9;
				continue;
			}
			*(minesweeper::amountofminesinneighbours + (i * width) + j) = addThreeByThreeArea(i, j);
		}
	}
}