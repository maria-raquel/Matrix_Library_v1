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
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    Matrix m1;

    m1 = create_matrix(array, 5, 3);
    // print_matrix(a_matrix);
    // putchar('\n');
    // print_matrix(tile_matrix(m1, 5));

    print_matrix(m1);
    print_matrix(slice(m1, 2, 5, 0, 2));

    return 0;
}