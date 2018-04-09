#include <stdio.h>
#include <stdlib.h>
 
typedef struct _Node {
    struct _Node* Pre; // 전 노드를 가리키는 포인터
    int data;
    struct _Node* Next; // 다음 노드를 가리키는 포인터
}Node;
 
int main(void) {
    Node* Head = NULL;
    Node* Tail = NULL;
    Node* newNode;
    int readData;
 
    while (1) {
 
        printf("데이터 입력 : ");
        scanf("%d", &readData);
        if (0 == readData) {
            break;
        }
 
        newNode = (Node*)malloc(sizeof(Node));
        newNode->Pre = NULL;
        newNode->Next = NULL;
        newNode->data = readData;
 
        if (Head == NULL) {
            Head = newNode;
            Tail = newNode;
        }
        else {
            newNode->Pre = Tail;
            newNode->Next = Head;
            Tail->Next = newNode;
            Tail = newNode;
        }
 
    }
 
    Node* Cur = Head;
    while (Cur != NULL) {
        printf("%d ", Cur->data);
        Cur = Cur->Next;
    }
 
    printf("\n");
 
    /*Cur = Tail;
    while (Cur != NULL) {
        printf("%d ", Cur->data);
        Cur = Cur->Pre;
    }*/
 
    printf("\n");
 
    return 0;
}
