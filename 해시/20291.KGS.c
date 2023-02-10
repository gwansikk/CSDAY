#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct __node {
    char name[101];
    int num;
    struct __node *next;
} Node;

typedef struct __ChainHash {
    Node **table;
} ChainHash;

int MapInit(ChainHash *m) {
    m->table = calloc(27, sizeof(Node *)); // 소문자 = 26개

    for (int i = 0; i < 27; i++)
        m->table[i] = NULL;

    return 0;
}

char* PassingExtension(char *file) {
    strtok(file, "."); // 앞 부분 제거

    return strtok(NULL, ".");
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
        printf("%s %d\n", p->name, p->num);
        p = p->next;
    }
        
    return 0;
}

int main() {
    int i, pass;
    char filename[101];
    ChainHash Map;
    Node *NewNode;

    scanf(" %d", &i);
    MapInit(&Map);
    

    while (i--) {
        scanf(" %s", filename);

        pass = 0;
        char *PE = PassingExtension(filename); // 확장자 이름
        int HP = Hash(PE); //맵 위치 선정

        NewNode = calloc(1, sizeof(Node));
        strcpy(NewNode->name, PE);
        NewNode->num = 1;
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
                p->num++;
                pass = 1;
                break;
            }

            p = p->next;
        }

        if (pass == 0)
            p->next = NewNode;
    }

    // 출력
    for (int i = 0; i < 26; i++) {
        PrintMap(Map.table[i]); 
    }

    return 0;
}