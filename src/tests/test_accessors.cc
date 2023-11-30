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

TEST(AccessorsTest, Getter) {
  S21Matrix m1;
  S21Matrix m2(1, 1);
  S21Matrix m3(m2);

  EXPECT_EQ(m1.GetRows(), 0);
  EXPECT_EQ(m1.GetCols(), 0);
  EXPECT_EQ(m2.GetRows(), 1);
  EXPECT_EQ(m2.GetCols(), 1);
  EXPECT_EQ(m3.GetRows(), 1);
  EXPECT_EQ(m3.GetCols(), 1);
}

TEST(AccessorsTest, SetterColsIncrease) {
  S21Matrix m(3, 3);
  std::vector<double> vect = MATRIX_3_3;
  FillMatrixFromVector(m, vect);

  m.SetCols(4);
  EXPECT_EQ(m.GetRows(), 3);
  EXPECT_EQ(m.GetCols(), 4);
  EXPECT_EQ(m(0, 3), 0);
  EXPECT_EQ(m(1, 3), 0);
  EXPECT_EQ(m(2, 3), 0);
}

TEST(AccessorsTest, SetterColsDecrease) {
  S21Matrix m(3, 3);
  std::vector<double> vect = MATRIX_3_3;
  FillMatrixFromVector(m, vect);

  m.SetCols(1);
  EXPECT_EQ(m.GetRows(), 3);
  EXPECT_EQ(m.GetCols(), 1);
  m.SetCols(2);
  EXPECT_EQ(m(0, 1), 0);
  EXPECT_EQ(m(1, 1), 0);
  EXPECT_EQ(m(2, 1), 0);
}

TEST(AccessorsTest, SetterRowsIncrease) {
  S21Matrix m(3, 3);
  std::vector<double> vect = MATRIX_3_3;
  FillMatrixFromVector(m, vect);

  m.SetRows(4);
  EXPECT_EQ(m.GetRows(), 4);
  EXPECT_EQ(m.GetCols(), 3);
  EXPECT_EQ(m(3, 0), 0);
  EXPECT_EQ(m(3, 1), 0);
  EXPECT_EQ(m(3, 2), 0);
}

TEST(AccessorsTest, SetterRowsDecrease) {
  S21Matrix m(3, 3);
  std::vector<double> vect = MATRIX_3_3;
  FillMatrixFromVector(m, vect);

  m.SetRows(1);
  EXPECT_EQ(m.GetRows(), 1);
  EXPECT_EQ(m.GetCols(), 3);
  m.SetRows(2);
  EXPECT_EQ(m(1, 0), 0);
  EXPECT_EQ(m(1, 1), 0);
  EXPECT_EQ(m(1, 2), 0);
}

TEST(AccessorsTest, SetterIncorrectRows) {
  S21Matrix m(2, 2);
  m.SetRows(1);

  EXPECT_THROW(m.SetRows(0), std::invalid_argument);
}

TEST(AccessorsTest, SetterIncorrectCols) {
  S21Matrix m(1, 1);
  m.SetCols(2);

  EXPECT_THROW(m.SetCols(-13), std::invalid_argument);
}
