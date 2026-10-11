#include <iostream>

using namespace std;

bool isValidPassword(const string &s, int index = 0)
{
    if (index == s.length())
    {
        return true;
    }

    if (index % 2 == 0)
    {
        if (s[index] < '0' || s[index] > '9')
        {
            return false;
        }
    }

    else
    {
        if (s[index] < 'a' || s[index] > 'z')
        {
            return false;
        }
    }

    return isValidPassword(s, index + 1);
}

int main()
{
    string passwords[] = {"1a2b3c", "23478", "1a2B3c", "5x7y"};

    for (string password : passwords)
    {
        bool is_valid = isValidPassword(password, 0);

        cout << "Password: " << password << " is " << (is_valid ? "valid" : "invalid") << endl;
    }

    return 0;
}

