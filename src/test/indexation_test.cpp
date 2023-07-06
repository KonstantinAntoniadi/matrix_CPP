#include "unit_test.h"

TEST(IndexationOperatorTest, IndexesInTheRange) {
  Matrix matrix_1 = Matrix(2, 2);
  matrix_1(0, 0) = 1.0;
  matrix_1(0, 1) = 2.0;
  matrix_1(1, 0) = 3.0;
  matrix_1(1, 1) = 4.0;

  EXPECT_DOUBLE_EQ(matrix_1(1, 1), 4.0);
}

// TEST(IndexationOperatorTest, IndexesOutOfRange) {
//     Matrix matrix_1 = Matrix(2, 2);
//     matrix_1(0,0) = 1.0;
//     matrix_1(0,1) = 2.0;
//     matrix_1(1,0) = 3.0;
//     matrix_1(1,1) = 4.0;

//     EXPECT_THROW(matrix_1(3,1), std::out_of_range);
// }