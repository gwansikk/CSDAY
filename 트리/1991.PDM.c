#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    char data;
    struct Node *left;
    struct Node *right;
}node;

node *makeNode(char ch){
    node *nd = (node*)malloc(sizeof(node));
    nd->data = ch;
    nd->left = NULL;
    nd->right = NULL;
    
    return nd;
}

node *searchNode(node *nd, char ch){
    if(nd != NULL){
        if(nd->data == ch){
            return nd;
        }
        else{ // 왼쪽 뒤지고, 없으면 오른쪽 뒤짐
            node *ndd = searchNode(nd->left, ch);
            if(ndd != NULL){
                return ndd;
            }
            else
                return searchNode(nd->right, ch);
        }
    }
    else
        return NULL;
}

void setNode(node *nd, char fir, char sec, char thr){
    nd->data = fir;
    if (sec != '.'){
        nd->left = makeNode(sec);
    }
    if(thr != '.'){
        nd->right = makeNode(thr);
    }
}

void preorderPrint(node *nd){ // 전위
    if(nd == NULL){
        return;
    }
    else{
        printf("%c", nd->data);
        preorderPrint(nd->left);
        preorderPrint(nd->right);
    }
}

void inorderPrint(node *nd){ // 중위
    if(nd == NULL){
        return;
    }
    else{
        inorderPrint(nd->left);
        printf("%c", nd->data);
        inorderPrint(nd->right);
    }
}

void postorderPrint(node *nd){ // 후위
    if(nd == NULL){
        return;
    }
    else{
        postorderPrint(nd->left);
        postorderPrint(nd->right);
        printf("%c", nd->data);
    }
}

int main() {
    int num;
    char a, b, c;
    
    node *tree = makeNode(NULL); // 정답 도출용 작성되는 노드
    node *tree2; // tree에서 나온 주소에 바로 이어서 작성하기 위한 노드
    
    scanf("%d", &num);
    getchar();
    
    for(int i = 0; i < num; i++){
        scanf("%c %c %c", &a, &b, &c);
        getchar();
        
        tree2 = searchNode(tree, a);
        
        if(tree2 != NULL){ // tree노드에 있는 값이라는 뜻 => tree노드에서 a가 들어갈 주소를 갖고있는 btt에 넣기
            setNode(tree2, a, b, c);
        }
        else{ // 처음에 A를 집어넣는 과정
            setNode(tree, a, b, c);
        }
    }
    
    // 전위, 중위, 후위에 맞게 출력
    preorderPrint(tree);
    printf("\n");
    inorderPrint(tree);
    printf("\n");
    postorderPrint(tree);
    return 0;
}

/*
 노드를 뜻하는 구조체 생성
 구조체 내부에 자신의 값 넣고, 왼쪽, 오른쪽을 뜻하는 구조체 생성 넣기
 그럼
     A
    B C
 로 노드를 넣음
 전위 순회
    노드의 왼쪽으로 감 -> 없음, 오른쪽으로 감 -> 없음, 이전 노드로 돌아감. root node만나면 끝
 중위 순회
    
 */
