#include <iostream>
#include <math.h> 
using namespace std;
 
int heapSize, length, largest;
int left(int i)
{
    return (2 * i) + 1;
}
int right(int i)
{
    return (2 * i) + 2;
}

void heapify(int arr[], int i)
{
    int l = left(i);
    int r = right(i);

    if (l <= heapSize and arr[l] > arr[i])
    {
        largest = l;
    }
    else
    {
        largest = i;
    }
    if (r <= heapSize and arr[r] > arr[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, largest);
    }
}
void buildHeap(int arr[], int length)
{
    heapSize = length;
    for (int i = (floor(length / 2)); i >= 0; i--)
    {
        heapify(arr, i);
    }
}

void heapSort(int arr[])
{
    buildHeap(arr, heapSize);
    for (int i = heapSize; i >= 1; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapSize--;
        heapify(arr, 0);
    }
}
int main()
{
    cout << "Array { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7}";
    int arrayOfNumbers[] = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
    int n = sizeof(arrayOfNumbers) / sizeof(arrayOfNumbers[0]);
    int length = n - 1;
    buildHeap(arrayOfNumbers, length);
    cout << "\n";
    cout << "buildHeap: ";
    for (int i = 0; i < n; i++)
    {
        cout << arrayOfNumbers[i] << " ";
    }
    heapSort(arrayOfNumbers);
    cout << "\n";
    cout << "heapSort: ";
    for (int i = 0; i < n; i++)
    {
        cout << arrayOfNumbers[i] << " ";
    }
    cout << "\n- - - - -";
    cout << "\nArray { 13, 2, 91, 102, 12, 87, 45, 39, 27, 55, 42, 11, 3, 18, 64, 75, 51}";
    int arrayOfNumbers1[] = { 13, 2, 91, 102, 12, 87, 45, 39, 27, 55, 42, 11, 3, 18, 64, 75, 51 };
    n = sizeof(arrayOfNumbers1) / sizeof(arrayOfNumbers1[0]);
    length = n - 1;
    buildHeap(arrayOfNumbers1, length);
    cout << "\n";
    cout << "buildHeap: ";
    for (int i = 0; i < n; i++)
    {
        cout << arrayOfNumbers1[i] << " ";
    }
    heapSort(arrayOfNumbers1);
    cout << "\n";
    cout << "heapSort: ";
    for (int i = 0; i < n; i++)
    {
        cout << arrayOfNumbers1[i] << " ";
    }
}