#ifndef MATRIX_SRC_S21_MATRIX_OOP_H_
#define MATRIX_SRC_S21_MATRIX_OOP_H_

#include <cmath>
#include <iostream>
#define eps 1e-07

class Matrix {
 private:
  int rows_, cols_;
  double** matrix_;
  void DeallocateMatrix();
  void CreateMatrix();
  void CopyMatrix(Matrix& other);
  void FillMinor(Matrix& matrix, int i, int j);
  void CopyMatrix(const Matrix& other);

 public:
  Matrix();
  Matrix(int rows, int cols);
  Matrix(const Matrix& other);
  Matrix(Matrix&& other) noexcept;
  ~Matrix();

  bool EqMatrix(const Matrix& other);
  void SumMatrix(const Matrix& other);
  void SubMatrix(const Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const Matrix& other);
  Matrix Transpose();
  Matrix CalcComplements();
  double Determinant();
  Matrix InverseMatrix();

  Matrix operator+(const Matrix& other);
  Matrix operator-(const Matrix& other);
  Matrix operator*(const Matrix& other);
  friend Matrix operator*(double x, Matrix& matrix);
  friend Matrix operator*(Matrix& matrix, double x);
  bool operator==(const Matrix& other);
  Matrix& operator=(const Matrix& other);
  Matrix& operator=(Matrix&& other) noexcept;

  Matrix& operator+=(const Matrix& other);
  Matrix& operator-=(const Matrix& other);
  Matrix& operator*=(const Matrix& other);
  Matrix& operator*=(const double x);
  double& operator()(int row, int col);
  double& operator()(int row, int col) const;

  void set_rows(int rows);
  void set_cols(int cols);
  int get_rows() const;
  int get_cols() const;
};

#endif  // MATRIX_SRC_S21_MATRIX_OOP_H_
