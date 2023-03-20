#include <iostream>
#include <vector>
using namespace std;

int maxNum(int a, int b, int c) {
    int maxTemp = max(a, b);
    return max(maxTemp, c);
}
int maxCrossingSubArray(vector <int> arr, int, int, int);
int maxSubArray(vector <int> arr, int, int);

int main()
{
    int size;
    vector <int> arr;
    cin >> size;
    for (int i=0; i<size; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    cout << maxSubArray(arr, 0, size-1);
    return 0;
}

int maxCrossingSubArray(vector <int> arr, int low, int mid, int high) {
    int leftSum = INT_MIN;
    int rightSum = INT_MIN;
    int sum = 0;

    for (int i=mid; i>=low; i--) {
        sum += arr[i];
        leftSum = max(sum, leftSum);
    }

    sum = 0;
    for (int j=mid+1; j<=high; j++) {
        sum += arr[j];
        rightSum = max(sum, rightSum);
    }
    
    return (leftSum + rightSum);
}

int maxSubArray(vector <int> arr, int low, int high) {
    if (high == low) {
        return (low, high, arr[low]);
    }
    else {
        int mid = (low + high) / 2;
        int leftSum = maxSubArray(arr, low, mid);
        int rightSum = maxSubArray(arr, mid+1, high);
        int crossSum = maxCrossingSubArray(arr, low, mid, high);

        return maxNum(leftSum, rightSum, crossSum);
    }
}
