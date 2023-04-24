#include "unit_test.h"

TEST(TransposeOperationTest, 1x1) {
  S21Matrix matrix_1(1, 1);
  matrix_1(0, 0) = 123.345;

  S21Matrix matrix_2 = matrix_1.Transpose();

  S21Matrix result(1, 1);
  result(0, 0) = 123.345;

  EXPECT_TRUE(matrix_2 == result);
}

TEST(TransposeOperationTest, 3x2) {
  S21Matrix matrix_1(3, 2);
  matrix_1(0, 0) = 1.0;
  matrix_1(0, 1) = 4.0;
  matrix_1(1, 0) = 2.0;
  matrix_1(1, 1) = 5.0;
  matrix_1(2, 0) = 3.0;
  matrix_1(2, 1) = 6.0;

  S21Matrix matrix_2 = matrix_1.Transpose();

  S21Matrix result(2, 3);
  result(0, 0) = 1.0;
  result(0, 1) = 2.0;
  result(0, 2) = 3.0;
  result(1, 0) = 4.0;
  result(1, 1) = 5.0;
  result(1, 2) = 6.0;

  EXPECT_TRUE(matrix_2 == result);
}
