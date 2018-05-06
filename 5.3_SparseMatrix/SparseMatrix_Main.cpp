#include <iostream>
#include "SparseMatrix.cpp"

using namespace std;

int main() {
    SparseMatrix<int>::Triple t[8]{
            SparseMatrix<int>::Triple(1, 2, 12),
            SparseMatrix<int>::Triple(1, 3, 9),
            SparseMatrix<int>::Triple(3, 1, -3),
            SparseMatrix<int>::Triple(3, 6, 14),
            SparseMatrix<int>::Triple(4, 3, 24),
            SparseMatrix<int>::Triple(5, 2, 18),
            SparseMatrix<int>::Triple(6, 1, 15),
            SparseMatrix<int>::Triple(6, 4, -7)
    };
    SparseMatrix<int> matrix(t, 6, 7, 8);
    cout << matrix << endl;

    cout << matrix.transpose() << endl;

    return 0;
}

int main1() {
    SparseMatrix<int>::Triple t[4]{
            SparseMatrix<int>::Triple(1, 2, 2),
            SparseMatrix<int>::Triple(2, 1, 1),
            SparseMatrix<int>::Triple(3, 1, -2),
            SparseMatrix<int>::Triple(3, 2, 4)
    };
    SparseMatrix<int> matrix1(t, 4, 2, 4);

    SparseMatrix<int>::Triple q[4]{
            SparseMatrix<int>::Triple(1, 1, 3),
            SparseMatrix<int>::Triple(1, 4, 5),
            SparseMatrix<int>::Triple(2, 2, -1),
            SparseMatrix<int>::Triple(3, 1, 2)
    };
    SparseMatrix<int> matrix2(q, 3, 4, 4);

    cout << matrix2.mul(matrix1) << endl;
}