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
    
    for(int i = 0; i < N; i++)
    {
        int temp = i + 1;
        for(int j = i + 1; j >= 0; j--)
        {
            if(arr[temp] < arr[j])
            {
                swap(&arr[temp],&arr[j]);
                temp = j;
            }
        }
    }
    
    for(int i = 0; i < N; i++)
    {
        cout << arr[i] << endl;
    }
    
    return 0;
    
}