#include <iostream>

using namespace std;

void countSquares(int squareSize, int centerX, int centerY,int pointX, int pointY, int &totalSquares)
{
    // Check whether the point is inside or on the border
    // of the current square
    if (pointX >= centerX - squareSize &&
        pointX <= centerX + squareSize &&
        pointY >= centerY - squareSize &&
        pointY <= centerY + squareSize)
    {
        totalSquares++;
    }

    // Stop when the smallest square is reached
    if (squareSize <= 1)
    {
        return;
    }

    int childSquareSize = squareSize / 2;

    // Create a square at the top-left corner
    countSquares(childSquareSize,
                 centerX - squareSize, centerY - squareSize,
                 pointX, pointY, totalSquares);

    // Create a square at the top-right corner
    countSquares(childSquareSize,
                 centerX + squareSize, centerY - squareSize,
                 pointX, pointY, totalSquares);

    // Create a square at the bottom-left corner
    countSquares(childSquareSize,
                 centerX - squareSize, centerY + squareSize,
                 pointX, pointY, totalSquares);

    // Create a square at the bottom-right corner
    countSquares(childSquareSize,
                 centerX + squareSize, centerY + squareSize,
                 pointX, pointY, totalSquares);
}

int main()
{
    int largestSquareSize;
    int pointX, pointY;

    cin >> largestSquareSize >> pointX >> pointY;

    int totalSquares = 0;

    countSquares(largestSquareSize, 1024, 1024, pointX, pointY, totalSquares);

    cout << totalSquares << endl;

    return 0;
}