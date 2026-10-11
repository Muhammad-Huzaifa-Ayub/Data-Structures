#include <iostream>

using namespace std;

struct Pair
{
    int i;
    int j;
};

bool solve_maze(char maze1[6][6], Pair s, Pair d, int row, int col)
{
    if ( s.i == d.i && s.j == d.j )
    {
        return true;
    }

    if ( s.i < 0 || s.i >= row || s.j < 0 || s.j >= col )
    {
        return false;
    }

    if ( maze1[s.i][s.j] == '*' || maze1[s.i][s.j] == '3' )
    {
        return false;
    }

    maze1[s.i][s.j] = '3';

    Pair next;

    next = {s.i, s.j - 1};
    if ( solve_maze(maze1, next, d, row, col) )
    {
        return true;
    }

    next = {s.i, s.j + 1};
    if (solve_maze(maze1, next, d, row, col))
    {
        return true;
    }

    next = {s.i - 1, s.j};
    if (solve_maze(maze1, next, d, row, col))
    {
        return true;
    }

    next = {s.i + 1, s.j};
    if ( solve_maze(maze1, next, d, row, col) )
    {
        return true;
    }

    return false;
}

int main()
{
    char maze1[6][6] = {
        {' ', '*', ' ', '*', ' ', ' '},
        {' ', '*', ' ', '*', ' ', ' '},
        {'P', ' ', ' ', ' ', '*', ' '},
        {'*', ' ', '*', '*', '*', ' '},
        {' ', ' ', ' ', ' ', '*', 'T'},
        {'*', ' ', ' ', ' ', ' ', ' '}};

    Pair start = {2, 0};
    Pair dest = {4, 5};

    cout << "Maze 1" << endl;

    if ( solve_maze(maze1, start, dest, 6, 6) ) 
    {
        cout << "Solved" << endl;
    }
    else
    {
        cout << "UnSolved" << endl;
    }

    char maze2[6][6] = {
        {' ', '*', ' ', '*', ' ', ' '},
        {' ', '*', ' ', '*', ' ', ' '},
        {'P', ' ', ' ', ' ', '*', ' '},
        {'*', '*', '*', '*', '*', ' '},
        {' ', ' ', ' ', ' ', '*', 'T'},
        {'*', ' ', ' ', ' ', ' ', ' '}};

    cout << "Maze 2" << endl;

    if ( solve_maze(maze2, start, dest, 6, 6) )
    {
        cout << "Solved" << endl;
    }
    else
    {
        cout << "UnSolved" << endl;
    }

    return 0;
}



