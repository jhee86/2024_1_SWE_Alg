#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 8

void printMatrix(int *Matrix, int n);
int* Divide_and_Conquer(int *A, int *B, int n, int *cnt);
int *add(int *M1, int *M2, int n, int *cnt);

int mul_cnt;
int add_cnt;
int sub_cnt;

int main(void) {
    int A[SIZE][SIZE];
    int B[SIZE][SIZE];

    mul_cnt = 0;
    add_cnt = 0;
    sub_cnt = 0;

    

    int *C;
    int cnt =0 ;

    srand(time(NULL));

    // Initialize matrices A and B with random values

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            A[i][j] = rand() % 1000; // generate random value
            B[i][j] = rand() % 1000; // generate random value
        }
    }

    printf("Matrix A:\n");
    printMatrix(&A[0][0], SIZE);

    printf("Matrix B:\n");
    printMatrix(&B[0][0], SIZE);

    C = Divide_and_Conquer(&A[0][0], &B[0][0], SIZE , &cnt);

    printf("Matrix C:\n");
    printMatrix(C, SIZE);

    printf("cnt: %d\n",cnt);

    printf("mul_cnt: %d\n",mul_cnt);
    printf("sub_cnt: %d\n",sub_cnt);
    printf("add_cnt: %d\n",add_cnt);
    free(C);
    return 0;
}

void printMatrix(int *Matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", *((Matrix + i * n) + j));
        }
        printf("\n");
    }
    printf("\n");
}

int* Divide_and_Conquer(int *A, int *B, int n,  int *cnt){

    if (n == 1) {
        int *C = (int*)malloc(sizeof(int));
        (*cnt)++;
        mul_cnt++;
        C[0] = A[0] * B[0];
        //printMatrix(C, n);
        return C;}
    else {
        int size = n / 2;

        int *C = (int*)malloc(n * n * sizeof(int));

        int *temp1 = (int*)malloc(n * n * sizeof(int));
        int *temp2 = (int*)malloc(n * n * sizeof(int));

        int *a11 = (int*)malloc(size * size * sizeof(int));
        int *a12 = (int*)malloc(size * size * sizeof(int));
        int *a21 = (int*)malloc(size * size * sizeof(int));
        int *a22 = (int*)malloc(size * size * sizeof(int));

        int *b11 = (int*)malloc(size * size * sizeof(int));
        int *b12 = (int*)malloc(size * size * sizeof(int));
        int *b21 = (int*)malloc(size * size * sizeof(int));
        int *b22 = (int*)malloc(size * size * sizeof(int));

        int *c11 = (int*)malloc(size * size * sizeof(int));
        int *c12 = (int*)malloc(size * size * sizeof(int));
        int *c21 = (int*)malloc(size * size * sizeof(int));
        int *c22 = (int*)malloc(size * size * sizeof(int));

        //divide
         for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                a11[i * size + j] = A[i * n + j];
                a12[i * size + j] = A[i * n + j + size];
                a21[i * size + j] = A[(i + size) * n + j];
                a22[i * size + j] = A[(i + size) * n + j + size];

                b11[i * size + j] = B[i * n + j];
                b12[i * size + j] = B[i * n + j + size];
                b21[i * size + j] = B[(i + size) * n + j];
                b22[i * size + j] = B[(i + size) * n + j + size];
            }
         }

            temp1=  Divide_and_Conquer(a11, b11, size,cnt);
            temp2=  Divide_and_Conquer(a12, b21, size,cnt);
            c11= add(temp1, temp2,size,cnt);

            temp1=  Divide_and_Conquer(a11, b12, size,cnt);
            temp2=  Divide_and_Conquer(a12, b22, size,cnt);
            c12= add(temp1, temp2,size,cnt);            

            temp1=  Divide_and_Conquer(a21, b11, size,cnt);
            temp2=  Divide_and_Conquer(a22, b21, size,cnt);
            c21= add(temp1, temp2,size,cnt);

            temp1=  Divide_and_Conquer(a21, b12, size,cnt);
            temp2=  Divide_and_Conquer(a22, b22, size,cnt);
            c22= add(temp1, temp2,size,cnt);

            //
            if(size > 1){
                 printMatrix(c11,size);
        printMatrix(c12,size);
        printMatrix(c21,size);
        printMatrix(c22,size);

            }

                   // Combine C matrices
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                C[i * n + j] = c11[i * size + j];
                C[i * n + size + j] = c12[i * size + j];
                C[(i + size) * n + j] = c21[i * size + j];
                C[(i + size) * n + size + j] = c22[i * size + j];
            }
        }

        //printMatrix(C, n);

        free(a11);
        free(a12);
        free(a21);
        free(a22);
        free(b11);
        free(b12);
        free(b21);
        free(b22);
        free(c11);
        free(c12);
        free(c21);
        free(c22);
        free(temp1);
        free(temp2);

        

    
    return C;
}
}
int *add(int *M1, int *M2, int n, int*cnt){
    int *temp = (int*)malloc(n * n * sizeof(int));
    (*cnt)++;
    add_cnt++;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            *((temp + i * n) + j) =  *((M1 + i * n) + j) + *((M2 + i * n) + j);
        }
    }

    return temp;
}