#include <iostream>
using namespace std;

void mergeSort(int[], int, int);
void merge(int[], int, int, int);
void print(int[], int);

int main() {
    int size;
    cin >> size;
    int arrA[size];
    for (int i=0; i<size; i++)
        cin >> arrA[i];

    mergeSort(arrA, 0, size-1);
    print(arrA, size);
    return 0;
}

void mergeSort(int arrA[], int p, int r) {
    if (p < r) {
        int q = (p+r)/2;
        mergeSort(arrA, p, q);
        mergeSort(arrA, q+1, r);
        merge(arrA, p, q, r);
    }
    return;
}

void merge(int arrA[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
  
    int arrL[n1];
    int arrR[n2];
  
    for (int i = 0; i < n1; i++) {
        arrL[i] = arrA[p + i];
    }
    for (int j = 0; j < n2; j++) {
        arrR[j] = arrA[q + 1 + j];
    }

    int i=0, j=0, k=p;
    for (;(i<n1) && (j<n2);) {
        if (arrL[i] <= arrR[j]) {
            arrA[k] = arrL[i];
            i++;
        }
        else {
            arrA[k] = arrR[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arrA[k] = arrL[i];
        i++;
        k++;
    }
    while (j < n2) 
    {
        arrA[k] = arrR[j];
        j++;
        k++;
    }
}
  

void print(int arr[], int size) {
    for (int x=0; x<size; x++) {
        cout << arr[x] << ";";
    }
}
