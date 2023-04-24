#include "unit_test.h"

TEST(AssignmentOperatorTest, Copy) {
  S21Matrix matrix_1 = S21Matrix(2, 2);
  matrix_1(0, 0) = 1.0;
  matrix_1(0, 1) = 2.0;
  matrix_1(1, 0) = 3.0;
  matrix_1(1, 1) = 4.0;

  int rows = 3;
  int cols = 3;
  S21Matrix matrix_2 = S21Matrix(rows, cols);
  matrix_2(0, 0) = 12.4;
  matrix_2(0, 1) = 24.8;
  matrix_2(0, 2) = 24.8;
  matrix_2(1, 0) = 37.2;
  matrix_2(1, 1) = 37.2;
  matrix_2(1, 2) = 50.0;
  matrix_2(2, 0) = 37.2;
  matrix_2(2, 1) = 37.2;
  matrix_2(2, 2) = 50.0;

  matrix_1 = matrix_2;

  EXPECT_TRUE(matrix_1 == matrix_2);
}

TEST(AssignmentOperatorTest, Move) {
  S21Matrix matrix_1 = S21Matrix(2, 2);
  matrix_1(0, 0) = 1.0;
  matrix_1(0, 1) = 2.0;
  matrix_1(1, 0) = 3.0;
  matrix_1(1, 1) = 4.0;
  S21Matrix matrix_2 = matrix_1 * 12.4;

  matrix_1 = std::move(matrix_2);
  S21Matrix result = S21Matrix(2, 2);
  result(0, 0) = 12.4;
  result(0, 1) = 24.8;
  result(1, 0) = 37.2;
  result(1, 1) = 49.6;

  EXPECT_TRUE(matrix_1 == result);
  EXPECT_EQ(matrix_2.get_cols(), 0);
  EXPECT_EQ(matrix_2.get_rows(), 0);
}