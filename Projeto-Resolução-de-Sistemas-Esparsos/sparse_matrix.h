#ifndef INCLUDED_SPARSE_MATRIX
#define INCLUDED_SPARSE_MATRIX

typedef struct sparseMatrix * SparseMatrix;

SparseMatrix NewMatrix(int i, int j);
SparseMatrix NewSquareMatrix(int i);

void EditLine(SparseMatrix mat, int i, int nValues, int* j, double* values);
double GetValue(SparseMatrix mat, int i, int j);

void FreeMatrix(SparseMatrix mat);

void MatVetMul(SparseMatrix mat, double* vet, double* res);

#endif