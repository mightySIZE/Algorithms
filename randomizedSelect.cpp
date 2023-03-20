#include <iostream>
#include <vector>
using namespace std;
void randomizedSelect(vector <int> &A, int p, int r, int i);
int partition(vector <int> &A, int p, int r);
vector <int> pivots;

int main() {

    int bSize, ithSmallest;
    cin >> bSize >> ithSmallest;
    vector <int> A;
    for (int i=0; i<bSize; i++) {
        int temp;
        cin >> temp;
        A.push_back(temp);
    }

    randomizedSelect(A, 0, bSize-1, ithSmallest);
    for (int i=0; i<pivots.size(); i++) {
        cout << pivots[i] << ";";
    }

    return 0;
}

void randomizedSelect(vector <int> &A, int p, int r, int i) {
    pivots.push_back(A[r]);
    if (p == r) {
        return;
    }

    int q = partition(A, p, r);
    int k = q - p + 1;

    if (i == k) { //pivot is the answer
        pivots.push_back(A[q]);
        return;
    }
    else if (i < k) {
        return randomizedSelect(A, p, q-1, i);
    }
    else {
        return randomizedSelect(A, q+1, r, i-k);
    }
}

int partition(vector <int> &A, int p, int r) {
    int x = A[r];
    int i = p-1;
    for (int j=p; j<=r-1; j++) {
        if (A[j] <= x) {
            i++;
            swap(A[i], A[j]);
        }
    }
    
    swap(A[i+1], A[r]);
    return i+1;
}
