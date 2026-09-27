#include "Stack.h"

int getSize( char str[] )
{
    int i = 0;

    while ( str[i] != '\0' )
    {
        i++;
    }

    return i;
}

void AddingLargeNumbers(char n1[], char n2[], char res[])
{
    int size1 = getSize(n1);
    int size2 = getSize(n2);

    Stack<char> num1(size1);
    Stack<char> num2(size2);
    Stack<char> result(size1 + size2 + 1);

    for ( int i = 0; i < size1; i++ )
    {
        num1.push(n1[i]);
    }

    for ( int i = 0; i < size2; i++ )
    {
        num2.push(n2[i]);
    }

    int carry = 0;

    while ( !num1.isEmpty() || !num2.isEmpty() || carry != 0 )
    {
        short int digit1 = 0;
        short int digit2 = 0;

        if (!num1.isEmpty())
        {
            digit1 = num1.pop() - 48;
        }

        if (!num2.isEmpty())
        {
            digit2 = num2.pop() - 48;
        }

        short int sum = digit1 + digit2 + carry;

        carry = sum / 10;

        short int digit = sum % 10;

        result.push( digit + 48 );
    }

    int i = 0;

    while (!result.isEmpty())
    {
        res[i] = result.pop();
        i++;
    }

    res[i] = '\0';
}

int main()
{
    char n1[26], n2[26], result[26];

    cout << "Enter num1 : ";
    cin >> n1;

    cout << "Enter num2 : ";
    cin >> n2;

    AddingLargeNumbers(n1, n2, result);

    int i = 0;

    while (result[i] != '\0')
    {
        cout << result[i];
        i++;
    }

    return 0;
}