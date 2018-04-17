#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define MAX 100
#define getMax(x,y) ( x < y ? y : x )

int heap[MAX] = { 0 };
int heapSize = 0;

#define swap(x,y) {x ^= y; y ^= x; x ^= y;}

using namespace std;

int insertHeap(int n, int target)
{
    
    int i = ++heapSize;
    
    if (MAX <= heapSize) { printf("heapOverFlow\n"); return -1; }
    
    switch (target)
    {
        case 0:
            while (i != 0 && n < heap[i / 2])
            {
                heap[i] = heap[i / 2];
                i = i / 2;
            }
            
            heap[i] = n;
            break;
        case 1:
            while (i != 0 && n > heap[i / 2])
            {
                heap[i] = heap[i / 2];
                i = i / 2;
            }
            
            heap[i] = n;
            break;
    }
    return 0;
    
}

int deleteHeap()
{
    
    int child;
    int data;
    int temp;
    
    if(heapSize == 0){return -1;}
    
    data = heap[1];
    temp = heap[heapSize];
    heap[heapSize--] = INT32_MAX;
    
    child = 2;
    
    while (child <= heapSize)
    {
        
        if (heap[child] > heap[child + 1])
        {
            child++;
        }
        
        if (temp <= heap[child])
        {
            break;
        }
        
        heap[child/2] = heap[child];
        child *= 2;
        
    }
    
    heap[child/2] = temp;
    
    return data;
    
}

int main(void)
{
    
    // first arg -> data
    // second arg -> 0 : min, 1 : max
    
    insertHeap(1,0);
    insertHeap(3,0);
    insertHeap(5,0);
    insertHeap(7,0);
    insertHeap(9,0);
    insertHeap(8,0);
    insertHeap(6,0);
    insertHeap(9,0);
    insertHeap(2,0);
    
    deleteHeap();
    
    for(int i = 1; i <= heapSize; i++)
    {
        cout << heap[i] << endl;
    }
    
    return 0;
    
}
