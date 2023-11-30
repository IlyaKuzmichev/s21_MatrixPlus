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
#ifndef SRC_TESTS_TEST_MATRIX_H_
#define SRC_TESTS_TEST_MATRIX_H_

#include <gtest/gtest.h>

#include <vector>

#include "library/s21_matrix_oop.h"

#define MATRIX_1_1 \
  { 5 }
#define MATRIX_2_2 \
  { 1, 2, 3, 4 }
#define MATRIX_2_2_AN \
  { 4, 3, 2, 1 }
#define MATRIX_3_3 \
  { 4, 8, 15, 16, 0, -3, 5, -1, -16 }
#define MATRIX_1_3 \
  { 1, -1, 2 }
#define MATRIX_2_3 \
  { -5, 0, 3, -4, -7, 1 }

void FillMatrixFromVector(S21Matrix& m, const std::vector<double>& vect);

#endif  // SRC_TESTS_TEST_MATRIX_H_
