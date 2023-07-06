#include "unit_test.h"

TEST(GetRowsAccessorTest, RowsReceived) {
  int rows = 3;
  int cols = 5;
  Matrix matrix_1 = Matrix(rows, cols);
  EXPECT_EQ(matrix_1.get_rows(), rows);
}

TEST(GetColsAccessorTest, ColsReceived) {
  int rows = 3;
  int cols = 5;
  Matrix matrix_1 = Matrix(rows, cols);
  EXPECT_EQ(matrix_1.get_cols(), cols);
}