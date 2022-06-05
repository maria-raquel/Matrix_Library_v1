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

Matrix tile_matrix(Matrix matrix, int reps){
    int *data;
    data = malloc(matrix.n_cols*matrix.n_rows*sizeof(int)*reps);
    int k = 0;

    for (int l = 1; l < matrix.n_rows+1; l++){
        for (int j = 0; j < reps; j++){
            for (int i = 0 + (l-1)*matrix.stride_rows; i < matrix.stride_rows + (l-1)*matrix.stride_rows; i++){
                *(data + k) = matrix.data[i];
                k++;
            }
        }
    }
    return create_matrix(data, matrix.n_rows, matrix.n_cols*reps);
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
    int i=matrix.offset;
    for (int row = 0; row < matrix.n_rows; row++){
        printf("( ");
        for (int col = 0; col < matrix.n_cols; col++)
            printf("%2d ", matrix.data[i++]);
        printf(")\n");
    }
}

//>================= manipulacao de dimensoes: =================


Matrix transpose(Matrix matrix){
    Matrix m;
    m = create_matrix(matrix.data, matrix.n_cols, matrix.n_rows);
    m.stride_cols = matrix.stride_rows;
    m.stride_rows = matrix.stride_cols;
    return m;
}

Matrix reshape(Matrix matrix, int new_n_rows, int new_n_cols){
    Matrix mreshaped = matrix;

    if (matrix.n_cols*matrix.n_rows != new_n_rows*new_n_cols){
        puts("reshape invalido");
        return zeros_matrix(1, 1);    
    }
    
    mreshaped.n_cols = new_n_cols;
    mreshaped.n_rows = new_n_rows;

    return mreshaped;
}

Matrix slice(Matrix a_matrix, int rs, int re, int cs, int ce){
    Matrix m;
    int *data;
    int new_n_cols = re-rs;
    int new_n_rows = ce-cs;

    data = malloc((new_n_cols)*(new_n_rows)*sizeof(int)); 

    int i = 0;
    for (int x = 0; x < new_n_cols; x++)
        for (int y = 0; y < new_n_rows; y++)
            data[i++] = a_matrix.data[((rs+(x))*a_matrix.stride_rows) + ((cs+(y)) * a_matrix.stride_cols)];
    
    m = create_matrix(data, new_n_cols, new_n_rows);

    return m;
}

//>======================== agregacao: =========================

int min(Matrix matrix){
    int min = matrix.data[matrix.offset];

    for (int i=matrix.offset+1; i < matrix.n_cols*matrix.n_rows; i++)
        if (matrix.data[i] < min)
            min = matrix.data[i];

    return min;
}

int max(Matrix matrix){
    int max = matrix.data[matrix.offset];

    for (int i=matrix.offset+1; i < matrix.n_cols*matrix.n_rows; i++)
        if (matrix.data[i] > max)
            max = matrix.data[i];

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

    if (matrix_1.n_cols != matrix_2.n_cols || matrix_1.n_rows != matrix_2.n_rows){
        puts("soma invalida");
        return zeros_matrix(1, 1);
    }

    int *data;
    data = malloc(matrix_1.n_cols*matrix_1.n_rows*sizeof(int));

    for (int i=matrix_1.offset; i < matrix_1.n_cols*matrix_1.n_rows; i++)
        *(data+i) = matrix_1.data[i] + matrix_2.data[i];

    Matrix m3 = create_matrix(data, matrix_1.n_rows, matrix_1.n_cols);
    return m3;
}

Matrix sub(Matrix matrix_1, Matrix matrix_2){

    if (matrix_1.n_cols != matrix_2.n_cols || matrix_1.n_rows != matrix_2.n_rows){
        puts("subtracao invalida");
        return zeros_matrix(1, 1);
    }

    int *data;
    data = malloc(matrix_1.n_cols*matrix_1.n_rows*sizeof(int));

    for (int i=matrix_1.offset; i < matrix_1.n_cols*matrix_1.n_rows; i++)
        *(data+i) = matrix_1.data[i] - matrix_2.data[i];

    Matrix m3 = create_matrix(data, matrix_1.n_rows, matrix_1.n_cols);
    return m3;
}

Matrix division(Matrix matrix_1, Matrix matrix_2){
    int size;

    if (matrix_1.n_cols != matrix_2.n_cols || matrix_1.n_rows != matrix_2.n_rows){
        puts("divisao invalida: tamanhos incompativeis");
        return zeros_matrix(1, 1);
    }

    size = matrix_1.n_cols*matrix_1.n_rows;

    for (int i = 0; i<size; i++){
        if (matrix_2.data[i] == 0){
            puts("divisao invalida: denominador nulo");
            return zeros_matrix(1, 1);
        }
    }

    int *data;
    data = malloc(size*sizeof(int));

    for (int i = matrix_1.offset; i < matrix_1.n_cols*matrix_1.n_rows; i++)
        *(data+i) = matrix_1.data[i] / matrix_2.data[i];

    Matrix m3 = create_matrix(data, matrix_1.n_rows, matrix_1.n_cols);
    return m3;
}

Matrix mul(Matrix matrix_1, Matrix matrix_2){
    if (matrix_1.n_cols != matrix_2.n_cols || matrix_1.n_rows != matrix_2.n_rows){
        puts("multiplicacao invalida");
        return zeros_matrix(1, 1);
    }

    int *data;
    data = malloc(matrix_1.n_cols*matrix_1.n_rows*sizeof(int));

    for (int i=matrix_1.offset; i < matrix_1.n_cols*matrix_1.n_rows; i++)
        *(data+i) = matrix_1.data[i] * matrix_2.data[i];

    Matrix m3 = create_matrix(data, matrix_1.n_rows, matrix_1.n_cols);
    return m3;
}