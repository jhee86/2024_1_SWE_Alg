#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 16

void printMatrix(int *Matrix, int n);
int* strassen(int *A, int *B, int n, int *cnt);
int *add(int *M1, int *M2, int n, int *cnt);
int *subtract(int *M1, int *M2, int n, int *cnt);

int mul_cnt;
int add_cnt;
int sub_cnt;

int main(void) {
    int A[SIZE][SIZE];
    int B[SIZE][SIZE];

    int *C;
    int cnt=0; //computation cnt

    mul_cnt = 0;
    add_cnt = 0;
    sub_cnt = 0;

    

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

    C = strassen(&A[0][0], &B[0][0], SIZE , &cnt);

    printf("Matrix C:\n");
    printMatrix(C, SIZE);

    printf("cnt: %d\n",cnt);

    printf("mul_cnt: %d\n",mul_cnt);
    printf("sub_cnt: %d\n",sub_cnt);
    printf("add_cnt: %d\n",add_cnt);
    

    mul_cnt = 0;
 

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

int* strassen(int *A, int *B, int n, int *cnt) {
    if (n == 1) {
        int *C = (int*)malloc(sizeof(int));
        (*cnt)++;
        mul_cnt++;
        C[0] = A[0] * B[0];
        //printMatrix(C, n);
        return C;
    } else {
        int size = n / 2;

        int *C = (int*)malloc(n * n * sizeof(int));

        // Split matrices into submatrices
        int *a11 = (int*)malloc(size * size * sizeof(int));
        int *a12 = (int*)malloc(size * size * sizeof(int));
        int *a21 = (int*)malloc(size * size * sizeof(int));
        int *a22 = (int*)malloc(size * size * sizeof(int));

        int *b11 = (int*)malloc(size * size * sizeof(int));
        int *b12 = (int*)malloc(size * size * sizeof(int));
        int *b21 = (int*)malloc(size * size * sizeof(int));
        int *b22 = (int*)malloc(size * size * sizeof(int));



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

        // Recursive calls
        int *P1 = strassen(a11, subtract(b12, b22, size, cnt), size, cnt);
        int *P2 = strassen(add(a11, a12, size, cnt), b22, size, cnt);
        int *P3 = strassen(add(a21, a22, size, cnt), b11, size, cnt);
        int *P4 = strassen(a22, subtract(b21, b11, size, cnt), size, cnt);
        int *P5 = strassen(add(a11, a22, size, cnt), add(b11, b22, size, cnt), size, cnt);
        int *P6 = strassen(subtract(a12, a22, size, cnt), add(b21, b22, size, cnt), size, cnt);
        int *P7 = strassen(subtract(a11, a21, size, cnt), add(b11, b12, size, cnt), size, cnt);

        // Calculate C matrices
        int *c11 = add(subtract(add(P5, P4, size, cnt), P2, size, cnt), P6, size, cnt);
        int *c12 = add(P1, P2, size, cnt);
        int *c21 = add(P3, P4, size, cnt);
        int *c22 = subtract(subtract(add(P5, P1, size, cnt), P3, size, cnt), P7, size, cnt);

       // Combine C matrices
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                C[i * n + j] = c11[i * size + j];
                C[i * n + size + j] = c12[i * size + j];
                C[(i + size) * n + j] = c21[i * size + j];
                C[(i + size) * n + size + j] = c22[i * size + j];
            }
        }
            if(size > 1){
                 printMatrix(c11,size);
        printMatrix(c12,size);
        printMatrix(c21,size);
        printMatrix(c22,size);

            }
        //printMatrix(C, n);

        // Free intermediate matrices
        free(a11);
        free(a12);
        free(a21);
        free(a22);
        free(b11);
        free(b12);
        free(b21);
        free(b22);
        free(P1);
        free(P2);
        free(P3);
        free(P4);
        free(P5);
        free(P6);
        free(P7);
        free(c11);
        free(c12);
        free(c21);
        free(c22);

        return C;
    }
}

int *add(int *M1, int *M2, int n, int *cnt) {
    (*cnt)++;
    add_cnt++;
    int *temp = (int*)malloc(n * n * sizeof(int));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            *((temp + i * n) + j) =  *((M1 + i * n) + j) + *((M2 + i * n) + j);
        }
    }

    return temp;
}

int *subtract(int *M1, int *M2, int n, int *cnt) {
    (*cnt)++;
    sub_cnt++;
    int *temp = (int*)malloc(n * n * sizeof(int));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            *((temp + i * n) + j) =  *((M1 + i * n) + j) - *((M2 + i * n) + j);
        }
    }

    return temp;
}
