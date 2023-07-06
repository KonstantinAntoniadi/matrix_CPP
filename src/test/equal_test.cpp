#include "unit_test.h"

TEST(EqualOperationTest, Equal) {
  Matrix matrix_1(3, 2);
  matrix_1(0, 0) = 1.123456;
  matrix_1(0, 1) = 4.543564;
  matrix_1(1, 0) = 2.546356;
  matrix_1(1, 1) = 5.454325;

  Matrix matrix_2(3, 2);
  matrix_2(0, 0) = 1.123456;
  matrix_2(0, 1) = 4.543564;
  matrix_2(1, 0) = 2.546356;
  matrix_2(1, 1) = 5.454325;
  EXPECT_TRUE(matrix_1.EqMatrix(matrix_2));
}

TEST(EqualOperationTest, NotEqual) {
  Matrix matrix_1(3, 2);
  matrix_1(0, 0) = 1.123456;
  matrix_1(0, 1) = 4.543564;
  matrix_1(1, 0) = 2.546356;
  matrix_1(1, 1) = 5.454325;

  Matrix matrix_2(3, 2);
  matrix_2(0, 0) = 2.123456;
  matrix_2(0, 1) = 4.543564;
  matrix_2(1, 0) = 2.546356;
  matrix_2(1, 1) = 5.454325;
  EXPECT_FALSE(matrix_1.EqMatrix(matrix_2));
}

TEST(EqualOperatorTest, Equal) {
  Matrix matrix_1(3, 2);
  matrix_1(0, 0) = 1.123456;
  matrix_1(0, 1) = 4.543564;
  matrix_1(1, 0) = 2.546356;
  matrix_1(1, 1) = 5.454325;

  Matrix matrix_2(3, 2);
  matrix_2(0, 0) = 1.123456;
  matrix_2(0, 1) = 4.543564;
  matrix_2(1, 0) = 2.546356;
  matrix_2(1, 1) = 5.454325;
  EXPECT_TRUE(matrix_1 == matrix_2);
}

TEST(EqualOperatorTest, NotEqual) {
  Matrix matrix_1(3, 2);
  matrix_1(0, 0) = 1.123456;
  matrix_1(0, 1) = 4.543564;
  matrix_1(1, 0) = 2.546356;
  matrix_1(1, 1) = 5.454325;

  Matrix matrix_2(3, 2);
  matrix_2(0, 0) = 2.123456;
  matrix_2(0, 1) = 4.543564;
  matrix_2(1, 0) = 2.546356;
  matrix_2(1, 1) = 5.454325;
  EXPECT_FALSE(matrix_1 == matrix_2);
}