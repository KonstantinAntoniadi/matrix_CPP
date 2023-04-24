#include "unit_test.h"

TEST(CalcComplementsOperationTest, 3x3) {
  S21Matrix matrix_1(3, 3);
  matrix_1(0, 0) = 1.0;
  matrix_1(0, 1) = 2.0;
  matrix_1(0, 2) = 3.0;
  matrix_1(1, 0) = 0.0;
  matrix_1(1, 1) = 4.0;
  matrix_1(1, 2) = 2.0;
  matrix_1(2, 0) = 5.0;
  matrix_1(2, 1) = 2.0;
  matrix_1(2, 2) = 1.0;
  S21Matrix matrix_2 = matrix_1.CalcComplements();

  S21Matrix result(3, 3);
  result(0, 0) = 0.0;
  result(0, 1) = 10.0;
  result(0, 2) = -20.0;
  result(1, 0) = 4.0;
  result(1, 1) = -14.0;
  result(1, 2) = 8.0;
  result(2, 0) = -8.0;
  result(2, 1) = -2.0;
  result(2, 2) = 4.0;

  EXPECT_TRUE(result == matrix_2);
}

// TEST(CalcComplementsOperationTest, NotSquare) {
//     S21Matrix matrix(1,2);
//     EXPECT_THROW(matrix.CalcComplements(), std::invalid_argument);
// }