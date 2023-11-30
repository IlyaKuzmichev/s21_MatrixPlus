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

void FillMatrixFromVector(S21Matrix& m, const std::vector<double>& vect) {
  auto iter = vect.begin();
  for (int i = 0; i < m.GetRows() && iter != vect.end(); ++i) {
    for (int j = 0; j < m.GetCols() && iter != vect.end(); ++j) {
      m(i, j) = *iter;
      ++iter;
    }
  }
}
