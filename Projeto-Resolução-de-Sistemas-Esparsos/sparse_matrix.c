#include "sparse_matrix.h"
#include <stdlib.h>

typedef struct sparseMatrixCell
{
    int j;
    double value;

}SparseMatrixCell;

struct sparseMatrix
{
    int lineCount;
    int columnCount;
    int* lineSizes;
    SparseMatrixCell** lines;
};

SparseMatrix NewMatrix(int lines, int cols)
{
    SparseMatrix mat = (SparseMatrix)malloc(sizeof(struct sparseMatrix));
    if(mat!=NULL)
    {
        mat->lineCount = lines;
        mat->columnCount = cols;
        mat->lines = (SparseMatrixCell*)malloc(lines * sizeof(SparseMatrixCell*));
        mat->lineSizes = (int*)malloc(lines * sizeof(int));
        if(mat->lines == NULL || mat->lineSizes == NULL) return NULL;

        for(int i=0; i<lines; i++)
        {
            mat->lines[i] = NULL;
            mat->lineSizes[i] = 0;
        }
    }
    return mat;
}
SparseMatrix NewSquareMatrix(int i)
{
    return NewMatrix(i,i);
}

void EditLine(SparseMatrix mat, int line, int nValues, int* j, double* values)
{
    SparseMatrixCell* changedLine = mat->lines[line];

    if(changedLine != NULL) free(changedLine);
    
    mat->lines[line] = (SparseMatrixCell*)malloc(nValues * sizeof(SparseMatrixCell));
    if(mat->lines[line] == NULL) return;

    mat->lineSizes[line] = nValues;

    for (int i = 0; i < line; i++)
    {
        mat->lines[line][i].j = j[i];
        mat->lines[line][i].value = values[i];
    }
    return;
}

double GetValue(SparseMatrix mat, int i, int j)
{
    SparseMatrixCell* line = mat->lines[i];
    if(line == NULL) return 0.0f;
    return BinarySearch(line, mat->lineSizes[i], j);

}

void FreeMatrix(SparseMatrix mat)
{
    for(int i=0; i<mat->lineCount; i++)
    {
        if(mat->lines[i] != NULL) free(mat->lines[i]);
    }
    free(mat->lineSizes);
    free(mat);
}

void MatVetMul(SparseMatrix mat, double* vet, double* res)
{
    for(int i=0; i<mat->lineCount; i++)
    {
        res[i]=0.0f;
        for (int j = 0; j < mat->lineSizes[i]; j++)
        {
            SparseMatrixCell cell = mat->lines[i][j];
            res[i]+= cell.value * vet[cell.j];
        }
    }
}

static double BinarySearch(SparseMatrixCell* vet, int size, int target)
{
    if(size < 1)
    {
        return 0.0f;
    }
    int cur = size/2;
    if(vet[cur].j == target)
    {
        return vet[cur].value;
    }
    if(vet[cur].j > target)
    {
        return BinarySearch(vet, cur,target);
    }
    else
    {
        return BinarySearch(&vet[cur + 1], size - (cur + 1), target);
    }
    

}