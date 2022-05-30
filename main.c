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
    
    print_matrix(m1);
    for (int i=0; i<2; i++){
        for(int j=0; j<3; j++){
            printf("i=%d, j=%d, ", i, j);
            printf("elemento=%d\n", get_element(m1, i, j));
        }
    }

    put_element(mz, 2, 2, 3);
    print_matrix(mz);

    printf("\nValor minimo = %d\nIndice = %d\n", min(m1), argmin(m1));
    printf("Valor maximo = %d\nIndice = %d\n\n", max(m1), argmax(m1));

    printf("Soma: \n");
    print_matrix(add(m1, m1));
    printf("\nSubtracao: \n");
    print_matrix(sub(m1, m1));
    printf("\nDivisao: \n");
    print_matrix(division(m1, m1));
    printf("\nMultiplicacao: \n");
    print_matrix(mul(m1, m1));
    printf("\nTransposta: \n");
    print_matrix(transpose(m1));
    printf("\nCom dimensoes alteradas: \n");
    print_matrix(reshape(m1, 1, 6));

    return 0;
}