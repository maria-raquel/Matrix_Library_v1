/*
>>>>>>>>>>> PROVA_2_PROGRAMACAO_ESTRUTURADA <<<<<<<<<<<<<

* Professor: Igor Malheiros

>>>>>>>>>>>>>>>>>>>>>>>>>>|<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
Alunos:
- Joao Antonio Honorato | 20210026680
- Maria Raquel Martinez | 20200025900
*/

#ifndef MATRIX_H
#define MATRIX_H

//>==================== Definicao da Struct: ===================

typedef struct {
    int *data;
    int n_rows;
    int n_cols;
    int stride_rows;
    int stride_cols;
    int offset;
} Matrix;

//>================== Assinaturas de Funcoes: ==================

//>==================== criacao de matrizes: ===================

Matrix create_matrix(int *data, int n_rows, int n_cols);          //ok
Matrix zeros_matrix(int n_rows, int n_cols);                      //ok
Matrix full_matrix(int n_rows, int n_cols, int value);            //ok
Matrix i_matrix(int n);                                           //ok 
Matrix tile_matrix(Matrix matrix, int reps);

//>==================== acessar elementos: =====================

int get_element(Matrix matrix, int ri, int ci);                   //ok
void put_element(Matrix matrix, int ri, int ci, int elem);        //ok
void print_matrix(Matrix matrix);                                 //ok 

//>================= manipulacao de dimensoes: =================

Matrix transpose(Matrix matrix);
Matrix reshape(Matrix matrix, int new_n_rows, int new_n_cols);
Matrix slice(Matrix a_matrix, int rs, int re, int cs, int ce);

//>======================== agregacao: =========================

int min(Matrix matrix);                                           //ok
int max(Matrix matrix);                                           //ok
int argmin(Matrix matrix);                                        //ok
int argmax(Matrix matrix);                                        //ok

//>================== operacoes aritmeticas: ===================

Matrix add(Matrix matrix_1, Matrix matrix_2);                     //ok
Matrix sub(Matrix matrix_1, Matrix matrix_2);                     //ok
Matrix division(Matrix matrix_1, Matrix matrix_2);                //ok
Matrix mul(Matrix matrix_1, Matrix matrix_2);                     //ok

#endif