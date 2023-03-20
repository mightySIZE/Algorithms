#include <iostream>
using namespace std;
void maxHeapify(int [], int, int);
void buildMaxHeap(int [], int);
void heapSort(int [], int);
void printArray(int [], int);

int main()
{
    int arrSize;
    cin >> arrSize;
    int arr[arrSize];
    
    for (int i=0; i<arrSize; i++)
        cin >> arr[i];

    heapSort(arr, arrSize);
    printArray(arr, arrSize);

    return 0;
}

void heapSort(int arr[], int size) {
    buildMaxHeap(arr, size);

    for (int i=size-1; i>0; i--) {
        swap(arr[0], arr[i]);
        maxHeapify(arr, i, 0);
    }
}

void buildMaxHeap(int arr[], int size) {
    for (int i=(size/2)-1; i>=0; i--) {
        maxHeapify(arr, size, i);
    }
}

void maxHeapify(int arr[], int size, int i) {
    int largest;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[left] > arr[i])
        largest = left;
    else
        largest = i;

    if (right < size && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, size, largest);
    }
}

void printArray(int arr[], int size) {
    for (int i=0; i<size; i++)
        cout << arr[i] << ";";
}