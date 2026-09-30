#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }

    return -1;
}

int binarySearch(int arr[], int n, int key)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }
        else if (key < arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return -1;
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        swap(arr[i], arr[minIndex]);
    }
}

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main()
{
    int arr[100];
    int n, choice, key;

    cout << "Enter size of array: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "\n1. Linear Search";
    cout << "\n2. Binary Search";
    cout << "\n3. Selection Sort";
    cout << "\n4. Insertion Sort";
    cout << "\nEnter choice: ";
    cin >> choice;

    if (choice == 1)
    {
        cout << "Enter element to search: ";
        cin >> key;

        int result = linearSearch(arr, n, key);

        if (result != -1)
        {
            cout << "Element found at index " << result << endl;
        }
        else
        {
            cout << "Element not found" << endl;
        }
    }
    else if (choice == 2)
    {
        selectionSort(arr, n);

        cout << "Sorted array: ";
        display(arr, n);

        cout << "Enter element to search: ";
        cin >> key;

        int result = binarySearch(arr, n, key);

        if (result != -1)
        {
            cout << "Element found at index " << result << endl;
        }
        else
        {
            cout << "Element not found" << endl;
        }
    }
    else if (choice == 3)
    {
        selectionSort(arr, n);

        cout << "Sorted array: ";
        display(arr, n);
    }
    else if (choice == 4)
    {
        insertionSort(arr, n);

        cout << "Sorted array: ";
        display(arr, n);
    }
    else
    {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}