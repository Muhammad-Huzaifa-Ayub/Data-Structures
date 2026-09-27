#include <iostream>

using namespace std;

void printND( int n )
{
    int j = 0;

    for ( int i = 1; i <= n; i++ )
    {
        cout << "I" << i;
        for ( j = i+1; j <= n; j++ )
        {
            cout << "U" << j;
        }
        if ( i != n )
        {
            cout << " + ";
        }
    }

}


int main()
{
    int n = 0;
    cout << "Enter N Dimension for Row-Major : ";
    cin >> n;

    printND(n);

    return 0;
}