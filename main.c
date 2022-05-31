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
    int array[9] = {1, 2, 3, 4, 5, 6};
    Matrix m1, mz, mf, mi;

    m1 = create_matrix(array, 2, 3);
    mz = zeros_matrix(3, 3);
    mf = full_matrix(3, 2, 7);
    mi = i_matrix(4);

    printf("\nValor minimo = %d\nIndice = %d\n", min(mz), argmin(mz));
    printf("Valor maximo = %d\nIndice = %d\n\n", max(mz), argmax(mz));

    // printf("Soma: \n");
    // print_matrix(add(m1, mz));
    // printf("\nSubtracao: \n");
    // print_matrix(sub(m1, mz));
    // printf("\nDivisao: \n");
    // print_matrix(division(m1, mz));
    // printf("\nMultiplicacao: \n");
    // print_matrix(mul(m1, mz));
    // printf("\nTransposta: \n");
    // print_matrix(transpose(m1));
    // printf("\nCom dimensoes alteradas: \n");
    // print_matrix(reshape(m1, 1, 8));

    return 0;
}