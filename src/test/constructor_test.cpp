#include "unit_test.h"

TEST(ConstructorTest, WithoutRowsAndCols) {
  Matrix matrix_1 = Matrix();
  Matrix matrix_2 = Matrix(3, 3);

  EXPECT_TRUE(matrix_1 == matrix_2);
}

TEST(ConstructorTest, WithRowsAndCols) {
  int rows = 3;
  int cols = 5;
  Matrix matrix(rows, cols);

  EXPECT_EQ(matrix.get_rows(), rows);
  EXPECT_EQ(matrix.get_cols(), cols);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      EXPECT_DOUBLE_EQ(matrix(i, j), 0.0);
    }
  }
}

TEST(ConstructorTest, CopyConstructor) {
  Matrix matrix_1 = Matrix(3, 2);
  matrix_1(0, 0) = 1.123456;
  matrix_1(0, 1) = 4.543564;
  matrix_1(1, 0) = 2.546356;
  matrix_1(1, 1) = 5.454325;
  matrix_1(2, 0) = 3.254562;
  matrix_1(2, 1) = 6.252452;

  Matrix matrix_2 = Matrix(matrix_1);

  EXPECT_TRUE(matrix_1 == matrix_2);
}

TEST(ConstructorTest, MoveConstructor) {
  Matrix matrix_1 = Matrix(2, 2);
  matrix_1(0, 0) = 1.0;
  matrix_1(0, 1) = 2.0;
  matrix_1(1, 0) = 3.0;
  matrix_1(1, 1) = 4.0;
  Matrix matrix_2 = matrix_1 * 12.4;

  matrix_1 = Matrix(std::move(matrix_2));
  Matrix result = Matrix(2, 2);
  result(0, 0) = 12.4;
  result(0, 1) = 24.8;
  result(1, 0) = 37.2;
  result(1, 1) = 49.6;

  EXPECT_TRUE(matrix_1 == result);
  EXPECT_EQ(matrix_2.get_cols(), 0);
  EXPECT_EQ(matrix_2.get_rows(), 0);
}

// TEST(Constructor, error) {
//   EXPECT_THROW(Matrix matrix = Matrix(-3, -3), std::invalid_argument);
// }