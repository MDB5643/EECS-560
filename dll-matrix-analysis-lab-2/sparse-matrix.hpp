#ifndef SPARSE_MATRIX_HPP
#define SPARSE_MATRIX_HPP

class SparseMatrix {
private:
  int iMax;
  int iMin;
  int jMax;
  int jMin;
  //define private fields and methods here

public:
  /**
   * public constructor
   */
  SparseMatrix(int i, int j);

  /**
   * Public destructor
   */
  ~SparseMatrix();

  /**
   * checks for equality of matrices
   */
  bool equals(const SparseMatrix*);

  /**
   * returns a new matrix but transposed
   */
  SparseMatrix* transpose();
};

#endif //SPARSE_MATRIX_HPP defined
