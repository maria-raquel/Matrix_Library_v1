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
    int array[6] = {1, 2, 3, 4, 5, 6};
    Matrix m1, mz, mf, mi, mt;

    m1 = create_matrix(array, 2, 3);
    mz = zeros_matrix(3, 3);
    mf = full_matrix(3, 2, 7);
    mi = i_matrix(4);

    print_matrix(tile_matrix(m1, 3));

    return 0;
}