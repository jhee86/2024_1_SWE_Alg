#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100

//
int dupExist(int *A, int size, int value);
int selection_sort(int *A, int size);

//
void Already_sorted(int *A, int size);
void reversely_sorted(int *A, int size);
int main(void){

    int A[SIZE];

printf("\n");
printf("\n");
//selection_sort 
    printf("<selection_sort>\n");

    //case1)
    srand(time(NULL));
    for (int i = 0; i < SIZE; ++i) {
        int value;
        do {
            value = rand() % 1000;//generate randomv alue
        } while (dupExist(A, i, value)); // no duplication
        A[i] = value;
    }
    
    // print
    printf("case 1) Before sorting \n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    


    int cnt = selection_sort(A, SIZE);
 
    printf("case 1) After sorting\n");

     // print
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
   printf("case 1) the number of comparisons : %d \n",cnt);
printf("\n");
printf("\n");



   //case2) already sorted
   Already_sorted(A, SIZE);
       // print
    printf("case 2) Before sorting \n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    


    cnt = selection_sort(A, SIZE);
 
    printf("case 2) After sorting\n");

     // print
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
   printf("case 2) the number of comparisons : %d \n",cnt);

printf("\n");
printf("\n");

   //case3) reversed sorted
   reversely_sorted(A, SIZE);

       // print
    printf("case 3) Before sorting \n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    


    cnt = selection_sort(A, SIZE);
 
    printf("case 3) After sorting\n");

     // print
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
   printf("case 3) the number of comparisons : %d \n",cnt);

printf("\n");
printf("\n");

    return 0;
}

int dupExist(int *A, int size, int value) {
    for (int i = 0; i < size; ++i) {
        if (A[i] == value) {
            return 1;
        }
    }
    return 0;
}

int selection_sort(int *A, int size) {
    
    int maxIdx = 0;
    int cnt = 0;
    int temp;
    // iterating 
    for (int i = 0; i < size - 1; i++) {
        maxIdx = i;

        // find maxvalue 
        for (int j = i + 1; j < size; j++) {
            ++cnt;
            if (A[maxIdx] < A[j]) {
                // if there is the bigger one :  swap
                maxIdx = j;
            }
        }

        // swap
        temp = A[maxIdx];
        A[maxIdx] = A[i];
        A[i] = temp;
    }
    return cnt;
}



void Already_sorted(int *A, int size){
        for (int i = 0; i < size; ++i) {
        A[i] = i + 1;
    }
}
void reversely_sorted(int *A, int size){
    for (int i = 0; i < size; ++i) {
        A[i] = size - i;
    }
}


