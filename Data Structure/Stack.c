#include <stdio.h>
#include <stdlib.h>
 
#define MAX 512
 
int* push(int stack[],int *idx,int data)
{
    if (*idx < 0)
    {
        printf("잘못된 인덱스 입니다.\n");
 
    }
    else
    {
        printf("PUSH!\n");
        stack[*idx] = data;
        *idx = *idx + 1;
    }
 
    return stack;
}
 
int* pop(int stack[],int *idx)
{
    
    if (*idx < 0)
    {
        printf("잘못된 인덱스 입니다.\n");
 
    }
    else
    {
        printf("POP!\n");
        *idx = *idx - 1;
        printf("%d\n",stack[*idx]);
    }
 
    return stack;
}
 
int main(void)
{
 
    int *stack = (int*)malloc(sizeof(int) * MAX);
    int idx = 0;
 
    stack = push(stack, &idx, 1);
    stack = push(stack, &idx, 2);
    stack = pop(stack, &idx);

    for (int i = idx - 1;i >= 0;i--)
    {
        printf("%d ",stack[i]);
    }

    printf("\n");
    
    return 0;

}
