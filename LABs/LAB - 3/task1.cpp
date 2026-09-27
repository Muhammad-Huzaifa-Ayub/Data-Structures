#include "Stack.h"

bool IsPalindrome(Stack<char> s, Stack<char> str)
{
    while (!s.isEmpty() && !str.isEmpty())
    {
        if (tolower(s.pop()) != tolower(str.pop()))
        {
            return false;
        }
    }

    return true;
}

int main()
{
    char input[100];

    cout << "Enter string: ";
    cin.getline(input, 100);

    Stack<char> s(100);

    for (int i = 0; input[i] != '\0'; i++)
    {
        if ( (input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= 'a' && input[i] <= 'z') || (input[i] >= '0' && input[i] <= '9') )
        {
            s.push(input[i]);
        }
    }

    Stack<char> str(s.size());
    str = s.reverse();

    if (IsPalindrome(s, str))
    {
        cout << "Palindrome" << endl;
    }
    else
    {
        cout << "Not a palindrome" << endl;
    }

    return 0;
}


