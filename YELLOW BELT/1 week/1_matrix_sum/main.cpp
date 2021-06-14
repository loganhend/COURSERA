#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

// Реализуйте здесь
// * класс Matrix
// * оператор ввода для класса Matrix из потока istream
// * оператор вывода класса Matrix в поток ostream
// * оператор проверки на равенство двух объектов класса Matrix
// * оператор сложения двух объектов класса Matrix
class Matrix {
public:
    Matrix() {
        n_rows = 0;
        n_cols = 0;
    }
    Matrix(int num_rows, int num_cols) {
        Reset(num_rows, num_cols);
    }
    void Reset(int new_rows, int new_cols) {
        if (new_rows < 0 || new_cols < 0) {
            throw out_of_range("");
        }
        n_rows = new_rows;
        n_cols = new_cols;
        if (new_rows == 0 || new_cols == 0) {
            n_rows = 0;
            n_cols = 0;
        }
        data.assign(new_rows, vector<int>(new_cols));
    }
    int At(int row_num, int col_num) const {
        return data.at(row_num).at(col_num);
    }
    int& At(int row_num, int col_num) {
        return data.at(row_num).at(col_num);
    }
    int GetNumColumns() const{
        return n_cols;
    }
    int GetNumRows() const{
        return n_rows;
    }
private:
    int n_rows,n_cols;
    vector< vector <int> > data;
};

ostream& operator << (ostream& output, const Matrix& matrix){
    int nrows = matrix.GetNumRows();
    int ncols = matrix.GetNumColumns();
    output << nrows << " " << ncols << endl;
    for (int i = 0; i < nrows; ++i) {
        for (int j = 0; j < ncols; ++j) {
            int elem = matrix.At(i,j);
            if (j != (ncols-1)) {
                output << elem << " ";
            } else {
                output << elem;
            }
        }
        if (i != (nrows-1)) {
            output << endl;
        }
    }
    return output;
}

istream& operator >> (istream& input, Matrix& matrix){
    int nrows, ncols;
    if (input) {
        input >> nrows >> ncols;
        matrix.Reset(nrows,ncols);
        for (int i = 0; i < nrows; ++i) {
            for (int j = 0; j < ncols; ++j) {
                int elem;
                input >> elem;
                matrix.At(i,j) = elem;
            }
        }
    }
    return input;
}

bool operator == (const Matrix& lMatrix, const Matrix& rMatrix) {
    int lMatrix_rows = lMatrix.GetNumRows();
    int rMatrix_rows = rMatrix.GetNumRows();
    int lMatrix_cols = lMatrix.GetNumColumns();
    int rMatrix_cols = rMatrix.GetNumColumns();
    if (lMatrix_rows == rMatrix_rows
        && lMatrix_cols == rMatrix_cols) {
        Matrix sumMatrix(lMatrix_rows,lMatrix_cols);
        for (int i = 0; i < lMatrix_rows; ++i) {
            for (int j = 0; j < lMatrix_cols; ++j) {
                if (lMatrix.At(i,j) != rMatrix.At(i,j)) {
                    return false;
                }
            }
        }
        return true;
    } else {
        return false;
    }
}

Matrix operator + (const Matrix& lMatrix, const Matrix& rMatrix) {
    int lMatrix_rows = lMatrix.GetNumRows();
    int rMatrix_rows = rMatrix.GetNumRows();
    int lMatrix_cols = lMatrix.GetNumColumns();
    int rMatrix_cols = rMatrix.GetNumColumns();
    if (lMatrix_rows == rMatrix_rows
        && lMatrix_cols == rMatrix_cols) {
        Matrix sumMatrix(lMatrix_rows,lMatrix_cols);
        for (int i = 0; i < lMatrix_rows; ++i) {
            for (int j = 0; j < lMatrix_cols; ++j) {
                sumMatrix.At(i,j) =  lMatrix.At(i,j) + rMatrix.At(i,j);
            }
        }
        return sumMatrix;
    } else {
        throw invalid_argument("");
    }
}

int main() {
    Matrix one;
    Matrix two;

    cout << one + two << endl;
    return 0;
}