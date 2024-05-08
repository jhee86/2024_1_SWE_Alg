#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

typedef struct Node {
    int value;
    int flag; //delete 할때 홀수번째인지 확인
    int index; // print시 index
    struct Node* next;

} node;

void insert(node** head, int value);
void print_all(node** head);
void delete(node** head, int value);
void print(node** head);

int main(void) {

    node* list = NULL;

    int A[SIZE];

    //fill the array

    srand(time(NULL));
    for (int i = 0; i < SIZE; ++i) {
        int value;
        value = rand() % 100;//generate randomv alue
        A[i] = value;
        insert(&list, A[i]);
    }
    printf("\ngenerated numbers:\n");
    print_all(&list);
    printf("\n");

    printf("1st Trial\n");
    

    //select random index
    int random_index = rand() % SIZE;
    int num =  A[random_index];
    printf("number: %d\n", A[random_index]);

    //delete
    delete(&list, num);


    // print
    print(&list);
printf("\n");
    printf("2nd Trial\n");
    

    //select random index
    random_index = rand() % SIZE;
    num =  A[random_index];
    printf("number: %d\n", A[random_index]);

    //delete
    delete(&list, num);


    // print
    print(&list);
printf("\n");
    printf("3rd Trial\n");

    //select random index
    random_index = rand() % SIZE;
    num =  A[random_index];
    printf("number: %d\n", A[random_index]);

    //delete
    delete(&list, num);


    // print
    print(&list);
    return 0;
}

void insert(node** head, int value) {
    //새로운 노드를 생성하여 값을 할당
    node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->value = value;
    new_node->next = NULL;

    //빈 linked list일 때
    if (*head == NULL) {
        *head = new_node;
        return;
    }

    //리스트를 순회하여 마지막 요소와 그 전 요소를 찾음

   
    node *curr = *head;

    while (curr->next != NULL&& curr->next->next != NULL) {   

        curr = curr->next; // 뒤로 이동

    }

    // 새로운 노드를 이전 노드와 마지막 노드 사이에 연결
    new_node->next = curr -> next;
    curr->next=new_node;
}


void print_all(node** head){

    
    
    node *curr = *head;
    int index=1;

    //리스트 전체를 순회하면서 인덱스 매기기
    while (curr != NULL) {

        curr->index = index;
        index ++;
        curr = curr->next;
    }
    curr = *head;

    while (curr != NULL) {
        printf("%d ",curr->value);
        //printf("(%d) ->",curr->index);
        curr = curr->next; // 뒤로 이동
    }
    //printf("NULL\n");
    printf("\n");
}

void delete(node ** head, int value) {
    // 빈 linked list일 때
    if (*head == NULL) {
        printf("ERR: NO NODE HERE");
        return;
    }

      //odd-numbered-location을 찾아서 flag = 1
    //움직일때마다 idx ++, idx가 홀수이면 flag= 1
    node *curr = *head;
    int idx = 1;
    
    while (curr != NULL) {
        if (idx % 2 == 1) {
            curr->flag = 1;
        }
        curr = curr->next;
        idx++; 
    }

   //flag ==1 && value ==0이면 prev-> next = curr->next (del)
    node *prev = NULL;
    curr = *head;
    while (curr != NULL) {
        if (curr->flag == 1 && curr->value == value) {
            // 삭제하려는 노드가 첫 번째에 있을 때
            if (prev == NULL) {
                *head = curr->next;
                //free(curr);
                //return;
            } else {
                prev->next = curr->next;
                //free(curr);
                //return;
            }
        }
        prev = curr;
        curr = curr->next;
    }
}

//절반 나눠서 프린트
void print(node** head){


    // 빈 linked list일 때
    if (*head == NULL) {
        printf("ERR: NO NODE HERE");
        return;
    }


    node *curr = *head;
    int index=1;

    //리스트 전체를 순회하면서 인덱스 매기기
    while (curr != NULL) {

        curr->index = index;
        index ++;
        curr = curr->next;
    }

    int last = index-1; 

    curr = *head;

    printf("1st line : ");
    
    while (curr != NULL) {
        if (curr->index <( last/2)){
      
            printf("%d ",curr->value);
 
            curr = curr->next; // 뒤로 이동
        }
        if (curr->index == ( last/2)){
            printf("\n2nd line : ");
            
            printf("%d ",curr->value);
            curr = curr->next;

        }
        if(curr->index > (last/2)){
            
            printf("%d ",curr->value);
            curr = curr->next;
        }  
    }
 
    //printf("NULL\n");
       printf("\n");

}