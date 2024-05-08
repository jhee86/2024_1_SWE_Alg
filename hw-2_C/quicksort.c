#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100

int comparison_count;
//
int dupExist(int *A, int size, int value);
void swap(int* a, int* b);
void Already_sorted(int *A, int size);

void sort(int *A, int low, int high);
int partition(int *A,int left, int right);

void reversely_sorted(int *A, int size);
void reverse_array(int *A, int size);
///
void last_quick_sort(int *A, int low, int high);
int last_partition(int *A,int left, int right);

void random_quick_sort(int *A, int low, int high);
int random_partition(int *A,int left, int right);


int find_median(int *A, int right);
void median_quick_sort(int *A, int low, int high);
int median_partition(int *A,int left, int right);


void paranoid_quick_sort(int *A, int low, int high);
int paranoid_partition(int *A,int left, int right);



int main(void){

int A[SIZE] =  {0};
int B[SIZE] =  {0};
int C[SIZE] = {0};
int D[SIZE] =  {0};


printf("\n");
printf("\n");

    //case1)
srand(time(NULL));
    for (int i = 0; i < SIZE; ++i) {
        int value;
        do {
            value = rand() % 1000;//generate random value
        } while (dupExist(A, i, value)); // no duplication
        A[i] = value;
        B[i] = value;
        C[i] = value;
        D[i] = value;
    }

  

///////////////////////////////////////////////////////////////////////////////
    // print
    printf("case 1) Before sorting \n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    printf("-------After sorting-------\n");

    printf("<last_quick_sort>\n");
    comparison_count= 0;
    last_quick_sort(A, 0, sizeof(A)/sizeof(A[0])-1);
    printf("Number of comparisons: %d\n", comparison_count);
     // print
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
/////////////////
    printf("<median_quick_sort>\n");
   comparison_count= 0;
    median_quick_sort(B, 0, sizeof(B)/sizeof(B[0])-1);
       printf("Number of comparisons: %d\n", comparison_count);
     // print
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", B[i]);
    }
    printf("\n");
///////////////////
   printf("<random_quick_sort>\n");
   comparison_count= 0;
   random_quick_sort (C, 0, sizeof(C)/sizeof(C[0])-1);
      printf("Number of comparisons: %d\n", comparison_count);
     // print
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", C[i]);
    }
    printf("\n");

    printf("<paranoid_quick_sort>\n");
   comparison_count= 0;
    paranoid_quick_sort (D, 0, sizeof(D)/sizeof(D[0])-1);
   printf("Number of comparisons: %d\n", comparison_count);
     // print
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", D[i]);
    }
    printf("\n");
   //printf("case 1) the number of comparisons : %d \n",cnt);
printf("\n");
printf("\n");

///////////////////////////////////////////////////////////////////////////////
printf("case 2) Before sorting \n");
    
    Already_sorted(A, 100);

    // 출력
    for (int i = 0; i < 100; ++i) {
        printf("%d ", A[i]);
        B[i] = A[i];
        C[i] = A[i];
        D[i] = A[i];
    }
    printf("\n");

     printf("-------After sorting-------\n");

    printf("<last_quick_sort>\n");
   comparison_count= 0;
    last_quick_sort(A, 0, sizeof(A)/sizeof(A[0])-1);
       printf("Number of comparisons: %d\n", comparison_count);
     // print
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
/////////////////
    printf("<median_quick_sort>\n");
       comparison_count= 0;
    median_quick_sort(B, 0, sizeof(B)/sizeof(B[0])-1);
       printf("Number of comparisons: %d\n", comparison_count);
     // print
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", B[i]);
    }
    printf("\n");
///////////////////
   printf("<random_quick_sort>\n");
      comparison_count= 0;
   random_quick_sort (C, 0, sizeof(C)/sizeof(C[0])-1);
      printf("Number of comparisons: %d\n", comparison_count);
     // print
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", C[i]);
    }
    printf("\n");

    printf("<paranoid_quick_sort>\n");
       comparison_count= 0;
    paranoid_quick_sort (D, 0, sizeof(D)/sizeof(D[0])-1);
       printf("Number of comparisons: %d\n", comparison_count);
     // print
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", D[i]);
    }
    printf("\n");



printf("\n");
printf("\n");
    printf("case 3) Before sorting \n");
    
    reversely_sorted(A, 100);

    // 출력
    for (int i = 0; i < 100; ++i) {
        printf("%d ", A[i]);
        B[i] = A[i];
        C[i] = A[i];
        D[i] = A[i];
    }
    printf("\n");

     printf("-------After sorting-------\n");

    printf("<last_quick_sort>\n");
       comparison_count= 0;
    last_quick_sort(A, 0, sizeof(A)/sizeof(A[0])-1);
       printf("Number of comparisons: %d\n", comparison_count);
     // print
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
/////////////////
    printf("<median_quick_sort>\n");
       comparison_count= 0;
    median_quick_sort(B, 0, sizeof(B)/sizeof(B[0])-1);
       printf("Number of comparisons: %d\n", comparison_count);
     // print
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", B[i]);
    }
    printf("\n");
///////////////////
   printf("<random_quick_sort>\n");
      comparison_count= 0;
   random_quick_sort (C, 0, sizeof(C)/sizeof(C[0])-1);
      printf("Number of comparisons: %d\n", comparison_count);
     // print
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", C[i]);
    }
    printf("\n");

    printf("<paranoid_quick_sort>\n");
       comparison_count= 0;
    paranoid_quick_sort (D, 0, sizeof(D)/sizeof(D[0])-1);
       printf("Number of comparisons: %d\n", comparison_count);
     // print
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", D[i]);
    }
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


void Already_sorted(int *A, int size){
    int num = 1;
    for (int i = 0; i < size - 10; i++) {
        A[i] = num;
        num += 2;
    }

    // 나머지 10개의 원소 랜덤으로 채우기 ,중복 없이
    srand(time(NULL));
    for (int i = size - 10; i < size; i++) {
        int value;
        do {
            value = rand() % 200;//generate random value
        } while (dupExist(A, i, value)); // no duplication
        A[i] = value;
    }
    
}
void sort(int *A, int low, int high){
        if (low < high){
        int pivot = last_partition(A,low,high);
        //printf("pivot : %d \n ",pivot);
        sort(A,low,pivot-1);//left
        sort(A,pivot+1,high);//right
    }
}
int partition(int *A,int left, int right){
    int pivot = A[right];  
    int low = left;
    int high = right;

    int i = low-1;

    for ( int j = left; j<right; j++){

        if(A[j]<=pivot){
            i++;
            swap(&A[i], &A[j]); //피벗보다 작은 쪽을 왼쪽으로 이동
        }
    }
     swap(&A[i+1], &A[high]); //피벗 재설정
    
    return i+1; //반환

}


void reversely_sorted(int *A, int size){
 // 179부터 1까지의 홀수를 역순으로 채우기
    for (int i = 0; i < size - 10; ++i) {
        A[i] = 179 - 2 * i;
    }

    // 나머지 10개의 요소는 랜덤한 정수로 채우기
    srand(time(NULL));
    for (int i = size - 10; i < size; ++i) {
        int value;
        do {
            value = rand() % 200;
        } while (dupExist(A, i, value)); // 중복된 키 피하기
        A[i] = value;
    }

}

void reverse_array(int *A, int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = A[i];
        A[i] = A[size - i - 1];
        A[size - i - 1] = temp;
    }
}


void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void last_quick_sort(int *A, int low, int high){
    //printf("low : %d \n",low);
    //printf("high : %d \n",high);
   comparison_count++;

    if (low < high){
        int pivot = last_partition(A,low,high);
        //printf("pivot : %d \n ",pivot);
        last_quick_sort(A,low,pivot-1);//left
        last_quick_sort(A,pivot+1,high);//right
    }
    
}
int last_partition(int *A,int left, int right){
    int pivot = A[right];  //use the last element in the input as a pivot

    int low = left;
    int high = right;

    int i = low-1;

    for ( int j = left; j<right; j++){
   comparison_count++;

        if(A[j]<=pivot){
            i++;
            swap(&A[i], &A[j]); //피벗보다 작은 쪽을 왼쪽으로 이동
        }
    }
     swap(&A[i+1], &A[high]); //피벗 재설정
    
    return i+1; //반환
}
void random_quick_sort(int *A, int low, int high){
       comparison_count++;

        if (low < high){
        int pivot = random_partition(A,low,high);
        //printf("pivot : %d \n ",pivot);
        random_quick_sort(A,low,pivot-1);//left
        random_quick_sort(A,pivot+1,high);//right
    }


}
int random_partition(int *A,int left, int right){
    srand(time(NULL));
    int randIdx = left + rand() % (right - left + 1); // low와 high 사이의 랜덤 인덱스 선택
    swap(&A[randIdx], &A[right]); // 랜덤 피봇을 맨 끝과 자리 교체

    int pivot = A[right];  //use the last element in the input as a pivot
    int low = left;
    int high = right;

    int i = low-1;

    for ( int j = left; j<right; j++){
   comparison_count++;

        if(A[j]<=pivot){
            i++;
            swap(&A[i], &A[j]); //피벗보다 작은 쪽을 왼쪽으로 이동
        }
    }
     swap(&A[i+1], &A[high]); //피벗 재설정
    return i+1; //반환
}



int find_median(int *A, int right){
    //중간값 찾기
    int arr[3] = {right - 2,right -1,right};
    // 세 요소를 정렬
    
    if(A[arr[0]]>A[arr[1]]){
        comparison_count++;
        swap(&arr[0],&arr[1]);
    } 
    

    if(A[arr[1]]>A[arr[2]]){
        comparison_count++;
        swap(&arr[1],&arr[2]);

    }
    

    if(A[arr[0]]>A[arr[1]]){
        comparison_count++;
            swap(&arr[0],&arr[1]);

    }

    return arr[1];
}



void median_quick_sort(int *A, int low, int high){
    comparison_count++;
    if (low < high) {
        int pivot = median_partition(A, low, high);
        median_quick_sort(A, low, pivot - 1);  // 왼쪽 부분 배열 정렬
        median_quick_sort(A, pivot + 1, high); // 오른쪽 부분 배열 정렬
    }
}

int median_partition(int *A, int left, int right) {
    int randIdx = find_median (A,right); // 피벗은 마지막 요소로 설정
    swap(&A[randIdx], &A[right]); 
    int pivot = A[right];
    int i = left - 1;     // 더 작은 요소의 인덱스

    for (int j = left; j < right; j++) {
        comparison_count++;
        if (A[j] <= pivot) {
            i++;
            swap(&A[i], &A[j]); // 피벗보다 작은 요소를 왼쪽으로 이동
        }
    }
    swap(&A[i + 1], &A[right]); // 피벗을 올바른 위치로 이동
    return i + 1; // 파티션 인덱스 반환
}



void paranoid_quick_sort(int *A, int low, int high){
       comparison_count++;

    if (low < high){
        int pivot = paranoid_partition(A,low,high);
        //printf("pivot : %d \n ",pivot);
        paranoid_quick_sort(A,low,pivot-1);//left
        paranoid_quick_sort(A,pivot+1,high);//right
    }
}

int paranoid_partition(int *A, int left, int right) {
    srand(time(NULL));
    int randIdx;
    do{
        randIdx = left + rand() % (right - left + 1);
       comparison_count++;

    } while (((randIdx - left) < (right - left + 1) * 0.2) || ((randIdx - left) > (right - left + 1)*0.8)) ;

   
  
    // 피벗을 마지막 위치로 이동
    swap(&A[randIdx], &A[right]);

    int pivot = A[right]; // 피벗은 마지막 요소
    int i = left - 1; // 더 작은 요소의 인덱스

    // 피벗을 기준으로 배열을 파티션
    for(int j = left; j < right; j++){
           comparison_count++;

        if(A[j] <= pivot){
            i++;
            swap(&A[i], &A[j]);
        }
    }

    swap(&A[i + 1], &A[right]); // 피벗을 올바른 위치로 이동
    return i + 1; // 파티션 인덱스 반환
}
