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
#include <algorithm>
#include <cmath>
#include <stdexcept>

#include "library/s21_matrix_oop.h"

bool S21Matrix::EqMatrix(const S21Matrix& other) const noexcept {
  if (this->rows_ != other.rows_ || this->cols_ != other.cols_) {
    return false;
  }
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      if (fabs(matrix_[i][j] - other.matrix_[i][j]) > kMatrixEps) {
        return false;
      }
    }
  }
  return true;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  CheckSize(other);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] += other.matrix_[i][j];
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  CheckSize(other);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] -= other.matrix_[i][j];
    }
  }
}

void S21Matrix::MulNumber(const double num) noexcept {
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] *= num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (cols_ != other.rows_) {
    throw std::invalid_argument("Incompatible sizes of matrices!");
  }
  S21Matrix result(rows_, other.cols_);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < other.cols_; ++j) {
      for (int k = 0; k < cols_; ++k) {
        result.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
      }
    }
  }
  std::swap(*this, result);
}

S21Matrix S21Matrix::Transpose() const noexcept {
  S21Matrix result(cols_, rows_);

  for (int i = 0; i < cols_; ++i) {
    for (int j = 0; j < rows_; ++j) {
      result.matrix_[i][j] = matrix_[j][i];
    }
  }
  return result;
}

double S21Matrix::Determinant() const {
  if (cols_ != rows_ || cols_ < 1) {
    throw std::invalid_argument("Imposible to calculate determinant!");
  }
  if (rows_ == 1) {
    return matrix_[0][0];
  }
  S21Matrix temp(*this);
  double result = 1.;
  for (int i = 0; i < temp.rows_ && fabs(result) > kMatrixEps; ++i) {
    int swap_row = i;
    while (swap_row < rows_ - 1 &&
           fabs(temp.matrix_[swap_row][i]) < kMatrixEps) {
      swap_row++;
    }
    if (swap_row != i) {
      std::swap(temp.matrix_[swap_row], temp.matrix_[i]);
      result *= -1;
    }
    if (fabs(temp.matrix_[i][i]) >= kMatrixEps) {
      result *= temp.matrix_[i][i];
    } else {
      result = 0.;
    }
    for (int j = i + 1; j < temp.rows_ && fabs(result) > kMatrixEps; j++) {
      double multiplier = temp.matrix_[j][i] / temp.matrix_[i][i];
      for (int k = i; k < temp.rows_; k++) {
        temp.matrix_[j][k] -= multiplier * temp.matrix_[i][k];
      }
    }
  }
  return result;
}

void S21Matrix::CreateMinorMatrix(const S21Matrix& other, int row, int col) {
  for (int i = 0, new_row = 0; i < rows_ + 1; i++) {
    if (row != i) {
      for (int j = 0, new_column = 0; j < cols_ + 1; j++) {
        if (col != j) {
          this->matrix_[new_row][new_column++] = other.matrix_[i][j];
        }
      }
      new_row++;
    }
  }
}

S21Matrix S21Matrix::CalcComplements() const {
  if (cols_ != rows_ || cols_ <= 1) {
    throw std::invalid_argument("Matrix has incorrect size to calc complemets");
  }
  S21Matrix result(rows_, cols_);
  S21Matrix minor_matrix(rows_ - 1, cols_ - 1);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      minor_matrix.CreateMinorMatrix(*this, i, j);
      double determinant = minor_matrix.Determinant();
      double sign = (i + j) % 2 == 0 ? 1. : -1.;
      result.matrix_[i][j] = determinant * sign;
    }
  }
  return result;
}

S21Matrix S21Matrix::InverseMatrix() const {
  S21Matrix result(rows_, cols_);
  double determinant = Determinant();
  if (fabs(determinant) < kMatrixEps) {
    throw std::invalid_argument("Imposible to calculate inverse matrix!");
  }
  if (rows_ == 1) {
    result.matrix_[0][0] = 1. / determinant;
  } else {
    result = CalcComplements();
    result = result.Transpose();
    result.MulNumber(1. / determinant);
  }
  return result;
}
