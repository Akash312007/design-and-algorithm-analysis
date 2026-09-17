
#include <iostream>
#include <vector>
using namespace std;

void addMatrix(vector<vector<int>>& A, vector<vector<int>>& B,
               vector<vector<int>>& C, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void subtractMatrix(vector<vector<int>>& A, vector<vector<int>>& B,
                    vector<vector<int>>& C, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

void strassen(vector<vector<int>>& A, vector<vector<int>>& B,
              vector<vector<int>>& C, int n) {

    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int k = n / 2;

    vector<vector<int>> A11(k, vector<int>(k));
    vector<vector<int>> A12(k, vector<int>(k));
    vector<vector<int>> A21(k, vector<int>(k));
    vector<vector<int>> A22(k, vector<int>(k));

    vector<vector<int>> B11(k, vector<int>(k));
    vector<vector<int>> B12(k, vector<int>(k));
    vector<vector<int>> B21(k, vector<int>(k));
    vector<vector<int>> B22(k, vector<int>(k));

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];
            A22[i][j] = A[i + k][j + k];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];
            B22[i][j] = B[i + k][j + k];
        }
    }

    vector<vector<int>> P1(k, vector<int>(k));
    vector<vector<int>> P2(k, vector<int>(k));
    vector<vector<int>> P3(k, vector<int>(k));
    vector<vector<int>> P4(k, vector<int>(k));
    vector<vector<int>> P5(k, vector<int>(k));
    vector<vector<int>> P6(k, vector<int>(k));
    vector<vector<int>> P7(k, vector<int>(k));

    vector<vector<int>> T1(k, vector<int>(k));
    vector<vector<int>> T2(k, vector<int>(k));

    addMatrix(A11, A22, T1, k);
    addMatrix(B11, B22, T2, k);
    strassen(T1, T2, P1, k);

    addMatrix(A21, A22, T1, k);
    strassen(T1, B11, P2, k);

    subtractMatrix(B12, B22, T2, k);
    strassen(A11, T2, P3, k);

    subtractMatrix(B21, B11, T2, k);
    strassen(A22, T2, P4, k);

    addMatrix(A11, A12, T1, k);
    strassen(T1, B22, P5, k);

    subtractMatrix(A21, A11, T1, k);
    addMatrix(B11, B12, T2, k);
    strassen(T1, T2, P6, k);

    subtractMatrix(A12, A22, T1, k);
    addMatrix(B21, B22, T2, k);
    strassen(T1, T2, P7, k);

    vector<vector<int>> C11(k, vector<int>(k));
    vector<vector<int>> C12(k, vector<int>(k));
    vector<vector<int>> C21(k, vector<int>(k));
    vector<vector<int>> C22(k, vector<int>(k));

    addMatrix(P1, P4, T1, k);
    subtractMatrix(T1, P5, T2, k);
    addMatrix(T2, P7, C11, k);

    addMatrix(P3, P5, C12, k);

    addMatrix(P2, P4, C21, k);

    addMatrix(P1, P3, T1, k);
    subtractMatrix(T1, P2, T2, k);
    addMatrix(T2, P6, C22, k);

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            C[i][j] = C11[i][j];
            C[i][j + k] = C12[i][j];
            C[i + k][j] = C21[i][j];
            C[i + k][j + k] = C22[i][j];
        }
    }
}

int main() {
    int n;

    cout << "Enter the size of the matrix: ";
    cin >> n;

    vector<vector<int>> A(n, vector<int>(n));
    vector<vector<int>> B(n, vector<int>(n));

    cout << "Enter elements of Matrix A:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    cout << "Enter elements of Matrix B:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> B[i][j];

    int size = 1;
    while (size < n)
        size *= 2;

    vector<vector<int>> AP(size, vector<int>(size, 0));
    vector<vector<int>> BP(size, vector<int>(size, 0));
    vector<vector<int>> CP(size, vector<int>(size, 0));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            AP[i][j] = A[i][j];
            BP[i][j] = B[i][j];
        }

    strassen(AP, BP, CP, size);

    cout << "\nResultant Matrix:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << CP[i][j] << " ";
        cout << endl;
    }

    return 0;
}