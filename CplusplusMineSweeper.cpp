#include <iostream>
#include <vector>
#include "minesweeper.h"
#include "equalsidedsquarearea.h"
#include "vector_2d.h"
#include <ctime>

using namespace std;

int main()
{    
    srand(time(NULL));
    while (true)
    {
        int width = 0;
        do
        {
            cout << "\nWidth: ";
            cin >> width;
        } while (width <= 4);
        int height = 0;
        do
        {
            cout << "\nHeight: ";
            cin >> height;
        } while (height <= 4);
        int amount_of_mines = 0;
        do
        {
            cout << "\nAmount of mines: ";
            cin >> amount_of_mines;
        } while (amount_of_mines < 16 || amount_of_mines > ((width*height)-9));

        minesweeper game_simulation(width, height, amount_of_mines);
        game_simulation.show_all();
        int x = 0;
        do
        {
            cout << "\nColumn: ";
            cin >> x;
        } while (x < 0 || x > width-1);
        int y = 0;
        do
        {
            cout << "\nRow: ";
            cin >> y;
        } while (y < 0 || y > height - 1);
        coord2 interaction_point(x, y);
        game_simulation.generate_mines(interaction_point);
        while (true)
        {
            
            game_simulation.show_all();
            int option_number = 0;
            do
            {
                cout << "\nReveal (1)\nFlag (2)\nReveal around number (3)\nReset (4)\n";
                cin >> option_number;
            } while (option_number < 1 || option_number > 4);

            if (option_number != 4)
            {            
                do
                {
                    cout << "\nColumn: ";
                    cin >> x;
                } while (x < 0 || x > width - 1);
                do
                {
                    cout << "\nRow: ";
                    cin >> y;
                } while (y < 0 || y > height - 1);
                interaction_point.x = x;
                interaction_point.y = y;
                if (option_number == 1)
                {
                    game_simulation.reveal_point(interaction_point);            
                }
                else if (option_number == 2)
                {
                    if (game_simulation.revealed_area.get_value(interaction_point.y, interaction_point.x) != 1)
                    {
                        game_simulation.make_tile_flag(interaction_point);                
                    }
                }
                else
                {
                    if (game_simulation.revealed_area.get_value(interaction_point.y, interaction_point.x) == 1 &&game_simulation.amount_of_mines_in_neighbours.get_value(interaction_point.y, interaction_point.x) != 0)
                    {
                        game_simulation.reveal_area_with_enough_flags(interaction_point);
                    }
                }
            }
            else
            {
                game_simulation.reset();
                width = 0;
                do
                {
                    cout << "\nWidth: ";
                    cin >> width;
                } while (width <= 4);
                height = 0;
                do
                {
                    cout << "\nHeight: ";
                    cin >> height;
                } while (height <= 4);
                amount_of_mines = 0;
                do
                {
                    cout << "\nAmount of mines: ";
                    cin >> amount_of_mines;
                } while (amount_of_mines < 16 || amount_of_mines >((width * height) - 9));
                game_simulation.~minesweeper();
                minesweeper game_simulation(width, height, amount_of_mines);
                game_simulation.show_all();
                x = 0;
                do
                {
                    cout << "\nColumn: ";
                    cin >> x;
                } while (x < 0 || x > width - 1);
                y = 0;
                do
                {
                    cout << "\nRow: ";
                    cin >> y;
                } while (y < 0 || y > height - 1);
                coord2 interaction_point(x, y);
                game_simulation.generate_mines(interaction_point);
            }
        }
    }
}


