#include <iostream>

using namespace std;

// string reverse(string s, int len)
// {
//     if (len == -1)
//     {
//         return "";
//     }

//     return s[len] + reverse(s, len - 1);
// }

int reverse( int n, int result = 0 )
{
    if ( n == 0 )
    {
        return result;
    }

    return reverse ( n / 10 , result * 10 + n % 10);
}

int main()
{
    int n = 56321;

    cout << "Reversed number: " << reverse(n) << endl;
    n = 89641;
    cout << "Reversed number: " << reverse(n) << endl;
    return 0;

    // int n = 56321;
    // string s = to_string(n);

    // cout << "Reversed number: " << reverse(s,s.size()-1) << endl;

    // n = 89641;
    // s = to_string(89641);
    // cout << "Reversed number: " << reverse(s,s.size()-1) << endl;

    return 0;
}


