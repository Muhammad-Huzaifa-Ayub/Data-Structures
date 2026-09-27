#include "Stack.h"

const int r = 5;
const int c = 5;

struct p {

     int i;
     int j;
};

void findpath ( int arr[][c], int r, int c, p s , p d )
{
     Stack<p> st(r*c);
     st.push(s);

     while ( !st.isEmpty() )
     {
          p cur = st.peek();

          if ( cur.i == d.i && cur.j == d.j )
          {
               cout << "\n\nPath has been Found : ";
               Stack<p> n (r * c);
               n = st.reverse();

               while (!st.isEmpty())
               {
                    p path = n.peek();
                    cout << "(" << path.i << "," << path.j << ") ";
                    n.pop();
               }

               return;
          }
          else if ( cur.j - 1 >= 0 && arr [cur.i][cur.j - 1] == 0 )
          {
               arr[cur.i][cur.j] = 3;
               cur.j = cur.j - 1;
               st.push(cur);
          }
          else if ( cur.j + 1 < c && arr[cur.i][cur.j + 1] == 0 )
          {
               arr[cur.i][cur.j] = 3;
               cur.j = cur.j + 1;
               st.push(cur);
          }
          else if ( cur.i - 1 >= 0 && arr [cur.i - 1][cur.j] == 0 )
          {
               arr[cur.i][cur.j] = 3;
               cur.i = cur.i - 1;
               st.push(cur);
          }
          else if ( cur.i + 1 < r && arr[cur.i + 1][cur.j] == 0 )
          {
               arr[cur.i][cur.j] = 3;
               cur.i = cur.i + 1;
               st.push(cur);
          }
          else
          {
               arr[cur.i][cur.j] = 3;
               st.pop();
          }
     }

     cout << "\nNo Path Found\n";
}


int main()
{
     int arr[r][c] = {{0, 0, 0, 0, 0}, {1, 0, 1, 1, 1}, {0, 0, 0, 0, 0}, {0, 0, 1, 0, 0}, {0, 1, 1, 0, 0}}; // possible 
     //int arr[r][c] = {{0, 0, 0, 0, 0}, {1, 1, 1, 1, 1}, {0, 0, 0, 0, 0}, {0, 0, 1, 0, 0}, {0, 1, 1, 0, 0}}; // not possible

     cout << "\n\nMaze is : \n";
     for ( int i = 0; i < 5; i++ )
     {
          for ( int j = 0; j < 5; j++ )
          {
               cout << arr[i][j] << " ";
          }
          cout << "\n";
     }

     p s,d;

     s.i = 0;
     s.j = 0;
     d.i = 3;
     d.j = 3;


     findpath(arr, r, c, s, d);

     return 0;
}