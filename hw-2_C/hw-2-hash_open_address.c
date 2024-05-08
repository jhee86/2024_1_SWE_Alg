#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TABLE_SIZE 37 // 
#define KEY_VALUE 30 // Number of keys to insert
#define SIZE 500 // Maximum value for generating keys

int A[SIZE];
int dupExist(int *A, int size, int value);


// Linked list node structure for separate chaining
typedef struct Node {
    int key;
    struct Node* next;
} Node;

// Hash table structure

typedef struct {
    int keys[TABLE_SIZE];
    int probe_cnt[TABLE_SIZE];
} HashTable;


int hash_double(int key, int i, int table_size);
int hash_linear(int key, int i, int table_size);
void print_table(HashTable* table,int table_size);
void insert_linear(int key,HashTable* table, int table_size);
void insert_double(int key,HashTable* table, int table_size);

int main(void){
    srand(time(NULL));
    for (int i = 0; i < KEY_VALUE; i++) // Number of keys to insert 
    {
        int value;
        do {
            value = rand() % SIZE;//generate randomv alue
        } while (dupExist(A, i, value)); // no duplication
        A[i] = value;
    }

    HashTable* hashTable1 = (HashTable*)malloc(sizeof(HashTable)); 
    HashTable* hashTable2 = (HashTable*)malloc(sizeof(HashTable)); 

    //테이블 초기화: 비어있는 key list 칸은 -1로 prob count는 0으로
    for (int i = 0 ; i< TABLE_SIZE; i++){
        hashTable1->keys[i]= -1;
        hashTable2->keys[i]=-1;

        hashTable1->probe_cnt[i]= 0;
        hashTable2->probe_cnt[i]= 0;
    }



    printf("< Generated Random Numbers > \n");

    for (int i = 0; i < KEY_VALUE; i++) // Number of keys to insert 
    {
        printf("%d ",A[i]);
    }
    printf("\n");

    

    for (int i = 0; i < KEY_VALUE; i++) {
        int key = A[i];
        insert_linear(key, hashTable1,TABLE_SIZE);
        insert_double(key, hashTable2,TABLE_SIZE);
    }


    printf("\n\n<table1> \n");
    print_table(hashTable1, TABLE_SIZE);


    printf("\n\n<table2> \n");
     print_table(hashTable2, TABLE_SIZE);

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

void print_table(HashTable* table,int table_size){
    //table size만큼 돌아서 해당 인덱스의 chain을 모두 출력
    int cluster_cnt = 0; //cluster의 길이
    int longest_cluster = 0;
    int prob_sum = 0 ;
    int not_null_index_cnt = 0;


    for (int hash_index = 0; hash_index < table_size; hash_index++) {
        int current = table->keys[hash_index];
        int prob_cnt = table->probe_cnt[hash_index];
        
        printf("index %d  (key: %d, prob_cnt: %d) \n", hash_index, current, prob_cnt);
        if(current == -1){
            // 지금까지의 클러스터 길이가 최대 클러스터인지 확인
            if(longest_cluster<cluster_cnt){
                longest_cluster = cluster_cnt;
            }

        cluster_cnt = 0;

        }
        else if(current != -1) { // -1이 아니면 cluster
            cluster_cnt ++;
            prob_sum+=prob_cnt;
            not_null_index_cnt++;
        }

        
 

    }
    printf("\n");


    printf("prob sum : %d // ",prob_sum );
    printf("avg prob : %.1f", (float)prob_sum / not_null_index_cnt);   
    printf("\n");
    //가장 긴  클러스터의 길이
     printf("largest length: %d",longest_cluster);

    
}


int hash_double(int key, int i, int table_size){
    int h1 = key % table_size;
    int h2 = 1 + (key % (table_size - 1));
    return (h1 + i * h2) % table_size;

}

int hash_linear(int key, int i, int table_size){
    return (key % table_size + i) % table_size;

}

void insert_linear(int key,HashTable* table, int table_size){
    int hash_index;
    int i = 0;

    do{
    hash_index= hash_linear(key,i,table_size);
    //함수가 한번 호출 되었을 때마다 prob 회수 증가
    i++;
    }
    while(table->keys[hash_index] != -1);
    table->keys[hash_index]= key;
    table->probe_cnt[hash_index]=i;

    

}
void insert_double(int key,HashTable* table, int table_size){
    int hash_index;
    int i = 0;

    do{
    hash_index= hash_double(key,i,table_size);
    //함수가 한번 호출 되었을 때마다 prob 회수 증가
    i++;
    }
    while(table->keys[hash_index] != -1);
    table->keys[hash_index]= key;
    table->probe_cnt[hash_index]=i;

}
