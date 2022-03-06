// O(log n)
#include <stdio.h>
#include <stdlib.h>

typedef struct __node {
    int num;
    struct __node *left;
    struct __node *right;
} Node;

Node *FindNode(Node *node, int key){
    if (node == NULL)
        return NULL;

    if (node->num == key)
        return node;
    
    Node *res1 = FindNode(node->left, key);
    
    if (res1 != NULL)
        return res1;
    
    Node *res2 = FindNode(node->right, key);
    
    return res2;
}

void Preorder(Node *node){
	if(node == NULL) return;
	
	printf("%c", node->num);
	Preorder(node->left);
	Preorder(node->right);
}

void Inorder(Node *node){
	if(node == NULL) return;
	
	Inorder(node->left);
	printf("%c", node->num);
	Inorder(node->right);
}

void Postorder(Node *node){
	if(node == NULL) return;
	
	Postorder(node->left);
	Postorder(node->right);
	printf("%c", node->num);
}


int main(){
    Node tree;
    Node *p;

    int n;
    char a, b, c;

    scanf(" %d", &n);
    tree.num = 65; // 기본값 A
    tree.left = NULL;
    tree.right = NULL;
    
    while (n--) {
        scanf(" %c %c %c", &a, &b, &c);

        p = FindNode(&tree, a);
        
        if (b != '.') {
            p->left = calloc(1, sizeof(Node));
            p->left->num = b;
        }

        if (c != '.') {
            p->right = calloc(1, sizeof(Node));
            p->right->num = c;
        }
    }

    Preorder(&tree); puts("");
    Inorder(&tree); puts("");
	Postorder(&tree); puts("");

    return 0;
}