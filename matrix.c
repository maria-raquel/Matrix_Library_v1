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
    int *data;
    data = malloc(n_rows*n_cols*sizeof(0));

    for (int i=0; i < n_rows*n_cols; i++)
        *(data+i) = 0;

    Matrix z = create_matrix(data, n_rows, n_cols);
    return z;
}

//>==================== acessar elementos: =====================

/*
    a b c
    d e f
    g h i

*/

void print_matrix(Matrix matrix){
    int i=0;
    for (int row = 0; i < matrix.n_rows; row++){
        for (int col = 0; i < matrix.n_cols; col++)
            printf("%d ", matrix.data[i++]);
        putchar('\n');
    }
}

//>================= manipulacao de dimensoes: =================

//>======================== agregacao: =========================

//>================== operacoes aritmeticas: ===================