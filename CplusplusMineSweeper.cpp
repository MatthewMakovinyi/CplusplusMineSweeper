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
            cout << endl << "Width: ";
            cin >> width;
        } while (width <= 4);
        int height = 0;
        do
        {
            cout << endl << "Height: ";
            cin >> height;
        } while (height <= 4);
        int amountofmines = 0;
        do
        {
            cout << endl << "Amount of mines: ";
            cin >> amountofmines;
        } while (amountofmines < 16 || amountofmines > ((width*height)-9));

        minesweeper test(width, height, amountofmines);
        int x = 0;
        do
        {
            cout << endl << "Column: ";
            cin >> x;
        } while (x < 0 || x > width-1);
        int y = 0;
        do
        {
            cout << endl << "Row: ";
            cin >> y;
        } while (y < 0 || y > height - 1);
        coord2 revealpoint(x, y);
        test.generateMines(revealpoint);
        while (true)
        {
            
            test.showall();
            do
            {
                cout << endl << "Column: ";
                cin >> x;
            } while (x < 0 || x > width - 1);
            int y = 0;
            do
            {
                cout << endl << "Row: ";
                cin >> y;
            } while (y < 0 || y > height - 1);
            revealpoint.x = x;
            revealpoint.y = y;
            test.revealpoint(revealpoint);
        }
    }
    
       
    
    string input = "";
    cin >> input;
}


