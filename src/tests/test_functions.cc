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

TEST(FunctionsTest, EqMatrix) {
  S21Matrix m1(1, 1);
  S21Matrix m2(1, 1);
  std::vector<double> vect1 = MATRIX_1_1;
  FillMatrixFromVector(m1, vect1);
  FillMatrixFromVector(m2, vect1);

  EXPECT_TRUE(m1.EqMatrix(m2));

  S21Matrix m3(2, 2);
  S21Matrix m4(2, 2);
  std::vector<double> vect2 = MATRIX_2_2;
  FillMatrixFromVector(m3, vect2);
  FillMatrixFromVector(m4, vect2);

  EXPECT_FALSE(m1.EqMatrix(m3));
  EXPECT_TRUE(m3.EqMatrix(m4));

  std::vector<double> vect3 = MATRIX_2_2_AN;
  FillMatrixFromVector(m4, vect3);
  EXPECT_FALSE(m3.EqMatrix(m4));
}

TEST(FunctionsTest, SumMatrix) {
  S21Matrix m1(3, 3);
  S21Matrix m2(3, 3);
  std::vector<double> vect = MATRIX_3_3;
  FillMatrixFromVector(m1, vect);
  FillMatrixFromVector(m2, vect);
  m1.SumMatrix(m2);
  for (int i = 0; i < m1.GetRows(); ++i) {
    for (int j = 0; j < m1.GetCols(); ++j) {
      EXPECT_DOUBLE_EQ(m1(i, j), m2(i, j) * 2.);
    }
  }
}

TEST(FunctionsTest, SumMatrixIncorrect) {
  S21Matrix m1(1, 2);
  S21Matrix m2(2, 1);

  EXPECT_THROW(m1.SumMatrix(m2), std::invalid_argument);
}

TEST(FunctionsTest, SubMatrix) {
  S21Matrix m1(3, 3);
  S21Matrix m2(3, 3);
  std::vector<double> vect = MATRIX_3_3;
  FillMatrixFromVector(m1, vect);
  FillMatrixFromVector(m2, vect);
  m1.SubMatrix(m2);
  for (int i = 0; i < m1.GetRows(); ++i) {
    for (int j = 0; j < m1.GetCols(); ++j) {
      EXPECT_DOUBLE_EQ(m1(i, j), 0.);
    }
  }
}

TEST(FunctionsTest, SubMatrixIncorrect) {
  S21Matrix m1(1, 2);
  S21Matrix m2(2, 1);

  EXPECT_THROW(m1.SubMatrix(m2), std::invalid_argument);
}

TEST(FunctionsTest, NulNumber) {
  S21Matrix m1(3, 3);
  std::vector<double> vect = MATRIX_3_3;
  FillMatrixFromVector(m1, vect);
  m1.MulNumber(3.14);
  int iter = 0;
  for (int i = 0; i < m1.GetRows(); ++i) {
    for (int j = 0; j < m1.GetCols(); ++j) {
      EXPECT_DOUBLE_EQ(m1(i, j), vect[iter] * 3.14);
      ++iter;
    }
  }
}

TEST(FunctionsTest, MulMatrix) {
  S21Matrix m1(1, 1);
  S21Matrix m2(1, 3);
  std::vector<double> vect = MATRIX_1_3;
  FillMatrixFromVector(m2, vect);
  m1(0, 0) = 2.;
  m1.MulMatrix(m2);
  for (int i = 0; i < m1.GetRows(); ++i) {
    for (int j = 0; j < m1.GetCols(); ++j) {
      EXPECT_DOUBLE_EQ(m1(i, j), m2(i, j) * 2.);
    }
  }

  m1.SetCols(3);
  m1.SetRows(3);
  m2.SetRows(3);
  m2.SetCols(3);
  S21Matrix result(3, 3);
  std::vector<double> vect1 = {1.2, 2.4, 3.6, 4.8, 6.0, 7.2, 8.4, 9.6, 10.8};
  std::vector<double> vect2 = {3.5,  7.0,  10.5, 14.0, 17.5,
                               21.0, 24.5, 28.0, 31.5};
  std::vector<double> vect_res = {126,   151.2, 176.4, 277.2, 340.2,
                                  403.2, 428.4, 529.2, 630};

  FillMatrixFromVector(m1, vect1);
  FillMatrixFromVector(m2, vect2);
  FillMatrixFromVector(result, vect_res);
  m1.MulMatrix(m2);
  EXPECT_TRUE(m1.EqMatrix(result));
}

TEST(FunctionsTest, MulMatrixIncorrect) {
  S21Matrix m1(1, 2);
  S21Matrix m2(1, 2);

  EXPECT_THROW(m1.MulMatrix(m2), std::invalid_argument);
}

TEST(FunctionsTest, Transpose) {
  S21Matrix m(2, 3);
  S21Matrix res;
  std::vector<double> vect = MATRIX_2_3;
  FillMatrixFromVector(m, vect);
  res = m.Transpose();
  for (int i = 0; i < res.GetRows(); ++i) {
    for (int j = 0; j < res.GetCols(); ++j) {
      EXPECT_DOUBLE_EQ(res(i, j), m(j, i));
    }
  }
}

TEST(FunctionsTest, Determinant) {
  S21Matrix m1(1, 1);
  S21Matrix m2(2, 2);
  S21Matrix m3(5, 5);
  std::vector<double> vect1 = MATRIX_1_1;
  std::vector<double> vect2 = MATRIX_2_2;
  std::vector<double> vect3 = {1,  2,  3,  4,  5,  6,  7,   8, 9,
                               10, 11, 12, 49, 14, 15, 161, 7, 18,
                               19, 20, 64, 48, 1,  2,  3};
  FillMatrixFromVector(m1, vect1);
  FillMatrixFromVector(m2, vect2);
  FillMatrixFromVector(m3, vect3);

  EXPECT_DOUBLE_EQ(m1.Determinant(), 5.);
  EXPECT_DOUBLE_EQ(m2.Determinant(), -2.);
  EXPECT_DOUBLE_EQ(m3.Determinant(), -1369800.);
}

TEST(FunctionsTest, DeterminantIncorrect_1) {
  S21Matrix m;

  EXPECT_THROW(m.Determinant(), std::invalid_argument);
}

TEST(FunctionsTest, DeterminantIncorrect_2) {
  S21Matrix m(2, 1);

  EXPECT_THROW(m.Determinant(), std::invalid_argument);
}

TEST(FunctionsTest, CalcComplements) {
  S21Matrix m(3, 3);
  S21Matrix expected(3, 3);
  S21Matrix result;
  std::vector<double> vect = {1, 2, 3, 0, 4, 2, 5, 2, 1};
  std::vector<double> vect_res = {0, 10, -20, 4, -14, 8, -8, -2, 4};
  FillMatrixFromVector(m, vect);
  FillMatrixFromVector(expected, vect_res);
  result = m.CalcComplements();

  EXPECT_TRUE(result.EqMatrix(expected));

  vect = {1, 2, 3, 0, 4, 2, 5, 2, 1};
  vect_res = {0, 10, -20, 4, -14, 8, -8, -2, 4};
  FillMatrixFromVector(m, vect);
  FillMatrixFromVector(expected, vect_res);
  result = m.CalcComplements();

  EXPECT_TRUE(result.EqMatrix(expected));
}

TEST(FunctionsTest, ComplimentIncorrect_1) {
  S21Matrix m;

  EXPECT_THROW(m.CalcComplements(), std::invalid_argument);
}

TEST(FunctionsTest, ComplimentIncorrect_2) {
  S21Matrix m(1, 1);

  EXPECT_THROW(m.CalcComplements(), std::invalid_argument);
}

TEST(FunctionsTest, ComplimentIncorrect_3) {
  S21Matrix m(2, 1);

  EXPECT_THROW(m.CalcComplements(), std::invalid_argument);
}

TEST(FunctionsTest, InverseMatrix) {
  S21Matrix m(3, 3);
  S21Matrix expected(3, 3);
  S21Matrix result;
  std::vector<double> vect = {2, 5, 7, 6, 3, 4, 5, -2, -3};
  std::vector<double> vect_res = {1, -1, 1, -38, 41, -34, 27, -29, 24};
  FillMatrixFromVector(m, vect);
  FillMatrixFromVector(expected, vect_res);
  result = m.InverseMatrix();

  EXPECT_TRUE(result.EqMatrix(expected));

  vect = {4, 3, 2, 1, 2, 3, 4, 5, 5};
  vect_res = {1, 1, -1, -1.4, -2.4, 2, 0.6, 1.6, -1};
  FillMatrixFromVector(m, vect);
  FillMatrixFromVector(expected, vect_res);
  result = m.InverseMatrix();

  EXPECT_TRUE(result.EqMatrix(expected));

  S21Matrix m1(1, 1);
  m1(0, 0) = 4.;
  result = m1.InverseMatrix();

  EXPECT_DOUBLE_EQ(result(0, 0), 0.25);
}

TEST(FunctionsTest, InverseIncorrect_1) {
  S21Matrix m;

  EXPECT_THROW(m.InverseMatrix(), std::invalid_argument);
}

TEST(FunctionsTest, InverseIncorrect_2) {
  S21Matrix m(1, 1);
  m(0, 0) = 0;

  EXPECT_THROW(m.InverseMatrix(), std::invalid_argument);
}

TEST(FunctionsTest, InverseIncorrect_3) {
  S21Matrix m(2, 1);

  EXPECT_THROW(m.InverseMatrix(), std::invalid_argument);
}
