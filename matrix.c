/*
>>>>>>>>>>> PROJETO FINAL DE PROGRAMACAO ESTRUTURADA <<<<<<<<<<<<<

Professor: 
Igor Malheiros

Alunos:
Joao Antonio Honorato | 20210026680
Maria Raquel Martinez | 20200025900

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

    for (int i=0; i < n_rows*n_cols;)
        *(data+i++) = value;

    Matrix m = create_matrix(data, n_rows, n_cols);
    return m;
}

Matrix i_matrix(int n){
    int *data;
    data = malloc(n*n*sizeof(int));

    for (int i=0; i < n*n;)
        *(data+i++) = 0;
    
    for (int j=0; j < n*n; j += n+1)
        *(data+j) = 1;

    return create_matrix(data, n, n);
}

Matrix tile_matrix(Matrix matrix, int reps){
    int *data, k = 0;
    data = malloc(matrix.n_cols*matrix.n_rows*sizeof(int)*reps);

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

//>==================== acesso a elementos: ====================

int get_element(Matrix matrix, int ri, int ci){

    if (ri >= matrix.n_rows || ci >= matrix.n_cols){
        puts("in get_element: ");
        printf("Error: index [%d][%d] is out of bounds\n", ri, ci);
        exit(1);
    }

    int i = matrix.offset;

    for (int row=0; row<ri; i += matrix.stride_rows, row++){}
    for (int col=0; col<ci; i += matrix.stride_cols, col++){}

    return matrix.data[i];
}

void put_element(Matrix matrix, int ri, int ci, int elem){

    if (ri >= matrix.n_rows || ci >= matrix.n_cols){
        puts("in put_element: ");
        printf("Error: index [%d][%d] is out of bounds\n", ri, ci);
        exit(1);
    }

    int i = matrix.offset;

    for (int row=0; row<ri; i += matrix.stride_rows, row++){}
    for (int col=0; col<ci; i += matrix.stride_cols, col++){}

    matrix.data[i] = elem;
}

void print_matrix(Matrix matrix){
    int i = matrix.offset;
    for (int row = 0; row < matrix.n_rows; row++){
        printf("( ");
        for (int col = 0; col < matrix.n_cols; col++)
            printf("%2d ", matrix.data[i++]);
        printf(")\n");
    }
}

//>================= manipulacao de dimensoes: =================

Matrix transpose(Matrix matrix){
    int *data = malloc((matrix.n_cols)*(matrix.n_rows)*sizeof(int)); 

    int cols_counter = 1, cols_resetter = 0;

    for (int i = 0, j = 0; i < matrix.n_cols*matrix.n_rows; i++){
        data[i] = matrix.data[j];
        j += matrix.stride_rows;
        cols_counter++;
        if (cols_counter > matrix.n_rows){
            cols_counter = 1;
            cols_resetter++;
            j = cols_resetter;
        }
    }

    Matrix m = create_matrix(data, matrix.n_cols, matrix.n_rows);
    return m;
}

Matrix reshape(Matrix matrix, int new_n_rows, int new_n_cols){
   if (matrix.n_cols*matrix.n_rows != new_n_rows*new_n_cols){
        puts("in reshape: ");
        printf("Error: cannot reshape matrix of %d elements into shape (%d, %d)\n", matrix.n_cols*matrix.n_rows, new_n_rows, new_n_cols);
        exit(1);
    }

    return create_matrix(matrix.data, new_n_rows, new_n_cols);
}

Matrix slice(Matrix a_matrix, int rs, int re, int cs, int ce){
    Matrix m;
    int *data, new_n_cols = re-rs, new_n_rows = ce-cs;

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

    for (int i = matrix.offset+1; i < matrix.n_cols*matrix.n_rows; i++)
        if (matrix.data[i] < min)
            min = matrix.data[i];

    return min;
}

int max(Matrix matrix){
    int max = matrix.data[matrix.offset];

    for (int i = matrix.offset+1; i < matrix.n_cols*matrix.n_rows; i++)
        if (matrix.data[i] > max)
            max = matrix.data[i];

    return max;
}

int argmin(Matrix matrix){
    int index_min = matrix.offset, min = matrix.data[index_min];

    for (int i=matrix.offset+1; i < matrix.n_cols*matrix.n_rows; i++){
        if (matrix.data[i] < min){
            min = matrix.data[i];
            index_min = i;
        }
    }

    return index_min;
}

int argmax(Matrix matrix){
    int index_max = matrix.offset, max = matrix.data[index_max];

    for (int i = matrix.offset+1; i < matrix.n_cols*matrix.n_rows; i++){
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
        puts("in add: ");
        printf("Error: operands of incompatible shape\n");
        exit(1);
    }

    int *data;
    data = malloc(matrix_1.n_cols*matrix_1.n_rows*sizeof(int));

    for (int i = matrix_1.offset; i < matrix_1.n_cols*matrix_1.n_rows; i++)
        *(data+i) = matrix_1.data[i] + matrix_2.data[i];

    return create_matrix(data, matrix_1.n_rows, matrix_1.n_cols);;
}

Matrix sub(Matrix matrix_1, Matrix matrix_2){
    if (matrix_1.n_cols != matrix_2.n_cols || matrix_1.n_rows != matrix_2.n_rows){
        puts("in sub: ");
        printf("Error: operands of incompatible shape\n");
        exit(1);
    }

    int *data;
    data = malloc(matrix_1.n_cols*matrix_1.n_rows*sizeof(int));

    for (int i=matrix_1.offset; i < matrix_1.n_cols*matrix_1.n_rows; i++)
        *(data+i) = matrix_1.data[i] - matrix_2.data[i];

    return create_matrix(data, matrix_1.n_rows, matrix_1.n_cols);
}

Matrix division(Matrix matrix_1, Matrix matrix_2){
    if (matrix_1.n_cols != matrix_2.n_cols || matrix_1.n_rows != matrix_2.n_rows){
        puts("in division: ");
        printf("Error: operands of incompatible shape\n");
        exit(1);
    }

    int size = matrix_1.n_cols*matrix_1.n_rows;

    for (int i = 0; i<size; i++){
        if (matrix_2.data[i] == 0){
            puts("in division: ");
            printf("Error: cannot divide by 0\n");
            exit(1);
        }
    }

    int *data;
    data = malloc(size*sizeof(int));

    for (int i = matrix_1.offset; i < matrix_1.n_cols*matrix_1.n_rows; i++)
        *(data+i) = matrix_1.data[i] / matrix_2.data[i];

    return create_matrix(data, matrix_1.n_rows, matrix_1.n_cols);
}

Matrix mul(Matrix matrix_1, Matrix matrix_2){
    if (matrix_1.n_cols != matrix_2.n_cols || matrix_1.n_rows != matrix_2.n_rows){
        puts("in mul: ");
        printf("Error: operands of incompatible shape\n");
        exit(1);
    }

    int *data;
    data = malloc(matrix_1.n_cols*matrix_1.n_rows*sizeof(int));

    for (int i=matrix_1.offset; i < matrix_1.n_cols*matrix_1.n_rows; i++)
        *(data+i) = matrix_1.data[i] * matrix_2.data[i];

    return create_matrix(data, matrix_1.n_rows, matrix_1.n_cols);
}