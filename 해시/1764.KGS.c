#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct __node {
    char name[21];
    int num;
    struct __node *next;
} Node;

typedef struct __ChainHash {
    Node **table;
} ChainHash;

int MapInit(ChainHash *m) {
    m->table = calloc(100, sizeof(Node *)); // 소문자 = 26개

    for (int i = 0; i < 27; i++)
        m->table[i] = NULL;

    return 0;
}

int Hash(char* filename) {
    int HashTemp = (int)filename[0] % 97;

    if (HashTemp > 25)
        return 26;

    return HashTemp;
}

int PrintMap(const Node *p) {
    
    // 꼬리가 될 때까지 출력
    while (p != NULL) {
        if (p->num == 1)
            printf("%s\n", p->name);
        
        p = p->next;
    }
        
    return 0;
}

int main() {
    int i, l, pass;
    char name[21];
    ChainHash Map;
    Node *NewNode;

    MapInit(&Map);


    scanf(" %d %d", &i, &l);

    // 듣
    while (i--) {
        scanf(" %s", name);

        pass = 0;
        int HP = Hash(name); // 해시 -> 위치 선정

        NewNode = calloc(1, sizeof(Node));
        strcpy(NewNode->name, name);
        NewNode->num = 0;
        NewNode->next = NULL;
        
        Node *p = Map.table[HP];

        // 최초 등록
        if (p == NULL) {
            Map.table[HP] = NewNode;
            continue;
        }

        // 꼬리에 넣기
        while (p != NULL) {
            // 기존에 있을 경우
            if (strcmp(NewNode->name, p->name) == 0) {
                pass = 1;
                break;
            }

            p = p->next;
        }

        if (pass == 0) {
            p->next = NewNode;
        }
    }

    // 검색
    while (l--) {
        scanf(" %s", name);

        int HP = Hash(name);
        Node *p = Map.table[HP];

        // 꼬리 찾기
        while (p != NULL) {
            // 기존에 있을 경우
            if (strcmp(name, p->name) == 0) {
                p->num = 1;
                pass = 1;
                break;
            }

            p = p->next;
        }
    }


    // 출력
    for (int i = 0; i < 26; i++) {
        PrintMap(Map.table[i]); 
    }

    return 0;
}