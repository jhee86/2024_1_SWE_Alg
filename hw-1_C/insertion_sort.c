#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100

//
int dupExist(int *A, int size, int value);
int insertion_sort(int *A, int size);

//
void Already_sorted(int *A, int size);
void reversely_sorted(int *A, int size);

int main(void){

    int A[SIZE];


   //insertion_sort 
    printf("<insertion_sort> \n");

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
    printf("\n");
    


    int cnt = insertion_sort(A, SIZE);
 
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
    


    cnt = insertion_sort(A, SIZE);
 
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
    


    cnt = insertion_sort(A, SIZE);
 
    printf("case 3) After sorting\n");

     // print
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
   printf("case 3) the number of comparisons : %d \n",cnt);


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
/*
int insertion_sort(int *A, int size) { 

    int cnt = 0;
    int temp;
    int j;
    for (int i=1 ; i<size; i++){

        int key = A[i]; //삽입의 대상

        for(j=i-1,++cnt ; j>=0  && A[j - 1] > key ;j--,cnt++ ){
            
            A[j+1]=A[j];
             A[j] = key;
        }
        
    }
    return cnt;
}
*/
int insertion_sort(int *A, int size) { 

    int cnt = 0;
    int temp;
    for (int i = 1; i < size; i++) {

        int key = A[i]; // 삽입의 대상

        for (int j = i - 1; j >= 0; j--) {
            ++cnt;
            if (key < A[j]) { // key보다 더 작으면 swap
                A[j + 1] = A[j];
                A[j] = key;
            } else {
                break; //  정렬된 상태에서 비교 x
            }
        }
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


