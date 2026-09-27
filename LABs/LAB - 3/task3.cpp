#include <iostream>
#include "Stack.h"

using namespace std;

bool IsValid(const string &s)
{
    Stack<char> str;
    Stack<char> operators;
    Stack<char> operands;

    for ( int i = 0; i < s.size(); i++ )
    {
        if (s[i] == '[' || s[i] == '{' || s[i] == '(')
        {
            str.push(s[i]);
        }
        else
        {
            if ( s[i] == '*' || s[i] == '/' || s[i] == '+' || s[i] == '-' || s[i] == '^' )
            {
                operators.push(s[i]);
            }
            else if ( (s[i]) >= '0' && s[i] <= '9' )
            {
                operands.push(s[i]);
            }
            else
            {
                if (str.isEmpty())
                {
                    return false;
                }
                if (s[i] == ']' && str.peek() == '[')
                {
                    str.pop();
                }
                else if (s[i] == '}' && str.peek() == '{')
                {
                    str.pop();
                }
                else if (s[i] == ')' && str.peek() == '(')
                {
                    str.pop();
                }
                else
                {
                    return false;
                }
            }
        }
    }
    if ( str.isEmpty() )
    {
        return true;
    }

    return false;
}

int main()
{
    string s = "(3+7*9})";
    //s = "[{(4)}]";
    cout << IsValid(s);

    return 0;
}