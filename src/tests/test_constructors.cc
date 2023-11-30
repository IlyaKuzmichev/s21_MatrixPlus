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

TEST(ConstructorsTest, DefaultConstructor) {
  S21Matrix m;

  EXPECT_EQ(m.GetCols(), 0);
  EXPECT_EQ(m.GetRows(), 0);
}

TEST(ConstructorsTest, ParametrizedConstructor) {
  S21Matrix m1(1, 2), m2(1, 1);

  EXPECT_EQ(m1.GetCols(), 2);
  EXPECT_EQ(m1.GetRows(), 1);
  EXPECT_EQ(m2.GetCols(), 1);
  EXPECT_EQ(m2.GetRows(), 1);
}

TEST(ConstructorsTest, CopyConstructor) {
  S21Matrix m1(2, 2);
  std::vector<double> vect = MATRIX_2_2;
  FillMatrixFromVector(m1, vect);
  S21Matrix m2(m1);

  EXPECT_TRUE(m1.EqMatrix(m2));
  EXPECT_TRUE(m2.EqMatrix(m1));
}

TEST(ConstructorsTest, MoveConstructor) {
  S21Matrix m1(2, 2);
  std::vector<double> vect = MATRIX_2_2;
  FillMatrixFromVector(m1, vect);
  S21Matrix m2(m1);
  S21Matrix m3(std::move(m1));

  EXPECT_EQ(m1.GetRows(), 0);
  EXPECT_EQ(m1.GetCols(), 0);
  EXPECT_TRUE(m2.EqMatrix(m3));
}

TEST(ConstructorsTest, IncorrectSize) {
  EXPECT_THROW(S21Matrix m(0, 1), std::invalid_argument);
}

TEST(ConstructorsTest, IncorrectSizeCopy) {
  S21Matrix m1;
  EXPECT_THROW(S21Matrix m2(m1), std::invalid_argument);
}
