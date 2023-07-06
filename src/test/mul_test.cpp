#include "unit_test.h"

TEST(MulMatrixOperationTest, SameSize) {
  Matrix matrix_1 = Matrix(2, 2);
  matrix_1(0, 0) = 1.0;
  matrix_1(0, 1) = 2.0;
  matrix_1(1, 0) = 3.0;
  matrix_1(1, 1) = 4.0;

  Matrix matrix_2 = Matrix(2, 2);
  matrix_2(0, 0) = 4.0;
  matrix_2(0, 1) = 5.6;
  matrix_2(1, 0) = 6.0;
  matrix_2(1, 1) = 10.0;

  Matrix result = Matrix(2, 2);
  result(0, 0) = 16.0;
  result(0, 1) = 25.6;
  result(1, 0) = 36.0;
  result(1, 1) = 56.8;
  matrix_1.MulMatrix(matrix_2);

  EXPECT_TRUE(matrix_1 == result);
}

TEST(MulMatrixOperationTest, DifferentSize) {
  Matrix matrix_1 = Matrix(3, 2);
  matrix_1(0, 0) = 1.123456;
  matrix_1(0, 1) = 4.543564;
  matrix_1(1, 0) = 2.546356;
  matrix_1(1, 1) = 5.454325;
  matrix_1(2, 0) = 3.254562;
  matrix_1(2, 1) = 6.252452;

  Matrix matrix_2 = Matrix(2, 3);
  matrix_2(0, 0) = 1.254352;
  matrix_2(0, 1) = 6.245223;
  matrix_2(0, 2) = -1.14245;
  matrix_2(1, 0) = 2.153252;
  matrix_2(1, 1) = 3.132411;
  matrix_2(1, 2) = 4.413214;

  Matrix result = Matrix(3, 3);
  result(0, 0) = 11.19264755064;
  result(0, 1) = 21.248543103492;
  result(0, 2) = 18.768227947496;
  result(1, 0) = 14.938562956212;
  result(1, 1) = 32.987748684963;
  result(1, 2) = 21.16201903835;
  result(2, 0) = 17.545471127728;
  result(2, 1) = 39.910714879098;
  result(2, 2) = 23.875234343828;

  matrix_1.MulMatrix(matrix_2);
  EXPECT_TRUE(matrix_1 == result);
}

TEST(MulMatrixOperatorTest, SameSize) {
  Matrix matrix_1 = Matrix(2, 2);
  matrix_1(0, 0) = 1.0;
  matrix_1(0, 1) = 2.0;
  matrix_1(1, 0) = 3.0;
  matrix_1(1, 1) = 4.0;

  Matrix matrix_2 = Matrix(2, 2);
  matrix_2(0, 0) = 4.0;
  matrix_2(0, 1) = 5.6;
  matrix_2(1, 0) = 6.0;
  matrix_2(1, 1) = 10.0;

  Matrix matrix_3 = matrix_1 * matrix_2;

  Matrix result = Matrix(2, 2);
  result(0, 0) = 16.0;
  result(0, 1) = 25.6;
  result(1, 0) = 36.0;
  result(1, 1) = 56.8;

  EXPECT_TRUE(matrix_3 == result);
}

TEST(MulMatrixAssignOperatorTest, SameSize) {
  Matrix matrix_1 = Matrix(2, 2);
  matrix_1(0, 0) = 1.0;
  matrix_1(0, 1) = 2.0;
  matrix_1(1, 0) = 3.0;
  matrix_1(1, 1) = 4.0;

  Matrix matrix_2 = Matrix(2, 2);
  matrix_2(0, 0) = 4.0;
  matrix_2(0, 1) = 5.6;
  matrix_2(1, 0) = 6.0;
  matrix_2(1, 1) = 10.0;

  matrix_1 *= matrix_2;

  Matrix result = Matrix(2, 2);
  result(0, 0) = 16.0;
  result(0, 1) = 25.6;
  result(1, 0) = 36.0;
  result(1, 1) = 56.8;

  EXPECT_TRUE(matrix_1 == result);
}

TEST(MulNumberOperationTest, 2x2) {
  Matrix matrix = Matrix(2, 2);
  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;
  matrix(1, 0) = 3.0;
  matrix(1, 1) = 4.0;
  matrix.MulNumber(12.4);

  Matrix result = Matrix(2, 2);
  result(0, 0) = 12.4;
  result(0, 1) = 24.8;
  result(1, 0) = 37.2;
  result(1, 1) = 49.6;

  EXPECT_TRUE(matrix == result);
}

TEST(MulMatrixNumberOperatorTest, 2x2) {
  Matrix matrix_1 = Matrix(2, 2);
  matrix_1(0, 0) = 1.0;
  matrix_1(0, 1) = 2.0;
  matrix_1(1, 0) = 3.0;
  matrix_1(1, 1) = 4.0;
  Matrix matrix_2 = matrix_1 * 12.4;

  Matrix result = Matrix(2, 2);
  result(0, 0) = 12.4;
  result(0, 1) = 24.8;
  result(1, 0) = 37.2;
  result(1, 1) = 49.6;

  EXPECT_TRUE(matrix_2 == result);
}

TEST(MulMatrixNumberAssignOperatorTest, 2x2) {
  Matrix matrix = Matrix(2, 2);
  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;
  matrix(1, 0) = 3.0;
  matrix(1, 1) = 4.0;
  matrix *= 12.4;

  Matrix result = Matrix(2, 2);
  result(0, 0) = 12.4;
  result(0, 1) = 24.8;
  result(1, 0) = 37.2;
  result(1, 1) = 49.6;

  EXPECT_TRUE(matrix == result);
}

TEST(MulNumberMatrixOperatorTest, 2x2) {
  Matrix matrix_1 = Matrix(2, 2);
  matrix_1(0, 0) = 1.0;
  matrix_1(0, 1) = 2.0;
  matrix_1(1, 0) = 3.0;
  matrix_1(1, 1) = 4.0;
  Matrix matrix_2 = 12.4 * matrix_1;

  Matrix result = Matrix(2, 2);
  result(0, 0) = 12.4;
  result(0, 1) = 24.8;
  result(1, 0) = 37.2;
  result(1, 1) = 49.6;

  EXPECT_TRUE(matrix_2 == result);
}

// TEST(MulMatrixOperationTest, InvalidMatrix) {
//     Matrix matrix_1 = Matrix(3, 2);
//     Matrix matrix_2 = Matrix(2, 2);

//     EXPECT_THROW(matrix_1.MulMatrix(matrix_2), std::invalid_argument);
// }

// TEST(MulMatrixOperatorTest, DifferentRowsAndCols) {
//     Matrix matrix_1 = Matrix(3, 2);
//     Matrix matrix_2 = Matrix(2, 2);

//     EXPECT_THROW(matrix_1 * matrix_2, std::invalid_argument);
// }