#include <iostream>

using namespace std;

class NDArray {

    private :

    int *dimension;
    int size;

    public :

    NDArray( int s , int dim[] )
    {
        int total = 1;

        for ( int i = 0; i < s; i++ )
        {
            total *= dim[i];
        }

        this->dimension = new int[total];
        dimension = dim;
        this->size = total;

    }

    int CalculateIndex ( int s, int index[] ) const
    {
        int position = 0;
        
        int multiplier = 1;

        for (int i = 0; i < s; i++)
        {
            position += index[i] * multiplier;

            multiplier *= dimension[i];
        }

        return position;
    }
    void SetValue ( const int v , int s ,int index[] )
    {
        int position = 0;

        int multiplier = 1;

        for ( int i = 0; i < s; i++ )
        {
            position += index[i] * multiplier;

            multiplier *= dimension[i];
        }

        dimension[position] = v;
    }

    int GetValue( int s, int index[])
    {
        int position = 0;

        int multiplier = 1;

        for ( int i = 0; i < s; i++ )
        {
            position += index[i] * multiplier;

            multiplier *= dimension[i];
        }

        return dimension[position];
    }

    ~NDArray()
    {
        delete[] dimension;
    }
};

int main()
{
    int dim[3] = {5, 3, 8};
    NDArray arr (3 , dim);

    int index[3] = {4, 2, 3};

    int position = arr.CalculateIndex(3, index);
    cout << position << endl;
    arr.SetValue(90, 3, index);
    cout << arr.GetValue (3, index) << endl;


    return 0;
}