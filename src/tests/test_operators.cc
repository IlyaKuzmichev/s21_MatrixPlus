/* ==========================================================================*/
/* Copyright 2023 © Moscow, Russian Federaion
 *
 * This file contains Original Code created by
 * Ilya Kuzmichev aka wilmerno.
 *
 * The Original Code and all software developed in the process of
 * participation on learning by experimental programming educational method.
 * The whole methodology was developed and distributed by
 * Autonomous non-profit organization «School 21» (ANO «School 21»).
 *
 * Redistribution and use of this file, its parts, or entire project
 * are permitted by confirmation of its original creator.
 */
/* ==========================================================================*/
#include <vector>

#include "tests/test_matrix.h"

TEST(OperatorsTest, OperatorPlus) {
  S21Matrix m1(2, 3);
  S21Matrix m2(2, 3);
  std::vector<double> vect = MATRIX_2_3;
  FillMatrixFromVector(m1, vect);
  FillMatrixFromVector(m2, vect);
  S21Matrix result = m1 + m2;
  m1.SumMatrix(m2);

  EXPECT_TRUE(m1.EqMatrix(result));
}

TEST(OperatorsTest, OperatorMinus) {
  S21Matrix m1(2, 3);
  S21Matrix m2(2, 3);
  std::vector<double> vect = MATRIX_2_3;
  FillMatrixFromVector(m1, vect);
  FillMatrixFromVector(m2, vect);
  S21Matrix result = m1 - m2;
  m1.SubMatrix(m2);

  EXPECT_TRUE(m1.EqMatrix(result));
}

TEST(OperatorsTest, OperatorMul) {
  S21Matrix m1(2, 3);
  S21Matrix m2(3, 3);
  std::vector<double> vect1 = MATRIX_2_3;
  std::vector<double> vect2 = MATRIX_3_3;
  FillMatrixFromVector(m1, vect1);
  FillMatrixFromVector(m2, vect2);
  S21Matrix result = m1 * m2;
  m1.MulMatrix(m2);

  EXPECT_TRUE(m1.EqMatrix(result));
}

TEST(OperatorsTest, OperatorMulNumber) {
  S21Matrix m(1, 3);
  std::vector<double> vect = MATRIX_1_3;
  FillMatrixFromVector(m, vect);
  S21Matrix result1 = m * 3.14;
  S21Matrix result2 = 3.14 * m;
  m.MulNumber(3.14);

  EXPECT_TRUE(m.EqMatrix(result1));
  EXPECT_TRUE(m.EqMatrix(result2));
}

TEST(OperatorsTest, OperatorEquity) {
  S21Matrix m1(3, 3);
  S21Matrix m2(3, 3);
  std::vector<double> vect = MATRIX_3_3;
  FillMatrixFromVector(m1, vect);
  FillMatrixFromVector(m2, vect);
  m1 *= 2;
  m1 *= 0.5;
  EXPECT_TRUE(m1 == m2);
}

TEST(OperatorsTest, OperatorAsignment) {
  S21Matrix m1(2, 2);
  std::vector<double> vect = MATRIX_1_3;
  FillMatrixFromVector(m1, vect);
  m1 = m1;
  S21Matrix m2 = m1;
  S21Matrix m3;
  m3 = m2;
  S21Matrix m4(1, 1);
  m4 = m1;
  EXPECT_TRUE(m1.EqMatrix(m2) && m1.EqMatrix(m3) && m1.EqMatrix(m4));
}

TEST(OperatorsTest, OperatorPlusEq) {
  S21Matrix m1(2, 2);
  S21Matrix m2(2, 2);
  std::vector<double> vect = MATRIX_2_2;
  FillMatrixFromVector(m1, vect);
  FillMatrixFromVector(m2, vect);
  m1 += m2;
  m2.SumMatrix(m2);
  EXPECT_TRUE(m1.EqMatrix(m2));
}

TEST(OperatorsTest, OperatorMinusEq) {
  S21Matrix m1(2, 2);
  S21Matrix m2(2, 2);
  std::vector<double> vect = MATRIX_2_2;
  FillMatrixFromVector(m1, vect);
  FillMatrixFromVector(m2, vect);
  m1 -= m2;
  m2.SubMatrix(m2);
  EXPECT_TRUE(m1.EqMatrix(m2));
}

TEST(OperatorsTest, OperatorMulEq) {
  S21Matrix m1(2, 2);
  S21Matrix m2(2, 2);
  std::vector<double> vect = MATRIX_2_2;
  FillMatrixFromVector(m1, vect);
  FillMatrixFromVector(m2, vect);
  m1 *= m2;
  m2.MulMatrix(m2);
  EXPECT_TRUE(m1.EqMatrix(m2));
}

TEST(OperatorsTest, OperatorMulEqNumber) {
  S21Matrix m1(2, 2);
  S21Matrix m2(2, 2);
  std::vector<double> vect = MATRIX_2_2;
  FillMatrixFromVector(m1, vect);
  FillMatrixFromVector(m2, vect);
  m1 *= 3.14;
  m2.MulNumber(3.14);
  EXPECT_TRUE(m1.EqMatrix(m2));
}

TEST(OperatorsTest, OperatorBrackets) {
  S21Matrix m(1, 1);
  m(0, 0) = 1.;
  const S21Matrix mc = m;
  std::vector<double> vect = MATRIX_1_1;

  EXPECT_DOUBLE_EQ(mc(0, 0), 1.);
  EXPECT_DOUBLE_EQ(m.Determinant(), 1.);
  EXPECT_DOUBLE_EQ(m(0, 0), 1.);

  FillMatrixFromVector(m, vect);
  EXPECT_DOUBLE_EQ(m.Determinant(), 5.);
  EXPECT_DOUBLE_EQ(m(0, 0), 5.);
}

TEST(OperatorsTest, OperatorBracketsIncorrectIndex_1) {
  S21Matrix m(1, 1);

  EXPECT_THROW(m(1, 2), std::out_of_range);
}

TEST(OperatorsTest, OperatorBracketsIncorrectIndex_2) {
  S21Matrix m(1, 1);

  EXPECT_THROW(m(2, 1), std::out_of_range);
}

TEST(OperatorsTest, OperatorBracketsIncorrectIndex_3) {
  S21Matrix m(1, 1);

  EXPECT_THROW(m(1, -1), std::out_of_range);
}

TEST(OperatorsTest, OperatorBracketsIncorrectIndex_4) {
  S21Matrix m(1, 1);

  EXPECT_THROW(m(-1, 1), std::out_of_range);
}

TEST(OperatorsTest, OperatorBracketsIncorrectIndex_5) {
  S21Matrix m(1, 1);

  EXPECT_THROW(m(1, 2) = 3, std::out_of_range);
}

TEST(OperatorsTest, OperatorBracketsIncorrectIndex_6) {
  S21Matrix m(1, 1);
  const S21Matrix mc = m;

  EXPECT_THROW(mc(1, 2), std::out_of_range);
}

TEST(OperatorsTest, OperatorBracketsIncorrectIndex_7) {
  S21Matrix m(1, 1);
  const S21Matrix mc = m;

  EXPECT_THROW(mc(-1, -1), std::out_of_range);
}
