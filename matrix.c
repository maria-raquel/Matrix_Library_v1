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

//>======================== agregacao: =========================

//>================== operacoes aritmeticas: ===================