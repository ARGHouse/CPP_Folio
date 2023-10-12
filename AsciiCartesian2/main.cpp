// AsciiCartesianGrid.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

class Grid
{

public:

    void initGrid()
    {

        for (int x = 0; x < 19; x++)
        {

            for (int y = 0; y < 19; y++)
            {

                p_grid[x][y] = '*';

            }

        }

    }

    void printGrid()
    {
        //y+
        p_grid[0][9] = '9';
        p_grid[1][9] = '8';
        p_grid[2][9] = '7';
        p_grid[3][9] = '6';
        p_grid[4][9] = '5';
        p_grid[5][9] = '4';
        p_grid[6][9] = '3';
        p_grid[7][9] = '2';
        p_grid[8][9] = '1';
        p_grid[9][9] = '0';

        //x+
        p_grid[9][18] = '9';
        p_grid[9][17] = '8';
        p_grid[9][16] = '7';
        p_grid[9][15] = '6';
        p_grid[9][14] = '5';
        p_grid[9][13] = '4';
        p_grid[9][12] = '3';
        p_grid[9][11] = '2';
        p_grid[9][10] = '1';

        for (int y = 0; y < 19; y++)
        {

            for (int x = 0; x < 19; x++)
            {



                cout << p_grid[y][x];

            }

            cout << endl;

        }

    }

private:

    char p_grid[19][19];

};

int main()
{

    Grid grid;
    grid.initGrid();
    grid.printGrid();

    system("PAUSE");
    return 0;

}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu