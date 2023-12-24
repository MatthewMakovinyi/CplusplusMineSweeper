#include <iostream>
#include <vector>
#include "minesweeper.h"
#include "equalsidedsquarearea.h"
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
        coord2 reveal_point(x, y);
        game_simulation.generate_mines(reveal_point);
        while (true)
        {
            
            game_simulation.show_all();
            do
            {
                cout << "\nColumn: ";
                cin >> x;
            } while (x < 0 || x > width - 1);
            int y = 0;
            do
            {
                cout << "\nRow: ";
                cin >> y;
            } while (y < 0 || y > height - 1);
            reveal_point.x = x;
            reveal_point.y = y;
            game_simulation.reveal_point(reveal_point);
        }
    }
}


