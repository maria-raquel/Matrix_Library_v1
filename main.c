/*
>>>>>>>>>>> PROVA_2_PROGRAMACAO_ESTRUTURADA <<<<<<<<<<<<<

* Professor: Igor Malheiros

>>>>>>>>>>>>>>>>>>>>>>>>>>|<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
Alunos:
- Joao Antonio Honorato | 20210026680
- Maria Raquel Martinez | 20200025900
*/





#include "matrix.h"
#include <stdio.h>

int main(){
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    Matrix m1;

    m1 = create_matrix(array, 4, 3);
    // print_matrix(a_matrix);
    // putchar('\n');
    print_matrix(tile_matrix(m1, 4));

    // print_matrix(slice(a_matrix, 1, 3, 1, 3));

    return 0;
}