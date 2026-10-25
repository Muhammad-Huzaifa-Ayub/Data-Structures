#include <iostream>
using namespace std;

class NDArray
{
private:
    int *dimension;
    int *data;
    int size;
    int dimensions;

public:
    NDArray(int s, int dim[])
    {
        dimensions = s;
        size = 1;

        dimension = new int[s];

        for (int i = 0; i < s; i++)
        {
            dimension[i] = dim[i];
            size *= dim[i];
        }

        data = new int[size]();
    }

    int CalculateIndex(int s, int index[]) const
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

    void SetValue(const int v, int s, int index[])
    {
        int position = CalculateIndex(s, index);
        data[position] = v;
    }

    int GetValue(int s, int index[])
    {
        int position = CalculateIndex(s, index);
        return data[position];
    }

    ~NDArray()
    {
        delete[] dimension;
        delete[] data;
    }
};

int main()
{
    int dim[3] = {5, 3, 8};
    NDArray arr(3, dim);

    int index[3] = {4, 2, 3};

    cout << arr.CalculateIndex(3, index) << endl;

    arr.SetValue(90, 3, index);

    cout << arr.GetValue(3, index) << endl;

    return 0;
}

