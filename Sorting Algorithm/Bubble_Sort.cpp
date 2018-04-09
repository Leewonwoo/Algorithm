#include <vector>
#include <queue>
#include <time.h>
#include <iostream>
#include <math.h>

using namespace std;

#define N 1000

void swap(int *p, int *p2)
{
    
    int temp = *p;
    *p = *p2;
    *p2 = temp;
    
}

int main(void)
{
    
    srand(time(NULL));
    
    int arr[N] = {0};
    
    for(int i = 0; i < N; i++)
    {
        
        arr[i] = rand() % N + 1;
        
        for(int j = 0; j < i;j++)
        {
            if(arr[i] == arr[j])
            {
                i--;
                break;
            }
        }
    }
    
    for(int i = 0; i < N - 1; i++)
    {
        for(int j = 0; j < N - i - 1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
    
    return 0;

}



