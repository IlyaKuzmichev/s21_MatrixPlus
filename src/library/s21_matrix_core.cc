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
#include <stdexcept>

#include "library/s21_matrix_oop.h"

S21Matrix::S21Matrix() : rows_(0), cols_(0), matrix_(nullptr) {}

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  CheckSize();
  InitMatrix();
}

S21Matrix::S21Matrix(const S21Matrix& other)
    : rows_(other.rows_), cols_(other.cols_) {
  CheckSize();
  InitMatrix();
  CopyMatrix(other);
}

S21Matrix::S21Matrix(S21Matrix&& other) noexcept
    : rows_(other.rows_), cols_(other.cols_) {
  matrix_ = other.matrix_;
  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = nullptr;
}

S21Matrix::~S21Matrix() { FreeMatrix(); }

void S21Matrix::InitMatrix() {
  matrix_ = new double* [rows_] {};
  for (int i = 0; i < rows_; ++i) {
    matrix_[i] = new double[cols_]{0.};
  }
}

void S21Matrix::CheckSize() const {
  if (rows_ < 1 || cols_ < 1) {
    throw std::invalid_argument("Size of matrix is not correct!");
  }
}

void S21Matrix::CheckSize(const S21Matrix& other) const {
  if (this->rows_ != other.rows_ || this->cols_ != other.cols_) {
    throw std::invalid_argument("Matrices has different sizes!");
  }
}

void S21Matrix::CopyMatrix(const S21Matrix& other) {
  for (int i = 0; i < rows_ && i < other.rows_; ++i) {
    for (int j = 0; j < cols_ && j < other.cols_; ++j) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

void S21Matrix::FreeMatrix() {
  for (int i = 0; i < rows_; ++i) {
    delete[] matrix_[i];
  }
  delete[] matrix_;

  matrix_ = nullptr;
}

int S21Matrix::GetRows() const noexcept { return rows_; }

int S21Matrix::GetCols() const noexcept { return cols_; }

void S21Matrix::SetRows(int rows) {
  S21Matrix temp(rows, cols_);
  temp.CopyMatrix(*this);
  std::swap(*this, temp);
}

void S21Matrix::SetCols(int cols) {
  S21Matrix temp(rows_, cols);
  temp.CopyMatrix(*this);
  std::swap(*this, temp);
}
