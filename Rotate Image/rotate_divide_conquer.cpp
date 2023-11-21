#include <iostream>
#include <vector>

using namespace std;

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int element : row) {
            cout << element << " ";
        }
        cout << endl;
    }
}

void rotateSubMatrix(vector<vector<int>>& matrix, int size) {
    if (size <= 1) {
        return;
    }

    // Dividir la submatriz en cuatro partes
    vector<vector<int>> a(size/2, vector<int>(size/2));
    vector<vector<int>> b(size/2, vector<int>(size/2));
    vector<vector<int>> c(size/2, vector<int>(size/2));
    vector<vector<int>> d(size/2, vector<int>(size/2));

    for (int i = 0; i < size/2; ++i) {
        for (int j = 0; j < size/2; ++j) {
            a[i][j] = matrix[i][j];
            b[i][j] = matrix[i][j + size/2];
            c[i][j] = matrix[i + size/2][j];
            d[i][j] = matrix[i + size/2][j + size/2];
        }
    }

    printMatrix(a);
    printMatrix(b);
    printMatrix(c);
    printMatrix(d);

    // Rotar las submatrices recursivamente
    rotateSubMatrix(a, size/2); //esquina superior izquierda
    rotateSubMatrix(b, size/2); //esquina superior derecha
    rotateSubMatrix(c, size/2); //esquina inferior izquierda
    rotateSubMatrix(d, size/2); //esquina inferior derecha

    // Combinar las submatrices rotadas
    for (int i = 0; i < size/2; ++i) {
        for (int j = 0; j < size/2; ++j) {
            matrix[i][j] = c[i][j];
            matrix[i][j + size/2] = a[i][j];
            matrix[i + size/2][j] = d[i][j];
            matrix[i + size/2][j + size/2] = b[i][j];
        }
    }
}

void rotateMatrix(vector<vector<int>>& matrix) {
    int size = matrix.size();
    rotateSubMatrix(matrix, size);
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    cout << "Matriz original:" << endl;
    printMatrix(matrix);

    rotateMatrix(matrix);

    cout << "\nMatriz rotada 90 grados en sentido horario:" << endl;
    printMatrix(matrix);

    return 0;
}
