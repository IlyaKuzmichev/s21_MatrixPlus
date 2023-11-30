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
#ifndef SRC_LIBRARY_S21_MATRIX_OOP_H_
#define SRC_LIBRARY_S21_MATRIX_OOP_H_
class S21Matrix {
 public:
  S21Matrix();                                       // Default constructor
  S21Matrix(int rows, int cols);                     // Parametrized constructor
  S21Matrix(const S21Matrix& other);                 // Copy constructor
  S21Matrix& operator=(const S21Matrix& other);      // Copy assignment operator
  S21Matrix(S21Matrix&& other) noexcept;             // Move constructor
  S21Matrix& operator=(S21Matrix&& other) noexcept;  // Move assignment operator

  ~S21Matrix();  // Destructor

  // Class Functions
  bool EqMatrix(const S21Matrix& other) const noexcept;
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num) noexcept;
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose() const noexcept;
  S21Matrix CalcComplements() const;
  double Determinant() const;
  S21Matrix InverseMatrix() const;

  // Operators overloading
  // External class functions
  friend S21Matrix operator+(S21Matrix m1, const S21Matrix& m2);
  friend S21Matrix operator-(S21Matrix m1, const S21Matrix& m2);
  friend S21Matrix operator*(S21Matrix m1, const S21Matrix& m2);
  friend S21Matrix operator*(S21Matrix m1, const double num);
  friend S21Matrix operator*(const double num, S21Matrix m1);
  friend bool operator==(const S21Matrix& m1, const S21Matrix& m2) noexcept;
  // Internal class functions
  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix& operator-=(const S21Matrix& other);
  S21Matrix& operator*=(const S21Matrix& other);
  S21Matrix& operator*=(const double num);
  double& operator()(int row, int col);
  const double& operator()(int row, int col) const;

  // Accessors and mutators
  int GetRows() const noexcept;
  int GetCols() const noexcept;
  void SetRows(int rows);
  void SetCols(int cols);

 private:
  const double kMatrixEps = 1e-7;

  // Attributes
  int rows_, cols_;  // Rows and columns
  double** matrix_;  // Pointer to the memory where the matrix is allocated

  // Allocating memory for field matrix_
  void InitMatrix();
  // Verification of rows_ and cols_ fields (>= 1)
  void CheckSize() const;
  // Checking matrices for the same size
  void CheckSize(const S21Matrix& other) const;
  // Copying matrices with different sizes
  void CopyMatrix(const S21Matrix& other);
  // Free memory from matrix_
  void FreeMatrix();
  // Creating minor matrix for the element [row][col]
  void CreateMinorMatrix(const S21Matrix& other, int row, int col);
};

#endif  // SRC_LIBRARY_S21_MATRIX_OOP_H_
