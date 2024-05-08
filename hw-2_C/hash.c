#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TABLE_SIZE 5 // h(k)=kmod5
#define TABLE_SIZE_2 11 // h(k)=kmod11

#define KEY_VALUE 50 // Number of keys to insert
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
    Node* table1[TABLE_SIZE]; //h(k)=kmod5
    Node* table2[TABLE_SIZE_2]; //h(k)=kmod11

} HashTable;




int hash_func(int key, int table_size);

void insert (int key, Node* table[], int table_size);
void print_table(Node* table[],int table_size);

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

    HashTable* hashTables = (HashTable*)malloc(sizeof(HashTable)); 

    printf("< Generated Random Numbers > \n");

    for (int i = 0; i < KEY_VALUE; i++) // Number of keys to insert 
    {
        printf("%d ",A[i]);
        
    }
    printf("\n");

            // 각 배열에 대해 메모리 할당
    for (int i = 0; i < TABLE_SIZE; ++i) {
        hashTables->table1[i] = NULL;  // 초기화
    }


    for (int i = 0; i < TABLE_SIZE_2; ++i) {
        hashTables->table2[i] = NULL;  // 초기화
    }

    for (int i = 0; i < KEY_VALUE; i++) {
        int key = A[i];
        insert(key, hashTables->table1, TABLE_SIZE);
        insert(key, hashTables->table2, TABLE_SIZE_2);
        
    }


    printf("\n\n<table1> \n");
    print_table(hashTables->table1, TABLE_SIZE);


    printf("\n\n<table2> \n");
    print_table(hashTables->table2, TABLE_SIZE_2);


    return 0;
}


int hash_func(int key, int table_size) {
    return key % table_size;
}



void insert (int key, Node* table[], int table_size){
    //새로운 노드 생성
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = NULL;
     
    int hash_index= hash_func(key, table_size); //hash func
    

    if (table[hash_index] == NULL) { // 해당인덱스의 첫번째 요소로 들어갈때
        table[hash_index] = newNode;
    } else {
        // 체이닝으로 연결된 노드들 중 가장 마지막 노드에 새로운 노드 추가
        Node* current = table[hash_index];
        while (current->next != NULL) { //마지막으로 이동
            current = current->next;
        }
        current->next = newNode; //마지막에 새로운 노드를 추가
    }

} 

int dupExist(int *A, int size, int value) {
    for (int i = 0; i < size; ++i) {
        if (A[i] == value) {
            return 1;
        }
    }
    return 0;
}

void print_table(Node* table[], int table_size) {
    //table size만큼 돌아서 해당 인덱스의 chain을 모두 출력
    int cnt; //chain의 길이
    int lengths[table_size];

    for (int hash_index = 0; hash_index < table_size; hash_index++) {
        Node* current = table[hash_index];
        cnt = 0;

        printf("index %d : ", hash_index);
        while (current != NULL) { // NULL이 아닌 동안 반복
            printf("%d ", current->key);
            current = current->next;
            cnt++;
        }
        lengths[hash_index] = cnt;
        printf("\n");
        

    }
    printf("\n");

    int sum = 0 ; 
    for(int i = 0 ; i<table_size; i++){
            //printf("cnt: %d ", lengths[i]);
            sum+=lengths[i];
        }
    printf("avg length : %.1f", (float)sum/table_size);    
    printf("\n");
    
    //가장 긴 체인의 길이
    int max = 0;
     for(int i = 0 ; i<table_size; i++){
        
        if (max < lengths[i]){
            max = lengths[i];
        }
        
     }
     printf("longest length: %d",max);

    
}
