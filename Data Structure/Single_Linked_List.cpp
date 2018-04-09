typedef struct _node{
 
int data; //데이터
struct _node* Next; //구조체의 주소를 저장하는 포인터
 
}Node;
 
맨앞을 가리키는 포인터 Head와 꼬리를 가리키는 포인터 Tail을 사용해서 연결 리스트를 구현 하겠습니다.
 
int main(void){
 
Node* Head = NULL;
Node* Tail   = NULL;
Node* newNode = NULL;
 
int data = 0;
 
//InsertNode;
while(1){
 
printf("데이터 입력 : ");
scanf("%d",&data);
 
if(0 == data){
break;//입력 데이터가 0이면 인서트 작업을 끝냄.
}
 
//노드 동적 할당
newNode = (Node*)malloc(sizeof(Node));
newNode->Next = NULL;
newNode->data = data;
 
if(NULL == Head){
Head = newNode; //맨 처음을 가리키게 해야함.
} else {
Tail ->Next = newNode;
}
Tail = newNode; // 항상 끝을 가리키게 해야함.
}
 
//출력
Node* Cur = Head;
while(NULL != Cur){
printf("%d ",Cur->data);
Cur = Cur->Next;
}
 
//삭제
Node* Del = Head;
Node* DelNext;
while(Del != NULL){
free(Del);
DelNext = Head->Next;
Del = DelNext;
}
//삽입
printf("무슨 데이터 앞에 넣겠습니까? : ");
scanf("%d",&data);
Node* InsertNode = Head;
while(data != InsertNode->Next->data){
InsertNode = InsertNode->data;
}
newNode = (Node*)malloc(sizeof(Node));
newNode->Next = InsertNode->Next;
newNode->data = data;
InsetNode->Next = newNode;
 
return 0;
}
