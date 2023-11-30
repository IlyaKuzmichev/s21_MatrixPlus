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
#include <stdexcept>

#include "library/s21_matrix_oop.h"

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  if (this == &other) {
    return *this;
  }
  FreeMatrix();
  rows_ = other.rows_;
  cols_ = other.cols_;
  InitMatrix();
  CopyMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator=(S21Matrix&& other) noexcept {
  if (this == &other) {
    return *this;
  }
  FreeMatrix();
  rows_ = other.rows_;
  cols_ = other.cols_;
  InitMatrix();
  CopyMatrix(other);
  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = nullptr;
  return *this;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  SumMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  SubMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  MulMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const double num) {
  MulNumber(num);
  return *this;
}

S21Matrix operator+(S21Matrix m1, const S21Matrix& m2) {
  m1 += m2;
  return m1;
}

S21Matrix operator-(S21Matrix m1, const S21Matrix& m2) {
  m1 -= m2;
  return m1;
}

S21Matrix operator*(S21Matrix m1, const S21Matrix& m2) {
  m1 *= m2;
  return m1;
}

S21Matrix operator*(S21Matrix m1, const double num) {
  m1 *= num;
  return m1;
}

S21Matrix operator*(const double num, S21Matrix m1) {
  m1 *= num;
  return m1;
}

bool operator==(const S21Matrix& m1, const S21Matrix& m2) noexcept {
  return m1.EqMatrix(m2);
}

double& S21Matrix::operator()(int row, int col) {
  if (row >= rows_ || col >= cols_ || row < 0 || col < 0) {
    throw std::out_of_range("Incorrect indexes of matrix!");
  }
  return matrix_[row][col];
}
const double& S21Matrix::operator()(int row, int col) const {
  if (row >= rows_ || col >= cols_ || row < 0 || col < 0) {
    throw std::out_of_range("Incorrect indexes of matrix!");
  }
  return matrix_[row][col];
}
