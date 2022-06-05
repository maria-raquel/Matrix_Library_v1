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
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Matrix m1;

    m1 = create_matrix(array, 3, 3);

    print_matrix(m1);
    putchar('\n');
    print_matrix(transpose(m1));

    // print_matrix(m1);
    // printf("\n");
    // print_matrix(slice(m1, 0, 5, 1, 2));

    return 0;
}