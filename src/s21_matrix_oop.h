#ifndef CPP1_S21_MATRIXPLUS_1_SRC_S21_MATRIX_OOP_H_
#define CPP1_S21_MATRIXPLUS_1_SRC_S21_MATRIX_OOP_H_

#include <cmath>
#include <iostream>
#define eps 1e-07

class S21Matrix {
 private:
  int rows_, cols_;
  double** matrix_;
  void DeallocateMatrix();
  void CreateMatrix();
  void CopyMatrix(S21Matrix& other);
  void FillMinor(S21Matrix& matrix, int i, int j);
  void CopyMatrix(const S21Matrix& other);

 public:
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other) noexcept;
  ~S21Matrix();

  bool EqMatrix(const S21Matrix& other);
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();

  S21Matrix operator+(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other);
  S21Matrix operator*(const S21Matrix& other);
  friend S21Matrix operator*(double x, S21Matrix& matrix);
  friend S21Matrix operator*(S21Matrix& matrix, double x);
  bool operator==(const S21Matrix& other);
  S21Matrix& operator=(const S21Matrix& other);
  S21Matrix& operator=(S21Matrix&& other) noexcept;

  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix& operator-=(const S21Matrix& other);
  S21Matrix& operator*=(const S21Matrix& other);
  S21Matrix& operator*=(const double x);
  double& operator()(int row, int col);
  double& operator()(int row, int col) const;

  void set_rows(int rows);
  void set_cols(int cols);
  int get_rows() const;
  int get_cols() const;
};

#endif  // CPP1_S21_MATRIXPLUS_1_SRC_S21_MATRIX_OOP_H_
