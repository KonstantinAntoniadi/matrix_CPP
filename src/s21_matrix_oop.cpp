#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() : S21Matrix(3, 3) {}

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  if (rows <= 0 || cols <= 0) {
    throw std::invalid_argument("Number of rows or or cols less than 1");
  }

  this->CreateMatrix();
}

S21Matrix::S21Matrix(const S21Matrix& other)
    : rows_(other.rows_), cols_(other.cols_) {
  CreateMatrix();
  CopyMatrix(other);
}

S21Matrix::S21Matrix(S21Matrix&& other) noexcept
    : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_) {
  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = nullptr;
}

S21Matrix& S21Matrix::operator=(S21Matrix&& other) noexcept {
  if (this == &other) return *this;

  DeallocateMatrix();
  rows_ = other.rows_;
  cols_ = other.cols_;
  matrix_ = other.matrix_;

  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = nullptr;

  return *this;
}

S21Matrix::~S21Matrix() {
  DeallocateMatrix();

  rows_ = 0;
  cols_ = 0;
}

bool S21Matrix::EqMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    return false;
  }

  bool result = true;
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      if (fabs(matrix_[i][j] - other.matrix_[i][j]) > eps) {
        result = false;
        break;
      }
    }
  }

  return result;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::out_of_range(
        "Incorrect input, matrices should have the same size");
  }

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] += other.matrix_[i][j];
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::out_of_range(
        "Incorrect input, matrices should have the same size");
  }

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] -= other.matrix_[i][j];
    }
  }
}

void S21Matrix::MulNumber(const double num) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] *= num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (cols_ != other.rows_) {
    throw std::invalid_argument(
        "Incorrect input, the number of rows of the first matrix should be "
        "equal to the number of columns of the second matrix");
  }

  S21Matrix matrix_temp(rows_, other.cols_);

  long double x = 0.0;
  for (int i = 0; i < rows_; i++) {
    for (int k = 0; k < other.cols_; k++) {
      for (int j = 0; j < cols_; j++) {
        x += matrix_[i][j] * other.matrix_[j][k];
      }
      matrix_temp(i, k) = x;
      x = 0.0;
    }
  }

  *this = matrix_temp;
}

S21Matrix S21Matrix::Transpose() {
  S21Matrix transposed_matrix(cols_, rows_);

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      transposed_matrix.matrix_[j][i] = matrix_[i][j];
    }
  }

  return transposed_matrix;
}

S21Matrix S21Matrix::CalcComplements() {
  if (rows_ != cols_) {
    throw std::invalid_argument("The matrix must be square");
  }

  S21Matrix matrix_result(rows_, cols_);
  S21Matrix matrix_temp(rows_ - 1, cols_ - 1);

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      FillMinor(matrix_temp, i, j);
      double det = matrix_temp.Determinant();
      matrix_result.matrix_[i][j] = det * pow(-1, i + j + 2);
    }
  }

  return matrix_result;
}

double S21Matrix::Determinant() {
  if (rows_ != cols_) {
    throw std::invalid_argument("The matrix must be square");
  }

  double result = 0.0;
  if (rows_ == 1) {
    result = matrix_[0][0];
  } else if (rows_ == 2) {
    result = matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];
  } else {
    S21Matrix matrix_temp(rows_ - 1, cols_ - 1);

    for (int l = 0; l < cols_; l++) {
      for (int i = 0; i < matrix_temp.rows_; i++) {
        for (int j = 0; j < l; j++) {
          matrix_temp.matrix_[i][j] = matrix_[i + 1][j];
        }
        for (int j = l; j < matrix_temp.cols_; j++) {
          matrix_temp.matrix_[i][j] = matrix_[i + 1][j + 1];
        }
      }

      double det_temp = matrix_temp.Determinant();
      result += matrix_[0][l] * pow(-1, l + 2) * det_temp;
    }
  }
  return result;
}

S21Matrix S21Matrix::InverseMatrix() {
  double det = this->Determinant();
  if (det == 0) {
    throw std::invalid_argument("Determinant must not be zero");
  }

  S21Matrix matrix_result;
  if (rows_ == 1) {
    matrix_result = S21Matrix(rows_, cols_);
    matrix_result.matrix_[0][0] = 1.0 / matrix_[0][0];
  } else {
    S21Matrix matrix_temp = CalcComplements();
    S21Matrix matrix_transpon = matrix_temp.Transpose();
    matrix_transpon.MulNumber(1 / det);
    matrix_result = matrix_transpon;
  }

  return matrix_result;
}

S21Matrix S21Matrix::operator+(const S21Matrix& other) {
  S21Matrix result = S21Matrix(*this);
  result.SumMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) {
  S21Matrix result = S21Matrix(*this);
  result.SubMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) {
  S21Matrix result = S21Matrix(*this);
  result.MulMatrix(other);
  return result;
}

S21Matrix operator*(S21Matrix& matrix, double x) {
  S21Matrix result = S21Matrix(matrix);
  result.MulNumber(x);
  return result;
}

S21Matrix operator*(double x, S21Matrix& matrix) { return matrix * x; }

double& S21Matrix::operator()(int row, int col) {
  if (row < 0 || col < 0 || row >= rows_ || col >= cols_) {
    throw std::out_of_range("Incorrect input, index is out of range");
  }

  return matrix_[row][col];
}

double& S21Matrix::operator()(int row, int col) const {
  if (row < 0 || col < 0 || row >= rows_ || col >= cols_) {
    throw std::out_of_range("Incorrect input, index is out of range");
  }

  return matrix_[row][col];
}

bool S21Matrix::operator==(const S21Matrix& other) { return EqMatrix(other); }

void S21Matrix::CopyMatrix(const S21Matrix& other) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  if (this == &other) return *this;

  this->~S21Matrix();
  rows_ = other.rows_;
  cols_ = other.cols_;
  CreateMatrix();
  CopyMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  SumMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  SubMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  MulMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const double x) {
  MulNumber(x);
  return *this;
}

void S21Matrix::set_rows(int rows) {
  if (rows <= 0) {
    throw std::out_of_range("Incorrect input, rows should be greater then 0");
  }

  S21Matrix temp = S21Matrix(rows, cols_);

  int temp_rows = rows < rows_ ? rows : rows_;
  for (int i = 0; i < temp_rows; i++) {
    for (int j = 0; j < cols_; j++) {
      temp(i, j) = matrix_[i][j];
    }
  }
  *this = temp;
}

void S21Matrix::set_cols(int cols) {
  if (cols <= 0) {
    throw std::out_of_range("Incorrect input, cols should be greater then 0");
  }

  S21Matrix temp = S21Matrix(rows_, cols);
  int temp_cols = cols < cols_ ? cols : cols_;
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < temp_cols; j++) {
      temp(i, j) = matrix_[i][j];
    }
  }

  *this = temp;
}

int S21Matrix::get_rows() const { return rows_; }
int S21Matrix::get_cols() const { return cols_; }

void S21Matrix::CreateMatrix() {
  matrix_ = new double*[rows_]();
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_]();
  }
}

void S21Matrix::DeallocateMatrix() {
  if (matrix_) {
    for (int i = 0; i < rows_; i++) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
  }
}

void S21Matrix::FillMinor(S21Matrix& matrix, int i, int j) {
  for (int a = 0; a < i; a++) {
    for (int b = 0; b < j; b++) {
      matrix.matrix_[a][b] = matrix_[a][b];
    }
    for (int b = j; b < matrix.cols_; b++) {
      matrix.matrix_[a][b] = matrix_[a][b + 1];
    }
  }
  for (int a = i; a < matrix.rows_; a++) {
    for (int b = 0; b < j; b++) {
      matrix.matrix_[a][b] = matrix_[a + 1][b];
    }
    for (int b = j; b < matrix.cols_; b++) {
      matrix.matrix_[a][b] = matrix_[a + 1][b + 1];
    }
  }
}