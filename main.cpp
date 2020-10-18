#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <sstream>

using namespace std;

class Matrix {
 public:
  Matrix() {
    row_ = 0;
    column_ = 0;
  }

  Matrix(int new_rows, int new_columns) {
    Reset(new_rows, new_columns);
  }
  void Reset(int new_rows, int new_columns) {
    if (new_rows < 0) {
      throw out_of_range("row_ must be >= 0");
    }
    if (new_columns < 0) {
      throw out_of_range("columns must be >= 0");
    }
    if (new_rows == 0 || new_columns == 0) {
      new_rows = new_columns = 0;
    }
    row_ = new_rows;
    column_ = new_columns;
    matrix_.assign(new_rows, vector<int>(new_columns));
  }
  int& At(int rows, int columns) {
    return matrix_.at(rows).at(columns);
  }

  int At(int rows, int columns) const {
    return matrix_.at(rows).at(columns);
  }

  int GetNumRows() const {
    return row_;
  }

  int GetNumColumns() const {
    return column_;
  }

 private:
  int row_;
  int column_;
  vector<vector<int>> matrix_;
};
ostream& operator<<(ostream& stream, const Matrix& m) {
  int it = m.GetNumRows();
  int jt = m.GetNumColumns();
  stream << it << " " << jt << endl;
  for (int kI = 0; kI < it; ++kI) {
    for (int kJ = 0; kJ < jt; ++kJ) {
      stream << m.At(kI, kJ);
      if (kJ < jt - 1) {
        stream << " ";
      }
      if (kJ == jt - 1 && kI != it - 1) {
        stream << endl;
      }
    }
  }
  return stream;
}
istream& operator>>(istream& stream, Matrix& m) {
  int row, column;
  stream >> row;
  stream >> column;
  m.Reset(row, column);
  for (int kI = 0; kI < row; ++kI) {
    for (int kJ = 0; kJ < column; ++kJ) {
      stream >> m.At(kI, kJ);
      if (kJ < column - 1) {
        stream.ignore(1);
      }
    }
  }
  return stream;
}

bool operator==(const Matrix& lhs, const Matrix& rhs) {
  if (lhs.GetNumColumns() != rhs.GetNumColumns()) {
    return false;
  }
  if (lhs.GetNumRows() != rhs.GetNumRows()) {
    return false;
  }
  int it = lhs.GetNumRows();
  int jt = lhs.GetNumColumns();
  for (int kI = 0; kI < it; ++kI) {
    for (int kJ = 0; kJ < jt; ++kJ) {
      if (lhs.At(kI, kJ) != rhs.At(kI, kJ)) {
        return false;
      }
    }
  }
  return true;
}


Matrix operator+(const Matrix& lhs, const Matrix& rhs) {
  if (lhs.GetNumRows() != rhs.GetNumRows()) {
    throw invalid_argument("");
  }

  if (lhs.GetNumColumns() != rhs.GetNumColumns()) {
    throw invalid_argument("");
  }

  int it = lhs.GetNumRows();
  int jt = lhs.GetNumColumns();
  Matrix new_matrix(it, jt);
  for (int kI = 0; kI < it; ++kI) {
    for (int kJ = 0; kJ < jt; ++kJ) {
      new_matrix.At(kI, kJ) = lhs.At(kI, kJ) + rhs.At(kI, kJ);
    }
  }
  return new_matrix;
}

int main() {
  try {
    Matrix one;
    Matrix two;
//    string str = "3 5\n6 4 -1 9 8\n12 1 2 9 -5\n-4 0 12 8 6\n3 5\n5 1 0 -8 23\n14 5 -6 6 9\n8 0 5 4 1";
    string str = "3 0\n\n0 0\n0";
//    string str2 = "3 2\n9 8\n-7 6\n5 4\n4 2\n3 2\n9 8\n-7 6\n5 4";
    stringstream ss1(str);
    ss1 >> one >> two;
    Matrix three = one + two;
    bool one1 = one == two;
    bool one2 = three == two;
    cout <<  one1 << one2 << endl;
  } catch (exception e) {
    cout << e.what() << endl;
  }
  return 0;
}