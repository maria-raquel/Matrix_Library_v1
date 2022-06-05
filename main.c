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
    int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int array2[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

    // print_matrix(create_matrix(array, 1, 9));
    // putchar('\n');
    // print_matrix(create_matrix(array2, 3, 4));
    // putchar('\n');
    // print_matrix(zeros_matrix(1,4));
    // putchar('\n');
    // print_matrix(full_matrix(3,3,13));
    // putchar('\n');
    // print_matrix(i_matrix(2));
    // putchar('\n');
    // print_matrix(tile_matrix(i_matrix(2), 5));



    // Matrix mcreate = create_matrix(array2, 3, 4);
    // put_element(mcreate, 2, 8, 44);
    // print_matrix(mcreate);
    // putchar('\n');

    // printf("\n%d", get_element(create_matrix(array2, 3, 4), 2, 8));
    // putchar('\n');

    // putchar('\n');
    // print_matrix(transpose(i_matrix(3)));

    // print_matrix(reshape(create_matrix(array2, 3, 4), 2, 6));

    // printf("\n");
    // print_matrix(slice(create_matrix(array2, 3, 4), 1, 2, 3, 4));

    // printf("%d\n", argmax(create_matrix(array2, 3, 4)));

    

    print_matrix(division(full_matrix(3,3,5), full_matrix(3,3,0)));





    return 0;
}
