#include <iostream>
#include <vector>
using namespace std;
void matrixChainOrder(vector <int> &p, vector<vector<int> > &m, vector<vector<int> > &s);
void printOptimalParens(vector<vector<int> > &s, int i, int j);

int main() 
{
    int n;
    cin >> n;
    vector <int> p;
    for (int i=0; i<=n; i++) {
        int x;
        cin >> x;
        p.push_back(x);
    }

    vector<vector<int> > m(n, vector<int>(n));
    vector<vector<int> > s(n-1, vector<int>(n));
    matrixChainOrder(p, m, s);
    printOptimalParens(s, 0, n-1);
    cout << endl;

    return 0;
}

void matrixChainOrder(vector<int> &p, vector<vector<int> > &m, vector<vector<int> > &s) {
    int n = p.size() - 1;
    for (int i=0; i<n; i++) {
        m[i][i] = 0;
    }
    for (int l=1; l<n; l++) {
        for (int i=0; i<n-l; i++) {
            int j = i + l;
            m[i][j] = INT_MAX;
            for (int k=i; k<j; k++) {
                int q = m[i][k] + m[k+1][j] + p[i]*p[k+1]*p[j+1];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    cout << m[0][n-1] << endl;
}

void printOptimalParens(vector<vector<int> > &s, int i, int j) {
    if (i == j) {
        cout << "A" << i;
    } else {
        cout << "(";
        printOptimalParens(s, i, s[i][j]);
        printOptimalParens(s, s[i][j]+1, j);
        cout << ")";
    }
}