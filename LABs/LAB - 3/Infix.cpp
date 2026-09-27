#include "Stack.h"

int precedence( char ch )
{
    if ( ch == '^' )
    {
        return 3;
    }
    else if ( ch == '*' || ch == '/' )
    {
        return 2;
    }
    else if ( ch == '+' || ch == '-' )
    {
        return 1;
    } 
    else
    {
        return 0;
    }
}

bool IsOperator( char ch )
{
    return ch == '*' || ch == '+' || ch == '/' || ch == '-' || ch == '^';
}

bool isOpening(char ch)
{
    return ch == '(' || ch == '[' || ch == '{';
}

bool isClosing(char ch)
{
    return ch == ')' || ch == ']' || ch == '}';
}

bool isMatching(char open, char close)
{
    return (open == '(' && close == ')') || (open == '[' && close == ']') || (open == '{' && close == '}');
}


void Infix_to_Postfix(string s, int size)
{
    Stack<char> st(size);
    string output = "";

    for (int i = 0; i < size; i++)
    {
        if (isalpha(s[i]))
        {
            output += s[i];
        }
        else if (isOpening(s[i]))
        {
            st.push(s[i]);
        }
        else if (isClosing(s[i]))
        {
            while (!st.isEmpty() && !isOpening(st.peek()))
            {
                output += st.peek();
                st.pop();
            }

            if (!st.isEmpty())
                st.pop();
        }
        else if (IsOperator(s[i]))
        {
            while (!st.isEmpty() && !isOpening(st.peek()) && precedence(st.peek()) >= precedence(s[i]))
            {
                output += st.peek();
                st.pop();
            }

            st.push(s[i]);
        }
    }

    while (!st.isEmpty())
    {
        output += st.peek();
        st.pop();
    }

    cout << "Postfix: " << output << endl;
}

string Infix_to_Prefix(string s, int size)
{
    Stack<char> st(size);
    string output = "";

    for (int i = size - 1; i >= 0; i--)
    {
        if (isalpha(s[i]))
        {
            output += s[i];
        }
        else if (isClosing(s[i]))
        {
            st.push(s[i]);
        }
        else if (isOpening(s[i]))
        {
            while (!st.isEmpty() && !isClosing(st.peek()))
            {
                output += st.peek();
                st.pop();
            }

            if (!st.isEmpty())
                st.pop();
        }
        else if (IsOperator(s[i]))
        {
            while (!st.isEmpty() && !isClosing(st.peek()) && precedence(st.peek()) > precedence(s[i]))
            {
                output += st.peek();
                st.pop();
            }

            st.push(s[i]);
        }
    }

    while (!st.isEmpty())
    {
        output += st.peek();
        st.pop();
    }

    string prefix = "";

    for (int i = output.size() - 1; i >= 0; i--)
    {
        prefix += output[i];
    }

    return prefix;
}

int main()
{
    string s = "A+B*(C-D/E)^(F+G*H)-I";
    int size = s.size();

    Infix_to_Postfix(s,size);

    return 0;
}