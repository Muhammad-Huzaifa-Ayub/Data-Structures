#include "Stack.h"

int main()
{
    Stack<string> page(100);
    Stack<string> history(100);

    string p;
    int op = 0;

    while ( true )
    {
        cout << "\n\n   --- Welcome to Browser ---    \n1. Visit Page \n2. Go Back \n3. Display History \n4. Exit\n   Enter option : ";
        cin >> op;
        if ( op == 1 )
        {
            cout << "\nEnter page : ";
            cin >> p;
            page.push(p);
        }
        else if ( op == 2 )
        {
            if ( page.isEmpty() )
            {
                cout << "\nNo Browser History!\n";
            }
            else
            {
                cout << "\nGoing back to : " << page.pop() << "\n";
            }
        }
        else if ( op == 3 )
        {
            if ( page.isEmpty() )
            {
                cout << "\nNo Browser History !\n";
                continue;
            }
            cout << "\nBrowser History : \n\n";
            history = page;
            while ( !history.isEmpty() )
            {
                cout << history.pop() << "\n";
            }
        }
        else if ( op == 4 )
        {
            cout << "\nExiting browser ...\n";
            break;
        }
        else
        {
            cout << "\nInValid Choice\n";
            continue;
        }
    }

    return 0;
}

