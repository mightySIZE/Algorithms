#include <iostream>
#include <vector>
using namespace std;
void extendedBottomUpCutRod(int p[], int n);
void printRodIndex(int cutIndex[], int n);

int main ()
{
    int size;
    cin >> size;
    int p[size];
    for (int i=0; i<size; i++) {
        cin >> p[i];
    }

    /* int size = 8;
    int p[8] = {1, 5, 8, 9, 10, 17, 17, 20}; */

    extendedBottomUpCutRod(p, size);
    return 0;
}

void extendedBottomUpCutRod(int p[], int n) {
    int maxRev[n];
    maxRev[0] = 0;
    int cutIndex[n];
    cutIndex[0] = 0;
    for (int i=1; i<=n; i++) {
        maxRev[i] = p[i-1];
        cutIndex[i] = i;
        for (int j=1; j<i; j++) {
            if ((p[j-1] + maxRev[i-j] > maxRev[i]) ) {
                maxRev[i] = p[j-1] + maxRev[i-j];
                cutIndex[i] = j;
            }
        }
    }
    cout << maxRev[n] << endl;

    printRodIndex(cutIndex, n);
}

void printRodIndex(int cutIndex[], int n) {
    while (n > 0)
    {
        cout << cutIndex[n] << " ";
        n = n - cutIndex[n];
    }
    cout << "-1" << endl;
}
