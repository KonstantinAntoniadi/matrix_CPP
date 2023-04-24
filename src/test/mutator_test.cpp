#include "unit_test.h"

TEST(SetRowsMutatorTest, RowsGreaterSize) {
  S21Matrix matrix_1 = S21Matrix(2, 2);
  matrix_1(0, 0) = 1.0;
  matrix_1(0, 1) = 2.0;
  matrix_1(1, 0) = 3.0;
  matrix_1(1, 1) = 4.0;

  int rows_new = 4;
  matrix_1.set_rows(rows_new);

  S21Matrix result = S21Matrix(rows_new, 2);
  result(0, 0) = 1.0;
  result(0, 1) = 2.0;
  result(1, 0) = 3.0;
  result(1, 1) = 4.0;
  result(2, 0) = 0.0;
  result(2, 1) = 0.0;
  result(3, 0) = 0.0;
  result(3, 1) = 0.0;

  EXPECT_TRUE(result == matrix_1);
}

TEST(SetRowsMutatorTest, RowsLessSize) {
  S21Matrix matrix_1 = S21Matrix(2, 2);
  matrix_1(0, 0) = 1.0;
  matrix_1(0, 1) = 2.0;
  matrix_1(1, 0) = 3.0;
  matrix_1(1, 1) = 4.0;
  int rows_new = 1;
  matrix_1.set_rows(rows_new);

  S21Matrix result = S21Matrix(rows_new, 2);
  result(0, 0) = 1.0;
  result(0, 1) = 2.0;

  EXPECT_TRUE(result == matrix_1);
}

TEST(SetColsMutatorTest, ColsGreaterSize) {
  S21Matrix matrix_1 = S21Matrix(2, 2);
  matrix_1(0, 0) = 1.0;
  matrix_1(0, 1) = 2.0;
  matrix_1(1, 0) = 3.0;
  matrix_1(1, 1) = 4.0;

  int cols_new = 4;
  matrix_1.set_cols(cols_new);

  S21Matrix result = S21Matrix(2, cols_new);
  result(0, 0) = 1.0;
  result(0, 1) = 2.0;
  result(0, 2) = 0.0;
  result(0, 3) = 0.0;
  result(1, 0) = 3.0;
  result(1, 1) = 4.0;
  result(1, 2) = 0.0;
  result(1, 3) = 0.0;

  EXPECT_TRUE(result == matrix_1);
}

TEST(SetColsMutatorTest, ColsLessSize) {
  S21Matrix matrix_1 = S21Matrix(2, 2);
  matrix_1(0, 0) = 1.0;
  matrix_1(0, 1) = 2.0;
  matrix_1(1, 0) = 3.0;
  matrix_1(1, 1) = 4.0;

  int cols_new = 1;
  matrix_1.set_cols(cols_new);

  S21Matrix result = S21Matrix(2, cols_new);
  result(0, 0) = 1.0;
  result(1, 0) = 3.0;

  EXPECT_TRUE(result == matrix_1);
}

// TEST(SetRowsMutatorTest, RowsOutOfRange) {
//     S21Matrix matrix_1 = S21Matrix(2, 2);
//     EXPECT_THROW(matrix_1.set_rows(-1), std::out_of_range);
// }

// TEST(SetColsMutatorTest, OutOfRange) {
//     S21Matrix matrix_1 = S21Matrix(2, 2);
//     EXPECT_THROW(matrix_1.set_cols(-1), std::out_of_range);
// }