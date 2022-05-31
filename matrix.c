/*
>>>>>>>>>>> PROVA_2_PROGRAMACAO_ESTRUTURADA <<<<<<<<<<<<<

* Professor: Igor Malheiros

>>>>>>>>>>>>>>>>>>>>>>>>>>|<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
Alunos:
- Joao Antonio Honorato | 20210026680
- Maria Raquel Martinez | 20200025900
*/

#include "matrix.h"
#include <stdlib.h>
#include <stdio.h>

//>================ Implementacoes de Funcoes: =================

//>==================== criacao de matrizes: ===================

Matrix create_matrix(int *data, int n_rows, int n_cols){
    Matrix m = {data, n_rows, n_cols, n_cols, 1, 0};
    return m;
}

Matrix zeros_matrix(int n_rows, int n_cols){
    return full_matrix(n_rows, n_cols, 0);
}

Matrix full_matrix(int n_rows, int n_cols, int value){
    int *data;
    data = malloc(n_rows*n_cols*sizeof(int));

    for (int i=0; i < n_rows*n_cols; i++)
        *(data+i) = value;

    Matrix m = create_matrix(data, n_rows, n_cols);
    return m;
}

Matrix i_matrix(int n){
    int *data;
    data = malloc(n*n*sizeof(int));

    for (int i=0; i<n*n; i++)
        *(data+i) = 0;
    
    for (int j=0; j<n*n; j+=n+1)
        *(data+j) = 1;

    return create_matrix(data, n, n);
}

//>==================== acessar elementos: =====================

int get_element(Matrix matrix, int ri, int ci){
    int i=matrix.offset;

    for (int row=0; row<ri; i += matrix.stride_rows, row++){}
    for (int col=0; col<ci; i += matrix.stride_cols, col++){}

    return matrix.data[i];
}

void put_element(Matrix matrix, int ri, int ci, int elem){
    int i=matrix.offset;

    for (int row=0; row<ri; i += matrix.stride_rows, row++){}
    for (int col=0; col<ci; i += matrix.stride_cols, col++){}

    matrix.data[i] = elem;
}

void print_matrix(Matrix matrix){
    int i=0;
    for (int row = 0; row < matrix.n_rows; row++){
        printf("( ");
        for (int col = 0; col < matrix.n_cols; col++)
            printf("%d ", matrix.data[i++]);
        printf(")\n");
    }
}

//>================= manipulacao de dimensoes: =================

Matrix transpose(Matrix matrix){
    int k = 0;
    int *data;
    data = malloc(matrix.n_cols*matrix.n_rows*sizeof(int));
    
    for (int i = matrix.offset; i < matrix.n_cols-1; i += matrix.stride_rows){
        for (int j = matrix.offset; j < matrix.n_rows*matrix.n_cols; j += matrix.stride_cols)
            data[j] = matrix.data[k++];
    }

    Matrix mt = create_matrix(data, matrix.n_cols, matrix.n_rows);
    return mt;
}

Matrix reshape(Matrix matrix, int new_n_rows, int new_n_cols){
    Matrix mreshaped = matrix;

    if (matrix.n_cols*matrix.n_rows != new_n_rows*new_n_cols){
        puts("reshape invalido");
        return matrix;    
    }
    
    mreshaped.n_cols = new_n_cols;
    mreshaped.n_rows = new_n_rows;

    return mreshaped;
}

//>======================== agregacao: =========================

int min(Matrix matrix){
    int min = matrix.data[matrix.offset];

    for (int i=matrix.offset+1; i < matrix.n_cols*matrix.n_rows; i++){
        if (matrix.data[i] < min){
            min = matrix.data[i];
        }
    }

    return min;
}

int max(Matrix matrix){
    int max = matrix.data[matrix.offset];

    for (int i=matrix.offset+1; i < matrix.n_cols*matrix.n_rows; i++){
        if (matrix.data[i] > max){
            max = matrix.data[i];
        }
    }

    return max;
}

int argmin(Matrix matrix){

    int index_min = matrix.offset;
    int min = matrix.data[index_min];

    for (int i=matrix.offset+1; i < matrix.n_cols*matrix.n_rows; i++){
        if (matrix.data[i] < min){
            min = matrix.data[i];
            index_min = i;
        }
    }

    return index_min;
}

int argmax(Matrix matrix){

    int index_max = matrix.offset;
    int max = matrix.data[index_max];

    for (int i=matrix.offset+1; i < matrix.n_cols*matrix.n_rows; i++){
        if (matrix.data[i] > max){
            max = matrix.data[i];
            index_max = i;
        }
    }

    return index_max;
}


//>================== operacoes aritmeticas: ===================

Matrix add(Matrix matrix_1, Matrix matrix_2){
    int *data;
    data = malloc(matrix_1.n_cols*matrix_1.n_rows*sizeof(int));

    for (int i=matrix_1.offset; i < matrix_1.n_cols*matrix_1.n_rows; i++)
        *(data+i) = matrix_1.data[i] + matrix_2.data[i];

    Matrix m3 = create_matrix(data, matrix_1.n_rows, matrix_1.n_cols);
    return m3;
}

Matrix sub(Matrix matrix_1, Matrix matrix_2){
    int *data;
    data = malloc(matrix_1.n_cols*matrix_1.n_rows*sizeof(int));

    for (int i=matrix_1.offset; i < matrix_1.n_cols*matrix_1.n_rows; i++)
        *(data+i) = matrix_1.data[i] - matrix_2.data[i];

    Matrix m3 = create_matrix(data, matrix_1.n_rows, matrix_1.n_cols);
    return m3;
}

Matrix division(Matrix matrix_1, Matrix matrix_2){
    int *data;
    data = malloc(matrix_1.n_cols*matrix_1.n_rows*sizeof(int));

    for (int i=matrix_1.offset; i < matrix_1.n_cols*matrix_1.n_rows; i++)
        *(data+i) = matrix_1.data[i] / matrix_2.data[i];

    Matrix m3 = create_matrix(data, matrix_1.n_rows, matrix_1.n_cols);
    return m3;
}

Matrix mul(Matrix matrix_1, Matrix matrix_2){
    int *data;
    data = malloc(matrix_1.n_cols*matrix_1.n_rows*sizeof(int));

    for (int i=matrix_1.offset; i < matrix_1.n_cols*matrix_1.n_rows; i++)
        *(data+i) = matrix_1.data[i] * matrix_2.data[i];

    Matrix m3 = create_matrix(data, matrix_1.n_rows, matrix_1.n_cols);
    return m3;
}