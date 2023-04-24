#include "unit_test.h"

TEST(SubOperationTest, SameSize) {
  S21Matrix matrix_1 = S21Matrix(2, 2);
  matrix_1(0, 0) = 1.0;
  matrix_1(0, 1) = 2.0;
  matrix_1(1, 0) = 3.0;
  matrix_1(1, 1) = 4.0;
  S21Matrix matrix_2 = S21Matrix(2, 2);
  matrix_2(0, 0) = 4.0;
  matrix_2(0, 1) = 5.6;
  matrix_2(1, 0) = 6.0;
  matrix_2(1, 1) = 10.0;

  matrix_1.SubMatrix(matrix_2);

  S21Matrix result = S21Matrix(2, 2);
  result(0, 0) = -3.0;
  result(0, 1) = -3.6;
  result(1, 0) = -3.0;
  result(1, 1) = -6.0;

  EXPECT_TRUE(matrix_1 == result);
}

TEST(SubOperatorTest, SameSize) {
  S21Matrix matrix_1 = S21Matrix(2, 2);
  matrix_1(0, 0) = 1.0;
  matrix_1(0, 1) = 2.0;
  matrix_1(1, 0) = 3.0;
  matrix_1(1, 1) = 4.0;
  S21Matrix matrix_2 = S21Matrix(2, 2);
  matrix_2(0, 0) = 4.0;
  matrix_2(0, 1) = 5.6;
  matrix_2(1, 0) = 6.0;
  matrix_2(1, 1) = 10.0;

  S21Matrix matrix_3 = matrix_1 - matrix_2;

  S21Matrix result = S21Matrix(2, 2);
  result(0, 0) = -3.0;
  result(0, 1) = -3.6;
  result(1, 0) = -3.0;
  result(1, 1) = -6.0;

  EXPECT_TRUE(matrix_3 == result);
}

TEST(SubAssignOperatorTest, SameSize) {
  S21Matrix matrix_1 = S21Matrix(2, 2);
  matrix_1(0, 0) = 1.0;
  matrix_1(0, 1) = 2.0;
  matrix_1(1, 0) = 3.0;
  matrix_1(1, 1) = 4.0;
  S21Matrix matrix_2 = S21Matrix(2, 2);
  matrix_2(0, 0) = 4.0;
  matrix_2(0, 1) = 5.6;
  matrix_2(1, 0) = 6.0;
  matrix_2(1, 1) = 10.0;

  matrix_1 -= matrix_2;

  S21Matrix result = S21Matrix(2, 2);
  result(0, 0) = -3.0;
  result(0, 1) = -3.6;
  result(1, 0) = -3.0;
  result(1, 1) = -6.0;

  EXPECT_TRUE(matrix_1 == result);
}

// TEST(SubOperationTest, DifferentSize) {
//     S21Matrix matrix_1 = init(3, 3, 3.0);
//     S21Matrix matrix_2 = init(2, 2, 2.0);
//     EXPECT_THROW(matrix_1.SubMatrix(matrix_2), std::out_of_range);
// }

// TEST(SubOperatorTest, DifferentSize) {
//     S21Matrix matrix_1(2, 3);
//     S21Matrix matrix_2(4, 2);
//     EXPECT_THROW(matrix_1 - matrix_2, std::out_of_range);
// }

// TEST(SubAssignOperatorTest, DifferentSize) {
//     S21Matrix matrix_1(2, 3);
//     S21Matrix matrix_2(4, 2);
//     EXPECT_THROW(matrix_1 -= matrix_2, std::out_of_range);
// }