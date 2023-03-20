
#include <iostream>
#include <vector>
using namespace std;
void countingSort(int [], int[], int, int);
void printArray(int [], int);
void radixSort(int [][10], int);

int main()
{
    /* int row;
    cin >> row;
    int A[row][10];
    for (int i=0; i<row; i++) {
        for (int j=0; j<10; j++) {
            A[i][j] = 0;
        }
    }

    for (int i=0; i<row; i++) {
        for (int j=0; j<10; j++) {
            cout << A[i][j] << ";";
        }
        cout << endl;
    } */

    int arrSize = 5;
    int array[5][10] = {
        {3,3,3,3,3,2,2,2,2,2},
        {2,3,2,2,2,2,2,2,2,2},
        {1,3,0,0,2,1,0,0,0,0},
        {1,3,0,0,2,2,0,0,0,0},
        {2,3,2,1,2,2,2,2,2,2}
    };
    int array2[5][10];

    radixSort(array, arrSize);

    return 0;
}

void countingSort(int A[], int B[], int k, int n) {
    int C[k+1];
    for (int i=0; i<=k; i++)
        C[i] = 0;

    for (int j=0; j<n; j++)
        C[A[j]]++;  //C[i] now contains the number of elements equal to i
    
    for (int i=1; i<=k; i++)
        C[i] = C[i] + C[i-1];   //C[i] now contains the number of elements less than or equal to i

    for (int j=n-1; j>=0; j--) {
        B[C[A[j]]-1] = A[j];
        C[A[j]]--;
    }
    printArray(A, n);
}

void printArray(int arr[], int n) {
    for (int i=0; i<n; i++)
        cout << arr[i] << ";";
    cout << endl;
}

void radixSort(int A[], int n) {
    int B[n];

    for (int i=0; i>10; i = i++) {
        countingSort(A, B, i, n);
    }
}