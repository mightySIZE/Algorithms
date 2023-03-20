#include <iostream>
#include <vector>
using namespace std;
int partition(vector <int>&, int, int);
int randomizedPartition(vector <int>&, int, int);
void randomizedQuicksort(vector <int>&, int, int);
void printArray(vector <int>, int);

int main()
{
    //int arrSize = 6;
    //vector <int> arr = {5,3,2,1,6,4};

    int arrSize;
    cin >> arrSize;
    vector <int> arr;
    for (int i=0; i<arrSize; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    
    randomizedQuicksort(arr, 0, arrSize-1);
    printArray(arr, arrSize);

    return 0;
}

int partition(vector <int>& arr, int p, int r) {
    int x = arr[r];
    int i = p-1;
    for (int j=p; j<=r-1; j++) {
        if (arr[j] <= x) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    swap(arr[i+1], arr[r]);
    return i+1;
}

int randomizedPartition(vector <int>& arr, int p, int r) {
    int i = rand() % (r - p + 1) + p;
    swap(arr[r], arr[i]);
    return partition(arr, p, r);
}

void randomizedQuicksort(vector <int>& arr, int p, int r) {
    if (p < r) {
        int q = randomizedPartition(arr, p, r);
        randomizedQuicksort(arr, p, q-1);
        randomizedQuicksort(arr, q+1, r);
    }
}

void printArray(vector <int> arr, int size) {
    for (int i=0; i<size; i++)
        cout << arr[i] << ";";
}
