#include <iostream>
using namespace std;

void insertionSort(int[], int);
void print(int[], int, int);

int main() {
    int size;
    cin >> size;                // Enter the size of the array to be sorted
    int arr[size];
    for (int i=0; i<size; i++)  // Enter elements of the array to be sorted
        cin >> arr[i];

    insertionSort(arr, size);
    return 0;
}

void insertionSort(int arr[], int size) {
    for (int i=1; i<(int)size ; i++) {
        int sortedKey = arr[i];
        int j = i-1;
        while ((j>=0) && (arr[j]>sortedKey)) {
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = sortedKey;
        print(arr, i, size);
    }
    return;
}

void print(int arr[], int i, int size) {
    int end = i+1;
    if (end > size) {end = size;}
    for (int x=0; x<end; x++) {
        if (end > size)
            end = size;
        cout << arr[x] << ";";
    }
    cout << endl;
}
