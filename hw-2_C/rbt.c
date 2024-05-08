#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include <string.h>

#define BLACK 0
#define RED 1
#define SIZE 10

int rrcnt; // right rotation cnt
int lrcnt;  //left rotation cnt
int totalR;
int totalL;

typedef struct node
{
	int key;
	int color;
	struct node* left;
	struct node* right;
	struct node* parent;
}Node;

typedef struct rbt
{
	struct node* root;
	struct node* nil;
}rbtree;

int dupExist(int *A, int size, int value);
Node* new_node(rbtree* T, int val);
void left_rotate(rbtree* T, Node *x);
void right_rotate(rbtree* T, Node *x);

int RB_insert(rbtree* T, Node *z);
void RB_insert_Fixup(rbtree* T,Node *z);

void RB_transplant (rbtree* T, Node *u, Node *v);
void RB_Delete(rbtree* T, Node *z);
void RB_Delete_Fixup(rbtree* T, Node *z);

//void print_tree_structure(Node* node, Node* parent, int is_left);
void print_tree_structure(Node* node, Node* parent, int is_left, char** lines, int level, int max_level);

void print_tree(rbtree* T) ;
int get_level(Node* node, Node* nil);
int get_max_level(rbtree* T);
//void fill_tree_lines(Node* node, Node* nil, char** tree_lines, int level, int max_level);
void fill_tree_structure(Node* node, Node* nil, char tree_structure[][100], int level, int left, int right);

Node* search(Node* T, int k);

Node* Tree_Minimum(Node* T);

int main (void){
    int success; 
	rbtree* T = (rbtree*)malloc(sizeof(rbtree));
	T->nil=(Node*)malloc(sizeof(Node));

    T->nil->left = T->nil;
	T->nil->right = T->nil;
	T->nil->parent= T->nil;

	T->nil->color = BLACK;
	T->nil->key = -1;


	T->root = T->nil;
    int A[SIZE];
        srand(time(NULL));
    for (int i = 0; i < SIZE; ++i) {
        int value;
        do {
            value = rand() % 20;//generate randomv alue
        } while (dupExist(A, i, value)); // no duplication
        A[i] = value;
    }
    int totalR = 0;
    int totalL = 0;
    printf("\nGenerated Numbers\n");
    for (int i = 0; i < SIZE; i++) {
        int x = A[i];
        printf("\n __________________________________ \n");
        printf("insert %d \n ",x );
        lrcnt = 0;
        rrcnt = 0;
        success = RB_insert(T,new_node (T,x));
        totalR+=rrcnt;
        totalL+=lrcnt;
        printf("left rotation cnt : %d  right rotation cnt : %d \n", lrcnt,rrcnt);
        print_tree(T);
        printf("\n");

        
     
            }




    
        lrcnt = 0;
        rrcnt = 0;
    success = RB_insert(T,new_node (T,7));
    if(success ==1 ){
        printf("\n __________________________________ \n");

        printf(" insert %d\n ",7 );
        printf("left rotation cnt : %d  right rotation cnt : %d \n", lrcnt,rrcnt);
        totalR+=rrcnt;
        totalL+=lrcnt;
        
        printf("\n");
        print_tree(T);
        printf("\n");

    }
            lrcnt = 0;
        rrcnt = 0;
    success = RB_insert(T, new_node(T,12));
        if(success ==1 ){
        printf("\n __________________________________ \n");
        printf("insert %d\n ",12 );
         printf("left rotation cnt : %d  right rotation cnt : %d \n", lrcnt,rrcnt);
        totalR+=rrcnt;
        totalL+=lrcnt;        
        printf("\n");
        print_tree(T);
        printf("\n");

    }
            lrcnt = 0;
        rrcnt = 0;
    success = RB_insert(T, new_node(T,2));
          if(success ==1 ){
printf("\n __________________________________ \n");        
        printf("insert %d\n ",2 );
         printf("left rotation cnt : %d  right rotation cnt : %d \n", lrcnt,rrcnt);
        totalR+=rrcnt;
        totalL+=lrcnt;        
        printf("\n");
        print_tree(T);
        printf("\n");

    }  
            lrcnt = 0;
        rrcnt = 0;
    success = RB_insert(T,new_node(T,18));
            if(success ==1 ){
printf("\n __________________________________ \n");
        printf("insert %d\n ",18 );
         printf("left rotation cnt : %d  right rotation cnt : %d \n", lrcnt,rrcnt);
        totalR+=rrcnt;
        totalL+=lrcnt;        
        printf("\n");
        print_tree(T);
        printf("\n");

    }
    success = RB_insert(T, new_node(T,16));
        if(success ==1 ){
    printf("\n __________________________________ \n");
        printf("insert %d\n ",16 );
         printf("left rotation cnt : %d  right rotation cnt : %d \n", lrcnt,rrcnt);
        totalR+=rrcnt;
        totalL+=lrcnt;        
        printf("\n");
        print_tree(T);
        printf("\n");

    }

    printf("\n3) After finish insert:\n");
    printf("\ntotal Left rotation : %d, total Right rotaion: %d\n",totalL,totalR);
    print_tree(T);

    totalR = 0;
    totalL = 0;

    printf("\n\n\n4) Red-Black Tree (delete): ");
    lrcnt = 0; rrcnt = 0;
    printf("\n __________________________________ \n");
    printf("Delete %d",18);
    RB_Delete(T, search(T->root,18));
    printf("\nleft rotation cnt : %d  right rotation cnt : %d \n", lrcnt,rrcnt);
        totalR+=rrcnt;
        totalL+=lrcnt;    
    print_tree(T);

    lrcnt = 0; rrcnt = 0;
    printf("\n __________________________________ \n");    
    printf("Delete root - key  %d ",search(T->root,T->root->key)->key);
    RB_Delete(T, search(T->root,T->root->key));
    printf("\nleft rotation cnt : %d  right rotation cnt : %d \n", lrcnt,rrcnt);
        totalR+=rrcnt;
        totalL+=lrcnt;    
    print_tree(T);

    lrcnt = 0; rrcnt = 0;
    printf("\n __________________________________ \n");
    printf("Delete %d",2);    
    RB_Delete(T, search(T->root,2));
    printf("\nleft rotation cnt : %d  right rotation cnt : %d \n", lrcnt,rrcnt);
        totalR+=rrcnt;
        totalL+=lrcnt;    
    print_tree(T);

    lrcnt = 0; rrcnt = 0;
    printf("\n __________________________________ \n");
    printf("Delete root - key  %d ",search(T->root,T->root->key)->key);
    RB_Delete(T, search(T->root,T->root->key));
    printf("\nleft rotation cnt : %d  right rotation cnt : %d \n", lrcnt,rrcnt);
        totalR+=rrcnt;
        totalL+=lrcnt;    
    print_tree(T);

    lrcnt = 0; rrcnt = 0;
    printf("\n __________________________________ \n");
    printf("Delete root - key  %d ",search(T->root,T->root->key)->key);
    RB_Delete(T, search(T->root,T->root->key));
    printf("\nleft rotation cnt : %d  right rotation cnt : %d \n", lrcnt,rrcnt);
        totalR+=rrcnt;
        totalL+=lrcnt;    
    
    print_tree(T);
    printf("\nAfter finish delete:\n");
 printf("\ntotal Left rotation : %d, total Right rotaion: %d\n",totalL,totalR);    
    print_tree(T);

    printf("\n");
    printf("\n");
    
  


    return 0;
}

Node* new_node(rbtree* T, int val)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->key = val;
	node->color = BLACK;
	node->left = T->nil;
	node->right = T->nil;
	node->parent = T->nil;
	return node;
}

void left_rotate(rbtree* T, Node *x){
    Node* y =(Node*)malloc(sizeof(Node)); 
    y= x->right;
    x->right = y->left;
    if(y->left != T->nil){
        y->left->parent = x;
    }
    y->parent = x->parent;
    if(x->parent == T->nil){
        T->root = y;
    }
    else if(x == x->parent->left){
        x->parent->left =y;

    }
    else x->parent->right = y;
    y->left = x;
    x->parent =y;


}

void right_rotate(rbtree* T, Node *x){
   Node* y =(Node*)malloc(sizeof(Node)); 
    y= x->left;
    x->left = y->right;
    if(y->right != T->nil){
        y->right->parent = x;
    }
    y->parent = x->parent;
    if(x->parent == T->nil){
        T->root = y;
    }
    else if(x == x->parent->right){
        x->parent->right =y;

    }
    else x->parent->left = y;
    y->right = x;
    x->parent =y;
}

int RB_insert(rbtree* T, Node *z){
    Node* x =(Node*)malloc(sizeof(Node)); 
    x = T->root;
    
    Node* y =(Node*)malloc(sizeof(Node)); //새로운 노드의 부모
    y = T->nil; 

    while (x!=T->nil){ // nil까지 
        y = x;
        if (z->key < x->key){ //작으면 왼쪽 크면 오른쪽
            x=x->left;

        } 
        else if (z->key == x->key){ //노드가 이미 있을때 중단

        //printf("the node already exists");
        return -1;



        }
        else{
            x=x->right;
        }
    }
    z->parent = y; // y를 z의 부모로 두고 삽입할 위치를 탐색

    if(y==T -> nil){ // 비어있는 트리라면
        T->root = z; // z를 루트로
    }
    else if(z->key < y->key) {
        y->left = z; // 작으면 왼쪽
    }
    else {y->right = z;} // 크면 오른쪽

// z의 맨끝은 nil
    z->left = T->nil;
    z->right = T->nil;
    z->color = RED; // 새로 삽입하는 노드의 색은 red 

    RB_insert_Fixup(T,z); // 재정렬
return 1;
}

void RB_insert_Fixup(rbtree* T,Node *z){
     Node* y =(Node*)malloc(sizeof(Node)); //새로운 노드의 부모
    while(z->parent->color==RED){

        if(z->parent == z->parent->parent->left){
            y = z->parent->parent->right;
        
            if(y->color == RED){
                z->parent->color = BLACK ; //case 1
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;

            }
            else{ 
                if(z==z->parent->right){ //case 2
                    z = z->parent;
                    left_rotate(T,z);
                    lrcnt++;
                }
                z->parent->color=BLACK; //case 3
                z->parent->parent->color = RED;
                right_rotate(T,z->parent->parent);
                rrcnt ++;
            }
    } else{
        y = z->parent->parent->left;
        if (y->color == RED){
             z->parent->color =BLACK;
             y->color = BLACK;
             z->parent->parent ->color = RED;
             z = z->parent->parent;
        } else{
            if(z == z->parent->left){
                z=z->parent;
                right_rotate(T,z);
                rrcnt++;

            }
            z->parent->color =BLACK;
            z->parent->parent->color =RED;
            left_rotate(T,z->parent->parent);
            lrcnt++;
        
        }
        
    }

} 
T->root->color = BLACK;
}
Node* Tree_Minimum(Node* T){
    Node* x =(Node*)malloc(sizeof(Node)); 
    while (T->left->key != -1 ){ //-1 = nil
    T = T->left;
    }
    x=T;
    return x;
}
void RB_transplant (rbtree* T, Node *u, Node *v){
    if(u->parent == T->nil) T->root = v;
    else if(u == u->parent->left) u->parent->left = v;
    else u->parent->right = v;
    v->parent = u->parent;
}

void RB_Delete(rbtree* T, Node *z){
     Node* y =(Node*)malloc(sizeof(Node)); //새로운 노드의 부모
     Node* x =(Node*)malloc(sizeof(Node)); //새로운 노드의 부모
     y = z;
     int y_original_color = y->color;
     if (z->left == T->nil){
        x= z->right;
        RB_transplant(T,z,z->right);
     }
     else if(z->right == T->nil){
        x=z->left;
        RB_transplant(T,z,z->left);
     }
     else{
        y=Tree_Minimum(z->right);
        y_original_color = y->color;
        x= y->right;
        if(y!=z->right){
            RB_transplant(T,y,y->right);
            y->right = z->right;
            y->right->parent = y;
            
        }
        else x->parent =y;
        RB_transplant(T,z,y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;


     }
     if(y_original_color == BLACK) RB_Delete_Fixup(T,x);


}

void RB_Delete_Fixup(rbtree* T, Node *x){
    Node* w =(Node*)malloc(sizeof(Node)); 
    while((x!=T->root) &&( x->color == BLACK)){
        if(x==x->parent->left) { //case 1
            w = x->parent->right;
            if(w->color == RED){
                w->color = BLACK;
                x->parent->color = RED;
                left_rotate(T,x->parent);
                lrcnt++;
                w = x->parent->right;

            }
            if(w->left->color == BLACK && w->right->color == BLACK){ //case2
                w->color = RED;
                x= x->parent;
            }
            else{
                if(w->right->color ==BLACK){ //case 3
                    w->left->color = BLACK; 
                    w->color = RED;
                    right_rotate(T,w);
                    rrcnt++;
                    w= x->parent->right;

                } w->color = x->parent->color; //case 4
                x->parent->color = BLACK;
                w->right->color =BLACK;
                left_rotate(T,x->parent);
                lrcnt++;
                x=T->root;
            }

            
        }
        else{
            w = x->parent->left;
            if(w->color == RED){
                w->color = BLACK;
                x->parent->color = RED;
                right_rotate(T,x->parent);
                rrcnt++;
                w = x->parent->left;

            }
            if(w->right->color == BLACK && w->left->color == BLACK){ //case2
                w->color = RED;
                x= x->parent;
            }
            else{
                if(w->left->color ==BLACK){ //case 3
                    w->right->color = BLACK; 
                    w->color = RED;
                    left_rotate(T,w);
                    lrcnt++;
                    w= x->parent->left;

                } w->color = x->parent->color; //case 4
                x->parent->color = BLACK;
                w->left->color=BLACK;
                right_rotate(T,x->parent);
                rrcnt++;
                x=T->root;
            }

        }


    }
    x->color =BLACK;

}

int dupExist(int *A, int size, int value) {
    for (int i = 0; i < size; ++i) {
        if (A[i] == value) {
            return 1;
        }
    }
    return 0;
}

Node* search(Node* T, int k){
    Node* node = (Node*)malloc(sizeof(Node));
    if (k == T->key){ // 탐색 성공
        node = T;
        return node; 
    }
    // 오른쪽 탐색
    else if (k > T->key){
        //단말 노드면
        if (T->right->key == -1)
		{
			node = T;
			return node;
		}  // 단말노드가 아니면 탐색을 지속
        else{
            return search(T->right , k);
        }     

    }
    //왼쪽 탐색
    else{
         if (T->left->key == -1)
		{
			node = T;
			return node;
		}  // 단말노드가 아니면 탐색을 지속
        else{
            return search(T->left , k);
        }     

 
    }
}

int get_max_level(rbtree* T) {
    return get_level(T->root, T->nil);
}
int get_level(Node* node, Node* nil) {
 
    if (node == nil)
        return -1;
    int left_level = get_level(node->left, nil);
    int right_level = get_level(node->right, nil);
    return (left_level > right_level) ? (left_level + 1) : (right_level + 1);
}

void print_tree(rbtree* T)
{
    if (T->root == T->nil)
    {
        printf("트리가 비어 있습니다!\n");
        return;
    }

    // 트리의 최대 높이 계산
    int max_level = get_max_level(T);

    // 출력할 레드-블랙 트리의 구조를 저장할 배열 생성
    char tree_structure[50][100] = {0};

    // 레드-블랙 트리의 구조를 배열에 저장
    fill_tree_structure(T->root, T->nil, tree_structure, 0, 0, 100);

    // 저장된 배열을 이용하여 트리 출력
    for (int i = 0; i <= max_level; ++i)
    {
        for (int j = 0; j < 100; ++j)
        {
            if (tree_structure[i][j] != 0)
            {
                printf("%c", tree_structure[i][j]);
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

/*
void fill_tree_structure(Node* node, Node* nil, char tree_structure[][100], int level, int left, int right)
{
    if (node == nil || level > 49)
        return;

    // 현재 노드의 위치 계산
    int mid = (left + right) / 2;

    // 현재 노드의 색상에 따라 문자 지정
    if (node->color == BLACK)
    {
        tree_structure[level][mid] = 'B';
    
    }
    else
    {
        tree_structure[level][mid] = 'R';
    }

    // 현재 노드의 키 값을 문자열로 변환하여 출력 배열에 추가
    char key_str[5]; // 키 값이 최대 4자리이므로 5자리 배열
    snprintf(key_str, 5, "%d", node->key);

    // 현재 노드의 키 값을 출력 배열에 추가
    int key_len = strlen(key_str);
    int start_index = mid - (key_len / 2);
    for (int i = 0; i < key_len; ++i)
    {
        //tree_structure[level][start_index + i] = key_str[i];
    }

    // 키 값과 색상 사이에 공백 추가
    tree_structure[level][start_index - 1] = ' '; // 왼쪽 공백
    tree_structure[level][start_index + key_len] = ' '; // 오른쪽 공백

    // 왼쪽 자식 노드 처리
    fill_tree_structure(node->left, nil, tree_structure, level + 1, left, mid - 1);

    // 오른쪽 자식 노드 처리
    fill_tree_structure(node->right, nil, tree_structure, level + 1, mid + 1, right);
}
*/
void fill_tree_structure(Node* node, Node* nil, char tree_structure[][100], int level, int left, int right)
{
    if (node == nil || level > 49)
        return;

    // 현재 노드의 위치 계산
    int mid = (left + right) / 2;

    // 현재 노드의 색상과 키 값을 문자열로 변환하여 출력 배열에 추가
    char color_key_str[7]; // 최대 6자리(색상 + 키 값)이므로 7자리 배열
    if (node->color == BLACK)
        snprintf(color_key_str, 7, "%d B", node->key);
    else
        snprintf(color_key_str, 7, "%d R", node->key);

    // 현재 노드의 색상과 키 값을 출력 배열에 추가
    int color_key_len = strlen(color_key_str);
    int start_index = mid - (color_key_len / 2);
    for (int i = 0; i < color_key_len; ++i)
    {
        tree_structure[level][start_index + i] = color_key_str[i];
    }

    // 왼쪽 자식 노드 처리
    fill_tree_structure(node->left, nil, tree_structure, level + 1, left, mid - 1);

    // 오른쪽 자식 노드 처리
    fill_tree_structure(node->right, nil, tree_structure, level + 1, mid + 1, right);
}
