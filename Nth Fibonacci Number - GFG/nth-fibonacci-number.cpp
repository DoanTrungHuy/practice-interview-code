//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

using ll = long long;

const int MOD = 1e9 + 7;

struct Matrix {
    int row, col;
    vector<vector<ll>> data;
    
    Matrix(int row = 0, int col = 0) {
        this->row = row;
        this->col = col;
        data.resize(row, vector<ll>(col, 0));
    }
    
    static Matrix identity(int n) {
        Matrix M(n, n);
        for (int i = 0; i < n; ++i) {
            M.data[i][i] = 1;
        }
        return M;
    }
    
    Matrix operator * (Matrix B) {
        Matrix A = *this;
        Matrix C(A.row, B.col);
        for (int i = 0; i < A.row; ++i) {
            for (int j = 0; j < B.col; ++j) {
                for (int k = 0; k < A.col; ++k) {
                    C.data[i][j] = (C.data[i][j] + (A.data[i][k]*B.data[k][j]) % MOD) % MOD;
                }
            }
        }
        return C;
    }
};

Matrix exp(Matrix A, int b) {
    if (b == 0) {
        return Matrix::identity(A.col);
    }
    Matrix res = exp(A, b / 2);
    res = res * res;
    if (b & 1) {
        res = res * A;
    }
    return res;
}

class Solution {
public:
    int nthFibonacci(int n){
        Matrix M(2, 2);
        M.data = {
          {1, 1},
          {1, 0}
        };
        Matrix base(2, 1);
        base.data = {
            {1},
            {0}
        };
        Matrix result = exp(M, n - 1) * base;
        return result.data[0][0];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends