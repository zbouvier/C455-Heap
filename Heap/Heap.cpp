// Heap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <math.h> 
using namespace std;

int heapSize, length, largest;
int left(int i)
{
    return 2 * i;
}
int right(int i)
{
    return (2 * i) + 1;
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
    for (int i = heapSize; i > 0; i--)
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

    int arrayOfNumbers[] = { 17,9,5,21,23,14,11,8,3};
    int n = sizeof(arrayOfNumbers) / sizeof(arrayOfNumbers[0]);
    int length = n - 1;
    buildHeap(arrayOfNumbers, length);
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << arrayOfNumbers[i] << " ";
    }
    heapSort(arrayOfNumbers);
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << arrayOfNumbers[i] << " ";
    }
}
