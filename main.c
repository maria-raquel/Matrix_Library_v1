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

void printar_arrays(int *array, int n){
    putchar('{');

    for(int i=0; i<n-1; i++)
        printf("%d, ", array[i]);

    printf("%d}\n", array[n-1]);
}

int main(){
    int array[9] = {1, 2, 3, 1, 2, 3, 1, 2, 3};
    Matrix m;

    m = create_matrix(array, 3, 3);
    
    print_matrix(m);

    return 0;
}