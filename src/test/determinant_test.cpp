#include "unit_test.h"

TEST(DeterminantOperationTest, 1x1) {
  S21Matrix matrix(1, 1);
  matrix(0, 0) = 234.2312;
  EXPECT_DOUBLE_EQ(matrix.Determinant(), 234.2312);
}

TEST(DeterminantOperationTest, 2x2) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1.23;
  matrix(0, 1) = 2.83;
  matrix(1, 0) = 3.63;
  matrix(1, 1) = 4.33;
  EXPECT_DOUBLE_EQ(matrix.Determinant(), -4.947);
}

TEST(DeterminantOperationTest, 3x3) {
  S21Matrix matrix(3, 3);
  matrix(0, 0) = 1.0;
  matrix(0, 1) = 32.12;
  matrix(0, 2) = 432.12;
  matrix(1, 0) = 2.32;
  matrix(1, 1) = 123.12;
  matrix(1, 2) = 0.453;
  matrix(2, 0) = 3.34;
  matrix(2, 1) = 42.12;
  matrix(2, 2) = 345.21;
  EXPECT_DOUBLE_EQ(matrix.Determinant(), -118663.3809096);
}

TEST(DeterminantOperationTest, 4x4) {
  S21Matrix matrix(4, 4);
  matrix(0, 0) = 1.0;
  matrix(0, 1) = 5.2;
  matrix(0, 2) = 2.6;
  matrix(0, 3) = 7.2;
  matrix(1, 0) = 1.4;
  matrix(1, 1) = 5.2;
  matrix(1, 2) = 7.3;
  matrix(1, 3) = 3.1;
  matrix(2, 0) = 6.2;
  matrix(2, 1) = 5.2;
  matrix(2, 2) = 6.2;
  matrix(2, 3) = 2.2;
  matrix(3, 0) = 2.2;
  matrix(3, 1) = 6.2;
  matrix(3, 2) = 0.1;
  matrix(3, 3) = 5.1;
  EXPECT_DOUBLE_EQ(matrix.Determinant(), -672.3544);
}

// TEST(DeterminantOperationTest, NotSquare) {
//     S21Matrix matrix(1,2);
//     EXPECT_THROW(matrix.Determinant(), std::invalid_argument);
// }
