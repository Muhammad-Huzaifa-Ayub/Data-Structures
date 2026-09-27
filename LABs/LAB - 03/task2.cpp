#include "Stack.h"

bool Form( Stack<char> s )
{
    int size = s.size();
    int len = size / 2;

    if ( size % 2 != 0 )
    {
        cout << "\nNot in ( a^n b^n ) form with size problem\n";
        return false;
    }
    for ( int i = 1; i <= len; i++ )
    {
        if ( s.pop() != 'b' )
        {
            return false;
        }
    }

    for ( int i = 1; i <= len; i++ )
    {
        if ( s.pop() != 'a' )
        {
            return false;
        }
    }

    return true;
}

int main()
{
    Stack<char> s(100);

    s.push('a');
    s.push('a');
    s.push('a');
    
    s.push('b');
    s.push('b');
    s.push('b');

    cout << Form(s) << endl;

    return 0;
}